// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vbitrev_tb.h for the primary calling header

#ifndef VERILATED_VBITREV_TB___024ROOT_H_
#define VERILATED_VBITREV_TB___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vbitrev_tb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vbitrev_tb___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ bitrev_tb__DOT__clk_i;
    CData/*0:0*/ bitrev_tb__DOT__rst_ni;
    CData/*0:0*/ bitrev_tb__DOT__valid_i;
    CData/*0:0*/ bitrev_tb__DOT__valid_o;
    CData/*0:0*/ bitrev_tb__DOT__ready_i;
    CData/*0:0*/ bitrev_tb__DOT____Vlvbound_h3aee0c48__0;
    CData/*0:0*/ bitrev_tb__DOT__dut__DOT__bank_sel_wr;
    CData/*0:0*/ bitrev_tb__DOT__dut__DOT__bank_sel_rd;
    CData/*5:0*/ bitrev_tb__DOT__dut__DOT__wr_cnt;
    CData/*5:0*/ bitrev_tb__DOT__dut__DOT__rd_cnt;
    CData/*5:0*/ bitrev_tb__DOT__dut__DOT__wr_cnt_next;
    CData/*5:0*/ bitrev_tb__DOT__dut__DOT__rev_addr;
    CData/*5:0*/ __Vfunc_bitrev_tb__DOT__dut__DOT__bit_reverse__2__Vfuncout;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__bitrev_tb__DOT__clk_i__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__bitrev_tb__DOT__rst_ni__0;
    CData/*0:0*/ __Vtrigprevexpr_h822765d9__1;
    CData/*0:0*/ __VactDidInit;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ bitrev_tb__DOT__data_i;
    IData/*31:0*/ bitrev_tb__DOT__cycle_count;
    IData/*31:0*/ bitrev_tb__DOT__input_start_cycle;
    IData/*31:0*/ bitrev_tb__DOT__output_start_cycle;
    IData/*31:0*/ bitrev_tb__DOT__output_end_cycle;
    IData/*31:0*/ bitrev_tb__DOT__err_cnt;
    IData/*31:0*/ bitrev_tb__DOT__unnamedblk2__DOT__i;
    IData/*31:0*/ bitrev_tb__DOT__unnamedblk3__DOT__i;
    IData/*31:0*/ bitrev_tb__DOT__dut__DOT__data_q;
    IData/*31:0*/ bitrev_tb__DOT__dut__DOT__data_d;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<IData/*31:0*/, 64> bitrev_tb__DOT__dut__DOT__sram_a;
    VlUnpacked<IData/*31:0*/, 64> bitrev_tb__DOT__dut__DOT__sram_b;
    VlUnpacked<CData/*0:0*/, 4> __Vm_traceActivity;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_h915c4b11__0;
    VlTriggerScheduler __VtrigSched_he610b0fb__0;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<4> __VactTriggered;
    VlTriggerVec<4> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vbitrev_tb__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vbitrev_tb___024root(Vbitrev_tb__Syms* symsp, const char* v__name);
    ~Vbitrev_tb___024root();
    VL_UNCOPYABLE(Vbitrev_tb___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
