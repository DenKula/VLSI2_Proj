// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vbitrev_tb.h for the primary calling header

#include "Vbitrev_tb__pch.h"
#include "Vbitrev_tb__Syms.h"
#include "Vbitrev_tb___024root.h"

VL_INLINE_OPT VlCoroutine Vbitrev_tb___024root___eval_initial__TOP__Vtiming__0(Vbitrev_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitrev_tb___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vbitrev_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    SData/*9:0*/ __Vfunc_bitrev_tb__DOT__reverse_bits_k__0__Vfuncout;
    __Vfunc_bitrev_tb__DOT__reverse_bits_k__0__Vfuncout = 0;
    SData/*9:0*/ __Vfunc_bitrev_tb__DOT__reverse_bits_k__0__x;
    __Vfunc_bitrev_tb__DOT__reverse_bits_k__0__x = 0;
    IData/*31:0*/ __Vfunc_bitrev_tb__DOT__reverse_bits_k__0__unnamedblk1__DOT__i;
    __Vfunc_bitrev_tb__DOT__reverse_bits_k__0__unnamedblk1__DOT__i = 0;
    SData/*9:0*/ __Vfunc_bitrev_tb__DOT__reverse_bits_k__1__Vfuncout;
    __Vfunc_bitrev_tb__DOT__reverse_bits_k__1__Vfuncout = 0;
    SData/*9:0*/ __Vfunc_bitrev_tb__DOT__reverse_bits_k__1__x;
    __Vfunc_bitrev_tb__DOT__reverse_bits_k__1__x = 0;
    IData/*31:0*/ __Vfunc_bitrev_tb__DOT__reverse_bits_k__1__unnamedblk1__DOT__i;
    __Vfunc_bitrev_tb__DOT__reverse_bits_k__1__unnamedblk1__DOT__i = 0;
    VlWide<4>/*127:0*/ __Vtemp_1;
    // Body
    __Vtemp_1[0U] = 0x2e766364U;
    __Vtemp_1[1U] = 0x765f7462U;
    __Vtemp_1[2U] = 0x69747265U;
    __Vtemp_1[3U] = 0x62U;
    vlSymsp->_vm_contextp__->dumpfile(VL_CVT_PACK_STR_NW(4, __Vtemp_1));
    vlSymsp->_traceDumpOpen();
    vlSelfRef.bitrev_tb__DOT__rst_ni = 0U;
    co_await vlSelfRef.__VtrigSched_h915c4b11__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge bitrev_tb.clk_i)", 
                                                         "sw/bitrev_tb.sv", 
                                                         72);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h915c4b11__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge bitrev_tb.clk_i)", 
                                                         "sw/bitrev_tb.sv", 
                                                         72);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h915c4b11__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge bitrev_tb.clk_i)", 
                                                         "sw/bitrev_tb.sv", 
                                                         72);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VtrigSched_h915c4b11__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge bitrev_tb.clk_i)", 
                                                         "sw/bitrev_tb.sv", 
                                                         72);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.bitrev_tb__DOT__rst_ni = 1U;
    vlSelfRef.bitrev_tb__DOT__unnamedblk2__DOT__i = 0U;
    while ((0x400U > vlSelfRef.bitrev_tb__DOT__unnamedblk2__DOT__i)) {
        co_await vlSelfRef.__VtrigSched_h915c4b11__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge bitrev_tb.clk_i)", 
                                                             "sw/bitrev_tb.sv", 
                                                             78);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        if ((0U == vlSelfRef.bitrev_tb__DOT__unnamedblk2__DOT__i)) {
            vlSelfRef.bitrev_tb__DOT__input_start_cycle 
                = vlSelfRef.bitrev_tb__DOT__cycle_count;
        }
        vlSelfRef.bitrev_tb__DOT__valid_i = 1U;
        vlSelfRef.bitrev_tb__DOT__data_i = vlSelfRef.bitrev_tb__DOT__unnamedblk2__DOT__i;
        vlSelfRef.bitrev_tb__DOT__unnamedblk2__DOT__i 
            = ((IData)(1U) + vlSelfRef.bitrev_tb__DOT__unnamedblk2__DOT__i);
    }
    co_await vlSelfRef.__VtrigSched_h915c4b11__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge bitrev_tb.clk_i)", 
                                                         "sw/bitrev_tb.sv", 
                                                         86);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.bitrev_tb__DOT__valid_i = 0U;
    vlSelfRef.bitrev_tb__DOT__unnamedblk3__DOT__i = 0U;
    while ((0x400U > vlSelfRef.bitrev_tb__DOT__unnamedblk3__DOT__i)) {
        vlSelfRef.bitrev_tb__DOT__ready_i = 1U;
        while ((1U & (~ ((IData)(vlSelfRef.bitrev_tb__DOT__valid_o) 
                         & (IData)(vlSelfRef.bitrev_tb__DOT__ready_i))))) {
            co_await vlSelfRef.__VtrigSched_he610b0fb__0.trigger(1U, 
                                                                 nullptr, 
                                                                 "@( (bitrev_tb.valid_o & bitrev_tb.ready_i))", 
                                                                 "sw/bitrev_tb.sv", 
                                                                 93);
            vlSelfRef.__Vm_traceActivity[2U] = 1U;
        }
        if ((0U == vlSelfRef.bitrev_tb__DOT__unnamedblk3__DOT__i)) {
            vlSelfRef.bitrev_tb__DOT__output_start_cycle 
                = vlSelfRef.bitrev_tb__DOT__cycle_count;
        }
        if ((0x3ffU == vlSelfRef.bitrev_tb__DOT__unnamedblk3__DOT__i)) {
            vlSelfRef.bitrev_tb__DOT__output_end_cycle 
                = vlSelfRef.bitrev_tb__DOT__cycle_count;
        }
        if (VL_UNLIKELY((((0x3ffU & vlSelfRef.bitrev_tb__DOT__dut__DOT__data_q) 
                          != ([&]() {
                                __Vfunc_bitrev_tb__DOT__reverse_bits_k__0__x 
                                    = (0x3ffU & vlSelfRef.bitrev_tb__DOT__unnamedblk3__DOT__i);
                                __Vfunc_bitrev_tb__DOT__reverse_bits_k__0__unnamedblk1__DOT__i = 0;
                                vlSelfRef.bitrev_tb__DOT____Vlvbound_h6ebd1da0__0 
                                    = (1U & ((IData)(__Vfunc_bitrev_tb__DOT__reverse_bits_k__0__x) 
                                             >> 9U));
                                __Vfunc_bitrev_tb__DOT__reverse_bits_k__0__Vfuncout 
                                    = ((0x3feU & (IData)(__Vfunc_bitrev_tb__DOT__reverse_bits_k__0__Vfuncout)) 
                                       | (IData)(vlSelfRef.bitrev_tb__DOT____Vlvbound_h6ebd1da0__0));
                                __Vfunc_bitrev_tb__DOT__reverse_bits_k__0__unnamedblk1__DOT__i = 1U;
                                vlSelfRef.bitrev_tb__DOT____Vlvbound_h6ebd1da0__0 
                                    = (1U & ((IData)(__Vfunc_bitrev_tb__DOT__reverse_bits_k__0__x) 
                                             >> 8U));
                                __Vfunc_bitrev_tb__DOT__reverse_bits_k__0__Vfuncout 
                                    = ((0x3fdU & (IData)(__Vfunc_bitrev_tb__DOT__reverse_bits_k__0__Vfuncout)) 
                                       | ((IData)(vlSelfRef.bitrev_tb__DOT____Vlvbound_h6ebd1da0__0) 
                                          << 1U));
                                __Vfunc_bitrev_tb__DOT__reverse_bits_k__0__unnamedblk1__DOT__i = 2U;
                                vlSelfRef.bitrev_tb__DOT____Vlvbound_h6ebd1da0__0 
                                    = (1U & ((IData)(__Vfunc_bitrev_tb__DOT__reverse_bits_k__0__x) 
                                             >> 7U));
                                __Vfunc_bitrev_tb__DOT__reverse_bits_k__0__Vfuncout 
                                    = ((0x3fbU & (IData)(__Vfunc_bitrev_tb__DOT__reverse_bits_k__0__Vfuncout)) 
                                       | ((IData)(vlSelfRef.bitrev_tb__DOT____Vlvbound_h6ebd1da0__0) 
                                          << 2U));
                                __Vfunc_bitrev_tb__DOT__reverse_bits_k__0__unnamedblk1__DOT__i = 3U;
                                vlSelfRef.bitrev_tb__DOT____Vlvbound_h6ebd1da0__0 
                                    = (1U & ((IData)(__Vfunc_bitrev_tb__DOT__reverse_bits_k__0__x) 
                                             >> 6U));
                                __Vfunc_bitrev_tb__DOT__reverse_bits_k__0__Vfuncout 
                                    = ((0x3f7U & (IData)(__Vfunc_bitrev_tb__DOT__reverse_bits_k__0__Vfuncout)) 
                                       | ((IData)(vlSelfRef.bitrev_tb__DOT____Vlvbound_h6ebd1da0__0) 
                                          << 3U));
                                __Vfunc_bitrev_tb__DOT__reverse_bits_k__0__unnamedblk1__DOT__i = 4U;
                                vlSelfRef.bitrev_tb__DOT____Vlvbound_h6ebd1da0__0 
                                    = (1U & ((IData)(__Vfunc_bitrev_tb__DOT__reverse_bits_k__0__x) 
                                             >> 5U));
                                __Vfunc_bitrev_tb__DOT__reverse_bits_k__0__Vfuncout 
                                    = ((0x3efU & (IData)(__Vfunc_bitrev_tb__DOT__reverse_bits_k__0__Vfuncout)) 
                                       | ((IData)(vlSelfRef.bitrev_tb__DOT____Vlvbound_h6ebd1da0__0) 
                                          << 4U));
                                __Vfunc_bitrev_tb__DOT__reverse_bits_k__0__unnamedblk1__DOT__i = 5U;
                                vlSelfRef.bitrev_tb__DOT____Vlvbound_h6ebd1da0__0 
                                    = (1U & ((IData)(__Vfunc_bitrev_tb__DOT__reverse_bits_k__0__x) 
                                             >> 4U));
                                __Vfunc_bitrev_tb__DOT__reverse_bits_k__0__Vfuncout 
                                    = ((0x3dfU & (IData)(__Vfunc_bitrev_tb__DOT__reverse_bits_k__0__Vfuncout)) 
                                       | ((IData)(vlSelfRef.bitrev_tb__DOT____Vlvbound_h6ebd1da0__0) 
                                          << 5U));
                                __Vfunc_bitrev_tb__DOT__reverse_bits_k__0__unnamedblk1__DOT__i = 6U;
                                vlSelfRef.bitrev_tb__DOT____Vlvbound_h6ebd1da0__0 
                                    = (1U & ((IData)(__Vfunc_bitrev_tb__DOT__reverse_bits_k__0__x) 
                                             >> 3U));
                                __Vfunc_bitrev_tb__DOT__reverse_bits_k__0__Vfuncout 
                                    = ((0x3bfU & (IData)(__Vfunc_bitrev_tb__DOT__reverse_bits_k__0__Vfuncout)) 
                                       | ((IData)(vlSelfRef.bitrev_tb__DOT____Vlvbound_h6ebd1da0__0) 
                                          << 6U));
                                __Vfunc_bitrev_tb__DOT__reverse_bits_k__0__unnamedblk1__DOT__i = 7U;
                                vlSelfRef.bitrev_tb__DOT____Vlvbound_h6ebd1da0__0 
                                    = (1U & ((IData)(__Vfunc_bitrev_tb__DOT__reverse_bits_k__0__x) 
                                             >> 2U));
                                __Vfunc_bitrev_tb__DOT__reverse_bits_k__0__Vfuncout 
                                    = ((0x37fU & (IData)(__Vfunc_bitrev_tb__DOT__reverse_bits_k__0__Vfuncout)) 
                                       | ((IData)(vlSelfRef.bitrev_tb__DOT____Vlvbound_h6ebd1da0__0) 
                                          << 7U));
                                __Vfunc_bitrev_tb__DOT__reverse_bits_k__0__unnamedblk1__DOT__i = 8U;
                                vlSelfRef.bitrev_tb__DOT____Vlvbound_h6ebd1da0__0 
                                    = (1U & ((IData)(__Vfunc_bitrev_tb__DOT__reverse_bits_k__0__x) 
                                             >> 1U));
                                __Vfunc_bitrev_tb__DOT__reverse_bits_k__0__Vfuncout 
                                    = ((0x2ffU & (IData)(__Vfunc_bitrev_tb__DOT__reverse_bits_k__0__Vfuncout)) 
                                       | ((IData)(vlSelfRef.bitrev_tb__DOT____Vlvbound_h6ebd1da0__0) 
                                          << 8U));
                                __Vfunc_bitrev_tb__DOT__reverse_bits_k__0__unnamedblk1__DOT__i = 9U;
                                vlSelfRef.bitrev_tb__DOT____Vlvbound_h6ebd1da0__0 
                                    = (1U & (IData)(__Vfunc_bitrev_tb__DOT__reverse_bits_k__0__x));
                                __Vfunc_bitrev_tb__DOT__reverse_bits_k__0__Vfuncout 
                                    = ((0x1ffU & (IData)(__Vfunc_bitrev_tb__DOT__reverse_bits_k__0__Vfuncout)) 
                                       | ((IData)(vlSelfRef.bitrev_tb__DOT____Vlvbound_h6ebd1da0__0) 
                                          << 9U));
                                __Vfunc_bitrev_tb__DOT__reverse_bits_k__0__unnamedblk1__DOT__i = 0xaU;
                            }(), (IData)(__Vfunc_bitrev_tb__DOT__reverse_bits_k__0__Vfuncout)))))) {
            VL_WRITEF_NX("Mismatch @%0# : got %0#, exp %0#\n",0,
                         32,vlSelfRef.bitrev_tb__DOT__unnamedblk3__DOT__i,
                         32,vlSelfRef.bitrev_tb__DOT__dut__DOT__data_q,
                         10,([&]() {
                            __Vfunc_bitrev_tb__DOT__reverse_bits_k__1__x 
                                = (0x3ffU & vlSelfRef.bitrev_tb__DOT__unnamedblk3__DOT__i);
                            __Vfunc_bitrev_tb__DOT__reverse_bits_k__1__unnamedblk1__DOT__i = 0;
                            vlSelfRef.bitrev_tb__DOT____Vlvbound_h6ebd1da0__0 
                                = (1U & ((IData)(__Vfunc_bitrev_tb__DOT__reverse_bits_k__1__x) 
                                         >> 9U));
                            __Vfunc_bitrev_tb__DOT__reverse_bits_k__1__Vfuncout 
                                = ((0x3feU & (IData)(__Vfunc_bitrev_tb__DOT__reverse_bits_k__1__Vfuncout)) 
                                   | (IData)(vlSelfRef.bitrev_tb__DOT____Vlvbound_h6ebd1da0__0));
                            __Vfunc_bitrev_tb__DOT__reverse_bits_k__1__unnamedblk1__DOT__i = 1U;
                            vlSelfRef.bitrev_tb__DOT____Vlvbound_h6ebd1da0__0 
                                = (1U & ((IData)(__Vfunc_bitrev_tb__DOT__reverse_bits_k__1__x) 
                                         >> 8U));
                            __Vfunc_bitrev_tb__DOT__reverse_bits_k__1__Vfuncout 
                                = ((0x3fdU & (IData)(__Vfunc_bitrev_tb__DOT__reverse_bits_k__1__Vfuncout)) 
                                   | ((IData)(vlSelfRef.bitrev_tb__DOT____Vlvbound_h6ebd1da0__0) 
                                      << 1U));
                            __Vfunc_bitrev_tb__DOT__reverse_bits_k__1__unnamedblk1__DOT__i = 2U;
                            vlSelfRef.bitrev_tb__DOT____Vlvbound_h6ebd1da0__0 
                                = (1U & ((IData)(__Vfunc_bitrev_tb__DOT__reverse_bits_k__1__x) 
                                         >> 7U));
                            __Vfunc_bitrev_tb__DOT__reverse_bits_k__1__Vfuncout 
                                = ((0x3fbU & (IData)(__Vfunc_bitrev_tb__DOT__reverse_bits_k__1__Vfuncout)) 
                                   | ((IData)(vlSelfRef.bitrev_tb__DOT____Vlvbound_h6ebd1da0__0) 
                                      << 2U));
                            __Vfunc_bitrev_tb__DOT__reverse_bits_k__1__unnamedblk1__DOT__i = 3U;
                            vlSelfRef.bitrev_tb__DOT____Vlvbound_h6ebd1da0__0 
                                = (1U & ((IData)(__Vfunc_bitrev_tb__DOT__reverse_bits_k__1__x) 
                                         >> 6U));
                            __Vfunc_bitrev_tb__DOT__reverse_bits_k__1__Vfuncout 
                                = ((0x3f7U & (IData)(__Vfunc_bitrev_tb__DOT__reverse_bits_k__1__Vfuncout)) 
                                   | ((IData)(vlSelfRef.bitrev_tb__DOT____Vlvbound_h6ebd1da0__0) 
                                      << 3U));
                            __Vfunc_bitrev_tb__DOT__reverse_bits_k__1__unnamedblk1__DOT__i = 4U;
                            vlSelfRef.bitrev_tb__DOT____Vlvbound_h6ebd1da0__0 
                                = (1U & ((IData)(__Vfunc_bitrev_tb__DOT__reverse_bits_k__1__x) 
                                         >> 5U));
                            __Vfunc_bitrev_tb__DOT__reverse_bits_k__1__Vfuncout 
                                = ((0x3efU & (IData)(__Vfunc_bitrev_tb__DOT__reverse_bits_k__1__Vfuncout)) 
                                   | ((IData)(vlSelfRef.bitrev_tb__DOT____Vlvbound_h6ebd1da0__0) 
                                      << 4U));
                            __Vfunc_bitrev_tb__DOT__reverse_bits_k__1__unnamedblk1__DOT__i = 5U;
                            vlSelfRef.bitrev_tb__DOT____Vlvbound_h6ebd1da0__0 
                                = (1U & ((IData)(__Vfunc_bitrev_tb__DOT__reverse_bits_k__1__x) 
                                         >> 4U));
                            __Vfunc_bitrev_tb__DOT__reverse_bits_k__1__Vfuncout 
                                = ((0x3dfU & (IData)(__Vfunc_bitrev_tb__DOT__reverse_bits_k__1__Vfuncout)) 
                                   | ((IData)(vlSelfRef.bitrev_tb__DOT____Vlvbound_h6ebd1da0__0) 
                                      << 5U));
                            __Vfunc_bitrev_tb__DOT__reverse_bits_k__1__unnamedblk1__DOT__i = 6U;
                            vlSelfRef.bitrev_tb__DOT____Vlvbound_h6ebd1da0__0 
                                = (1U & ((IData)(__Vfunc_bitrev_tb__DOT__reverse_bits_k__1__x) 
                                         >> 3U));
                            __Vfunc_bitrev_tb__DOT__reverse_bits_k__1__Vfuncout 
                                = ((0x3bfU & (IData)(__Vfunc_bitrev_tb__DOT__reverse_bits_k__1__Vfuncout)) 
                                   | ((IData)(vlSelfRef.bitrev_tb__DOT____Vlvbound_h6ebd1da0__0) 
                                      << 6U));
                            __Vfunc_bitrev_tb__DOT__reverse_bits_k__1__unnamedblk1__DOT__i = 7U;
                            vlSelfRef.bitrev_tb__DOT____Vlvbound_h6ebd1da0__0 
                                = (1U & ((IData)(__Vfunc_bitrev_tb__DOT__reverse_bits_k__1__x) 
                                         >> 2U));
                            __Vfunc_bitrev_tb__DOT__reverse_bits_k__1__Vfuncout 
                                = ((0x37fU & (IData)(__Vfunc_bitrev_tb__DOT__reverse_bits_k__1__Vfuncout)) 
                                   | ((IData)(vlSelfRef.bitrev_tb__DOT____Vlvbound_h6ebd1da0__0) 
                                      << 7U));
                            __Vfunc_bitrev_tb__DOT__reverse_bits_k__1__unnamedblk1__DOT__i = 8U;
                            vlSelfRef.bitrev_tb__DOT____Vlvbound_h6ebd1da0__0 
                                = (1U & ((IData)(__Vfunc_bitrev_tb__DOT__reverse_bits_k__1__x) 
                                         >> 1U));
                            __Vfunc_bitrev_tb__DOT__reverse_bits_k__1__Vfuncout 
                                = ((0x2ffU & (IData)(__Vfunc_bitrev_tb__DOT__reverse_bits_k__1__Vfuncout)) 
                                   | ((IData)(vlSelfRef.bitrev_tb__DOT____Vlvbound_h6ebd1da0__0) 
                                      << 8U));
                            __Vfunc_bitrev_tb__DOT__reverse_bits_k__1__unnamedblk1__DOT__i = 9U;
                            vlSelfRef.bitrev_tb__DOT____Vlvbound_h6ebd1da0__0 
                                = (1U & (IData)(__Vfunc_bitrev_tb__DOT__reverse_bits_k__1__x));
                            __Vfunc_bitrev_tb__DOT__reverse_bits_k__1__Vfuncout 
                                = ((0x1ffU & (IData)(__Vfunc_bitrev_tb__DOT__reverse_bits_k__1__Vfuncout)) 
                                   | ((IData)(vlSelfRef.bitrev_tb__DOT____Vlvbound_h6ebd1da0__0) 
                                      << 9U));
                            __Vfunc_bitrev_tb__DOT__reverse_bits_k__1__unnamedblk1__DOT__i = 0xaU;
                        }(), (IData)(__Vfunc_bitrev_tb__DOT__reverse_bits_k__1__Vfuncout)));
            vlSelfRef.bitrev_tb__DOT__err_cnt = ((IData)(1U) 
                                                 + vlSelfRef.bitrev_tb__DOT__err_cnt);
        }
        co_await vlSelfRef.__VtrigSched_h915c4b11__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge bitrev_tb.clk_i)", 
                                                             "sw/bitrev_tb.sv", 
                                                             107);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        vlSelfRef.bitrev_tb__DOT__ready_i = 0U;
        vlSelfRef.bitrev_tb__DOT__unnamedblk3__DOT__i 
            = ((IData)(1U) + vlSelfRef.bitrev_tb__DOT__unnamedblk3__DOT__i);
    }
    if ((0U == vlSelfRef.bitrev_tb__DOT__err_cnt)) {
        VL_WRITEF_NX("Bit-reversal test PASSED for 1024-point frame\n",0);
    } else {
        VL_WRITEF_NX("Bit-reversal test FAILED : %0d errors\n",0,
                     32,vlSelfRef.bitrev_tb__DOT__err_cnt);
    }
    VL_WRITEF_NX("Input start at cycle  : %0d\nOutput start at cycle : %0d\nOutput end at cycle   : %0d\nEnd-to-end latency    : %0d cycles\nTotal output duration : %0d cycles\n",0,
                 32,vlSelfRef.bitrev_tb__DOT__input_start_cycle,
                 32,vlSelfRef.bitrev_tb__DOT__output_start_cycle,
                 32,vlSelfRef.bitrev_tb__DOT__output_end_cycle,
                 32,(vlSelfRef.bitrev_tb__DOT__output_start_cycle 
                     - vlSelfRef.bitrev_tb__DOT__input_start_cycle),
                 32,((IData)(1U) + (vlSelfRef.bitrev_tb__DOT__output_end_cycle 
                                    - vlSelfRef.bitrev_tb__DOT__output_start_cycle)));
    co_await vlSelfRef.__VdlySched.delay(0x4e20ULL, 
                                         nullptr, "sw/bitrev_tb.sv", 
                                         126);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    VL_FINISH_MT("sw/bitrev_tb.sv", 127, "");
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vbitrev_tb___024root___dump_triggers__act(Vbitrev_tb___024root* vlSelf);
#endif  // VL_DEBUG

