/*
 * bitrev.sv – parameterisable bit‑reversal address generator + ping‑pong SRAM
 * ---------------------------------------------------------------------------
 * Interface conventions
 *   *_i : input   | *_o : output | *_n : active‑low
 *   *_d : comb.   | *_q : registered
 *
 * Write‑side handshake : valid_i / ready_o  (producer never stalled)
 * Read‑side  handshake : valid_o / ready_i
 *
 * Example compile (Verilator ≥ 5.0):
 *   verilator -Wall -sv --trace --binary --top-module bitrev_tb \
 *             sw/bitrev_tb.sv rtl/user_domain/bit_rev/bitrev.sv
 */

module bitrev #(
  parameter int K  = 10,   // log₂(N) – e.g. 10 ⇒ 1024‑point FFT
  parameter int DW = 32    // data width (bits per sample)
)(
  // Clock & reset
  input  logic                 clk_i,
  input  logic                 rst_ni,

  // Write side (natural‑order stream in)
  input  logic                 valid_i,
  input  logic [DW-1:0]        data_i,
  output logic                 ready_o,

  // Read side (bit‑reversed stream out)
  output logic                 valid_o,
  output logic [DW-1:0]        data_o,
  input  logic                 ready_i
);

  localparam int N = 1 << K;           // samples per bank

  // ---------------------------------------------------------------------
  // Dual‑port SRAM : 2 banks × N locations (behavioural model)
  // ---------------------------------------------------------------------
  logic [DW-1:0] sram [0:2*N-1];       // index = {bank_sel , address}

  // Ping‑pong selectors : 0 ⇒ bank‑A , 1 ⇒ bank‑B
  logic bank_sel_wr;                   // writer bank pointer
  logic bank_sel_rd;                   // reader bank pointer

  // Address counters
  logic [K-1:0] wr_cnt;                // write address within bank
  logic [K-1:0] rd_cnt;                // read  address within bank

  // =====================================================================
  //  WRITE PATH – always ready (no back‑pressure towards producer)
  // =====================================================================
  logic [K-1:0] wr_cnt_next;

  always_ff @(posedge clk_i or negedge rst_ni) begin : wr_path
    if (!rst_ni) begin
      wr_cnt      <= '0;
      bank_sel_wr <= 1'b0;             // start filling bank‑A
    end else if (valid_i && ready_o) begin
      // Store incoming sample
      sram[{bank_sel_wr, wr_cnt}] <= data_i;

      // Increment address counter
      wr_cnt_next = wr_cnt + 1'b1;
      wr_cnt      <= wr_cnt_next;

      // Toggle bank *after* final address (when counter wraps to 0)
      if (wr_cnt_next == '0) begin
        bank_sel_wr <= ~bank_sel_wr;
      end
    end
  end

  /* verilator lint_off WAITCONST */
  assign ready_o = 1'b1;                       // producer never stalled
  /* verilator lint_on  WAITCONST */

  // =====================================================================
  //  READ PATH – one‑cycle latency (data_q), aligned to current rd_cnt
  // =====================================================================

  // 1. Bit‑reverse helper -------------------------------------------------
  function automatic [K-1:0] bit_reverse (input logic [K-1:0] x);
    for (int i = 0; i < K; ++i)
      bit_reverse[i] = x[K-1-i];
  endfunction

  // 2. Combinational read address & data ---------------------------------
  logic [DW-1:0] data_d, data_q;
  logic [K-1:0]  rev_addr;
  assign rev_addr = bit_reverse(rd_cnt);       // current address
  assign data_d   = sram[{bank_sel_rd, rev_addr}];

  // 3. Sequential pipeline & control -------------------------------------
  always_ff @(posedge clk_i or negedge rst_ni) begin : rd_path_seq
    if (!rst_ni) begin
      rd_cnt      <= '0;
      bank_sel_rd <= 1'b0;                     // same bank as writer
      data_q      <= '0;
      valid_o     <= 1'b0;
    end else if (ready_i || ~valid_o) begin
      // Present fetched data
      data_q  <= data_d;
      valid_o <= 1'b1;

      // Advance read address and handle bank switch
      if (rd_cnt == K'((1<<K)-1)) begin        // just read last address
        rd_cnt      <= '0;
        bank_sel_rd <= ~bank_sel_rd;           // switch banks
      end else begin
        rd_cnt <= rd_cnt + 1'b1;
      end
    end
  end

  // 4. Output mapping -----------------------------------------------------
  assign data_o = data_q;

endmodule