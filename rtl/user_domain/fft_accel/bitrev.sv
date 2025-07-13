/*
 * bitrev.sv – parameterizable bit‑reversal address generator + ping‑pong RAM
 *
 * Croc naming style:
 *   *_i : input  | *_o : output | *_n : active‑low
 *   *_d : combinational data    | *_q : registered data
 *
 * Write side handshake : valid_i / ready_o
 * Read  side handshake : valid_o / ready_i
 *
 * Public domain / CC0.
 */
module bitrev #(
  parameter int K  = 10,   // log2(N) – e.g. 10 ⇒ 1024‑point FFT
  parameter int DW = 32    // data width
)(
  // Clock / reset
  input  logic                 clk_i,
  input  logic                 rst_ni,

  // Write side (natural‑order stream from butterflies)
  input  logic                 valid_i,
  input  logic [DW-1:0]        data_i,
  output logic                 ready_o,

  // Read side (bit‑reversed stream to next stage)
  output logic                 valid_o,
  output logic [DW-1:0]        data_o,
  input  logic                 ready_i
);

  localparam int N = 1 << K;

  // ------------------------------------------------------------------
  // Dual‑port SRAM (behavioural placeholder – swap for tc_sram macros)
  // ------------------------------------------------------------------
  logic [DW-1:0] sram [0:2*N-1];

  // Ping‑pong selects : 0 ⇒ bank A , 1 ⇒ bank B.
  logic bank_sel_wr, bank_sel_rd;

  // Counters
  logic [K-1:0] wr_cnt, rd_cnt;

  // ============================================================== 
  //  WRITE PATH  – always accept one word per clock                 |
  // ==============================================================
  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin
      wr_cnt      <= '0;
      bank_sel_wr <= 1'b0;
    end else if (valid_i && ready_o) begin
      sram[{bank_sel_wr, wr_cnt}] <= data_i;
      wr_cnt <= wr_cnt + 1'b1;
      if (wr_cnt == (N-1)) begin
        wr_cnt      <= '0;
        bank_sel_wr <= ~bank_sel_wr;     // switch banks after N samples
      end
    end
  end
  // Consumer is always ready
  assign ready_o = 1'b1;

  // ============================================================== 
  //  READ PATH – bit‑reversal with data_d / data_q separation       |
  // ==============================================================
  // Combinational next‑data
  logic [DW-1:0] data_d, data_q;
  assign data_o = data_q;   // expose registered data to the outside

  // Bit‑reverse function (combinational)
  function automatic [K-1:0] bit_reverse (input logic [K-1:0] x);
    for (int i = 0; i < K; i++) begin
      bit_reverse[i] = x[K-1-i];
    end
  endfunction

  // Combinational read address and data
  always_comb begin
    data_d = sram[{bank_sel_rd, bit_reverse(rd_cnt)}];
  end

  // Sequential part
  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin
      rd_cnt      <= '0;
      bank_sel_rd <= 1'b1;   // opposite bank of writer at reset
      data_q      <= '0;
      valid_o     <= 1'b0;
    end else if (ready_i || ~valid_o) begin
      data_q  <= data_d;
      valid_o <= 1'b1;
      rd_cnt  <= rd_cnt + 1'b1;

      if (rd_cnt == (N-1)) begin
        rd_cnt      <= '0;
        bank_sel_rd <= ~bank_sel_rd;     // switch when bank fully read
      end
    end
  end

endmodule
