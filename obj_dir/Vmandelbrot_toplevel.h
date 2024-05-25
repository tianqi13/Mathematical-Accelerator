// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VMANDELBROT_TOPLEVEL_H_
#define _VMANDELBROT_TOPLEVEL_H_  // guard

#include "verilated.h"

//==========

class Vmandelbrot_toplevel__Syms;
class Vmandelbrot_toplevel_VerilatedVcd;


//----------

VL_MODULE(Vmandelbrot_toplevel) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_IN8(enable,0,0);
    VL_IN16(x_size,9,0);
    VL_IN16(y_size,9,0);
    VL_OUT16(RGB_out,14,0);
    VL_OUT16(X,9,0);
    VL_OUT16(Y,9,0);
    VL_IN(Re_axis_width,31,0);
    VL_IN(Im_axis_width,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*0:0*/ mandelbrot_toplevel__DOT__ovf;
    CData/*0:0*/ mandelbrot_toplevel__DOT__q;
    CData/*0:0*/ mandelbrot_toplevel__DOT__q_bar;
    CData/*0:0*/ mandelbrot_toplevel__DOT__ovf_it;
    CData/*0:0*/ mandelbrot_toplevel__DOT__or_out;
    SData/*14:0*/ mandelbrot_toplevel__DOT__counter_out;
    SData/*9:0*/ mandelbrot_toplevel__DOT__Mapper__DOT__X;
    SData/*9:0*/ mandelbrot_toplevel__DOT__Mapper__DOT__Y;
    SData/*14:0*/ mandelbrot_toplevel__DOT__counter_mod__DOT__counter_reg;
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
    SData/*14:0*/ mandelbrot_toplevel__DOT__ram__DOT__ram_array[1048576];
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __Vclklast__TOP__clk;
    CData/*0:0*/ __Vm_traceActivity[3];
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vmandelbrot_toplevel__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vmandelbrot_toplevel);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vmandelbrot_toplevel(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vmandelbrot_toplevel();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vmandelbrot_toplevel__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vmandelbrot_toplevel__Syms* symsp, bool first);
  private:
    static QData _change_request(Vmandelbrot_toplevel__Syms* __restrict vlSymsp);
    static QData _change_request_1(Vmandelbrot_toplevel__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__3(Vmandelbrot_toplevel__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vmandelbrot_toplevel__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vmandelbrot_toplevel__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vmandelbrot_toplevel__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__1(Vmandelbrot_toplevel__Syms* __restrict vlSymsp);
    static void _settle__TOP__2(Vmandelbrot_toplevel__Syms* __restrict vlSymsp) VL_ATTR_COLD;
  private:
    static void traceChgSub0(void* userp, VerilatedVcd* tracep);
    static void traceChgTop0(void* userp, VerilatedVcd* tracep);
    static void traceCleanup(void* userp, VerilatedVcd* /*unused*/);
    static void traceFullSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceFullTop0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitTop(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    void traceRegister(VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
