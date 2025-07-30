module bitrev #(
  parameter integer K  = 10,   // log₂(N) – e.g. 10 ⇒ 1024‑point FFT
  parameter integer DW = 32    // data width (bits per sample)
)(
  // Clock & reset
  input  wire                 clk_i,
  input  wire                 rst_ni,

  // Write side (natural‑order stream in)
  input  wire                 valid_i,
  input  wire [DW-1:0]        data_i,
  output wire                 ready_o,

  // Read side (bit‑reversed stream out)
  output reg                  valid_o,
  output wire [DW-1:0]        data_o,
  input  wire                 ready_i
);

  localparam integer N = 1 << K;  // samples per bank

  // SRAM
  reg [DW-1:0] sram [0:2*N-1];    // 2 banks × N

  // Ping-pong control
  reg bank_sel_wr;
  reg bank_sel_rd;

  // Address counters
  reg [K-1:0] wr_cnt;
  reg [K-1:0] rd_cnt;

  // Write-side logic
  wire [K-1:0] wr_cnt_next = wr_cnt + 1'b1;

  always @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin
      wr_cnt      <= {K{1'b0}};
      bank_sel_wr <= 1'b0;
    end else if (valid_i && ready_o) begin
      sram[{bank_sel_wr, wr_cnt}] <= data_i;
      wr_cnt <= wr_cnt_next;
      if (wr_cnt_next == {K{1'b0}})
        bank_sel_wr <= ~bank_sel_wr;
    end
  end

  assign ready_o = 1'b1;

  // Bit-reversal function (combinational)
  function [K-1:0] bit_reverse;
    input [K-1:0] x;
    integer i;
    begin
      for (i = 0; i < K; i = i + 1)
        bit_reverse[i] = x[K-1-i];
    end
  endfunction

  // Read-side logic
  reg [DW-1:0] data_q;
  wire [K-1:0] rev_addr = bit_reverse(rd_cnt);
  wire [DW-1:0] data_d = sram[{bank_sel_rd, rev_addr}];

  always @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin
      rd_cnt      <= {K{1'b0}};
      bank_sel_rd <= 1'b0;
      data_q      <= {DW{1'b0}};
      valid_o     <= 1'b0;
    end else if (ready_i || ~valid_o) begin
      data_q  <= data_d;
      valid_o <= 1'b1;
      if (rd_cnt == ((1 << K) - 1)) begin
        rd_cnt      <= {K{1'b0}};
        bank_sel_rd <= ~bank_sel_rd;
      end else begin
        rd_cnt <= rd_cnt + 1'b1;
      end
    end
  end

  assign data_o = data_q;

endmodule
