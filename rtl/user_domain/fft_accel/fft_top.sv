//--------------------------------------------------------------------
// fft_top.sv  – streaming radix-2 FFT + on-chip bit-reversal
//--------------------------------------------------------------------
`include "user_pkg.sv"    // strm_t, BITREV_DW, etc.
`include "fft_pkg.sv"

module fft_top #(
  parameter int DATA_W = 16,             // width of each Re/Im part
  parameter int LOGN   = 10              // K = log2(N)
)(
  // Clock / reset (same names as bitrev.sv for consistency)
  input  logic                clk_i,
  input  logic                rst_ni,

  // Stream input (natural order)
  input  strm_t               fft_in_i,

  // Stream output (natural order, after bit-reversal)
  output strm_t               fft_out_o,

  // Optional consumer-side “ready”; tie-high if unused
  input  logic                ready_i
);

  //------------------------------------------------------------------
  // 1.  Unpack incoming stream word → complex_t
  //------------------------------------------------------------------
  logic                      vld_in;
  fft_pkg::complex_t         din_c;
  assign vld_in       = fft_in_i.valid;
  assign din_c.re     = $signed( fft_in_i.data[2*DATA_W-1:DATA_W] );
  assign din_c.im     = $signed( fft_in_i.data[DATA_W-1:0]      );

  //------------------------------------------------------------------
  // 2.  FFT pipeline (LOGN stages)
  //------------------------------------------------------------------
  logic                      vld_pipe [0:LOGN];
  fft_pkg::complex_t         d_pipe   [0:LOGN];

  assign vld_pipe[0] = vld_in;
  assign d_pipe  [0] = din_c;

  genvar s;
  generate
    for (s = 0; s < LOGN; s++) begin : g_stage
      fft_stage #(
        .DATA_W (DATA_W),
        .STAGE  (s),
        .LOGN   (LOGN)
      ) u_stage (
        .clk       (clk_i),
        .rst_n     (rst_ni),
        .valid_in  (vld_pipe[s]),
        .din       (d_pipe[s]),
        .valid_out (vld_pipe[s+1]),
        .dout      (d_pipe[s+1])
      );
    end
  endgenerate

  //------------------------------------------------------------------
  // 3.  Pack complex output → {Re,Im} for bit-reversal writer side
  //------------------------------------------------------------------
  logic        vld_wr;
  logic [BITREV_DW-1:0] data_wr;

  assign vld_wr  = vld_pipe[LOGN];
  assign data_wr = { d_pipe[LOGN].re, d_pipe[LOGN].im };

  //------------------------------------------------------------------
  // 4.  Bit-reversal instance  (K = LOGN, DW = BITREV_DW)
  //------------------------------------------------------------------
  logic ready_dummy;   // write-side ready – always 1 in bitrev.sv

  bitrev #(
    .K  (LOGN),
    .DW (BITREV_DW)
  ) u_bitrev (
    .clk_i    (clk_i),
    .rst_ni   (rst_ni),

    // write / producer side (FFT → bitrev)
    .valid_i  (vld_wr),
    .data_i   (data_wr),
    .ready_o  (ready_dummy),   // not needed by upstream, but connected

    // read / consumer side (bitrev → rest of system)
    .valid_o  (fft_out_o.valid),
    .data_o   (fft_out_o.data),
    .ready_i  (ready_i)        // tie to 1’b1 if downstream is always ready
  );

endmodule
