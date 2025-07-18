/*
 * bitrev.sv – parameterizable bit‑reversal address generator + ping‑pong RAM
 *
 * Croc naming style:
 *   *_i : input  | *_o : output | *_n : active‑low
 *   *_d : combinational data    | *_q : registered data
 *
 * Write side handshake : valid_i / ready_o
 * Read  side handshake : valid_o / ready_i
 *
 *to run the test bench: 
  >> verilator -Wall -sv --trace --binary --top-module bitrev_tb sw/bitrev_tb.sv rtl/user_domain/bit_rev/bitrev.sv 
 *
 */

module bitrev #(
  parameter int K  = 10,   // log2(N) – e.g. 10 ⇒ 1024‑point FFT
  parameter int DW = 32    // data width
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

  localparam int N = 1 << K;

  // ------------------------------------------------------------------
  // Dual‑port SRAM (behavioural placeholder – swap for tc_sram macros)
  // ------------------------------------------------------------------
  logic [DW-1:0] sram [0:2*N-1];

  // Ping‑pong selects : 0 ⇒ bank A , 1 ⇒ bank B.
  logic bank_sel_wr, bank_sel_rd;

  // Counters
  logic [K-1:0] wr_cnt, rd_cnt;

  // ============================================================== 
  //  WRITE PATH  – always accept one word per clock                 |
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
        bank_sel_wr <= ~bank_sel_wr;     // switch banks after N samples
      end
    end else begin
      // Default: hold current state (some linters require explicit branch)
      wr_cnt      <= wr_cnt;
      bank_sel_wr <= bank_sel_wr;
    end
  end
  // Producer is always accepted
  /* verilator lint_off WAITCONST */
  assign ready_o = 1'b1;
  /*verilator lint_on WAITCONST */

  // ============================================================== 
  //  READ PATH – bit‑reversal with data_d / data_q separation       |
  // ==============================================================
  // Combinational next‑data
  logic [DW-1:0] data_d, data_q;
  assign data_o = data_q;   // expose registered data to the outside

  // Bit‑reverse function (combinational)
  function automatic [K-1:0] bit_reverse (input logic [K-1:0] x);
    for (int i = 0; i < K; i++) begin
      bit_reverse[i] = x[K-1-i];
    end
  endfunction

  // Combinational read address and data with default assignment
  always_comb begin : rd_path_comb
    // default assignments (avoid accidental latches)
    logic [K-1:0] rev_addr; 
    data_d = '0;

    
    rev_addr = bit_reverse(rd_cnt);

    // Compute bit‑reversed address and fetch word
    data_d = sram[{bank_sel_rd, rev_addr}];
  end

  // Sequential part with explicit default (hold‑state) branch
  always_ff @(posedge clk_i or negedge rst_ni) begin : rd_path_seq
    if (!rst_ni) begin
      rd_cnt      <= '0;
      bank_sel_rd <= 1'b1;   // opposite bank of writer at reset
      data_q      <= '0;
      valid_o     <= 1'b0;
    end else if (ready_i || ~valid_o) begin
      // Normal advancing state
      data_q  <= data_d;
      valid_o <= 1'b1;
      rd_cnt  <= rd_cnt + 1'b1;

      if (rd_cnt == K'((1<<K)-1)) begin
        rd_cnt      <= '0;
        bank_sel_rd <= ~bank_sel_rd;     // switch when bank fully read
      end
    end else begin
      // Default: hold current state
      data_q      <= data_q;
      valid_o     <= valid_o;
      rd_cnt      <= rd_cnt;
      bank_sel_rd <= bank_sel_rd;
    end
  end

endmodule
