//====================================================================
// fft_pkg.sv – common types & helpers for the streaming radix-2 FFT
//====================================================================
package fft_pkg;

  // ------------------------------------------------------------------
  // Global width parameters
  // ------------------------------------------------------------------
  parameter int DATA_W    = 16;             // bits per Re or Im sample
  parameter int STREAM_DW = 2*DATA_W;       // packed {Re,Im} width = 32

  // ------------------------------------------------------------------
  // Complex sample record (signed fixed-point, Q( DATA_W-1 ).(DATA_W-1))
  // ------------------------------------------------------------------
  typedef struct packed {
    logic signed [DATA_W-1:0] re;
    logic signed [DATA_W-1:0] im;
  } complex_t;

  // ------------------------------------------------------------------
  // Basic complex arithmetic (combinational helpers)
  // ------------------------------------------------------------------
  function automatic complex_t c_add (complex_t a, complex_t b);
    c_add.re = a.re + b.re;
    c_add.im = a.im + b.im;
  endfunction

  function automatic complex_t c_sub (complex_t a, complex_t b);
    c_sub.re = a.re - b.re;
    c_sub.im = a.im - b.im;
  endfunction

  // Full-precision multiply then truncation (guard-bit at MSB side)
  function automatic complex_t c_mul (complex_t a, complex_t b);
    logic signed [2*DATA_W-1:0] mult_re;
    logic signed [2*DATA_W-1:0] mult_im;

    mult_re = a.re*b.re - a.im*b.im;
    mult_im = a.re*b.im + a.im*b.re;

    // Keep the top DATA_W bits (simple right-shift truncation).
    // Add rounding or saturation here if you need higher SQNR.
    c_mul.re = mult_re[2*DATA_W-2 -: DATA_W];
    c_mul.im = mult_im[2*DATA_W-2 -: DATA_W];
  endfunction

  // ------------------------------------------------------------------
  // Generic bit-reverse utility (rarely needed now but handy for test)
  // ------------------------------------------------------------------
  function automatic logic [K-1:0] bit_reverse_generic
    #(parameter int K = 1)
    (input logic [K-1:0] x);

    for (int i = 0; i < K; i++) begin
      bit_reverse_generic[i] = x[K-1-i];
    end
  endfunction

endpackage : fft_pkg
