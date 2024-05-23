// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vmandelbrot_toplevel.h for the primary calling header

#ifndef VERILATED_VMANDELBROT_TOPLEVEL___024ROOT_H_
#define VERILATED_VMANDELBROT_TOPLEVEL___024ROOT_H_  // guard

#include "verilated.h"

class Vmandelbrot_toplevel__Syms;

class Vmandelbrot_toplevel___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    CData/*0:0*/ mandelbrot_toplevel__DOT__or_out;
    VL_IN8(rst,0,0);
    VL_IN8(enable,0,0);
    CData/*0:0*/ mandelbrot_toplevel__DOT__ovf;
    CData/*0:0*/ mandelbrot_toplevel__DOT__q;
    CData/*0:0*/ mandelbrot_toplevel__DOT__q_bar;
    CData/*0:0*/ mandelbrot_toplevel__DOT__ovf_it;
    CData/*0:0*/ mandelbrot_toplevel__DOT____Vcellinp__Mapper__en;
    CData/*0:0*/ mandelbrot_toplevel__DOT__DIVERGE__DOT__GENERATOR__DOT__X;
    CData/*0:0*/ mandelbrot_toplevel__DOT__DIVERGE__DOT__GENERATOR__DOT__delta;
    CData/*0:0*/ __VinpClk__TOP__mandelbrot_toplevel__DOT__or_out;
    CData/*0:0*/ __Vclklast__TOP__clk;
    CData/*0:0*/ __Vclklast__TOP____VinpClk__TOP__mandelbrot_toplevel__DOT__or_out;
    CData/*0:0*/ __Vchglast__TOP__mandelbrot_toplevel__DOT__or_out;
    VL_IN16(x_size,9,0);
    VL_IN16(y_size,9,0);
    VL_OUT16(RGB_out,14,0);
    VL_OUT16(X,9,0);
    VL_OUT16(Y,9,0);
    SData/*14:0*/ mandelbrot_toplevel__DOT__out;
    SData/*9:0*/ mandelbrot_toplevel__DOT____Vcellout__addr_counter__Y;
    SData/*9:0*/ mandelbrot_toplevel__DOT____Vcellout__addr_counter__X;
    SData/*9:0*/ mandelbrot_toplevel__DOT__Mapper__DOT__X;
    SData/*9:0*/ mandelbrot_toplevel__DOT__Mapper__DOT__Y;
    SData/*14:0*/ mandelbrot_toplevel__DOT__counter_mod__DOT__counter_reg;
    SData/*14:0*/ __Vdly__mandelbrot_toplevel__DOT__counter_mod__DOT__counter_reg;
    VL_IN(Re_axis_width,31,0);
    VL_IN(Im_axis_width,31,0);
    IData/*31:0*/ mandelbrot_toplevel__DOT__x_internal;
    IData/*31:0*/ mandelbrot_toplevel__DOT__y_internal;
    IData/*31:0*/ mandelbrot_toplevel__DOT__real_internal;
    IData/*19:0*/ mandelbrot_toplevel__DOT__rd_addr;
    IData/*31:0*/ mandelbrot_toplevel__DOT__DIVERGE__DOT__A;
    IData/*31:0*/ mandelbrot_toplevel__DOT__DIVERGE__DOT__B;
    IData/*31:0*/ mandelbrot_toplevel__DOT__DIVERGE__DOT__twoab;
    IData/*31:0*/ mandelbrot_toplevel__DOT__DIVERGE__DOT__s1;
    IData/*31:0*/ mandelbrot_toplevel__DOT__DIVERGE__DOT__s2;
    IData/*31:0*/ mandelbrot_toplevel__DOT__DIVERGE__DOT__muxout1;
    IData/*31:0*/ mandelbrot_toplevel__DOT__DIVERGE__DOT__muxout2;
    IData/*30:0*/ mandelbrot_toplevel__DOT__DIVERGE__DOT__GENERATOR__DOT__ab_truncated;
    VlUnpacked<SData/*14:0*/, 1048576> mandelbrot_toplevel__DOT__ram__DOT__ram_array;
    VlUnpacked<CData/*0:0*/, 3> __Vm_traceActivity;

    // INTERNAL VARIABLES
    Vmandelbrot_toplevel__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vmandelbrot_toplevel___024root(Vmandelbrot_toplevel__Syms* symsp, const char* name);
    ~Vmandelbrot_toplevel___024root();
    VL_UNCOPYABLE(Vmandelbrot_toplevel___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
