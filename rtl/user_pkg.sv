// Copyright 2024 ETH Zurich and University of Bologna.
// Solderpad Hardware License, Version 0.51, see LICENSE for details.
// SPDX-License-Identifier: SHL-0.51
//
// Authors:
// - Philippe Sauter <phsauter@iis.ee.ethz.ch>

`include "register_interface/typedef.svh"
`include "obi/typedef.svh"

package user_pkg;

  ////////////////////////////////
  // User Manager Address maps //
  ///////////////////////////////
  
  // None


  /////////////////////////////////////
  // User Subordinate Address maps ////
  /////////////////////////////////////

  localparam int unsigned NumUserDomainSubordinates = 2;  //Den: I have changed this to 2, as we have added another subordinate (ROM & fft) to the user domain

  localparam bit [31:0] UserRomAddrOffset   = croc_pkg::UserBaseAddr; // 32'h2000_0000;
  localparam bit [31:0] UserRomAddrRange    = 32'h0000_1000;          // every subordinate has at least 4KB

  localparam int unsigned BITREV_K  = 10;   // log2(FFT length) → 1024
  localparam int unsigned BITREV_DW = 32;   // data-word width
  // **NEW** FFT ─ next 4 KiB at 0x2000_1000
  localparam bit [31:0] UserBitrevAddrOffset = UserRomAddrOffset + UserRomAddrRange; // 0x2000_1000
  localparam bit [31:0] UserBitrevAddrRange  = 32'h0000_1000;
  
  localparam int unsigned NumDemuxSbrRules  = NumUserDomainSubordinates; // number of address rules in the decoder
  localparam int unsigned NumDemuxSbr       = NumDemuxSbrRules + 1; // additional OBI error, used for signal arrays

  // Enum for bus indices
  typedef enum int {
    UserError = 0,
    UserRom = 1,
    UserBitrev = 2
  } user_demux_outputs_e;

  // Two address-decode rules (ROM, FFT) – **order doesn’t matter**
  localparam croc_pkg::addr_map_rule_t [NumDemuxSbrRules-1:0] user_addr_map = '{
    '{ start_addr: UserRomAddrOffset,
       end_addr : UserRomAddrOffset + UserRomAddrRange - 1,
       idx      : UserRom },
    '{ start_addr: UserBitrevAddrOffset,
       end_addr : UserBitrevAddrOffset + UserBitrevAddrRange - 1,
       idx      : UserBitrev }
  };

endpackage
