/*
 * bitrev.sv – parameterizable bit‑reversal address generator + ping‑pong RAM
 *
 * Croc naming style:
 *   *_i : input  | *_o : output | *_n : active‑low
 *   *_d : combinational data    | *_q : registered data
 *
 * Build example (Verilator):
 *   verilator -Wall -sv --trace --binary --top-module bitrev_tb \
 *             sw/bitrev_tb.sv rtl/user_domain/bit_rev/bitrev.sv
 */

module bitrev #(
  parameter int K  = 10,   // log2(N) – e.g. 10 ⇒ 1024‑point FFT
  parameter int DW = 32    // data‑path width
)(
  // Clocks & resets
  input  logic                 clk_i,
  input  logic                 rst_ni,

  // Write‑side (natural order)
  input  logic                 valid_i,
  input  logic [DW-1:0]        data_i,
  output logic                 ready_o,

  // Read‑side (bit‑reversed order)
  output logic                 valid_o,
  output logic [DW-1:0]        data_o,
  input  logic                 ready_i
);

  localparam int N = 1 << K;

  // ------------------------------------------------------------------
  // Simple dual‑port memory – two banks, each N deep
  // ------------------------------------------------------------------
  logic [DW-1:0] sram [0:2*N-1];

  // Ping‑pong bank selectors
  logic bank_sel_wr, bank_sel_rd, bank_sel_rd_next;

  // Address counters
  logic [K-1:0] wr_cnt;
  logic [K-1:0] rd_cnt, rd_cnt_next;

  // ==============================================================
  //  WRITE PATH – always ready (no back‑pressure towards producer)
  // ==============================================================
  always_ff @(posedge clk_i or negedge rst_ni) begin : wr_path
    if (!rst_ni) begin
      wr_cnt      <= '0;
      bank_sel_wr <= 1'b0;
    end else if (valid_i && ready_o) begin
      sram[{bank_sel_wr, wr_cnt}] <= data_i;
      wr_cnt <= wr_cnt + 1'b1;
      if (wr_cnt == K'((1<<K)-1)) begin
        wr_cnt      <= '0;
        bank_sel_wr <= ~bank_sel_wr;   // toggle after last address
      end
    end
  end

  /* verilator lint_off WAITCONST */
  assign ready_o = 1'b1;                // writer never stalls
  /* verilator lint_on  WAITCONST */

  // ==============================================================
  //  READ PATH – one registered stage (1‑cycle latency)
  // ==============================================================
  logic [DW-1:0] data_d, data_q;
  assign data_o = data_q;

  // -------- Bit‑reverse helper ----------------------------------
  function automatic [K-1:0] bit_reverse (input logic [K-1:0] x);
    for (int i = 0; i < K; ++i) begin
      bit_reverse[i] = x[K-1-i];
    end
  endfunction

  // -------- Combinational next‑state & SRAM read ----------------
  always_comb begin : rd_path_comb
    // Default next‑state
    logic [K-1:0] rev_addr;
    rd_cnt_next       = rd_cnt + 1'b1;
    bank_sel_rd_next  = bank_sel_rd;
    data_d            = '0;

    // Wrap
    if (rd_cnt == K'((1<<K)-1)) begin
      rd_cnt_next      = '0;
      bank_sel_rd_next = ~bank_sel_rd;
    end

    // Compute bit‑reversed address for *current* counter value
    
    rev_addr = bit_reverse(rd_cnt);

    // Fetch current sample (output appears next cycle)
    data_d = sram[{bank_sel_rd, rev_addr}];
  end

  // -------- Sequential update -----------------------------------
  always_ff @(posedge clk_i or negedge rst_ni) begin : rd_path_seq
    if (!rst_ni) begin
      rd_cnt      <= '0;
      bank_sel_rd <= 1'b0;              // same bank as writer at reset
      data_q      <= '0;
      valid_o     <= 1'b0;
    end else if (ready_i || ~valid_o) begin
      rd_cnt      <= rd_cnt_next;
      bank_sel_rd <= bank_sel_rd_next;
      data_q      <= data_d;
      valid_o     <= 1'b1;
    end
  end

endmodule
