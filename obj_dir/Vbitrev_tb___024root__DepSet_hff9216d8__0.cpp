// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vbitrev_tb.h for the primary calling header

#include "Vbitrev_tb__pch.h"
#include "Vbitrev_tb___024root.h"

VlCoroutine Vbitrev_tb___024root___eval_initial__TOP__Vtiming__0(Vbitrev_tb___024root* vlSelf);
VlCoroutine Vbitrev_tb___024root___eval_initial__TOP__Vtiming__1(Vbitrev_tb___024root* vlSelf);

void Vbitrev_tb___024root___eval_initial(Vbitrev_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitrev_tb___024root___eval_initial\n"); );
    Vbitrev_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    Vbitrev_tb___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vbitrev_tb___024root___eval_initial__TOP__Vtiming__1(vlSelf);
}

VL_INLINE_OPT VlCoroutine Vbitrev_tb___024root___eval_initial__TOP__Vtiming__1(Vbitrev_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitrev_tb___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vbitrev_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (1U) {
        co_await vlSelfRef.__VdlySched.delay(0x1388ULL, 
                                             nullptr, 
                                             "sw/bitrev_tb.sv", 
                                             42);
        vlSelfRef.bitrev_tb__DOT__clk_i = (1U & (~ (IData)(vlSelfRef.bitrev_tb__DOT__clk_i)));
    }
}

