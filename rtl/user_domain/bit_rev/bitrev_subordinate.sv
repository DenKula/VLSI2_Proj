// ============================================================================
// bitrev_subordinate.sv  –  Croc SBR-style OBI slave for the streaming
//                           bit-reversal core
// Register map (32-bit, word aligned):
//   0x0  INPUT   [WO]  write sample
//   0x4  OUTPUT  [RO]  read next bit-reversed sample
//   0x8  STATUS  [RO]  bit[0] = valid_o
// ============================================================================

module bitrev_subordinate
  import croc_pkg::*;
  #(
    parameter int unsigned K  = 10,   // log2 FFT length
    parameter int unsigned DW = 32    // data width
  ) (
    input  logic         clk_i,
    input  logic         rst_ni,
    // ---------------- SBR-OBI subordinate port --------------------
    input  sbr_obi_req_t obi_req_i,
    output sbr_obi_rsp_t obi_rsp_o
  );

  // ---------------------------------------------------------------
  // Local register selection
  // ---------------------------------------------------------------
  typedef enum logic [2:0] { RegInput=3'b000, RegOutput=3'b001, RegStatus=3'b010 } reg_sel_e;

  // ---------------------------------------------------------------
  // Bit-reversal core
  // ---------------------------------------------------------------
  logic          br_valid_i, br_ready_o;
  logic          br_valid_o, br_ready_i;
  logic [DW-1:0] br_data_i , br_data_o;

  bitrev #(
    .K (K),
    .DW(DW)
  ) i_bitrev (
    .clk_i,
    .rst_ni,
    .valid_i (br_valid_i),
    .data_i  (br_data_i ),
    .ready_o (br_ready_o),  // constant 1’b1 inside the core
    .valid_o (br_valid_o),
    .data_o  (br_data_o ),
    .ready_i (br_ready_i)
  );

  // ---------------------------------------------------------------
  // Write: feed INPUT register
  // ---------------------------------------------------------------
  assign br_data_i  = obi_req_i.wdata;
  assign br_valid_i =
         obi_req_i.req                &&   // request
         obi_req_i.we                 &&   // write
         (obi_req_i.addr[2+:3] == RegInput);

  // ---------------------------------------------------------------
  // Read control: accept one read, respond when ready
  // ---------------------------------------------------------------
  logic     rd_pending_q;
  reg_sel_e rd_reg_q;

  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin
      rd_pending_q <= 1'b0;
      rd_reg_q     <= RegInput;
    end else begin
      // latch new read request
      if (obi_req_i.req && !obi_req_i.we && !rd_pending_q)
      begin
        rd_pending_q <= 1'b1;
        rd_reg_q     <= reg_sel_e'(obi_req_i.addr[2+:3]);
      end
      // clear once data accepted
      if (obi_rsp_o.rvalid)
        rd_pending_q <= 1'b0;
    end
  end

  // ---------------------------------------------------------------
  // Combinational response and handshake to bitrev
  // ---------------------------------------------------------------
  always_comb begin
    // defaults
    obi_rsp_o           = '0;
    obi_rsp_o.gnt       = 1'b1;          // always ready
    obi_rsp_o.err       = 1'b0;
    br_ready_i          = 1'b0;

    if (rd_pending_q) begin
      obi_rsp_o.rvalid = 1'b1;

      unique case (rd_reg_q)
        RegOutput: begin
          obi_rsp_o.rdata = br_data_o;
          br_ready_i      = 1'b1;       // pop one word
        end
        RegStatus: begin
          obi_rsp_o.rdata = {{(DW-1){1'b0}}, br_valid_o};
        end
        default: ;                      // unimplemented → zero
      endcase
    end
  end

endmodule
