// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmandelbrot_toplevel.h for the primary calling header

#include "verilated.h"

#include "Vmandelbrot_toplevel___024root.h"

VL_ATTR_COLD void Vmandelbrot_toplevel___024root___settle__TOP__0(Vmandelbrot_toplevel___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmandelbrot_toplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmandelbrot_toplevel___024root___settle__TOP__0\n"); );
    // Body
    vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__GENERATOR__DOT__ab_truncated 
        = (0x7fffffffU & (IData)((((QData)((IData)(vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__A)) 
                                   * (QData)((IData)(vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__B))) 
                                  >> 0x15U)));
    vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__twoab 
        = (vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__GENERATOR__DOT__ab_truncated 
           << 1U);
    vlSelf->mandelbrot_toplevel__DOT__real_internal 
        = ((IData)((((QData)((IData)(((IData)(vlSelf->mandelbrot_toplevel__DOT__Mapper__DOT__X) 
                                      << 0x15U))) * (QData)((IData)(
                                                                    VL_DIV_III(32, vlSelf->Re_axis_width, (IData)(vlSelf->x_size))))) 
                    >> 0x15U)) + vlSelf->Re_axis_width);
    vlSelf->mandelbrot_toplevel__DOT__or_out = ((0x800000U 
                                                 < vlSelf->mandelbrot_toplevel__DOT__real_internal) 
                                                | (IData)(vlSelf->mandelbrot_toplevel__DOT__ovf_it));
    vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__s1 
        = (vlSelf->mandelbrot_toplevel__DOT__real_internal 
           + ((IData)((((QData)((IData)(vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__A)) 
                        * (QData)((IData)(vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__A))) 
                       >> 0x15U)) - (IData)((((QData)((IData)(vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__B)) 
                                              * (QData)((IData)(vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__B))) 
                                             >> 0x15U))));
    vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__s2 
        = (vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__twoab 
           + ((IData)((((QData)((IData)(((IData)(vlSelf->mandelbrot_toplevel__DOT__Mapper__DOT__Y) 
                                         << 0x15U))) 
                        * (QData)((IData)(VL_DIV_III(32, vlSelf->Im_axis_width, (IData)(vlSelf->y_size))))) 
                       >> 0x15U)) + vlSelf->Im_axis_width));
    if (vlSelf->mandelbrot_toplevel__DOT__or_out) {
        vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__muxout1 = 0U;
        vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__muxout2 = 0U;
    } else {
        vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__muxout1 
            = vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__s1;
        vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__muxout2 
            = vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__s2;
    }
}

VL_ATTR_COLD void Vmandelbrot_toplevel___024root___eval_initial(Vmandelbrot_toplevel___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmandelbrot_toplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmandelbrot_toplevel___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

VL_ATTR_COLD void Vmandelbrot_toplevel___024root___eval_settle(Vmandelbrot_toplevel___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmandelbrot_toplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmandelbrot_toplevel___024root___eval_settle\n"); );
    // Body
    Vmandelbrot_toplevel___024root___settle__TOP__0(vlSelf);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
}

VL_ATTR_COLD void Vmandelbrot_toplevel___024root___final(Vmandelbrot_toplevel___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmandelbrot_toplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmandelbrot_toplevel___024root___final\n"); );
}

VL_ATTR_COLD void Vmandelbrot_toplevel___024root___ctor_var_reset(Vmandelbrot_toplevel___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmandelbrot_toplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmandelbrot_toplevel___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->enable = VL_RAND_RESET_I(1);
    vlSelf->x_size = VL_RAND_RESET_I(10);
    vlSelf->y_size = VL_RAND_RESET_I(10);
    vlSelf->Re_axis_width = VL_RAND_RESET_I(32);
    vlSelf->Im_axis_width = VL_RAND_RESET_I(32);
    vlSelf->RGB_out = VL_RAND_RESET_I(15);
    vlSelf->X = VL_RAND_RESET_I(10);
    vlSelf->Y = VL_RAND_RESET_I(10);
    vlSelf->mandelbrot_toplevel__DOT__ovf = VL_RAND_RESET_I(1);
    vlSelf->mandelbrot_toplevel__DOT__real_internal = VL_RAND_RESET_I(32);
    vlSelf->mandelbrot_toplevel__DOT__q = VL_RAND_RESET_I(1);
    vlSelf->mandelbrot_toplevel__DOT__q_bar = VL_RAND_RESET_I(1);
    vlSelf->mandelbrot_toplevel__DOT__counter_out = VL_RAND_RESET_I(15);
    vlSelf->mandelbrot_toplevel__DOT__ovf_it = VL_RAND_RESET_I(1);
    vlSelf->mandelbrot_toplevel__DOT__or_out = VL_RAND_RESET_I(1);
    vlSelf->mandelbrot_toplevel__DOT__rd_addr = VL_RAND_RESET_I(20);
    vlSelf->mandelbrot_toplevel__DOT__Mapper__DOT__X = VL_RAND_RESET_I(10);
    vlSelf->mandelbrot_toplevel__DOT__Mapper__DOT__Y = VL_RAND_RESET_I(10);
    vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__A = VL_RAND_RESET_I(32);
    vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__B = VL_RAND_RESET_I(32);
    vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__twoab = VL_RAND_RESET_I(32);
    vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__s1 = VL_RAND_RESET_I(32);
    vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__s2 = VL_RAND_RESET_I(32);
    vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__muxout1 = VL_RAND_RESET_I(32);
    vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__muxout2 = VL_RAND_RESET_I(32);
    vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__GENERATOR__DOT__ab_truncated = VL_RAND_RESET_I(31);
    vlSelf->mandelbrot_toplevel__DOT__counter_mod__DOT__counter_reg = VL_RAND_RESET_I(15);
    for (int __Vi0=0; __Vi0<1048576; ++__Vi0) {
        vlSelf->mandelbrot_toplevel__DOT__ram__DOT__ram_array[__Vi0] = VL_RAND_RESET_I(15);
    }
    for (int __Vi0=0; __Vi0<3; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }
}