void Vbitrev_tb___024root___eval_act(Vbitrev_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitrev_tb___024root___eval_act\n"); );
    Vbitrev_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vbitrev_tb___024root___nba_sequent__TOP__0(Vbitrev_tb___024root* vlSelf);
void Vbitrev_tb___024root___nba_sequent__TOP__1(Vbitrev_tb___024root* vlSelf);

void Vbitrev_tb___024root___eval_nba(Vbitrev_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitrev_tb___024root___eval_nba\n"); );
    Vbitrev_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vbitrev_tb___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vbitrev_tb___024root___nba_sequent__TOP__1(vlSelf);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
}

VL_INLINE_OPT void Vbitrev_tb___024root___nba_sequent__TOP__0(Vbitrev_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitrev_tb___024root___nba_sequent__TOP__0\n"); );
    Vbitrev_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.bitrev_tb__DOT__cycle_count = ((IData)(1U) 
                                             + vlSelfRef.bitrev_tb__DOT__cycle_count);
}

VL_INLINE_OPT void Vbitrev_tb___024root___nba_sequent__TOP__1(Vbitrev_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitrev_tb___024root___nba_sequent__TOP__1\n"); );
    Vbitrev_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ bitrev_tb__DOT__dut__DOT____Vlvbound_h12462a78__0;
    bitrev_tb__DOT__dut__DOT____Vlvbound_h12462a78__0 = 0;
    CData/*5:0*/ __Vfunc_bitrev_tb__DOT__dut__DOT__bit_reverse__2__x;
    __Vfunc_bitrev_tb__DOT__dut__DOT__bit_reverse__2__x = 0;
    CData/*5:0*/ __Vdly__bitrev_tb__DOT__dut__DOT__rd_cnt;
    __Vdly__bitrev_tb__DOT__dut__DOT__rd_cnt = 0;
    IData/*31:0*/ __VdlyVal__bitrev_tb__DOT__dut__DOT__sram_b__v0;
    __VdlyVal__bitrev_tb__DOT__dut__DOT__sram_b__v0 = 0;
    CData/*5:0*/ __VdlyDim0__bitrev_tb__DOT__dut__DOT__sram_b__v0;
    __VdlyDim0__bitrev_tb__DOT__dut__DOT__sram_b__v0 = 0;
    CData/*0:0*/ __VdlySet__bitrev_tb__DOT__dut__DOT__sram_b__v0;
    __VdlySet__bitrev_tb__DOT__dut__DOT__sram_b__v0 = 0;
    IData/*31:0*/ __VdlyVal__bitrev_tb__DOT__dut__DOT__sram_a__v0;
    __VdlyVal__bitrev_tb__DOT__dut__DOT__sram_a__v0 = 0;
    CData/*5:0*/ __VdlyDim0__bitrev_tb__DOT__dut__DOT__sram_a__v0;
    __VdlyDim0__bitrev_tb__DOT__dut__DOT__sram_a__v0 = 0;
    CData/*0:0*/ __VdlySet__bitrev_tb__DOT__dut__DOT__sram_a__v0;
    __VdlySet__bitrev_tb__DOT__dut__DOT__sram_a__v0 = 0;
    // Body
    __Vdly__bitrev_tb__DOT__dut__DOT__rd_cnt = vlSelfRef.bitrev_tb__DOT__dut__DOT__rd_cnt;
    __VdlySet__bitrev_tb__DOT__dut__DOT__sram_b__v0 = 0U;
    __VdlySet__bitrev_tb__DOT__dut__DOT__sram_a__v0 = 0U;
    if (vlSelfRef.bitrev_tb__DOT__rst_ni) {
        if (vlSelfRef.bitrev_tb__DOT__valid_i) {
            if (vlSelfRef.bitrev_tb__DOT__dut__DOT__bank_sel_wr) {
                __VdlyVal__bitrev_tb__DOT__dut__DOT__sram_b__v0 
                    = vlSelfRef.bitrev_tb__DOT__data_i;
                __VdlyDim0__bitrev_tb__DOT__dut__DOT__sram_b__v0 
                    = vlSelfRef.bitrev_tb__DOT__dut__DOT__wr_cnt;
                __VdlySet__bitrev_tb__DOT__dut__DOT__sram_b__v0 = 1U;
            } else {
                __VdlyVal__bitrev_tb__DOT__dut__DOT__sram_a__v0 
                    = vlSelfRef.bitrev_tb__DOT__data_i;
                __VdlyDim0__bitrev_tb__DOT__dut__DOT__sram_a__v0 
                    = vlSelfRef.bitrev_tb__DOT__dut__DOT__wr_cnt;
                __VdlySet__bitrev_tb__DOT__dut__DOT__sram_a__v0 = 1U;
            }
            if ((0U == (0x3fU & ((IData)(1U) + (IData)(vlSelfRef.bitrev_tb__DOT__dut__DOT__wr_cnt))))) {
                vlSelfRef.bitrev_tb__DOT__dut__DOT__bank_sel_wr 
                    = (1U & (~ (IData)(vlSelfRef.bitrev_tb__DOT__dut__DOT__bank_sel_wr)));
            }
            vlSelfRef.bitrev_tb__DOT__dut__DOT__wr_cnt 
                = vlSelfRef.bitrev_tb__DOT__dut__DOT__wr_cnt_next;
        }
        if ((1U & ((IData)(vlSelfRef.bitrev_tb__DOT__ready_i) 
                   | (~ (IData)(vlSelfRef.bitrev_tb__DOT__valid_o))))) {
            if ((0x3fU == (IData)(vlSelfRef.bitrev_tb__DOT__dut__DOT__rd_cnt))) {
                vlSelfRef.bitrev_tb__DOT__dut__DOT__bank_sel_rd 
                    = (1U & (~ (IData)(vlSelfRef.bitrev_tb__DOT__dut__DOT__bank_sel_rd)));
                __Vdly__bitrev_tb__DOT__dut__DOT__rd_cnt = 0U;
            } else {
                __Vdly__bitrev_tb__DOT__dut__DOT__rd_cnt 
                    = (0x3fU & ((IData)(1U) + (IData)(vlSelfRef.bitrev_tb__DOT__dut__DOT__rd_cnt)));
            }
            vlSelfRef.bitrev_tb__DOT__dut__DOT__data_q 
                = vlSelfRef.bitrev_tb__DOT__dut__DOT__data_d;
            vlSelfRef.bitrev_tb__DOT__valid_o = 1U;
        }
    } else {
        vlSelfRef.bitrev_tb__DOT__dut__DOT__bank_sel_wr = 0U;
        __Vdly__bitrev_tb__DOT__dut__DOT__rd_cnt = 0U;
        vlSelfRef.bitrev_tb__DOT__dut__DOT__bank_sel_rd = 0U;
        vlSelfRef.bitrev_tb__DOT__dut__DOT__data_q = 0U;
        vlSelfRef.bitrev_tb__DOT__valid_o = 0U;
        vlSelfRef.bitrev_tb__DOT__dut__DOT__wr_cnt = 0U;
    }
    if (__VdlySet__bitrev_tb__DOT__dut__DOT__sram_b__v0) {
        vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[__VdlyDim0__bitrev_tb__DOT__dut__DOT__sram_b__v0] 
            = __VdlyVal__bitrev_tb__DOT__dut__DOT__sram_b__v0;
    }
    if (__VdlySet__bitrev_tb__DOT__dut__DOT__sram_a__v0) {
        vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[__VdlyDim0__bitrev_tb__DOT__dut__DOT__sram_a__v0] 
            = __VdlyVal__bitrev_tb__DOT__dut__DOT__sram_a__v0;
    }
    vlSelfRef.bitrev_tb__DOT__dut__DOT__rd_cnt = __Vdly__bitrev_tb__DOT__dut__DOT__rd_cnt;
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
    vlSelfRef.bitrev_tb__DOT__dut__DOT__wr_cnt_next 
        = (0x3fU & ((IData)(1U) + (IData)(vlSelfRef.bitrev_tb__DOT__dut__DOT__wr_cnt)));
}

void Vbitrev_tb___024root___timing_resume(Vbitrev_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitrev_tb___024root___timing_resume\n"); );
    Vbitrev_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_h915c4b11__0.resume(
                                                   "@(posedge bitrev_tb.clk_i)");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_he610b0fb__0.resume(
                                                   "@( (bitrev_tb.valid_o & bitrev_tb.ready_i))");
    }
    if ((8ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vbitrev_tb___024root___timing_commit(Vbitrev_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitrev_tb___024root___timing_commit\n"); );
    Vbitrev_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((! (1ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_h915c4b11__0.commit(
                                                   "@(posedge bitrev_tb.clk_i)");
    }
    if ((! (4ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_he610b0fb__0.commit(
                                                   "@( (bitrev_tb.valid_o & bitrev_tb.ready_i))");
    }
}

void Vbitrev_tb___024root___eval_triggers__act(Vbitrev_tb___024root* vlSelf);

bool Vbitrev_tb___024root___eval_phase__act(Vbitrev_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitrev_tb___024root___eval_phase__act\n"); );
    Vbitrev_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<4> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vbitrev_tb___024root___eval_triggers__act(vlSelf);
    Vbitrev_tb___024root___timing_commit(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vbitrev_tb___024root___timing_resume(vlSelf);
        Vbitrev_tb___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vbitrev_tb___024root___eval_phase__nba(Vbitrev_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitrev_tb___024root___eval_phase__nba\n"); );
    Vbitrev_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vbitrev_tb___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vbitrev_tb___024root___dump_triggers__nba(Vbitrev_tb___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vbitrev_tb___024root___dump_triggers__act(Vbitrev_tb___024root* vlSelf);
#endif  // VL_DEBUG

void Vbitrev_tb___024root___eval(Vbitrev_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitrev_tb___024root___eval\n"); );
    Vbitrev_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vbitrev_tb___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("sw/bitrev_tb.sv", 3, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vbitrev_tb___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("sw/bitrev_tb.sv", 3, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vbitrev_tb___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vbitrev_tb___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vbitrev_tb___024root___eval_debug_assertions(Vbitrev_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitrev_tb___024root___eval_debug_assertions\n"); );
    Vbitrev_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
