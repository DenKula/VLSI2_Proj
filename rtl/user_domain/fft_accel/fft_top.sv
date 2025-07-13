// -----------------------------------------------------------------------------
// fft_top.sv  –  Streaming radix‑2 FFT with on‑chip bit‑reversal
// -----------------------------------------------------------------------------
//   * Parameterised data width (Re/Im) and size (LOGN = log2 N)
//   * Purely streaming I/O using a simple valid/ready handshake (strm_t)
//   * LOGN pipeline stages followed by an in‑place bit‑reversal buffer
//   * No configuration or control registers inside this block
// -----------------------------------------------------------------------------
//  Dependencies:
//     • user_pkg.sv    – for strm_t typedef and BITREV_DW constant
//     • fft_pkg.sv     – complex_t typedef, sin/cos tables (twiddles)
//     • fft_stage.sv   – one radix‑2 butterfly stage (see note below)
//     • bitrev.sv      – generic on‑chip bit‑reversal SRAM buffer
// -----------------------------------------------------------------------------
//  NOTE:  fft_stage.sv is *not* included here; instantiate the simple version
//  from the class or copy your own implementation.  It must expose:
//     ‑ parameters DATA_W, STAGE, LOGN
//     ‑ ports (clk, rst_n, valid_in, din, valid_out, dout)
// -----------------------------------------------------------------------------

`include "user_pkg.sv"    // strm_t, BITREV_DW
`include "fft_pkg.sv"

module fft_top #(
  parameter int unsigned DATA_W = 16,  // width of Re or Im (scalar)
  parameter int unsigned LOGN   = 10   // log2(N), N = 1024 default
)(
  // Clocks / reset
  input  logic           clk_i,
  input  logic           rst_ni,

  // Stream input  – natural order samples
  input  strm_t          fft_in_i,

  // Stream output – natural order after bit‑reversal
  output strm_t          fft_out_o,

  // Consumer‑side ready (tie‑high if downstream always ready)
  input  logic           ready_i
);

  // ─────────────────────────────────────────────────────────────
  // 1. Unpack incoming word into complex_t (signed fixed‑point)
  // ─────────────────────────────────────────────────────────────
  logic               vld_in;
  fft_pkg::complex_t  din_c;

  assign vld_in   = fft_in_i.valid;
  assign fft_in_i.ready = 1'b1;               // always ready (no back‑pressure)

  assign din_c.re = $signed( fft_in_i.data[2*DATA_W-1:DATA_W] );
  assign din_c.im = $signed( fft_in_i.data[DATA_W-1:0]      );

  // ─────────────────────────────────────────────────────────────
  // 2. FFT pipeline – array of LOGN streaming stages
  // ─────────────────────────────────────────────────────────────
  logic               vld_pipe [0:LOGN];
  fft_pkg::complex_t  d_pipe   [0:LOGN];

  assign vld_pipe[0] = vld_in;
  assign d_pipe  [0] = din_c;

  genvar s;
  generate
    for (s = 0; s < LOGN; s++) begin : g_stage
      fft_stage #(
        .DATA_W ( DATA_W ),
        .STAGE  ( s      ),
        .LOGN   ( LOGN   )
      ) i_stage (
        .clk       ( clk_i ),
        .rst_n     ( rst_ni ),
        .valid_in  ( vld_pipe[s] ),
        .din       ( d_pipe[s]   ),
        .valid_out ( vld_pipe[s+1] ),
        .dout      ( d_pipe[s+1]  )
      );
    end
  endgenerate

  // Expose pipeline-valid vector for external BUSY flag if desired
  // synthesis translate_off
  //pragma synthesis_off
  //  *Used by fft_adapter to raise BUSY
  //pragma synthesis_on
  // synthesis translate_on

  // ─────────────────────────────────────────────────────────────
  // 3. Pack complex output -> word for bit‑reversal writer side
  // ─────────────────────────────────────────────────────────────
  logic               vld_wr;
  logic [BITREV_DW-1:0] data_wr;

  assign vld_wr  = vld_pipe[LOGN];
  assign data_wr = { d_pipe[LOGN].re, d_pipe[LOGN].im };

  // ─────────────────────────────────────────────────────────────
  // 4. On‑chip bit‑reversal (K = LOGN, DW = BITREV_DW)
  // ─────────────────────────────────────────────────────────────
  logic ready_dummy; // write‑side ready, always 1 inside bitrev.sv

  bitrev #(
    .K  ( LOGN ),
    .DW ( BITREV_DW )
  ) i_bitrev (
    .clk_i   ( clk_i ),
    .rst_ni  ( rst_ni ),

    // write side (FFT -> BR)
    .valid_i ( vld_wr  ),
    .data_i  ( data_wr ),
    .ready_o ( ready_dummy ),  // ignored

    // read side (BR -> downstream)
    .valid_o ( fft_out_o.valid ),
    .data_o  ( fft_out_o.data  ),
    .ready_i ( ready_i )
  );

  // propagate ready back (no back‑pressure in this direction)
  assign fft_out_o.ready = ready_i;

endmodule
