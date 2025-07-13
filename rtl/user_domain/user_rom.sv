// ============================================================================
// bitrev_subordinate.sv  –  Croc SBR-style OBI slave for the streaming
//                           bit-reversal core
// Register map (word-aligned, 32-bit):
//   0x0  INPUT   [WO]  write  sample  -> feeds bitrev.valid_i / data_i
//   0x4  OUTPUT  [RO]  read   sample  -> strobes bitrev.ready_i
//   0x8  STATUS  [RO]  bit[0] = bitrev.valid_o
// ============================================================================

module bitrev_subordinate
  import croc_pkg::*;
  #(
    parameter int unsigned K  = 10,
    parameter int unsigned DW = 32
  ) (
    input  logic         clk_i,
    input  logic         rst_ni,

    // SBR-OBI subordinate port
    input  sbr_obi_req_t obi_req_i,
    output sbr_obi_rsp_t obi_rsp_o
  );

  //------------------------------ local ---------------------------------
  typedef enum logic [2:0] { RegInput=3'b000, RegOutput=3'b001,
                             RegStatus=3'b010 } reg_sel_e;

  //------------------------------ core ----------------------------------
  logic          br_valid_i, br_ready_o;
  logic          br_valid_o, br_ready_i;
  logic [DW-1:0] br_data_i , br_data_o;

  bitrev #(.K(K), .DW(DW)) i_bitrev (
    .clk_i, .rst_ni,
    .valid_i (br_valid_i), .data_i (br_data_i), .ready_o (br_ready_o),
    .valid_o (br_valid_o), .data_o (br_data_o), .ready_i (br_ready_i)
  );

  //------------------------------ WRITE ---------------------------------
  assign br_data_i  = obi_req_i.wdata;
  assign br_valid_i =
         obi_req_i.req                      &&   // request present
         obi_req_i.a.we                     &&   // write access
         (obi_req_i.a.addr[2+:3] == RegInput);

  //------------------------------ READ state ----------------------------
  logic     rd_pending_q;
  reg_sel_e rd_reg_q;
  logic [ObiCfg.IdWidth-1:0] rd_id_q;

  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin
      rd_pending_q <= 1'b0;
      rd_reg_q     <= RegInput;
      rd_id_q      <= '0;
    end else begin
      // Latch new read request
      if (obi_req_i.req && !obi_req_i.a.we && !rd_pending_q) begin
        rd_pending_q <= 1'b1;
        rd_reg_q     <= reg_sel_e'(obi_req_i.a.addr[2+:3]);
        rd_id_q      <= obi_req_i.a.aid;
      end
      // Response delivered => clear
      if (obi_rsp_o.rvalid)
        rd_pending_q <= 1'b0;
    end
  end

  //------------------------------ RESPONSE ------------------------------
  always_comb begin
    // Root channel defaults
    obi_rsp_o         = '0;
    obi_rsp_o.gnt     = 1'b1;          // always grant
    obi_rsp_o.rvalid  = 1'b0;

    // R-channel defaults
    obi_rsp_o.r.rdata       = '0;
    obi_rsp_o.r.rid         = rd_id_q;
    obi_rsp_o.r.err         = 1'b0;
    obi_rsp_o.r.r_optional  = '0;

    br_ready_i              = 1'b0;

    if (rd_pending_q) begin
      obi_rsp_o.rvalid = 1'b1;

      unique case (rd_reg_q)
        RegOutput: begin
          obi_rsp_o.r.rdata = br_data_o;
          br_ready_i        = 1'b1;   // pop exactly one word
        end
        RegStatus: begin
          obi_rsp_o.r.rdata = {{(DW-1){1'b0}}, br_valid_o};
        end
        default: ;                    // undefined offsets => 0
      endcase
    end
  end

endmodule
