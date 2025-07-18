`timescale 1ns/1ps
// ====================================================================
// bitrev_tb – single‑frame smoke test for the bit‑reversal core
// ====================================================================

module bitrev_tb;

  // ------------------------------------------------------------------
  // Parameters (must match DUT generics)
  localparam int unsigned K  = 10;
  localparam int unsigned N  = 1 << K;   // 1024‑point frame
  localparam int unsigned DW = 32;

  // ------------------------------------------------------------------
  // DUT interface signals
  logic clk_i   = 0;
  logic rst_ni  = 0;

  logic                 valid_i = 0;
  logic [DW-1:0]        data_i  = '0;
  logic                 ready_o;

  logic                 valid_o;
  logic [DW-1:0]        data_o;
  logic                 ready_i = 0;

  // ------------------------------------------------------------------
  // Device Under Test
  bitrev #(
    .K (K),
    .DW(DW)
  ) dut (
    .clk_i  (clk_i),
    .rst_ni (rst_ni),
    .valid_i(valid_i),
    .data_i (data_i),
    .ready_o(ready_o),
    .valid_o(valid_o),
    .data_o (data_o),
    .ready_i(ready_i)
  );

  // ------------------------------------------------------------------
  // Clock generator : 100 MHz (10 ns period)
  always #5 clk_i = ~clk_i;

  // ------------------------------------------------------------------
  // Bit‑reverse utility (combinational)
  function automatic [K-1:0] reverse_bits_k (input logic [K-1:0] x);
    for (int i = 0; i < K; i++)
      reverse_bits_k[i] = x[K-1-i];
  endfunction

  // ------------------------------------------------------------------
  // Main stimulus
  integer err_cnt = 0;     // signed 32‑bit – tool‑friendly

  initial begin
    $dumpfile("bitrev_tb.vcd");
    $dumpvars(0, bitrev_tb);

    // ------------------------------------------------------------
    // 1) Reset
    rst_ni = 0;
    repeat (4) @(posedge clk_i);
    rst_ni = 1;

    // ------------------------------------------------------------
    // 2) Send one natural‑order frame
    for (int unsigned i = 0; i < N; i++) begin
      @(posedge clk_i);
      valid_i <= 1'b1;
      data_i  <= i;
      wait (ready_o);
    end
    @(posedge clk_i);
    valid_i <= 1'b0;        // stop writing

    // ------------------------------------------------------------
    // 3) Read frame back and check
    // ➊ build a 32‑bit expected word
     logic [DW-1:0] exp_word;
    for (int unsigned i = 0; i < N; i++) begin
      ready_i <= 1'b1;
      wait (valid_o);
     @(posedge clk_i);
      ready_i <= 1'b0;


      exp_word = {{(DW-K){1'b0}}, reverse_bits_k(i[K-1:0])};

     // ➋ compare and report
      if (data_o !== exp_word) begin
        $display("Mismatch @%0d : got %0d, exp %0d",
             i, data_o, exp_word);
    err_cnt++;
  end
end

    // ------------------------------------------------------------
    // 4) Report result and finish
    if (err_cnt == 0)
      $display("Bit‑reversal test PASSED for %0d‑point frame", N);
    else
      $display("Bit‑reversal test FAILED : %0d errors", err_cnt);

    #20;
    $finish;
  end

endmodule