void Vbitrev_tb___024root___eval_triggers__act(Vbitrev_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitrev_tb___024root___eval_triggers__act\n"); );
    Vbitrev_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __Vtrigprevexpr_h822765d9__0;
    __Vtrigprevexpr_h822765d9__0 = 0;
    // Body
    __Vtrigprevexpr_h822765d9__0 = ((IData)(vlSelfRef.bitrev_tb__DOT__valid_o) 
                                    & (IData)(vlSelfRef.bitrev_tb__DOT__ready_i));
    vlSelfRef.__VactTriggered.setBit(0U, ((IData)(vlSelfRef.bitrev_tb__DOT__clk_i) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__bitrev_tb__DOT__clk_i__0))));
    vlSelfRef.__VactTriggered.setBit(1U, ((~ (IData)(vlSelfRef.bitrev_tb__DOT__rst_ni)) 
                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__bitrev_tb__DOT__rst_ni__0)));
    vlSelfRef.__VactTriggered.setBit(2U, ((IData)(__Vtrigprevexpr_h822765d9__0) 
                                          != (IData)(vlSelfRef.__Vtrigprevexpr_h822765d9__1)));
    vlSelfRef.__VactTriggered.setBit(3U, vlSelfRef.__VdlySched.awaitingCurrentTime());
    vlSelfRef.__Vtrigprevexpr___TOP__bitrev_tb__DOT__clk_i__0 
        = vlSelfRef.bitrev_tb__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__bitrev_tb__DOT__rst_ni__0 
        = vlSelfRef.bitrev_tb__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr_h822765d9__1 = __Vtrigprevexpr_h822765d9__0;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__VactDidInit)))))) {
        vlSelfRef.__VactDidInit = 1U;
        vlSelfRef.__VactTriggered.setBit(2U, 1U);
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vbitrev_tb___024root___dump_triggers__act(vlSelf);
    }
#endif
}
