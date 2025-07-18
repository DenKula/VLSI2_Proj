// ============================================================================
// bitrev_subordinate.sv  –  Croc SBR‑style OBI slave for the streaming
//                           bit‑reversal core
// Register map (word‑aligned, 32‑bit):
//   0x0  INPUT   [WO]  write sample   -> feeds bitrev.valid_i / data_i
//   0x4  OUTPUT  [RO]  read  sample   -> pops one word when available
//   0x8  STATUS  [RO]  bit[0] = bitrev.valid_o
// ============================================================================

module bitrev_subordinate
  import croc_pkg::*;
  #(
    parameter obi_pkg::obi_cfg_t ObiCfg = obi_pkg::ObiDefaultConfig,
    parameter int unsigned       K      = 10,
    parameter int unsigned       DW     = 32
  ) (
    input  logic         clk_i,
    input  logic         rst_ni,

    // SBR‑OBI subordinate port
    input  sbr_obi_req_t obi_req_i,
    output sbr_obi_rsp_t obi_rsp_o
  );

  // -------------------------------------------------------------------------
  // Local register enumeration
  typedef enum logic [2:0] {
    REG_INPUT  = 3'h0,
    REG_OUTPUT = 3'h1,
    REG_STATUS = 3'h2
  } reg_sel_e;

  // -------------------------------------------------------------------------
  // Bit‑reversal core instance
  logic          br_valid_i, br_ready_o;
  logic          br_valid_o, br_ready_i;
  logic [DW-1:0] br_data_i , br_data_o;

  bitrev #(.K(K), .DW(DW)) i_bitrev (
    .clk_i   (clk_i),
    .rst_ni  (rst_ni),
    .valid_i (br_valid_i),
    .data_i  (br_data_i),
    .ready_o (br_ready_o),
    .valid_o (br_valid_o),
    .data_o  (br_data_o),
    .ready_i (br_ready_i)
  );

  // -------------------------------------------------------------------------
  // Request decode
  logic                 req_valid;
  logic                 req_write;
  logic [31:0]          req_addr;
  logic [2:0]           req_reg_sel;

  assign req_valid    = obi_req_i.req;
  assign req_write    = obi_req_i.a.we;
  assign req_addr     = obi_req_i.a.addr;
  assign req_reg_sel  = req_addr[4:2];

  // -------------------------------------------------------------------------
  // Read‑transaction bookkeeping
  logic      rd_pending_q;
  reg_sel_e  rd_reg_q;
  logic [ObiCfg.IdWidth-1:0] rd_id_q;

  // Accept a new read when no other read is outstanding
  wire read_request   = req_valid && !req_write;
  wire read_accepted  = read_request && !rd_pending_q;

  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin
      rd_pending_q <= 1'b0;
      rd_reg_q     <= REG_INPUT;
      rd_id_q      <= '0;
    end else begin
      if (read_accepted) begin
        rd_pending_q <= 1'b1;
        rd_reg_q     <= reg_sel_e'(req_reg_sel);
        rd_id_q      <= obi_req_i.a.aid;
      end
      // Clear when response has been issued
      if (obi_rsp_o.rvalid) rd_pending_q <= 1'b0;
    end
  end

  // -------------------------------------------------------------------------
  // Write path – only REG_INPUT is writable
  wire write_to_input = req_valid && req_write && (req_reg_sel == REG_INPUT);

  // Grant logic: 
  //  • For INPUT writes, grant only when core is ready.  
  //  • For reads, grant only when no prior read is pending.  
  //  • All other accesses are granted immediately.
  logic gnt_int;
  always_comb begin
    unique case (1'b1)
      write_to_input: gnt_int =  br_ready_o;
      read_request : gnt_int = !rd_pending_q;
      default      : gnt_int =  1'b1;
    endcase
  end

  assign br_data_i  = obi_req_i.a.wdata[DW-1:0];
  assign br_valid_i = write_to_input && gnt_int;   // handshake

  // -------------------------------------------------------------------------
  // Read response generation (blocking for OUTPUT)
  logic rvalid_int;
  logic [ObiCfg.DataWidth-1:0] rdata_int;
  logic rerr_int;

  always_comb begin
    // Defaults
    br_ready_i   = 1'b0;
    rvalid_int   = 1'b0;
    rdata_int    = '0;
    rerr_int     = 1'b0;

    if (rd_pending_q) begin
      unique case (rd_reg_q)
        REG_OUTPUT: begin
          if (br_valid_o) begin
            rvalid_int = 1'b1;
            rdata_int  = { {(ObiCfg.DataWidth-DW){1'b0}}, br_data_o };
            br_ready_i = 1'b1; // pop one word
          end
        end

        REG_STATUS: begin
          rvalid_int = 1'b1;
          rdata_int  = { {(ObiCfg.DataWidth-1){1'b0}}, br_valid_o };
        end

        default: begin
          rvalid_int = 1'b1;
          rdata_int  = 32'hDEAD_BEEF;
          rerr_int   = 1'b1;
        end
      endcase
    end
  end

  // -------------------------------------------------------------------------
  // OBI response
  assign obi_rsp_o.gnt           = gnt_int;
  assign obi_rsp_o.rvalid        = rvalid_int;

  assign obi_rsp_o.r.rdata       = rdata_int;
  assign obi_rsp_o.r.rid         = rd_id_q;
  assign obi_rsp_o.r.err         = rerr_int;
  assign obi_rsp_o.r.r_optional  = '0;

endmodule
