// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop_level.h for the primary calling header

#ifndef VERILATED_VTOP_LEVEL___024ROOT_H_
#define VERILATED_VTOP_LEVEL___024ROOT_H_  // guard

#include "verilated.h"


class Vtop_level__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop_level___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_IN8(enable,0,0);
    CData/*0:0*/ top_level__DOT__ovf;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__rst__0;
    CData/*0:0*/ __VactContinue;
    VL_OUT16(RGB_out,14,0);
    SData/*14:0*/ top_level__DOT__count_out;
    SData/*9:0*/ top_level__DOT__x;
    SData/*9:0*/ top_level__DOT__y;
    SData/*9:0*/ __Vdly__top_level__DOT__x;
    SData/*9:0*/ __Vdly__top_level__DOT__y;
    IData/*19:0*/ top_level__DOT__rd_addr;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<SData/*14:0*/, 1048576> top_level__DOT__ram__DOT__ram_array;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtop_level__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop_level___024root(Vtop_level__Syms* symsp, const char* v__name);
    ~Vtop_level___024root();
    VL_UNCOPYABLE(Vtop_level___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
