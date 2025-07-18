/*
 * bitrev.sv – parameterizable bit‑reversal address generator + ping‑pong RAM
 *
 * Croc naming style:
 *   *_i : input  | *_o : output | *_n : active‑low
 *   *_d : combinational data    | *_q : registered data
 *
 * Write‑side handshake : valid_i / ready_o
 * Read‑side  handshake : valid_o / ready_i
 *
 * Build example:
 *   verilator -Wall -sv --trace --binary --top-module bitrev_tb \
 *             sw/bitrev_tb.sv rtl/user_domain/bit_rev/bitrev.sv
 */

module bitrev #(
  parameter int K  = 10,   // log2(N) – e.g. 10 ⇒ 1024‑point FFT
  parameter int DW = 32    // data width per sample
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

  localparam int N = 1 << K;            // samples per ping‑pong bank

  // ------------------------------------------------------------------
  // Dual‑port SRAM (behavioural placeholder – replace with real macros)
  // ------------------------------------------------------------------
  logic [DW-1:0] sram [0:2*N-1];        // 2 banks × N locations

  // Bank selectors : 0 ⇒ bank‑A , 1 ⇒ bank‑B.
  logic bank_sel_wr, bank_sel_rd, bank_sel_rd_next;

  // Address counters
  logic [K-1:0] wr_cnt;
  logic [K-1:0] rd_cnt, rd_cnt_next;

  // ==============================================================
  //  WRITE PATH  – always accepts one sample per clock
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
        bank_sel_wr <= ~bank_sel_wr;   // switch after writing last addr
      end
    end
  end

  /* verilator lint_off WAITCONST */
  assign ready_o = 1'b1;                // producer never throttled
  /* verilator lint_on  WAITCONST */

  // ==============================================================
  //  READ PATH – bit‑reverse addressing with 1‑cycle latency
  // ==============================================================
  // Pipeline registers
  logic [DW-1:0] data_d, data_q;
  assign data_o = data_q;

  // -------- Bit‑reverse helper ----------------------------------
  function automatic [K-1:0] bit_reverse (input logic [K-1:0] x);
    for (int i = 0; i < K; ++i) begin
      bit_reverse[i] = x[K-1-i];
    end
  endfunction

  // -------- Combinational next‑state + SRAM read ----------------
  always_comb begin : rd_path_comb
    // Default next‑state
    rd_cnt_next       = rd_cnt + 1'b1;
    bank_sel_rd_next  = bank_sel_rd;
    data_d            = '0;

    // Wrap and bank‑toggle
    if (rd_cnt == K'((1<<K)-1)) begin
      rd_cnt_next      = '0;
      bank_sel_rd_next = ~bank_sel_rd;
    end

    // Compute bit‑reversed address for *next* counter value
    logic [K-1:0] rev_addr;
    rev_addr = bit_reverse(rd_cnt_next);

    // Pull word for the next cycle
    data_d = sram[{bank_sel_rd_next, rev_addr}];
  end

  // -------- Sequential register/update --------------------------
  always_ff @(posedge clk_i or negedge rst_ni) begin : rd_path_seq
    if (!rst_ni) begin
      rd_cnt      <= '0;
      bank_sel_rd <= 1'b0;             // start on same bank as writer
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
