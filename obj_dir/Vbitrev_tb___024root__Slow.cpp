// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vbitrev_tb.h for the primary calling header

#include "Vbitrev_tb__pch.h"
#include "Vbitrev_tb__Syms.h"
#include "Vbitrev_tb___024root.h"

void Vbitrev_tb___024root___ctor_var_reset(Vbitrev_tb___024root* vlSelf);

Vbitrev_tb___024root::Vbitrev_tb___024root(Vbitrev_tb__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vbitrev_tb___024root___ctor_var_reset(this);
}

void Vbitrev_tb___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vbitrev_tb___024root::~Vbitrev_tb___024root() {
}
