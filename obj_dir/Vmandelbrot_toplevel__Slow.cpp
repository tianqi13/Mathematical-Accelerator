// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmandelbrot_toplevel.h for the primary calling header

#include "Vmandelbrot_toplevel.h"
#include "Vmandelbrot_toplevel__Syms.h"

//==========

VL_CTOR_IMP(Vmandelbrot_toplevel) {
    Vmandelbrot_toplevel__Syms* __restrict vlSymsp = __VlSymsp = new Vmandelbrot_toplevel__Syms(this, name());
    Vmandelbrot_toplevel* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vmandelbrot_toplevel::__Vconfigure(Vmandelbrot_toplevel__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vmandelbrot_toplevel::~Vmandelbrot_toplevel() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vmandelbrot_toplevel::_settle__TOP__2(Vmandelbrot_toplevel__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmandelbrot_toplevel::_settle__TOP__2\n"); );
    Vmandelbrot_toplevel* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__GENERATOR__DOT__ab_truncated 
        = (0x7fffffffU & (IData)((((QData)((IData)(vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__A)) 
                                   * (QData)((IData)(vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__B))) 
                                  >> 0x15U)));
    vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__twoab 
        = (vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__GENERATOR__DOT__ab_truncated 
           << 1U);
    vlTOPp->mandelbrot_toplevel__DOT__real_internal 
        = ((IData)((((QData)((IData)(((IData)(vlTOPp->mandelbrot_toplevel__DOT__Mapper__DOT__X) 
                                      << 0x15U))) * (QData)((IData)(
                                                                    VL_DIV_III(32, vlTOPp->Re_axis_width, (IData)(vlTOPp->x_size))))) 
                    >> 0x15U)) + vlTOPp->Re_axis_width);
    vlTOPp->mandelbrot_toplevel__DOT__or_out = ((0x800000U 
                                                 < vlTOPp->mandelbrot_toplevel__DOT__real_internal) 
                                                | (IData)(vlTOPp->mandelbrot_toplevel__DOT__ovf_it));
    vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__s1 
        = (vlTOPp->mandelbrot_toplevel__DOT__real_internal 
           + ((IData)((((QData)((IData)(vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__A)) 
                        * (QData)((IData)(vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__A))) 
                       >> 0x15U)) - (IData)((((QData)((IData)(vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__B)) 
                                              * (QData)((IData)(vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__B))) 
                                             >> 0x15U))));
    vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__muxout1 
        = ((IData)(vlTOPp->mandelbrot_toplevel__DOT__or_out)
            ? 0U : vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__s1);
    vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__s2 
        = (vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__twoab 
           + ((IData)((((QData)((IData)(((IData)(vlTOPp->mandelbrot_toplevel__DOT__Mapper__DOT__Y) 
                                         << 0x15U))) 
                        * (QData)((IData)(VL_DIV_III(32, vlTOPp->Im_axis_width, (IData)(vlTOPp->y_size))))) 
                       >> 0x15U)) + vlTOPp->Im_axis_width));
    vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__muxout2 
        = ((IData)(vlTOPp->mandelbrot_toplevel__DOT__or_out)
            ? 0U : vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__s2);
}

void Vmandelbrot_toplevel::_eval_initial(Vmandelbrot_toplevel__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmandelbrot_toplevel::_eval_initial\n"); );
    Vmandelbrot_toplevel* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

void Vmandelbrot_toplevel::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmandelbrot_toplevel::final\n"); );
    // Variables
    Vmandelbrot_toplevel__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vmandelbrot_toplevel* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vmandelbrot_toplevel::_eval_settle(Vmandelbrot_toplevel__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmandelbrot_toplevel::_eval_settle\n"); );
    Vmandelbrot_toplevel* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
    vlTOPp->__Vm_traceActivity[2U] = 1U;
    vlTOPp->__Vm_traceActivity[1U] = 1U;
    vlTOPp->__Vm_traceActivity[0U] = 1U;
}

void Vmandelbrot_toplevel::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmandelbrot_toplevel::_ctor_var_reset\n"); );
    // Body
    rst = VL_RAND_RESET_I(1);
    clk = VL_RAND_RESET_I(1);
    enable = VL_RAND_RESET_I(1);
    x_size = VL_RAND_RESET_I(10);
    y_size = VL_RAND_RESET_I(10);
    Re_axis_width = VL_RAND_RESET_I(32);
    Im_axis_width = VL_RAND_RESET_I(32);
    RGB_out = VL_RAND_RESET_I(15);
    X = VL_RAND_RESET_I(10);
    Y = VL_RAND_RESET_I(10);
    mandelbrot_toplevel__DOT__ovf = VL_RAND_RESET_I(1);
    mandelbrot_toplevel__DOT__real_internal = VL_RAND_RESET_I(32);
    mandelbrot_toplevel__DOT__q = VL_RAND_RESET_I(1);
    mandelbrot_toplevel__DOT__q_bar = VL_RAND_RESET_I(1);
    mandelbrot_toplevel__DOT__counter_out = VL_RAND_RESET_I(15);
    mandelbrot_toplevel__DOT__ovf_it = VL_RAND_RESET_I(1);
    mandelbrot_toplevel__DOT__or_out = VL_RAND_RESET_I(1);
    mandelbrot_toplevel__DOT__rd_addr = VL_RAND_RESET_I(20);
    mandelbrot_toplevel__DOT__Mapper__DOT__X = VL_RAND_RESET_I(10);
    mandelbrot_toplevel__DOT__Mapper__DOT__Y = VL_RAND_RESET_I(10);
    mandelbrot_toplevel__DOT__DIVERGE__DOT__A = VL_RAND_RESET_I(32);
    mandelbrot_toplevel__DOT__DIVERGE__DOT__B = VL_RAND_RESET_I(32);
    mandelbrot_toplevel__DOT__DIVERGE__DOT__twoab = VL_RAND_RESET_I(32);
    mandelbrot_toplevel__DOT__DIVERGE__DOT__s1 = VL_RAND_RESET_I(32);
    mandelbrot_toplevel__DOT__DIVERGE__DOT__s2 = VL_RAND_RESET_I(32);
    mandelbrot_toplevel__DOT__DIVERGE__DOT__muxout1 = VL_RAND_RESET_I(32);
    mandelbrot_toplevel__DOT__DIVERGE__DOT__muxout2 = VL_RAND_RESET_I(32);
    mandelbrot_toplevel__DOT__DIVERGE__DOT__GENERATOR__DOT__ab_truncated = VL_RAND_RESET_I(31);
    mandelbrot_toplevel__DOT__counter_mod__DOT__counter_reg = VL_RAND_RESET_I(15);
    { int __Vi0=0; for (; __Vi0<1048576; ++__Vi0) {
            mandelbrot_toplevel__DOT__ram__DOT__ram_array[__Vi0] = VL_RAND_RESET_I(15);
    }}
    { int __Vi0=0; for (; __Vi0<3; ++__Vi0) {
            __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }}
}
