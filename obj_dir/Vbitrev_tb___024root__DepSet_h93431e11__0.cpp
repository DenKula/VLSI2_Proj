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
    CData/*5:0*/ __Vfunc_bitrev_tb__DOT__reverse_bits_k__0__Vfuncout;
    __Vfunc_bitrev_tb__DOT__reverse_bits_k__0__Vfuncout = 0;
    CData/*5:0*/ __Vfunc_bitrev_tb__DOT__reverse_bits_k__0__x;
    __Vfunc_bitrev_tb__DOT__reverse_bits_k__0__x = 0;
    IData/*31:0*/ __Vfunc_bitrev_tb__DOT__reverse_bits_k__0__unnamedblk1__DOT__i;
    __Vfunc_bitrev_tb__DOT__reverse_bits_k__0__unnamedblk1__DOT__i = 0;
    CData/*5:0*/ __Vfunc_bitrev_tb__DOT__reverse_bits_k__1__Vfuncout;
    __Vfunc_bitrev_tb__DOT__reverse_bits_k__1__Vfuncout = 0;
    CData/*5:0*/ __Vfunc_bitrev_tb__DOT__reverse_bits_k__1__x;
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
    co_await vlSelfRef.__VtrigSched_h915c4b11__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge bitrev_tb.clk_i)", 
                                                         "sw/bitrev_tb.sv", 
                                                         78);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.bitrev_tb__DOT__input_start_cycle = vlSelfRef.bitrev_tb__DOT__cycle_count;
    vlSelfRef.bitrev_tb__DOT__valid_i = 1U;
    vlSelfRef.bitrev_tb__DOT__data_i = 0U;
    vlSelfRef.bitrev_tb__DOT__unnamedblk2__DOT__i = 1U;
    co_await vlSelfRef.__VtrigSched_h915c4b11__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge bitrev_tb.clk_i)", 
                                                         "sw/bitrev_tb.sv", 
                                                         78);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.bitrev_tb__DOT__valid_i = 1U;
    vlSelfRef.bitrev_tb__DOT__data_i = 1U;
    vlSelfRef.bitrev_tb__DOT__unnamedblk2__DOT__i = 2U;
    co_await vlSelfRef.__VtrigSched_h915c4b11__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge bitrev_tb.clk_i)", 
                                                         "sw/bitrev_tb.sv", 
                                                         78);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.bitrev_tb__DOT__valid_i = 1U;
    vlSelfRef.bitrev_tb__DOT__data_i = 2U;
    vlSelfRef.bitrev_tb__DOT__unnamedblk2__DOT__i = 3U;
    co_await vlSelfRef.__VtrigSched_h915c4b11__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge bitrev_tb.clk_i)", 
                                                         "sw/bitrev_tb.sv", 
                                                         78);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.bitrev_tb__DOT__valid_i = 1U;
    vlSelfRef.bitrev_tb__DOT__data_i = 3U;
    vlSelfRef.bitrev_tb__DOT__unnamedblk2__DOT__i = 4U;
    co_await vlSelfRef.__VtrigSched_h915c4b11__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge bitrev_tb.clk_i)", 
                                                         "sw/bitrev_tb.sv", 
                                                         78);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.bitrev_tb__DOT__valid_i = 1U;
    vlSelfRef.bitrev_tb__DOT__data_i = 4U;
    vlSelfRef.bitrev_tb__DOT__unnamedblk2__DOT__i = 5U;
    co_await vlSelfRef.__VtrigSched_h915c4b11__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge bitrev_tb.clk_i)", 
                                                         "sw/bitrev_tb.sv", 
                                                         78);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.bitrev_tb__DOT__valid_i = 1U;
    vlSelfRef.bitrev_tb__DOT__data_i = 5U;
    vlSelfRef.bitrev_tb__DOT__unnamedblk2__DOT__i = 6U;
    co_await vlSelfRef.__VtrigSched_h915c4b11__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge bitrev_tb.clk_i)", 
                                                         "sw/bitrev_tb.sv", 
                                                         78);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.bitrev_tb__DOT__valid_i = 1U;
    vlSelfRef.bitrev_tb__DOT__data_i = 6U;
    vlSelfRef.bitrev_tb__DOT__unnamedblk2__DOT__i = 7U;
    co_await vlSelfRef.__VtrigSched_h915c4b11__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge bitrev_tb.clk_i)", 
                                                         "sw/bitrev_tb.sv", 
                                                         78);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.bitrev_tb__DOT__valid_i = 1U;
    vlSelfRef.bitrev_tb__DOT__data_i = 7U;
    vlSelfRef.bitrev_tb__DOT__unnamedblk2__DOT__i = 8U;
    co_await vlSelfRef.__VtrigSched_h915c4b11__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge bitrev_tb.clk_i)", 
                                                         "sw/bitrev_tb.sv", 
                                                         78);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.bitrev_tb__DOT__valid_i = 1U;
    vlSelfRef.bitrev_tb__DOT__data_i = 8U;
    vlSelfRef.bitrev_tb__DOT__unnamedblk2__DOT__i = 9U;
    co_await vlSelfRef.__VtrigSched_h915c4b11__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge bitrev_tb.clk_i)", 
                                                         "sw/bitrev_tb.sv", 
                                                         78);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.bitrev_tb__DOT__valid_i = 1U;
    vlSelfRef.bitrev_tb__DOT__data_i = 9U;
    vlSelfRef.bitrev_tb__DOT__unnamedblk2__DOT__i = 0xaU;
    co_await vlSelfRef.__VtrigSched_h915c4b11__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge bitrev_tb.clk_i)", 
                                                         "sw/bitrev_tb.sv", 
                                                         78);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.bitrev_tb__DOT__valid_i = 1U;
    vlSelfRef.bitrev_tb__DOT__data_i = 0xaU;
    vlSelfRef.bitrev_tb__DOT__unnamedblk2__DOT__i = 0xbU;
    co_await vlSelfRef.__VtrigSched_h915c4b11__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge bitrev_tb.clk_i)", 
                                                         "sw/bitrev_tb.sv", 
                                                         78);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.bitrev_tb__DOT__valid_i = 1U;
    vlSelfRef.bitrev_tb__DOT__data_i = 0xbU;
    vlSelfRef.bitrev_tb__DOT__unnamedblk2__DOT__i = 0xcU;
    co_await vlSelfRef.__VtrigSched_h915c4b11__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge bitrev_tb.clk_i)", 
                                                         "sw/bitrev_tb.sv", 
                                                         78);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.bitrev_tb__DOT__valid_i = 1U;
    vlSelfRef.bitrev_tb__DOT__data_i = 0xcU;
    vlSelfRef.bitrev_tb__DOT__unnamedblk2__DOT__i = 0xdU;
    co_await vlSelfRef.__VtrigSched_h915c4b11__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge bitrev_tb.clk_i)", 
                                                         "sw/bitrev_tb.sv", 
                                                         78);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.bitrev_tb__DOT__valid_i = 1U;
    vlSelfRef.bitrev_tb__DOT__data_i = 0xdU;
    vlSelfRef.bitrev_tb__DOT__unnamedblk2__DOT__i = 0xeU;
    co_await vlSelfRef.__VtrigSched_h915c4b11__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge bitrev_tb.clk_i)", 
                                                         "sw/bitrev_tb.sv", 
                                                         78);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.bitrev_tb__DOT__valid_i = 1U;
    vlSelfRef.bitrev_tb__DOT__data_i = 0xeU;
    vlSelfRef.bitrev_tb__DOT__unnamedblk2__DOT__i = 0xfU;
    co_await vlSelfRef.__VtrigSched_h915c4b11__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge bitrev_tb.clk_i)", 
                                                         "sw/bitrev_tb.sv", 
                                                         78);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.bitrev_tb__DOT__valid_i = 1U;
    vlSelfRef.bitrev_tb__DOT__data_i = 0xfU;
    vlSelfRef.bitrev_tb__DOT__unnamedblk2__DOT__i = 0x10U;
    co_await vlSelfRef.__VtrigSched_h915c4b11__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge bitrev_tb.clk_i)", 
                                                         "sw/bitrev_tb.sv", 
                                                         78);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.bitrev_tb__DOT__valid_i = 1U;
    vlSelfRef.bitrev_tb__DOT__data_i = 0x10U;
    vlSelfRef.bitrev_tb__DOT__unnamedblk2__DOT__i = 0x11U;
    co_await vlSelfRef.__VtrigSched_h915c4b11__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge bitrev_tb.clk_i)", 
                                                         "sw/bitrev_tb.sv", 
                                                         78);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.bitrev_tb__DOT__valid_i = 1U;
    vlSelfRef.bitrev_tb__DOT__data_i = 0x11U;
    vlSelfRef.bitrev_tb__DOT__unnamedblk2__DOT__i = 0x12U;
    co_await vlSelfRef.__VtrigSched_h915c4b11__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge bitrev_tb.clk_i)", 
                                                         "sw/bitrev_tb.sv", 
                                                         78);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.bitrev_tb__DOT__valid_i = 1U;
    vlSelfRef.bitrev_tb__DOT__data_i = 0x12U;
    vlSelfRef.bitrev_tb__DOT__unnamedblk2__DOT__i = 0x13U;
    co_await vlSelfRef.__VtrigSched_h915c4b11__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge bitrev_tb.clk_i)", 
                                                         "sw/bitrev_tb.sv", 
                                                         78);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.bitrev_tb__DOT__valid_i = 1U;
    vlSelfRef.bitrev_tb__DOT__data_i = 0x13U;
    vlSelfRef.bitrev_tb__DOT__unnamedblk2__DOT__i = 0x14U;
    co_await vlSelfRef.__VtrigSched_h915c4b11__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge bitrev_tb.clk_i)", 
                                                         "sw/bitrev_tb.sv", 
                                                         78);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.bitrev_tb__DOT__valid_i = 1U;
    vlSelfRef.bitrev_tb__DOT__data_i = 0x14U;
    vlSelfRef.bitrev_tb__DOT__unnamedblk2__DOT__i = 0x15U;
    co_await vlSelfRef.__VtrigSched_h915c4b11__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge bitrev_tb.clk_i)", 
                                                         "sw/bitrev_tb.sv", 
                                                         78);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.bitrev_tb__DOT__valid_i = 1U;
    vlSelfRef.bitrev_tb__DOT__data_i = 0x15U;
    vlSelfRef.bitrev_tb__DOT__unnamedblk2__DOT__i = 0x16U;
    co_await vlSelfRef.__VtrigSched_h915c4b11__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge bitrev_tb.clk_i)", 
                                                         "sw/bitrev_tb.sv", 
                                                         78);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.bitrev_tb__DOT__valid_i = 1U;
    vlSelfRef.bitrev_tb__DOT__data_i = 0x16U;
    vlSelfRef.bitrev_tb__DOT__unnamedblk2__DOT__i = 0x17U;
    co_await vlSelfRef.__VtrigSched_h915c4b11__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge bitrev_tb.clk_i)", 
                                                         "sw/bitrev_tb.sv", 
                                                         78);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.bitrev_tb__DOT__valid_i = 1U;
    vlSelfRef.bitrev_tb__DOT__data_i = 0x17U;
    vlSelfRef.bitrev_tb__DOT__unnamedblk2__DOT__i = 0x18U;
    co_await vlSelfRef.__VtrigSched_h915c4b11__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge bitrev_tb.clk_i)", 
                                                         "sw/bitrev_tb.sv", 
                                                         78);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.bitrev_tb__DOT__valid_i = 1U;
    vlSelfRef.bitrev_tb__DOT__data_i = 0x18U;
    vlSelfRef.bitrev_tb__DOT__unnamedblk2__DOT__i = 0x19U;
    co_await vlSelfRef.__VtrigSched_h915c4b11__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge bitrev_tb.clk_i)", 
                                                         "sw/bitrev_tb.sv", 
                                                         78);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.bitrev_tb__DOT__valid_i = 1U;
    vlSelfRef.bitrev_tb__DOT__data_i = 0x19U;
    vlSelfRef.bitrev_tb__DOT__unnamedblk2__DOT__i = 0x1aU;
    co_await vlSelfRef.__VtrigSched_h915c4b11__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge bitrev_tb.clk_i)", 
                                                         "sw/bitrev_tb.sv", 
                                                         78);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.bitrev_tb__DOT__valid_i = 1U;
    vlSelfRef.bitrev_tb__DOT__data_i = 0x1aU;
    vlSelfRef.bitrev_tb__DOT__unnamedblk2__DOT__i = 0x1bU;
    co_await vlSelfRef.__VtrigSched_h915c4b11__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge bitrev_tb.clk_i)", 
                                                         "sw/bitrev_tb.sv", 
                                                         78);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.bitrev_tb__DOT__valid_i = 1U;
    vlSelfRef.bitrev_tb__DOT__data_i = 0x1bU;
    vlSelfRef.bitrev_tb__DOT__unnamedblk2__DOT__i = 0x1cU;
    co_await vlSelfRef.__VtrigSched_h915c4b11__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge bitrev_tb.clk_i)", 
                                                         "sw/bitrev_tb.sv", 
                                                         78);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.bitrev_tb__DOT__valid_i = 1U;
    vlSelfRef.bitrev_tb__DOT__data_i = 0x1cU;
    vlSelfRef.bitrev_tb__DOT__unnamedblk2__DOT__i = 0x1dU;
    co_await vlSelfRef.__VtrigSched_h915c4b11__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge bitrev_tb.clk_i)", 
                                                         "sw/bitrev_tb.sv", 
                                                         78);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.bitrev_tb__DOT__valid_i = 1U;
    vlSelfRef.bitrev_tb__DOT__data_i = 0x1dU;
    vlSelfRef.bitrev_tb__DOT__unnamedblk2__DOT__i = 0x1eU;
    co_await vlSelfRef.__VtrigSched_h915c4b11__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge bitrev_tb.clk_i)", 
                                                         "sw/bitrev_tb.sv", 
                                                         78);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.bitrev_tb__DOT__valid_i = 1U;
    vlSelfRef.bitrev_tb__DOT__data_i = 0x1eU;
    vlSelfRef.bitrev_tb__DOT__unnamedblk2__DOT__i = 0x1fU;
    co_await vlSelfRef.__VtrigSched_h915c4b11__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge bitrev_tb.clk_i)", 
                                                         "sw/bitrev_tb.sv", 
                                                         78);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.bitrev_tb__DOT__valid_i = 1U;
    vlSelfRef.bitrev_tb__DOT__data_i = 0x1fU;
    vlSelfRef.bitrev_tb__DOT__unnamedblk2__DOT__i = 0x20U;
    co_await vlSelfRef.__VtrigSched_h915c4b11__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge bitrev_tb.clk_i)", 
                                                         "sw/bitrev_tb.sv", 
                                                         78);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.bitrev_tb__DOT__valid_i = 1U;
    vlSelfRef.bitrev_tb__DOT__data_i = 0x20U;
    vlSelfRef.bitrev_tb__DOT__unnamedblk2__DOT__i = 0x21U;
    co_await vlSelfRef.__VtrigSched_h915c4b11__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge bitrev_tb.clk_i)", 
                                                         "sw/bitrev_tb.sv", 
                                                         78);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.bitrev_tb__DOT__valid_i = 1U;
    vlSelfRef.bitrev_tb__DOT__data_i = 0x21U;
    vlSelfRef.bitrev_tb__DOT__unnamedblk2__DOT__i = 0x22U;
    co_await vlSelfRef.__VtrigSched_h915c4b11__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge bitrev_tb.clk_i)", 
                                                         "sw/bitrev_tb.sv", 
                                                         78);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.bitrev_tb__DOT__valid_i = 1U;
    vlSelfRef.bitrev_tb__DOT__data_i = 0x22U;
    vlSelfRef.bitrev_tb__DOT__unnamedblk2__DOT__i = 0x23U;
    co_await vlSelfRef.__VtrigSched_h915c4b11__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge bitrev_tb.clk_i)", 
                                                         "sw/bitrev_tb.sv", 
                                                         78);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.bitrev_tb__DOT__valid_i = 1U;
    vlSelfRef.bitrev_tb__DOT__data_i = 0x23U;
    vlSelfRef.bitrev_tb__DOT__unnamedblk2__DOT__i = 0x24U;
    co_await vlSelfRef.__VtrigSched_h915c4b11__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge bitrev_tb.clk_i)", 
                                                         "sw/bitrev_tb.sv", 
                                                         78);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.bitrev_tb__DOT__valid_i = 1U;
    vlSelfRef.bitrev_tb__DOT__data_i = 0x24U;
    vlSelfRef.bitrev_tb__DOT__unnamedblk2__DOT__i = 0x25U;
    co_await vlSelfRef.__VtrigSched_h915c4b11__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge bitrev_tb.clk_i)", 
                                                         "sw/bitrev_tb.sv", 
                                                         78);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.bitrev_tb__DOT__valid_i = 1U;
    vlSelfRef.bitrev_tb__DOT__data_i = 0x25U;
    vlSelfRef.bitrev_tb__DOT__unnamedblk2__DOT__i = 0x26U;
    co_await vlSelfRef.__VtrigSched_h915c4b11__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge bitrev_tb.clk_i)", 
                                                         "sw/bitrev_tb.sv", 
                                                         78);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.bitrev_tb__DOT__valid_i = 1U;
    vlSelfRef.bitrev_tb__DOT__data_i = 0x26U;
    vlSelfRef.bitrev_tb__DOT__unnamedblk2__DOT__i = 0x27U;
    co_await vlSelfRef.__VtrigSched_h915c4b11__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge bitrev_tb.clk_i)", 
                                                         "sw/bitrev_tb.sv", 
                                                         78);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.bitrev_tb__DOT__valid_i = 1U;
    vlSelfRef.bitrev_tb__DOT__data_i = 0x27U;
    vlSelfRef.bitrev_tb__DOT__unnamedblk2__DOT__i = 0x28U;
    co_await vlSelfRef.__VtrigSched_h915c4b11__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge bitrev_tb.clk_i)", 
                                                         "sw/bitrev_tb.sv", 
                                                         78);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.bitrev_tb__DOT__valid_i = 1U;
    vlSelfRef.bitrev_tb__DOT__data_i = 0x28U;
    vlSelfRef.bitrev_tb__DOT__unnamedblk2__DOT__i = 0x29U;
    co_await vlSelfRef.__VtrigSched_h915c4b11__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge bitrev_tb.clk_i)", 
                                                         "sw/bitrev_tb.sv", 
                                                         78);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.bitrev_tb__DOT__valid_i = 1U;
    vlSelfRef.bitrev_tb__DOT__data_i = 0x29U;
    vlSelfRef.bitrev_tb__DOT__unnamedblk2__DOT__i = 0x2aU;
    co_await vlSelfRef.__VtrigSched_h915c4b11__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge bitrev_tb.clk_i)", 
                                                         "sw/bitrev_tb.sv", 
                                                         78);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.bitrev_tb__DOT__valid_i = 1U;
    vlSelfRef.bitrev_tb__DOT__data_i = 0x2aU;
    vlSelfRef.bitrev_tb__DOT__unnamedblk2__DOT__i = 0x2bU;
    co_await vlSelfRef.__VtrigSched_h915c4b11__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge bitrev_tb.clk_i)", 
                                                         "sw/bitrev_tb.sv", 
                                                         78);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.bitrev_tb__DOT__valid_i = 1U;
    vlSelfRef.bitrev_tb__DOT__data_i = 0x2bU;
    vlSelfRef.bitrev_tb__DOT__unnamedblk2__DOT__i = 0x2cU;
    co_await vlSelfRef.__VtrigSched_h915c4b11__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge bitrev_tb.clk_i)", 
                                                         "sw/bitrev_tb.sv", 
                                                         78);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.bitrev_tb__DOT__valid_i = 1U;
    vlSelfRef.bitrev_tb__DOT__data_i = 0x2cU;
    vlSelfRef.bitrev_tb__DOT__unnamedblk2__DOT__i = 0x2dU;
    co_await vlSelfRef.__VtrigSched_h915c4b11__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge bitrev_tb.clk_i)", 
                                                         "sw/bitrev_tb.sv", 
                                                         78);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.bitrev_tb__DOT__valid_i = 1U;
    vlSelfRef.bitrev_tb__DOT__data_i = 0x2dU;
    vlSelfRef.bitrev_tb__DOT__unnamedblk2__DOT__i = 0x2eU;
    co_await vlSelfRef.__VtrigSched_h915c4b11__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge bitrev_tb.clk_i)", 
                                                         "sw/bitrev_tb.sv", 
                                                         78);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.bitrev_tb__DOT__valid_i = 1U;
    vlSelfRef.bitrev_tb__DOT__data_i = 0x2eU;
    vlSelfRef.bitrev_tb__DOT__unnamedblk2__DOT__i = 0x2fU;
    co_await vlSelfRef.__VtrigSched_h915c4b11__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge bitrev_tb.clk_i)", 
                                                         "sw/bitrev_tb.sv", 
                                                         78);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.bitrev_tb__DOT__valid_i = 1U;
    vlSelfRef.bitrev_tb__DOT__data_i = 0x2fU;
    vlSelfRef.bitrev_tb__DOT__unnamedblk2__DOT__i = 0x30U;
    co_await vlSelfRef.__VtrigSched_h915c4b11__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge bitrev_tb.clk_i)", 
                                                         "sw/bitrev_tb.sv", 
                                                         78);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.bitrev_tb__DOT__valid_i = 1U;
    vlSelfRef.bitrev_tb__DOT__data_i = 0x30U;
    vlSelfRef.bitrev_tb__DOT__unnamedblk2__DOT__i = 0x31U;
    co_await vlSelfRef.__VtrigSched_h915c4b11__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge bitrev_tb.clk_i)", 
                                                         "sw/bitrev_tb.sv", 
                                                         78);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.bitrev_tb__DOT__valid_i = 1U;
    vlSelfRef.bitrev_tb__DOT__data_i = 0x31U;
    vlSelfRef.bitrev_tb__DOT__unnamedblk2__DOT__i = 0x32U;
    co_await vlSelfRef.__VtrigSched_h915c4b11__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge bitrev_tb.clk_i)", 
                                                         "sw/bitrev_tb.sv", 
                                                         78);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.bitrev_tb__DOT__valid_i = 1U;
    vlSelfRef.bitrev_tb__DOT__data_i = 0x32U;
    vlSelfRef.bitrev_tb__DOT__unnamedblk2__DOT__i = 0x33U;
    co_await vlSelfRef.__VtrigSched_h915c4b11__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge bitrev_tb.clk_i)", 
                                                         "sw/bitrev_tb.sv", 
                                                         78);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.bitrev_tb__DOT__valid_i = 1U;
    vlSelfRef.bitrev_tb__DOT__data_i = 0x33U;
    vlSelfRef.bitrev_tb__DOT__unnamedblk2__DOT__i = 0x34U;
    co_await vlSelfRef.__VtrigSched_h915c4b11__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge bitrev_tb.clk_i)", 
                                                         "sw/bitrev_tb.sv", 
                                                         78);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.bitrev_tb__DOT__valid_i = 1U;
    vlSelfRef.bitrev_tb__DOT__data_i = 0x34U;
    vlSelfRef.bitrev_tb__DOT__unnamedblk2__DOT__i = 0x35U;
    co_await vlSelfRef.__VtrigSched_h915c4b11__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge bitrev_tb.clk_i)", 
                                                         "sw/bitrev_tb.sv", 
                                                         78);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.bitrev_tb__DOT__valid_i = 1U;
    vlSelfRef.bitrev_tb__DOT__data_i = 0x35U;
    vlSelfRef.bitrev_tb__DOT__unnamedblk2__DOT__i = 0x36U;
    co_await vlSelfRef.__VtrigSched_h915c4b11__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge bitrev_tb.clk_i)", 
                                                         "sw/bitrev_tb.sv", 
                                                         78);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.bitrev_tb__DOT__valid_i = 1U;
    vlSelfRef.bitrev_tb__DOT__data_i = 0x36U;
    vlSelfRef.bitrev_tb__DOT__unnamedblk2__DOT__i = 0x37U;
    co_await vlSelfRef.__VtrigSched_h915c4b11__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge bitrev_tb.clk_i)", 
                                                         "sw/bitrev_tb.sv", 
                                                         78);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.bitrev_tb__DOT__valid_i = 1U;
    vlSelfRef.bitrev_tb__DOT__data_i = 0x37U;
    vlSelfRef.bitrev_tb__DOT__unnamedblk2__DOT__i = 0x38U;
    co_await vlSelfRef.__VtrigSched_h915c4b11__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge bitrev_tb.clk_i)", 
                                                         "sw/bitrev_tb.sv", 
                                                         78);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.bitrev_tb__DOT__valid_i = 1U;
    vlSelfRef.bitrev_tb__DOT__data_i = 0x38U;
    vlSelfRef.bitrev_tb__DOT__unnamedblk2__DOT__i = 0x39U;
    co_await vlSelfRef.__VtrigSched_h915c4b11__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge bitrev_tb.clk_i)", 
                                                         "sw/bitrev_tb.sv", 
                                                         78);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.bitrev_tb__DOT__valid_i = 1U;
    vlSelfRef.bitrev_tb__DOT__data_i = 0x39U;
    vlSelfRef.bitrev_tb__DOT__unnamedblk2__DOT__i = 0x3aU;
    co_await vlSelfRef.__VtrigSched_h915c4b11__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge bitrev_tb.clk_i)", 
                                                         "sw/bitrev_tb.sv", 
                                                         78);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.bitrev_tb__DOT__valid_i = 1U;
    vlSelfRef.bitrev_tb__DOT__data_i = 0x3aU;
    vlSelfRef.bitrev_tb__DOT__unnamedblk2__DOT__i = 0x3bU;
    co_await vlSelfRef.__VtrigSched_h915c4b11__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge bitrev_tb.clk_i)", 
                                                         "sw/bitrev_tb.sv", 
                                                         78);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.bitrev_tb__DOT__valid_i = 1U;
    vlSelfRef.bitrev_tb__DOT__data_i = 0x3bU;
    vlSelfRef.bitrev_tb__DOT__unnamedblk2__DOT__i = 0x3cU;
    co_await vlSelfRef.__VtrigSched_h915c4b11__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge bitrev_tb.clk_i)", 
                                                         "sw/bitrev_tb.sv", 
                                                         78);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.bitrev_tb__DOT__valid_i = 1U;
    vlSelfRef.bitrev_tb__DOT__data_i = 0x3cU;
    vlSelfRef.bitrev_tb__DOT__unnamedblk2__DOT__i = 0x3dU;
    co_await vlSelfRef.__VtrigSched_h915c4b11__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge bitrev_tb.clk_i)", 
                                                         "sw/bitrev_tb.sv", 
                                                         78);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.bitrev_tb__DOT__valid_i = 1U;
    vlSelfRef.bitrev_tb__DOT__data_i = 0x3dU;
    vlSelfRef.bitrev_tb__DOT__unnamedblk2__DOT__i = 0x3eU;
    co_await vlSelfRef.__VtrigSched_h915c4b11__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge bitrev_tb.clk_i)", 
                                                         "sw/bitrev_tb.sv", 
                                                         78);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.bitrev_tb__DOT__valid_i = 1U;
    vlSelfRef.bitrev_tb__DOT__data_i = 0x3eU;
    vlSelfRef.bitrev_tb__DOT__unnamedblk2__DOT__i = 0x3fU;
    co_await vlSelfRef.__VtrigSched_h915c4b11__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge bitrev_tb.clk_i)", 
                                                         "sw/bitrev_tb.sv", 
                                                         78);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.bitrev_tb__DOT__valid_i = 1U;
    vlSelfRef.bitrev_tb__DOT__data_i = 0x3fU;
    vlSelfRef.bitrev_tb__DOT__unnamedblk2__DOT__i = 0x40U;
    co_await vlSelfRef.__VtrigSched_h915c4b11__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge bitrev_tb.clk_i)", 
                                                         "sw/bitrev_tb.sv", 
                                                         86);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.bitrev_tb__DOT__valid_i = 0U;
    vlSelfRef.bitrev_tb__DOT__unnamedblk3__DOT__i = 0U;
    while ((0x40U > vlSelfRef.bitrev_tb__DOT__unnamedblk3__DOT__i)) {
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
        if ((0x3fU == vlSelfRef.bitrev_tb__DOT__unnamedblk3__DOT__i)) {
            vlSelfRef.bitrev_tb__DOT__output_end_cycle 
                = vlSelfRef.bitrev_tb__DOT__cycle_count;
        }
        if (VL_UNLIKELY((((0x3fU & vlSelfRef.bitrev_tb__DOT__dut__DOT__data_q) 
                          != ([&]() {
                                __Vfunc_bitrev_tb__DOT__reverse_bits_k__0__x 
                                    = (0x3fU & vlSelfRef.bitrev_tb__DOT__unnamedblk3__DOT__i);
                                __Vfunc_bitrev_tb__DOT__reverse_bits_k__0__unnamedblk1__DOT__i = 0;
                                vlSelfRef.bitrev_tb__DOT____Vlvbound_h3aee0c48__0 
                                    = (1U & ((IData)(__Vfunc_bitrev_tb__DOT__reverse_bits_k__0__x) 
                                             >> 5U));
                                __Vfunc_bitrev_tb__DOT__reverse_bits_k__0__Vfuncout 
                                    = ((0x3eU & (IData)(__Vfunc_bitrev_tb__DOT__reverse_bits_k__0__Vfuncout)) 
                                       | (IData)(vlSelfRef.bitrev_tb__DOT____Vlvbound_h3aee0c48__0));
                                __Vfunc_bitrev_tb__DOT__reverse_bits_k__0__unnamedblk1__DOT__i = 1U;
                                vlSelfRef.bitrev_tb__DOT____Vlvbound_h3aee0c48__0 
                                    = (1U & ((IData)(__Vfunc_bitrev_tb__DOT__reverse_bits_k__0__x) 
                                             >> 4U));
                                __Vfunc_bitrev_tb__DOT__reverse_bits_k__0__Vfuncout 
                                    = ((0x3dU & (IData)(__Vfunc_bitrev_tb__DOT__reverse_bits_k__0__Vfuncout)) 
                                       | ((IData)(vlSelfRef.bitrev_tb__DOT____Vlvbound_h3aee0c48__0) 
                                          << 1U));
                                __Vfunc_bitrev_tb__DOT__reverse_bits_k__0__unnamedblk1__DOT__i = 2U;
                                vlSelfRef.bitrev_tb__DOT____Vlvbound_h3aee0c48__0 
                                    = (1U & ((IData)(__Vfunc_bitrev_tb__DOT__reverse_bits_k__0__x) 
                                             >> 3U));
                                __Vfunc_bitrev_tb__DOT__reverse_bits_k__0__Vfuncout 
                                    = ((0x3bU & (IData)(__Vfunc_bitrev_tb__DOT__reverse_bits_k__0__Vfuncout)) 
                                       | ((IData)(vlSelfRef.bitrev_tb__DOT____Vlvbound_h3aee0c48__0) 
                                          << 2U));
                                __Vfunc_bitrev_tb__DOT__reverse_bits_k__0__unnamedblk1__DOT__i = 3U;
                                vlSelfRef.bitrev_tb__DOT____Vlvbound_h3aee0c48__0 
                                    = (1U & ((IData)(__Vfunc_bitrev_tb__DOT__reverse_bits_k__0__x) 
                                             >> 2U));
                                __Vfunc_bitrev_tb__DOT__reverse_bits_k__0__Vfuncout 
                                    = ((0x37U & (IData)(__Vfunc_bitrev_tb__DOT__reverse_bits_k__0__Vfuncout)) 
                                       | ((IData)(vlSelfRef.bitrev_tb__DOT____Vlvbound_h3aee0c48__0) 
                                          << 3U));
                                __Vfunc_bitrev_tb__DOT__reverse_bits_k__0__unnamedblk1__DOT__i = 4U;
                                vlSelfRef.bitrev_tb__DOT____Vlvbound_h3aee0c48__0 
                                    = (1U & ((IData)(__Vfunc_bitrev_tb__DOT__reverse_bits_k__0__x) 
                                             >> 1U));
                                __Vfunc_bitrev_tb__DOT__reverse_bits_k__0__Vfuncout 
                                    = ((0x2fU & (IData)(__Vfunc_bitrev_tb__DOT__reverse_bits_k__0__Vfuncout)) 
                                       | ((IData)(vlSelfRef.bitrev_tb__DOT____Vlvbound_h3aee0c48__0) 
                                          << 4U));
                                __Vfunc_bitrev_tb__DOT__reverse_bits_k__0__unnamedblk1__DOT__i = 5U;
                                vlSelfRef.bitrev_tb__DOT____Vlvbound_h3aee0c48__0 
                                    = (1U & (IData)(__Vfunc_bitrev_tb__DOT__reverse_bits_k__0__x));
                                __Vfunc_bitrev_tb__DOT__reverse_bits_k__0__Vfuncout 
                                    = ((0x1fU & (IData)(__Vfunc_bitrev_tb__DOT__reverse_bits_k__0__Vfuncout)) 
                                       | ((IData)(vlSelfRef.bitrev_tb__DOT____Vlvbound_h3aee0c48__0) 
                                          << 5U));
                                __Vfunc_bitrev_tb__DOT__reverse_bits_k__0__unnamedblk1__DOT__i = 6U;
                            }(), (IData)(__Vfunc_bitrev_tb__DOT__reverse_bits_k__0__Vfuncout)))))) {
            VL_WRITEF_NX("Mismatch @%0# : got %0#, exp %0#\n",0,
                         32,vlSelfRef.bitrev_tb__DOT__unnamedblk3__DOT__i,
                         32,vlSelfRef.bitrev_tb__DOT__dut__DOT__data_q,
                         6,([&]() {
                            __Vfunc_bitrev_tb__DOT__reverse_bits_k__1__x 
                                = (0x3fU & vlSelfRef.bitrev_tb__DOT__unnamedblk3__DOT__i);
                            __Vfunc_bitrev_tb__DOT__reverse_bits_k__1__unnamedblk1__DOT__i = 0;
                            vlSelfRef.bitrev_tb__DOT____Vlvbound_h3aee0c48__0 
                                = (1U & ((IData)(__Vfunc_bitrev_tb__DOT__reverse_bits_k__1__x) 
                                         >> 5U));
                            __Vfunc_bitrev_tb__DOT__reverse_bits_k__1__Vfuncout 
                                = ((0x3eU & (IData)(__Vfunc_bitrev_tb__DOT__reverse_bits_k__1__Vfuncout)) 
                                   | (IData)(vlSelfRef.bitrev_tb__DOT____Vlvbound_h3aee0c48__0));
                            __Vfunc_bitrev_tb__DOT__reverse_bits_k__1__unnamedblk1__DOT__i = 1U;
                            vlSelfRef.bitrev_tb__DOT____Vlvbound_h3aee0c48__0 
                                = (1U & ((IData)(__Vfunc_bitrev_tb__DOT__reverse_bits_k__1__x) 
                                         >> 4U));
                            __Vfunc_bitrev_tb__DOT__reverse_bits_k__1__Vfuncout 
                                = ((0x3dU & (IData)(__Vfunc_bitrev_tb__DOT__reverse_bits_k__1__Vfuncout)) 
                                   | ((IData)(vlSelfRef.bitrev_tb__DOT____Vlvbound_h3aee0c48__0) 
                                      << 1U));
                            __Vfunc_bitrev_tb__DOT__reverse_bits_k__1__unnamedblk1__DOT__i = 2U;
                            vlSelfRef.bitrev_tb__DOT____Vlvbound_h3aee0c48__0 
                                = (1U & ((IData)(__Vfunc_bitrev_tb__DOT__reverse_bits_k__1__x) 
                                         >> 3U));
                            __Vfunc_bitrev_tb__DOT__reverse_bits_k__1__Vfuncout 
                                = ((0x3bU & (IData)(__Vfunc_bitrev_tb__DOT__reverse_bits_k__1__Vfuncout)) 
                                   | ((IData)(vlSelfRef.bitrev_tb__DOT____Vlvbound_h3aee0c48__0) 
                                      << 2U));
                            __Vfunc_bitrev_tb__DOT__reverse_bits_k__1__unnamedblk1__DOT__i = 3U;
                            vlSelfRef.bitrev_tb__DOT____Vlvbound_h3aee0c48__0 
                                = (1U & ((IData)(__Vfunc_bitrev_tb__DOT__reverse_bits_k__1__x) 
                                         >> 2U));
                            __Vfunc_bitrev_tb__DOT__reverse_bits_k__1__Vfuncout 
                                = ((0x37U & (IData)(__Vfunc_bitrev_tb__DOT__reverse_bits_k__1__Vfuncout)) 
                                   | ((IData)(vlSelfRef.bitrev_tb__DOT____Vlvbound_h3aee0c48__0) 
                                      << 3U));
                            __Vfunc_bitrev_tb__DOT__reverse_bits_k__1__unnamedblk1__DOT__i = 4U;
                            vlSelfRef.bitrev_tb__DOT____Vlvbound_h3aee0c48__0 
                                = (1U & ((IData)(__Vfunc_bitrev_tb__DOT__reverse_bits_k__1__x) 
                                         >> 1U));
                            __Vfunc_bitrev_tb__DOT__reverse_bits_k__1__Vfuncout 
                                = ((0x2fU & (IData)(__Vfunc_bitrev_tb__DOT__reverse_bits_k__1__Vfuncout)) 
                                   | ((IData)(vlSelfRef.bitrev_tb__DOT____Vlvbound_h3aee0c48__0) 
                                      << 4U));
                            __Vfunc_bitrev_tb__DOT__reverse_bits_k__1__unnamedblk1__DOT__i = 5U;
                            vlSelfRef.bitrev_tb__DOT____Vlvbound_h3aee0c48__0 
                                = (1U & (IData)(__Vfunc_bitrev_tb__DOT__reverse_bits_k__1__x));
                            __Vfunc_bitrev_tb__DOT__reverse_bits_k__1__Vfuncout 
                                = ((0x1fU & (IData)(__Vfunc_bitrev_tb__DOT__reverse_bits_k__1__Vfuncout)) 
                                   | ((IData)(vlSelfRef.bitrev_tb__DOT____Vlvbound_h3aee0c48__0) 
                                      << 5U));
                            __Vfunc_bitrev_tb__DOT__reverse_bits_k__1__unnamedblk1__DOT__i = 6U;
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
        VL_WRITEF_NX("Bit-reversal test PASSED for 64-point frame\n",0);
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
