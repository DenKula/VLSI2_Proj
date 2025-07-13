// -----------------------------------------------------------------------------
// fft_stage.sv  –  One radix‑2 streaming butterfly stage for fft_top
// -----------------------------------------------------------------------------
//   • Fixed‑point arithmetic, parameterised width
//   • Pure "valid" pipeline – always READY (no back‑pressure upstream)
//   • Assumes a decimation‑in‑time flow as in fft_top.sv
//   • Twiddle factors are fetched from fft_pkg::twiddle_rom(), which you can
//     replace with your own table or CORDIC generator.
//
// IMPORTANT:  This is a teaching‑oriented implementation.  For ASIC timing you
//             may want to retime, add rounding stages, or fold constants.
// -----------------------------------------------------------------------------
`include "fft_pkg.sv"

module fft_stage #(
  parameter int unsigned DATA_W = 16,   // width of Re/Im part
  parameter int unsigned STAGE  = 0,    // which radix‑2 stage (0 = first)
  parameter int unsigned LOGN   = 10    // log2 FFT length
)(
  input  logic                 clk,
  input  logic                 rst_n,

  // Stream input (always ready)
  input  logic                 valid_in,
  input  fft_pkg::complex_t    din,

  // Stream output
  output logic                 valid_out,
  output fft_pkg::complex_t    dout
);
  // ---------------------------------------------------------------------------
  // 1. Twiddle ROM – returns W = e^(−j 2π k / N) for this STAGE
  // ---------------------------------------------------------------------------
  localparam int unsigned TW_W = DATA_W+2;  // +2 bits headroom for mul
  logic signed [TW_W-1:0] w_re, w_im;

  // The address into the ROM for stage S in a radix‑2 DIF/DIT can be derived
  // from the sample index.  For demonstration we use a simple counter that
  // rolls every 2^S samples.
  logic [LOGN-1:0] sample_idx_q, sample_idx_d;
  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) sample_idx_q <= '0;
    else if (valid_in) sample_idx_q <= sample_idx_q + 1'b1;
  end
  assign sample_idx_d = sample_idx_q;

  // Instantiate read‑only twiddle table (power‑of‑two length N = 1<<LOGN)
  fft_pkg::twiddle_rom #(
    .DATA_W ( TW_W ),
    .LOGN   ( LOGN ),
    .STAGE  ( STAGE )
  ) i_tw_rom (
    .clk_i ( clk ),
    .addr_i( sample_idx_d[LOGN-1:LOGN-STAGE] ), // drop LSBs per stage
    .re_o  ( w_re ),
    .im_o  ( w_im )
  );

  // ---------------------------------------------------------------------------
  // 2. Complex multiply:  W * din[1] (assuming stream already reordered)
  // ---------------------------------------------------------------------------
  logic signed [DATA_W-1:0]  a_re, a_im;   // first operand
  logic signed [DATA_W-1:0]  b_re, b_im;   // second operand

  assign a_re = din.re;   // For streaming DIF, the pairing happens upstream
  assign a_im = din.im;
  assign b_re = din.re;   // Placeholder – ***replace with delayed sample***
  assign b_im = din.im;

  logic signed [2*DATA_W:0]  mult_re, mult_im;
  assign mult_re = w_re*b_re - w_im*b_im;
  assign mult_im = w_re*b_im + w_im*b_re;

  // ---------------------------------------------------------------------------
  // 3. Butterfly add/sub (truncate to DATA_W at output)
  // ---------------------------------------------------------------------------
  logic signed [DATA_W:0] x_re, x_im, y_re, y_im;
  assign x_re = a_re + mult_re[DATA_W+DATA_W-1 -: DATA_W+1];
  assign x_im = a_im + mult_im[DATA_W+DATA_W-1 -: DATA_W+1];
  assign y_re = a_re - mult_re[DATA_W+DATA_W-1 -: DATA_W+1];
  assign y_im = a_im - mult_im[DATA_W+DATA_W-1 -: DATA_W+1];

  // ---------------------------------------------------------------------------
  // 4. Pipeline register
  // ---------------------------------------------------------------------------
  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      valid_out <= 1'b0;
      dout      <= '0;
    end else begin
      valid_out <= valid_in;
      dout.re   <= x_re[DATA_W-1:0];  // simple truncation
      dout.im   <= x_im[DATA_W-1:0];
    end
  end
endmodule
