// ============================================================================
// bitrev_subordinate.sv  –  OBI-slave wrapper for the streaming bitrev core
// Croc flavour:  req.a.valid / req.a.we / req.a.addr / req.d.wdata
//                rsp.r.rvalid / rsp.r.rdata / rsp.err
// ============================================================================

module bitrev_subordinate
  import croc_pkg::*;
  #(
    parameter int unsigned K  = 10,
    parameter int unsigned DW = 32
  ) (
    input  logic         clk_i,
    input  logic         rst_ni,

    // OBI subordinate port (Croc SBR flavour)
    input  sbr_obi_req_t obi_req_i,
    output sbr_obi_rsp_t obi_rsp_o
  );

  // ----------------------------------------------------------------
  // Local register selection (addr[2+:3] because bus is 32-bit)
  // ----------------------------------------------------------------
  typedef enum logic [2:0] { RegInput=3'b000, RegOutput=3'b001, RegStatus=3'b010 } reg_sel_e;

  // ----------------------------------------------------------------
  // Streaming bit-reversal core
  // ----------------------------------------------------------------
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
    .ready_o (br_ready_o),   // always 1 in this core
    .valid_o (br_valid_o),
    .data_o  (br_data_o ),
    .ready_i (br_ready_i)
  );

  // ----------------------------------------------------------------
  // Write detection (INPUT register only)
  // ----------------------------------------------------------------
  assign br_data_i  = obi_req_i.d.wdata;

  assign br_valid_i =  obi_req_i.a.valid        // a-phase handshake
                    && obi_req_i.a.we           // write
                    && (obi_req_i.a.addr[2+:3] == RegInput);

  // ----------------------------------------------------------------
  // Read control: latch one request until we have answered it
  // ----------------------------------------------------------------
  logic     rd_pending_q;
  reg_sel_e rd_reg_q;

  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin
      rd_pending_q <= 1'b0;
      rd_reg_q     <= RegInput;
    end else begin
      // New read?
      if (obi_req_i.a.valid && !obi_req_i.a.we && !rd_pending_q) begin
        rd_pending_q <= 1'b1;
        rd_reg_q     <= reg_sel_e'(obi_req_i.a.addr[2+:3]);
      end

      // Response accepted → clear
      if (obi_rsp_o.r.rvalid) rd_pending_q <= 1'b0;
    end
  end

  // ----------------------------------------------------------------
  // Combinational response + handshake towards bitrev
  // ----------------------------------------------------------------
  always_comb begin
    // Default everything to zero (safe for X-prop)
    obi_rsp_o        = '0;
    obi_rsp_o.err    = 1'b0;
    br_ready_i       = 1'b0;

    if (rd_pending_q) begin
      obi_rsp_o.r.rvalid = 1'b1;

      unique case (rd_reg_q)
        RegOutput: begin
          obi_rsp_o.r.rdata = br_data_o;
          br_ready_i        = obi_rsp_o.r.rvalid;   // pop exactly once
        end
        RegStatus: begin
          obi_rsp_o.r.rdata = {{(DW-1){1'b0}}, br_valid_o};
        end
        default: ;  // reads of undefined offsets return zero
      endcase
    end
  end

endmodule
