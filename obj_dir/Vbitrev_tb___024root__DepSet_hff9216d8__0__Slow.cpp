// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vbitrev_tb.h for the primary calling header

#include "Vbitrev_tb__pch.h"
#include "Vbitrev_tb___024root.h"

VL_ATTR_COLD void Vbitrev_tb___024root___eval_static__TOP(Vbitrev_tb___024root* vlSelf);
VL_ATTR_COLD void Vbitrev_tb___024root____Vm_traceActivitySetAll(Vbitrev_tb___024root* vlSelf);

VL_ATTR_COLD void Vbitrev_tb___024root___eval_static(Vbitrev_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitrev_tb___024root___eval_static\n"); );
    Vbitrev_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vbitrev_tb___024root___eval_static__TOP(vlSelf);
    Vbitrev_tb___024root____Vm_traceActivitySetAll(vlSelf);
    vlSelfRef.__Vtrigprevexpr___TOP__bitrev_tb__DOT__clk_i__0 = 0U;
    vlSelfRef.__Vtrigprevexpr___TOP__bitrev_tb__DOT__rst_ni__0 = 0U;
    vlSelfRef.__Vtrigprevexpr_h822765d9__1 = 0U;
}

VL_ATTR_COLD void Vbitrev_tb___024root___eval_static__TOP(Vbitrev_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitrev_tb___024root___eval_static__TOP\n"); );
    Vbitrev_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.bitrev_tb__DOT__clk_i = 0U;
    vlSelfRef.bitrev_tb__DOT__rst_ni = 0U;
    vlSelfRef.bitrev_tb__DOT__valid_i = 0U;
    vlSelfRef.bitrev_tb__DOT__data_i = 0U;
    vlSelfRef.bitrev_tb__DOT__ready_i = 0U;
    vlSelfRef.bitrev_tb__DOT__cycle_count = 0U;
    vlSelfRef.bitrev_tb__DOT__input_start_cycle = 0xffffffffU;
    vlSelfRef.bitrev_tb__DOT__output_start_cycle = 0xffffffffU;
    vlSelfRef.bitrev_tb__DOT__output_end_cycle = 0xffffffffU;
    vlSelfRef.bitrev_tb__DOT__err_cnt = 0U;
}

