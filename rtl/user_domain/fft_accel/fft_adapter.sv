// -----------------------------------------------------------------------------
// fft_adapter.sv  –  OBI-subordinate bridge for streaming FFT core
// -----------------------------------------------------------------------------
// Maps a simple, blocking register set onto the streaming radix-2 FFT pipeline
// (fft_top.sv).  Software writes complex samples, reads back transformed data.
//
// Register map (byte offsets, word-aligned):
//   0x00  DATA_IN   W  {Re[31:16], Im[15:0]}   – push one complex sample
//   0x04  STATUS    R  {29:3 rsvd, OUT_VLD, IN_RDY, BUSY}
//                     BUSY    – 1 while pipeline still flushing this frame
//                     IN_RDY  – 1 if DATA_IN write will be accepted
//                     OUT_VLD – 1 if DATA_OUT holds a valid word
//   0x08  DATA_OUT  R  {Re[31:16], Im[15:0]}   – pop one transformed sample
//
// Two FIFOs decouple bus timing from the streaming datapath.
// -----------------------------------------------------------------------------
`include "obi/typedef.svh"
`include "obi/assign.svh"

module fft_adapter #(
  parameter int unsigned DATA_W      = 16,   // width of Re/Im part
  parameter int unsigned LOGN        = 10,   // N = 2**LOGN points
  parameter int unsigned FIFO_DEPTH  = 32,   // words per FIFO
  parameter obi_pkg::obi_cfg_t ObiCfg = obi_pkg::ObiDefaultConfig,

  localparam int unsigned WORD_W     = 2*DATA_W,
  localparam int unsigned ADDR_BITS  = cf_math_pkg::idx_width(3),
  localparam logic [ADDR_BITS-1:0] ADDR_DATA_IN  = 'h0,
  localparam logic [ADDR_BITS-1:0] ADDR_STATUS   = 'h1,
  localparam logic [ADDR_BITS-1:0] ADDR_DATA_OUT = 'h2
) (
  // Clocks / reset
  input  logic               clk_i,
  input  logic               rst_ni,
  input  logic               testmode_i,

  // OBI subordinate port
  input  obi_req_t           obi_req_i,
  output obi_rsp_t           obi_rsp_o,

  // Optional raw stream export (tie off if unused)
  output logic               fft_out_valid_o,
  output logic [WORD_W-1:0]  fft_out_data_o,
  input  logic               fft_out_ready_i
);

  // ─────────────────────────────────────────────────────────────
  // Local stream typedef
  typedef struct packed {
    logic               valid;
    logic [WORD_W-1:0]  data;
    logic               ready;
  } strm_t;
  // ─────────────────────────────────────────────────────────────
  // Input FIFO  (SW → FFT)
  logic              in_fifo_full,  in_fifo_empty;
  logic [WORD_W-1:0] in_fifo_rdata;
  logic              in_fifo_push,  in_fifo_pop;

  fifo_v3 #(
    .DATA_WIDTH  ( WORD_W ),
    .DEPTH       ( FIFO_DEPTH ),
    .FALL_THROUGH( 1'b0 )
  ) i_in_fifo (
    .clk_i, .rst_ni,
    .testmode_i,
    .flush_i   ( '0 ),
    .data_i    ( obi_req_i.w.data[WORD_W-1:0] ),
    .push_i    ( in_fifo_push ),
    .full_o    ( in_fifo_full ),
    .usage_o   (),
    .data_o    ( in_fifo_rdata ),
    .pop_i     ( in_fifo_pop ),
    .empty_o   ( in_fifo_empty )
  );

  // ─────────────────────────────────────────────────────────────
  // Output FIFO (FFT → SW)
  logic              out_fifo_full,  out_fifo_empty;
  logic [WORD_W-1:0] out_fifo_rdata;
  logic              out_fifo_push,  out_fifo_pop;

  fifo_v3 #(
    .DATA_WIDTH  ( WORD_W ),
    .DEPTH       ( FIFO_DEPTH ),
    .FALL_THROUGH( 1'b0 )
  ) i_out_fifo (
    .clk_i, .rst_ni,
    .testmode_i,
    .flush_i   ( '0 ),
    .data_i    ( out_strm.data ),
    .push_i    ( out_fifo_push ),
    .full_o    ( out_fifo_full ),
    .usage_o   (),
    .data_o    ( out_fifo_rdata ),
    .pop_i     ( out_fifo_pop ),
    .empty_o   ( out_fifo_empty )
  );

  // ─────────────────────────────────────────────────────────────
  // Stream wiring
  strm_t in_strm, out_strm;

  assign in_strm.valid = ~in_fifo_empty;
  assign in_strm.data  = in_fifo_rdata;
  assign in_fifo_pop   = in_strm.valid & in_strm.ready;

  assign out_fifo_push = out_strm.valid & out_strm.ready & ~out_fifo_full;

  // Export outgoing stream if wanted
  assign fft_out_valid_o = ~out_fifo_empty;
  assign fft_out_data_o  = out_fifo_rdata;
  assign out_fifo_pop    = fft_out_valid_o & fft_out_ready_i;
  assign out_strm.ready  = ~out_fifo_full;

  // ─────────────────────────────────────────────────────────────
  // FFT core
  fft_top #(
    .DATA_W ( DATA_W ),
    .LOGN   ( LOGN )
  ) i_fft_top (
    .clk_i,
    .rst_ni,
    .fft_in_i  ( in_strm  ),
    .fft_out_o ( out_strm ),
    .ready_i   ( out_strm.ready )
  );

  // ─────────────────────────────────────────────────────────────
  // Simple status flags
  logic busy;
  // expose last stage valid to flag BUSY while pipeline flushes
  assign busy = in_strm.valid | (|i_fft_top.vld_pipe);

  wire in_rdy  = ~in_fifo_full;
  wire out_vld = ~out_fifo_empty;

  // ─────────────────────────────────────────────────────────────
  // OBI subordinate logic
  typedef enum logic [1:0] {Idle, ReadWait} state_e;
  state_e state_q, state_d;

  logic [WORD_W-1:0] rdata_d, rdata_q;
  logic rerr_d,  rerr_q;
  logic gnt_d,   gnt_q;
  logic rvalid_d,rvalid_q;

  // Default combinational
  always_comb begin
    // defaults
    state_d   = state_q;
    rdata_d   = rdata_q;
    rerr_d    = 1'b0;
    gnt_d     = 1'b0;
    rvalid_d  = 1'b0;

    in_fifo_push = 1'b0;
    out_fifo_pop = 1'b0;

    // decode current request
    if (obi_req_i.req) begin
      unique case (obi_req_i.a.addr[ADDR_BITS+1:2])
        ADDR_DATA_IN: begin
          if (obi_req_i.we && in_rdy) begin
            in_fifo_push = 1'b1;
            gnt_d        = 1'b1; // accept write
          end
        end
        ADDR_STATUS: begin
          if (!obi_req_i.we) begin
            rdata_d  = {29'd0, out_vld, in_rdy, busy};
            gnt_d    = 1'b1;
            rvalid_d = 1'b1;
          end
        end
        ADDR_DATA_OUT: begin
          if (!obi_req_i.we) begin
            if (out_vld) begin
              rdata_d  = out_fifo_rdata;
              out_fifo_pop = 1'b1;
              gnt_d    = 1'b1;
              rvalid_d = 1'b1;
            end else begin
              // wait state
              state_d = ReadWait;
            end
          end
        end
        default: begin
          rerr_d   = 1'b1;  // decode error
          gnt_d    = 1'b1;
          rvalid_d = 1'b1;
        end
      endcase
    end

    // waiting for DATA_OUT to become valid
    if (state_q == ReadWait) begin
      if (out_vld) begin
        rdata_d   = out_fifo_rdata;
        out_fifo_pop = 1'b1;
        gnt_d     = 1'b1;
        rvalid_d  = 1'b1;
        state_d   = Idle;
      end
    end
  end

  // sequential
  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin
      state_q  <= Idle;
      rdata_q  <= '0;
      rerr_q   <= 1'b0;
      gnt_q    <= 1'b0;
      rvalid_q <= 1'b0;
    end else begin
      state_q  <= state_d;
      rdata_q  <= rdata_d;
      rerr_q   <= rerr_d;
      gnt_q    <= gnt_d;
      rvalid_q <= rvalid_d;
    end
  end

  // drive response
  assign obi_rsp_o.gnt    = gnt_q;
  assign obi_rsp_o.rvalid = rvalid_q;
  assign obi_rsp_o.r.err  = rerr_q;
  assign obi_rsp_o.r.rdata= rdata_q;
  assign obi_rsp_o.r.rid  = obi_req_i.a.aid; // echo

endmodule
