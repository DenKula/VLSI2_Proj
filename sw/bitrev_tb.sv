`timescale 1ns/1ps
// ====================================================================
// bitrev_tb – behavioural smoke test for the bit‑reversal core
// ====================================================================

module bitrev_tb;

  // ------------------------------------------------------------------
  // Parameters
  localparam int unsigned K  = 10;
  localparam int unsigned N  = 1 << K;
  localparam int unsigned DW = 32;

  // ------------------------------------------------------------------
  // DUT interface signals
  logic                 clk_i   = 0;
  logic                 rst_ni  = 0;

  // Write side
  logic                 valid_i = 0;
  logic [DW-1:0]        data_i  = '0;
  logic                 ready_o;

  // Read side
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
  // Clock generator – 100 MHz (10 ns period)
  always #5 clk_i = ~clk_i;

  // ------------------------------------------------------------------
  // Helpers
  function automatic [K-1:0] reverse_bits_k (input logic [K-1:0] x);
    for (int i = 0; i < K; i++)
      reverse_bits_k[i] = x[K-1-i];
  endfunction

  task automatic push_frame;
    for (int unsigned i = 0; i < N; i++) begin
      @(posedge clk_i);
      valid_i <= 1'b1;
      data_i  <= i;
      wait (ready_o);           // back‑pressure aware
    end
    @(posedge clk_i);
    valid_i <= 1'b0;            // stop driving
  endtask

  task automatic pull_and_check_frame (output int unsigned errors);
    errors = 0;
    for (int unsigned i = 0; i < N; i++) begin
      ready_i <= 1'b1;
      wait (valid_o);           // wait for next sample
      @(posedge clk_i);
      ready_i <= 1'b0;          // consume
      if (data_o !== reverse_bits_k(i)) begin
        $display("Mismatch @%0d : got %0d, exp %0d",
                 i, data_o, reverse_bits_k(i));
        errors++;
      end
    end
  endtask

  // ------------------------------------------------------------------
  // Test sequence
  initial begin
    // VCD dump
    $dumpfile("bitrev_tb.vcd");
    $dumpvars(0, bitrev_tb);

    // ------------------------------------------------------------
    // 1) Reset
    rst_ni = 0;
    repeat (4) @(posedge clk_i);
    rst_ni = 1;

    // ------------------------------------------------------------
    // 2) Prime writer/reader bank pointers (send one dummy frame)
    push_frame();
    pull_and_check_frame(.errors(/* unused */));

    // ------------------------------------------------------------
    // 3) Real test – send natural‑order frame, expect bit‑reversed
    intiger err_cnt;
    push_frame();
    pull_and_check_frame(.errors(err_cnt));

    if (err_cnt == 0)
      $display("Bit‑reversal test PASSED for %0d‑point frame", N);
    else
      $display("Bit‑reversal test FAILED : %0d errors", err_cnt);

    // ------------------------------------------------------------
    $finish;
  end

endmodule
