// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vbitrev_tb__Syms.h"


void Vbitrev_tb___024root__trace_chg_0_sub_0(Vbitrev_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vbitrev_tb___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitrev_tb___024root__trace_chg_0\n"); );
    // Init
    Vbitrev_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vbitrev_tb___024root*>(voidSelf);
    Vbitrev_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vbitrev_tb___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vbitrev_tb___024root__trace_chg_0_sub_0(Vbitrev_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitrev_tb___024root__trace_chg_0_sub_0\n"); );
    Vbitrev_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[1U] 
                      | vlSelfRef.__Vm_traceActivity
                      [2U])))) {
        bufp->chgBit(oldp+0,(vlSelfRef.bitrev_tb__DOT__rst_ni));
        bufp->chgBit(oldp+1,(vlSelfRef.bitrev_tb__DOT__valid_i));
        bufp->chgIData(oldp+2,(vlSelfRef.bitrev_tb__DOT__data_i),32);
        bufp->chgBit(oldp+3,(vlSelfRef.bitrev_tb__DOT__ready_i));
        bufp->chgIData(oldp+4,(vlSelfRef.bitrev_tb__DOT__input_start_cycle),32);
        bufp->chgIData(oldp+5,(vlSelfRef.bitrev_tb__DOT__output_start_cycle),32);
        bufp->chgIData(oldp+6,(vlSelfRef.bitrev_tb__DOT__output_end_cycle),32);
        bufp->chgIData(oldp+7,(vlSelfRef.bitrev_tb__DOT__err_cnt),32);
        bufp->chgIData(oldp+8,(vlSelfRef.bitrev_tb__DOT__unnamedblk2__DOT__i),32);
        bufp->chgIData(oldp+9,(vlSelfRef.bitrev_tb__DOT__unnamedblk3__DOT__i),32);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[3U]))) {
        bufp->chgBit(oldp+10,(vlSelfRef.bitrev_tb__DOT__valid_o));
        bufp->chgIData(oldp+11,(vlSelfRef.bitrev_tb__DOT__dut__DOT__data_q),32);
        bufp->chgIData(oldp+12,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[0]),32);
        bufp->chgIData(oldp+13,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[1]),32);
        bufp->chgIData(oldp+14,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[2]),32);
        bufp->chgIData(oldp+15,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[3]),32);
        bufp->chgIData(oldp+16,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[4]),32);
        bufp->chgIData(oldp+17,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[5]),32);
        bufp->chgIData(oldp+18,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[6]),32);
        bufp->chgIData(oldp+19,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[7]),32);
        bufp->chgIData(oldp+20,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[8]),32);
        bufp->chgIData(oldp+21,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[9]),32);
        bufp->chgIData(oldp+22,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[10]),32);
        bufp->chgIData(oldp+23,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[11]),32);
        bufp->chgIData(oldp+24,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[12]),32);
        bufp->chgIData(oldp+25,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[13]),32);
        bufp->chgIData(oldp+26,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[14]),32);
        bufp->chgIData(oldp+27,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[15]),32);
        bufp->chgIData(oldp+28,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[16]),32);
        bufp->chgIData(oldp+29,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[17]),32);
        bufp->chgIData(oldp+30,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[18]),32);
        bufp->chgIData(oldp+31,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[19]),32);
        bufp->chgIData(oldp+32,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[20]),32);
        bufp->chgIData(oldp+33,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[21]),32);
        bufp->chgIData(oldp+34,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[22]),32);
        bufp->chgIData(oldp+35,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[23]),32);
        bufp->chgIData(oldp+36,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[24]),32);
        bufp->chgIData(oldp+37,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[25]),32);
        bufp->chgIData(oldp+38,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[26]),32);
        bufp->chgIData(oldp+39,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[27]),32);
        bufp->chgIData(oldp+40,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[28]),32);
        bufp->chgIData(oldp+41,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[29]),32);
        bufp->chgIData(oldp+42,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[30]),32);
        bufp->chgIData(oldp+43,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[31]),32);
        bufp->chgIData(oldp+44,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[32]),32);
        bufp->chgIData(oldp+45,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[33]),32);
        bufp->chgIData(oldp+46,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[34]),32);
        bufp->chgIData(oldp+47,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[35]),32);
        bufp->chgIData(oldp+48,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[36]),32);
        bufp->chgIData(oldp+49,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[37]),32);
        bufp->chgIData(oldp+50,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[38]),32);
        bufp->chgIData(oldp+51,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[39]),32);
        bufp->chgIData(oldp+52,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[40]),32);
        bufp->chgIData(oldp+53,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[41]),32);
        bufp->chgIData(oldp+54,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[42]),32);
        bufp->chgIData(oldp+55,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[43]),32);
        bufp->chgIData(oldp+56,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[44]),32);
        bufp->chgIData(oldp+57,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[45]),32);
        bufp->chgIData(oldp+58,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[46]),32);
        bufp->chgIData(oldp+59,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[47]),32);
        bufp->chgIData(oldp+60,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[48]),32);
        bufp->chgIData(oldp+61,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[49]),32);
        bufp->chgIData(oldp+62,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[50]),32);
        bufp->chgIData(oldp+63,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[51]),32);
        bufp->chgIData(oldp+64,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[52]),32);
        bufp->chgIData(oldp+65,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[53]),32);
        bufp->chgIData(oldp+66,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[54]),32);
        bufp->chgIData(oldp+67,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[55]),32);
        bufp->chgIData(oldp+68,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[56]),32);
        bufp->chgIData(oldp+69,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[57]),32);
        bufp->chgIData(oldp+70,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[58]),32);
        bufp->chgIData(oldp+71,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[59]),32);
        bufp->chgIData(oldp+72,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[60]),32);
        bufp->chgIData(oldp+73,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[61]),32);
        bufp->chgIData(oldp+74,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[62]),32);
        bufp->chgIData(oldp+75,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[63]),32);
        bufp->chgIData(oldp+76,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[0]),32);
        bufp->chgIData(oldp+77,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[1]),32);
        bufp->chgIData(oldp+78,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[2]),32);
        bufp->chgIData(oldp+79,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[3]),32);
        bufp->chgIData(oldp+80,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[4]),32);
        bufp->chgIData(oldp+81,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[5]),32);
        bufp->chgIData(oldp+82,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[6]),32);
        bufp->chgIData(oldp+83,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[7]),32);
        bufp->chgIData(oldp+84,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[8]),32);
        bufp->chgIData(oldp+85,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[9]),32);
        bufp->chgIData(oldp+86,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[10]),32);
        bufp->chgIData(oldp+87,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[11]),32);
        bufp->chgIData(oldp+88,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[12]),32);
        bufp->chgIData(oldp+89,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[13]),32);
        bufp->chgIData(oldp+90,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[14]),32);
        bufp->chgIData(oldp+91,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[15]),32);
        bufp->chgIData(oldp+92,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[16]),32);
        bufp->chgIData(oldp+93,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[17]),32);
        bufp->chgIData(oldp+94,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[18]),32);
        bufp->chgIData(oldp+95,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[19]),32);
        bufp->chgIData(oldp+96,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[20]),32);
        bufp->chgIData(oldp+97,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[21]),32);
        bufp->chgIData(oldp+98,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[22]),32);
        bufp->chgIData(oldp+99,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[23]),32);
        bufp->chgIData(oldp+100,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[24]),32);
        bufp->chgIData(oldp+101,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[25]),32);
        bufp->chgIData(oldp+102,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[26]),32);
        bufp->chgIData(oldp+103,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[27]),32);
        bufp->chgIData(oldp+104,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[28]),32);
        bufp->chgIData(oldp+105,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[29]),32);
        bufp->chgIData(oldp+106,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[30]),32);
        bufp->chgIData(oldp+107,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[31]),32);
        bufp->chgIData(oldp+108,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[32]),32);
        bufp->chgIData(oldp+109,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[33]),32);
        bufp->chgIData(oldp+110,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[34]),32);
        bufp->chgIData(oldp+111,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[35]),32);
        bufp->chgIData(oldp+112,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[36]),32);
        bufp->chgIData(oldp+113,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[37]),32);
        bufp->chgIData(oldp+114,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[38]),32);
        bufp->chgIData(oldp+115,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[39]),32);
        bufp->chgIData(oldp+116,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[40]),32);
        bufp->chgIData(oldp+117,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[41]),32);
        bufp->chgIData(oldp+118,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[42]),32);
        bufp->chgIData(oldp+119,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[43]),32);
        bufp->chgIData(oldp+120,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[44]),32);
        bufp->chgIData(oldp+121,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[45]),32);
        bufp->chgIData(oldp+122,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[46]),32);
        bufp->chgIData(oldp+123,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[47]),32);
        bufp->chgIData(oldp+124,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[48]),32);
        bufp->chgIData(oldp+125,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[49]),32);
        bufp->chgIData(oldp+126,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[50]),32);
        bufp->chgIData(oldp+127,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[51]),32);
        bufp->chgIData(oldp+128,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[52]),32);
        bufp->chgIData(oldp+129,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[53]),32);
        bufp->chgIData(oldp+130,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[54]),32);
        bufp->chgIData(oldp+131,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[55]),32);
        bufp->chgIData(oldp+132,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[56]),32);
        bufp->chgIData(oldp+133,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[57]),32);
        bufp->chgIData(oldp+134,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[58]),32);
        bufp->chgIData(oldp+135,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[59]),32);
        bufp->chgIData(oldp+136,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[60]),32);
        bufp->chgIData(oldp+137,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[61]),32);
        bufp->chgIData(oldp+138,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[62]),32);
        bufp->chgIData(oldp+139,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[63]),32);
        bufp->chgBit(oldp+140,(vlSelfRef.bitrev_tb__DOT__dut__DOT__bank_sel_wr));
        bufp->chgBit(oldp+141,(vlSelfRef.bitrev_tb__DOT__dut__DOT__bank_sel_rd));
        bufp->chgCData(oldp+142,(vlSelfRef.bitrev_tb__DOT__dut__DOT__wr_cnt),6);
        bufp->chgCData(oldp+143,(vlSelfRef.bitrev_tb__DOT__dut__DOT__rd_cnt),6);
        bufp->chgCData(oldp+144,((0x3fU & ((IData)(1U) 
                                           + (IData)(vlSelfRef.bitrev_tb__DOT__dut__DOT__wr_cnt)))),6);
        bufp->chgCData(oldp+145,(vlSelfRef.bitrev_tb__DOT__dut__DOT__rev_addr),6);
        bufp->chgIData(oldp+146,(((IData)(vlSelfRef.bitrev_tb__DOT__dut__DOT__bank_sel_rd)
                                   ? vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b
                                  [vlSelfRef.bitrev_tb__DOT__dut__DOT__rev_addr]
                                   : vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a
                                  [vlSelfRef.bitrev_tb__DOT__dut__DOT__rev_addr])),32);
    }
    bufp->chgBit(oldp+147,(vlSelfRef.bitrev_tb__DOT__clk_i));
    bufp->chgIData(oldp+148,(vlSelfRef.bitrev_tb__DOT__cycle_count),32);
}

void Vbitrev_tb___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitrev_tb___024root__trace_cleanup\n"); );
    // Init
    Vbitrev_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vbitrev_tb___024root*>(voidSelf);
    Vbitrev_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
}