VL_ATTR_COLD void Vbitrev_tb___024root___eval_final(Vbitrev_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitrev_tb___024root___eval_final\n"); );
    Vbitrev_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vbitrev_tb___024root___dump_triggers__stl(Vbitrev_tb___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vbitrev_tb___024root___eval_phase__stl(Vbitrev_tb___024root* vlSelf);

VL_ATTR_COLD void Vbitrev_tb___024root___eval_settle(Vbitrev_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitrev_tb___024root___eval_settle\n"); );
    Vbitrev_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY(((0x64U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vbitrev_tb___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("sw/bitrev_tb.sv", 3, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vbitrev_tb___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vbitrev_tb___024root___dump_triggers__stl(Vbitrev_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitrev_tb___024root___dump_triggers__stl\n"); );
    Vbitrev_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vbitrev_tb___024root___stl_sequent__TOP__0(Vbitrev_tb___024root* vlSelf);

VL_ATTR_COLD void Vbitrev_tb___024root___eval_stl(Vbitrev_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitrev_tb___024root___eval_stl\n"); );
    Vbitrev_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vbitrev_tb___024root___stl_sequent__TOP__0(vlSelf);
        Vbitrev_tb___024root____Vm_traceActivitySetAll(vlSelf);
    }
}

VL_ATTR_COLD void Vbitrev_tb___024root___stl_sequent__TOP__0(Vbitrev_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitrev_tb___024root___stl_sequent__TOP__0\n"); );
    Vbitrev_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ bitrev_tb__DOT__dut__DOT____Vlvbound_h12462a78__0;
    bitrev_tb__DOT__dut__DOT____Vlvbound_h12462a78__0 = 0;
    CData/*5:0*/ __Vfunc_bitrev_tb__DOT__dut__DOT__bit_reverse__2__x;
    __Vfunc_bitrev_tb__DOT__dut__DOT__bit_reverse__2__x = 0;
    // Body
    vlSelfRef.bitrev_tb__DOT__dut__DOT__wr_cnt_next 
        = (0x3fU & ((IData)(1U) + (IData)(vlSelfRef.bitrev_tb__DOT__dut__DOT__wr_cnt)));
    __Vfunc_bitrev_tb__DOT__dut__DOT__bit_reverse__2__x 
        = vlSelfRef.bitrev_tb__DOT__dut__DOT__rd_cnt;
    bitrev_tb__DOT__dut__DOT____Vlvbound_h12462a78__0 
        = (1U & ((IData)(__Vfunc_bitrev_tb__DOT__dut__DOT__bit_reverse__2__x) 
                 >> 5U));
    vlSelfRef.__Vfunc_bitrev_tb__DOT__dut__DOT__bit_reverse__2__Vfuncout 
        = ((0x3eU & (IData)(vlSelfRef.__Vfunc_bitrev_tb__DOT__dut__DOT__bit_reverse__2__Vfuncout)) 
           | (IData)(bitrev_tb__DOT__dut__DOT____Vlvbound_h12462a78__0));
    bitrev_tb__DOT__dut__DOT____Vlvbound_h12462a78__0 
        = (1U & ((IData)(__Vfunc_bitrev_tb__DOT__dut__DOT__bit_reverse__2__x) 
                 >> 4U));
    vlSelfRef.__Vfunc_bitrev_tb__DOT__dut__DOT__bit_reverse__2__Vfuncout 
        = ((0x3dU & (IData)(vlSelfRef.__Vfunc_bitrev_tb__DOT__dut__DOT__bit_reverse__2__Vfuncout)) 
           | ((IData)(bitrev_tb__DOT__dut__DOT____Vlvbound_h12462a78__0) 
              << 1U));
    bitrev_tb__DOT__dut__DOT____Vlvbound_h12462a78__0 
        = (1U & ((IData)(__Vfunc_bitrev_tb__DOT__dut__DOT__bit_reverse__2__x) 
                 >> 3U));
    vlSelfRef.__Vfunc_bitrev_tb__DOT__dut__DOT__bit_reverse__2__Vfuncout 
        = ((0x3bU & (IData)(vlSelfRef.__Vfunc_bitrev_tb__DOT__dut__DOT__bit_reverse__2__Vfuncout)) 
           | ((IData)(bitrev_tb__DOT__dut__DOT____Vlvbound_h12462a78__0) 
              << 2U));
    bitrev_tb__DOT__dut__DOT____Vlvbound_h12462a78__0 
        = (1U & ((IData)(__Vfunc_bitrev_tb__DOT__dut__DOT__bit_reverse__2__x) 
                 >> 2U));
    vlSelfRef.__Vfunc_bitrev_tb__DOT__dut__DOT__bit_reverse__2__Vfuncout 
        = ((0x37U & (IData)(vlSelfRef.__Vfunc_bitrev_tb__DOT__dut__DOT__bit_reverse__2__Vfuncout)) 
           | ((IData)(bitrev_tb__DOT__dut__DOT____Vlvbound_h12462a78__0) 
              << 3U));
    bitrev_tb__DOT__dut__DOT____Vlvbound_h12462a78__0 
        = (1U & ((IData)(__Vfunc_bitrev_tb__DOT__dut__DOT__bit_reverse__2__x) 
                 >> 1U));
    vlSelfRef.__Vfunc_bitrev_tb__DOT__dut__DOT__bit_reverse__2__Vfuncout 
        = ((0x2fU & (IData)(vlSelfRef.__Vfunc_bitrev_tb__DOT__dut__DOT__bit_reverse__2__Vfuncout)) 
           | ((IData)(bitrev_tb__DOT__dut__DOT____Vlvbound_h12462a78__0) 
              << 4U));
    bitrev_tb__DOT__dut__DOT____Vlvbound_h12462a78__0 
        = (1U & (IData)(__Vfunc_bitrev_tb__DOT__dut__DOT__bit_reverse__2__x));
    vlSelfRef.__Vfunc_bitrev_tb__DOT__dut__DOT__bit_reverse__2__Vfuncout 
        = ((0x1fU & (IData)(vlSelfRef.__Vfunc_bitrev_tb__DOT__dut__DOT__bit_reverse__2__Vfuncout)) 
           | ((IData)(bitrev_tb__DOT__dut__DOT____Vlvbound_h12462a78__0) 
              << 5U));
    vlSelfRef.bitrev_tb__DOT__dut__DOT__rev_addr = vlSelfRef.__Vfunc_bitrev_tb__DOT__dut__DOT__bit_reverse__2__Vfuncout;
    vlSelfRef.bitrev_tb__DOT__dut__DOT__data_d = ((IData)(vlSelfRef.bitrev_tb__DOT__dut__DOT__bank_sel_rd)
                                                   ? 
                                                  vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b
                                                  [vlSelfRef.bitrev_tb__DOT__dut__DOT__rev_addr]
                                                   : 
                                                  vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a
                                                  [vlSelfRef.bitrev_tb__DOT__dut__DOT__rev_addr]);
}

VL_ATTR_COLD void Vbitrev_tb___024root___eval_triggers__stl(Vbitrev_tb___024root* vlSelf);

VL_ATTR_COLD bool Vbitrev_tb___024root___eval_phase__stl(Vbitrev_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitrev_tb___024root___eval_phase__stl\n"); );
    Vbitrev_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vbitrev_tb___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vbitrev_tb___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vbitrev_tb___024root___dump_triggers__act(Vbitrev_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitrev_tb___024root___dump_triggers__act\n"); );
    Vbitrev_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge bitrev_tb.clk_i)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(negedge bitrev_tb.rst_ni)\n");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @( (bitrev_tb.valid_o & bitrev_tb.ready_i))\n");
    }
    if ((8ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 3 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vbitrev_tb___024root___dump_triggers__nba(Vbitrev_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitrev_tb___024root___dump_triggers__nba\n"); );
    Vbitrev_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge bitrev_tb.clk_i)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(negedge bitrev_tb.rst_ni)\n");
    }
    if ((4ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @( (bitrev_tb.valid_o & bitrev_tb.ready_i))\n");
    }
    if ((8ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 3 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vbitrev_tb___024root____Vm_traceActivitySetAll(Vbitrev_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitrev_tb___024root____Vm_traceActivitySetAll\n"); );
    Vbitrev_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
}

VL_ATTR_COLD void Vbitrev_tb___024root___ctor_var_reset(Vbitrev_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitrev_tb___024root___ctor_var_reset\n"); );
    Vbitrev_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->bitrev_tb__DOT__clk_i = VL_RAND_RESET_I(1);
    vlSelf->bitrev_tb__DOT__rst_ni = VL_RAND_RESET_I(1);
    vlSelf->bitrev_tb__DOT__valid_i = VL_RAND_RESET_I(1);
    vlSelf->bitrev_tb__DOT__data_i = VL_RAND_RESET_I(32);
    vlSelf->bitrev_tb__DOT__valid_o = VL_RAND_RESET_I(1);
    vlSelf->bitrev_tb__DOT__ready_i = VL_RAND_RESET_I(1);
    vlSelf->bitrev_tb__DOT__cycle_count = 0;
    vlSelf->bitrev_tb__DOT__input_start_cycle = 0;
    vlSelf->bitrev_tb__DOT__output_start_cycle = 0;
    vlSelf->bitrev_tb__DOT__output_end_cycle = 0;
    vlSelf->bitrev_tb__DOT__err_cnt = VL_RAND_RESET_I(32);
    vlSelf->bitrev_tb__DOT__unnamedblk2__DOT__i = 0;
    vlSelf->bitrev_tb__DOT__unnamedblk3__DOT__i = 0;
    vlSelf->bitrev_tb__DOT____Vlvbound_h3aee0c48__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->bitrev_tb__DOT__dut__DOT__sram_a[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->bitrev_tb__DOT__dut__DOT__sram_b[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->bitrev_tb__DOT__dut__DOT__bank_sel_wr = VL_RAND_RESET_I(1);
    vlSelf->bitrev_tb__DOT__dut__DOT__bank_sel_rd = VL_RAND_RESET_I(1);
    vlSelf->bitrev_tb__DOT__dut__DOT__wr_cnt = VL_RAND_RESET_I(6);
    vlSelf->bitrev_tb__DOT__dut__DOT__rd_cnt = VL_RAND_RESET_I(6);
    vlSelf->bitrev_tb__DOT__dut__DOT__wr_cnt_next = VL_RAND_RESET_I(6);
    vlSelf->bitrev_tb__DOT__dut__DOT__data_q = VL_RAND_RESET_I(32);
    vlSelf->bitrev_tb__DOT__dut__DOT__rev_addr = VL_RAND_RESET_I(6);
    vlSelf->bitrev_tb__DOT__dut__DOT__data_d = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_bitrev_tb__DOT__dut__DOT__bit_reverse__2__Vfuncout = VL_RAND_RESET_I(6);
    vlSelf->__Vtrigprevexpr___TOP__bitrev_tb__DOT__clk_i__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__bitrev_tb__DOT__rst_ni__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr_h822765d9__1 = VL_RAND_RESET_I(1);
    vlSelf->__VactDidInit = 0;
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
