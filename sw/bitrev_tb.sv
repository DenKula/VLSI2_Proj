`timescale 1ns/1ps

module bitrev_tb;

  // ------------------------------------------------------------------
  // Parameters (must match DUT generics)
  localparam int unsigned K  = 7;
  localparam int unsigned N  = 1 << K;
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
    .data_o(data_o),
    .ready_i(ready_i)
  );

  // ------------------------------------------------------------------
  // Clock generator : 100 MHz
  always #5 clk_i = ~clk_i;

  // ------------------------------------------------------------------
  // Bit-reverse utility (combinational)
  function automatic [K-1:0] reverse_bits_k (input logic [K-1:0] x);
    for (int i = 0; i < K; i++)
      reverse_bits_k[i] = x[K-1-i];
  endfunction

  // ------------------------------------------------------------------
  // Cycle counter for timing
  int cycle_count         = 0;
  int input_start_cycle   = -1;
  int output_start_cycle  = -1;
  int output_end_cycle    = -1;

  always @(posedge clk_i)
    cycle_count <= cycle_count +1;

  // ------------------------------------------------------------------
  // Main stimulus
  integer err_cnt = 0;

  initial begin
    $dumpfile("bitrev_tb.vcd");
    $dumpvars(0, bitrev_tb);

    // ------------------------------------------------------------
    // 1) Reset
    rst_ni = 0;
    repeat (4) @(posedge clk_i);
    rst_ni = 1;

    // ------------------------------------------------------------
    // 2) Send one natural-order frame
    for (int unsigned i = 0; i < N; i++) begin
      @(posedge clk_i);
      if (i == 0)
        input_start_cycle = cycle_count;

      valid_i = 1'b1;
      data_i  = i;
      wait (ready_o);
    end
    @(posedge clk_i);
    valid_i = 1'b0;

    // ------------------------------------------------------------
    // 3) Read frame back and check (aligned to DUT latency)
    for (int unsigned i = 0; i < N; i++) begin
      ready_i = 1'b1;
      wait (valid_o && ready_i);

      if (i == 0)
        output_start_cycle = cycle_count;

      if (i == N - 1)
        output_end_cycle = cycle_count;

      if (data_o[K-1:0] !== reverse_bits_k(i[K-1:0])) begin
        $display("Mismatch @%0d : got %0d, exp %0d",
                 i, data_o, reverse_bits_k(i[K-1:0]));
        err_cnt++;
      end

      @(posedge clk_i);
      ready_i = 1'b0;
    end

    // ------------------------------------------------------------
    // 4) Report result and timing
    if (err_cnt == 0)
      $display("Bit-reversal test PASSED for %0d-point frame", N);
    else
      $display("Bit-reversal test FAILED : %0d errors", err_cnt);

    $display("Input start at cycle  : %0d", input_start_cycle);
    $display("Output start at cycle : %0d", output_start_cycle);
    $display("Output end at cycle   : %0d", output_end_cycle);
    $display("End-to-end latency    : %0d cycles",
             output_start_cycle - input_start_cycle);
    $display("Total output duration : %0d cycles",
             output_end_cycle - output_start_cycle + 1);

    #20;
    $finish;
  end

endmodule
