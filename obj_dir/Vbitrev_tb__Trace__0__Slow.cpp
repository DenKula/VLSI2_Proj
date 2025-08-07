// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vbitrev_tb__Syms.h"


VL_ATTR_COLD void Vbitrev_tb___024root__trace_init_sub__TOP__0(Vbitrev_tb___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitrev_tb___024root__trace_init_sub__TOP__0\n"); );
    Vbitrev_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("bitrev_tb", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+150,0,"K",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+151,0,"N",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+152,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+148,0,"clk_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"rst_ni",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"valid_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+3,0,"data_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+153,0,"ready_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+11,0,"valid_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+12,0,"data_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+4,0,"ready_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+149,0,"cycle_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+5,0,"input_start_cycle",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+6,0,"output_start_cycle",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+7,0,"output_end_cycle",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+8,0,"err_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->pushPrefix("dut", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+154,0,"K",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+155,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBit(c+148,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"valid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+3,0,"data_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+153,0,"ready_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+11,0,"valid_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+12,0,"data_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+4,0,"ready_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+156,0,"N",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->pushPrefix("sram_a", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 64; ++i) {
        tracep->declBus(c+13+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("sram_b", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 64; ++i) {
        tracep->declBus(c+77+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->declBit(c+141,0,"bank_sel_wr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+142,0,"bank_sel_rd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+143,0,"wr_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+144,0,"rd_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+145,0,"wr_cnt_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+154,0,"bit_reverse__Vstatic__i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+12,0,"data_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+146,0,"rev_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+147,0,"data_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+9,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk3", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+10,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vbitrev_tb___024root__trace_init_top(Vbitrev_tb___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitrev_tb___024root__trace_init_top\n"); );
    Vbitrev_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vbitrev_tb___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vbitrev_tb___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vbitrev_tb___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vbitrev_tb___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vbitrev_tb___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vbitrev_tb___024root__trace_register(Vbitrev_tb___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitrev_tb___024root__trace_register\n"); );
    Vbitrev_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vbitrev_tb___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vbitrev_tb___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vbitrev_tb___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vbitrev_tb___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vbitrev_tb___024root__trace_const_0_sub_0(Vbitrev_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vbitrev_tb___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitrev_tb___024root__trace_const_0\n"); );
    // Init
    Vbitrev_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vbitrev_tb___024root*>(voidSelf);
    Vbitrev_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vbitrev_tb___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vbitrev_tb___024root__trace_const_0_sub_0(Vbitrev_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitrev_tb___024root__trace_const_0_sub_0\n"); );
    Vbitrev_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+150,(6U),32);
    bufp->fullIData(oldp+151,(0x40U),32);
    bufp->fullIData(oldp+152,(0x20U),32);
    bufp->fullBit(oldp+153,(1U));
    bufp->fullIData(oldp+154,(6U),32);
    bufp->fullIData(oldp+155,(0x20U),32);
    bufp->fullIData(oldp+156,(0x40U),32);
}

VL_ATTR_COLD void Vbitrev_tb___024root__trace_full_0_sub_0(Vbitrev_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vbitrev_tb___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitrev_tb___024root__trace_full_0\n"); );
    // Init
    Vbitrev_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vbitrev_tb___024root*>(voidSelf);
    Vbitrev_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vbitrev_tb___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vbitrev_tb___024root__trace_full_0_sub_0(Vbitrev_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitrev_tb___024root__trace_full_0_sub_0\n"); );
    Vbitrev_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelfRef.bitrev_tb__DOT__rst_ni));
    bufp->fullBit(oldp+2,(vlSelfRef.bitrev_tb__DOT__valid_i));
    bufp->fullIData(oldp+3,(vlSelfRef.bitrev_tb__DOT__data_i),32);
    bufp->fullBit(oldp+4,(vlSelfRef.bitrev_tb__DOT__ready_i));
    bufp->fullIData(oldp+5,(vlSelfRef.bitrev_tb__DOT__input_start_cycle),32);
    bufp->fullIData(oldp+6,(vlSelfRef.bitrev_tb__DOT__output_start_cycle),32);
    bufp->fullIData(oldp+7,(vlSelfRef.bitrev_tb__DOT__output_end_cycle),32);
    bufp->fullIData(oldp+8,(vlSelfRef.bitrev_tb__DOT__err_cnt),32);
    bufp->fullIData(oldp+9,(vlSelfRef.bitrev_tb__DOT__unnamedblk2__DOT__i),32);
    bufp->fullIData(oldp+10,(vlSelfRef.bitrev_tb__DOT__unnamedblk3__DOT__i),32);
    bufp->fullBit(oldp+11,(vlSelfRef.bitrev_tb__DOT__valid_o));
    bufp->fullIData(oldp+12,(vlSelfRef.bitrev_tb__DOT__dut__DOT__data_q),32);
    bufp->fullIData(oldp+13,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[0]),32);
    bufp->fullIData(oldp+14,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[1]),32);
    bufp->fullIData(oldp+15,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[2]),32);
    bufp->fullIData(oldp+16,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[3]),32);
    bufp->fullIData(oldp+17,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[4]),32);
    bufp->fullIData(oldp+18,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[5]),32);
    bufp->fullIData(oldp+19,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[6]),32);
    bufp->fullIData(oldp+20,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[7]),32);
    bufp->fullIData(oldp+21,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[8]),32);
    bufp->fullIData(oldp+22,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[9]),32);
    bufp->fullIData(oldp+23,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[10]),32);
    bufp->fullIData(oldp+24,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[11]),32);
    bufp->fullIData(oldp+25,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[12]),32);
    bufp->fullIData(oldp+26,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[13]),32);
    bufp->fullIData(oldp+27,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[14]),32);
    bufp->fullIData(oldp+28,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[15]),32);
    bufp->fullIData(oldp+29,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[16]),32);
    bufp->fullIData(oldp+30,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[17]),32);
    bufp->fullIData(oldp+31,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[18]),32);
    bufp->fullIData(oldp+32,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[19]),32);
    bufp->fullIData(oldp+33,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[20]),32);
    bufp->fullIData(oldp+34,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[21]),32);
    bufp->fullIData(oldp+35,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[22]),32);
    bufp->fullIData(oldp+36,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[23]),32);
    bufp->fullIData(oldp+37,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[24]),32);
    bufp->fullIData(oldp+38,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[25]),32);
    bufp->fullIData(oldp+39,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[26]),32);
    bufp->fullIData(oldp+40,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[27]),32);
    bufp->fullIData(oldp+41,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[28]),32);
    bufp->fullIData(oldp+42,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[29]),32);
    bufp->fullIData(oldp+43,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[30]),32);
    bufp->fullIData(oldp+44,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[31]),32);
    bufp->fullIData(oldp+45,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[32]),32);
    bufp->fullIData(oldp+46,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[33]),32);
    bufp->fullIData(oldp+47,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[34]),32);
    bufp->fullIData(oldp+48,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[35]),32);
    bufp->fullIData(oldp+49,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[36]),32);
    bufp->fullIData(oldp+50,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[37]),32);
    bufp->fullIData(oldp+51,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[38]),32);
    bufp->fullIData(oldp+52,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[39]),32);
    bufp->fullIData(oldp+53,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[40]),32);
    bufp->fullIData(oldp+54,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[41]),32);
    bufp->fullIData(oldp+55,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[42]),32);
    bufp->fullIData(oldp+56,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[43]),32);
    bufp->fullIData(oldp+57,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[44]),32);
    bufp->fullIData(oldp+58,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[45]),32);
    bufp->fullIData(oldp+59,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[46]),32);
    bufp->fullIData(oldp+60,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[47]),32);
    bufp->fullIData(oldp+61,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[48]),32);
    bufp->fullIData(oldp+62,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[49]),32);
    bufp->fullIData(oldp+63,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[50]),32);
    bufp->fullIData(oldp+64,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[51]),32);
    bufp->fullIData(oldp+65,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[52]),32);
    bufp->fullIData(oldp+66,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[53]),32);
    bufp->fullIData(oldp+67,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[54]),32);
    bufp->fullIData(oldp+68,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[55]),32);
    bufp->fullIData(oldp+69,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[56]),32);
    bufp->fullIData(oldp+70,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[57]),32);
    bufp->fullIData(oldp+71,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[58]),32);
    bufp->fullIData(oldp+72,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[59]),32);
    bufp->fullIData(oldp+73,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[60]),32);
    bufp->fullIData(oldp+74,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[61]),32);
    bufp->fullIData(oldp+75,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[62]),32);
    bufp->fullIData(oldp+76,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a[63]),32);
    bufp->fullIData(oldp+77,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[0]),32);
    bufp->fullIData(oldp+78,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[1]),32);
    bufp->fullIData(oldp+79,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[2]),32);
    bufp->fullIData(oldp+80,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[3]),32);
    bufp->fullIData(oldp+81,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[4]),32);
    bufp->fullIData(oldp+82,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[5]),32);
    bufp->fullIData(oldp+83,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[6]),32);
    bufp->fullIData(oldp+84,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[7]),32);
    bufp->fullIData(oldp+85,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[8]),32);
    bufp->fullIData(oldp+86,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[9]),32);
    bufp->fullIData(oldp+87,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[10]),32);
    bufp->fullIData(oldp+88,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[11]),32);
    bufp->fullIData(oldp+89,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[12]),32);
    bufp->fullIData(oldp+90,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[13]),32);
    bufp->fullIData(oldp+91,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[14]),32);
    bufp->fullIData(oldp+92,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[15]),32);
    bufp->fullIData(oldp+93,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[16]),32);
    bufp->fullIData(oldp+94,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[17]),32);
    bufp->fullIData(oldp+95,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[18]),32);
    bufp->fullIData(oldp+96,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[19]),32);
    bufp->fullIData(oldp+97,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[20]),32);
    bufp->fullIData(oldp+98,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[21]),32);
    bufp->fullIData(oldp+99,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[22]),32);
    bufp->fullIData(oldp+100,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[23]),32);
    bufp->fullIData(oldp+101,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[24]),32);
    bufp->fullIData(oldp+102,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[25]),32);
    bufp->fullIData(oldp+103,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[26]),32);
    bufp->fullIData(oldp+104,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[27]),32);
    bufp->fullIData(oldp+105,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[28]),32);
    bufp->fullIData(oldp+106,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[29]),32);
    bufp->fullIData(oldp+107,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[30]),32);
    bufp->fullIData(oldp+108,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[31]),32);
    bufp->fullIData(oldp+109,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[32]),32);
    bufp->fullIData(oldp+110,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[33]),32);
    bufp->fullIData(oldp+111,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[34]),32);
    bufp->fullIData(oldp+112,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[35]),32);
    bufp->fullIData(oldp+113,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[36]),32);
    bufp->fullIData(oldp+114,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[37]),32);
    bufp->fullIData(oldp+115,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[38]),32);
    bufp->fullIData(oldp+116,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[39]),32);
    bufp->fullIData(oldp+117,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[40]),32);
    bufp->fullIData(oldp+118,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[41]),32);
    bufp->fullIData(oldp+119,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[42]),32);
    bufp->fullIData(oldp+120,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[43]),32);
    bufp->fullIData(oldp+121,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[44]),32);
    bufp->fullIData(oldp+122,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[45]),32);
    bufp->fullIData(oldp+123,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[46]),32);
    bufp->fullIData(oldp+124,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[47]),32);
    bufp->fullIData(oldp+125,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[48]),32);
    bufp->fullIData(oldp+126,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[49]),32);
    bufp->fullIData(oldp+127,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[50]),32);
    bufp->fullIData(oldp+128,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[51]),32);
    bufp->fullIData(oldp+129,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[52]),32);
    bufp->fullIData(oldp+130,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[53]),32);
    bufp->fullIData(oldp+131,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[54]),32);
    bufp->fullIData(oldp+132,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[55]),32);
    bufp->fullIData(oldp+133,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[56]),32);
    bufp->fullIData(oldp+134,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[57]),32);
    bufp->fullIData(oldp+135,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[58]),32);
    bufp->fullIData(oldp+136,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[59]),32);
    bufp->fullIData(oldp+137,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[60]),32);
    bufp->fullIData(oldp+138,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[61]),32);
    bufp->fullIData(oldp+139,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[62]),32);
    bufp->fullIData(oldp+140,(vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b[63]),32);
    bufp->fullBit(oldp+141,(vlSelfRef.bitrev_tb__DOT__dut__DOT__bank_sel_wr));
    bufp->fullBit(oldp+142,(vlSelfRef.bitrev_tb__DOT__dut__DOT__bank_sel_rd));
    bufp->fullCData(oldp+143,(vlSelfRef.bitrev_tb__DOT__dut__DOT__wr_cnt),6);
    bufp->fullCData(oldp+144,(vlSelfRef.bitrev_tb__DOT__dut__DOT__rd_cnt),6);
    bufp->fullCData(oldp+145,((0x3fU & ((IData)(1U) 
                                        + (IData)(vlSelfRef.bitrev_tb__DOT__dut__DOT__wr_cnt)))),6);
    bufp->fullCData(oldp+146,(vlSelfRef.bitrev_tb__DOT__dut__DOT__rev_addr),6);
    bufp->fullIData(oldp+147,(((IData)(vlSelfRef.bitrev_tb__DOT__dut__DOT__bank_sel_rd)
                                ? vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_b
                               [vlSelfRef.bitrev_tb__DOT__dut__DOT__rev_addr]
                                : vlSelfRef.bitrev_tb__DOT__dut__DOT__sram_a
                               [vlSelfRef.bitrev_tb__DOT__dut__DOT__rev_addr])),32);
    bufp->fullBit(oldp+148,(vlSelfRef.bitrev_tb__DOT__clk_i));
    bufp->fullIData(oldp+149,(vlSelfRef.bitrev_tb__DOT__cycle_count),32);
}
