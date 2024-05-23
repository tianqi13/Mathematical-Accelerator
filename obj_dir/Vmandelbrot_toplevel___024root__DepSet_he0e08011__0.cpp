// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmandelbrot_toplevel.h for the primary calling header

#include "verilated.h"

#include "Vmandelbrot_toplevel___024root.h"

VL_INLINE_OPT void Vmandelbrot_toplevel___024root___sequent__TOP__0(Vmandelbrot_toplevel___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmandelbrot_toplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmandelbrot_toplevel___024root___sequent__TOP__0\n"); );
    // Body
    vlSelf->__Vdly__mandelbrot_toplevel__DOT__counter_mod__DOT__counter_reg 
        = vlSelf->mandelbrot_toplevel__DOT__counter_mod__DOT__counter_reg;
}

VL_INLINE_OPT void Vmandelbrot_toplevel___024root___sequent__TOP__1(Vmandelbrot_toplevel___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmandelbrot_toplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmandelbrot_toplevel___024root___sequent__TOP__1\n"); );
    // Init
    SData/*9:0*/ __Vdly__mandelbrot_toplevel__DOT__Mapper__DOT__X;
    SData/*9:0*/ __Vdly__mandelbrot_toplevel__DOT__Mapper__DOT__Y;
    IData/*19:0*/ __Vdly__mandelbrot_toplevel__DOT__rd_addr;
    IData/*19:0*/ __Vdlyvdim0__mandelbrot_toplevel__DOT__ram__DOT__ram_array__v0;
    SData/*14:0*/ __Vdlyvval__mandelbrot_toplevel__DOT__ram__DOT__ram_array__v0;
    CData/*0:0*/ __Vdlyvset__mandelbrot_toplevel__DOT__ram__DOT__ram_array__v0;
    // Body
    __Vdly__mandelbrot_toplevel__DOT__Mapper__DOT__Y 
        = vlSelf->mandelbrot_toplevel__DOT__Mapper__DOT__Y;
    __Vdly__mandelbrot_toplevel__DOT__rd_addr = vlSelf->mandelbrot_toplevel__DOT__rd_addr;
    __Vdly__mandelbrot_toplevel__DOT__Mapper__DOT__X 
        = vlSelf->mandelbrot_toplevel__DOT__Mapper__DOT__X;
    __Vdlyvset__mandelbrot_toplevel__DOT__ram__DOT__ram_array__v0 = 0U;
    vlSelf->mandelbrot_toplevel__DOT__ovf_it = (1U 
                                                & (~ (IData)(vlSelf->mandelbrot_toplevel__DOT__out)));
    vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__A 
        = vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__muxout1;
    vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__B 
        = vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__muxout2;
    if (vlSelf->mandelbrot_toplevel__DOT__ovf) {
        vlSelf->RGB_out = vlSelf->mandelbrot_toplevel__DOT__ram__DOT__ram_array
            [vlSelf->mandelbrot_toplevel__DOT__rd_addr];
    }
    vlSelf->mandelbrot_toplevel__DOT__q_bar = (1U & 
                                               (~ (IData)(vlSelf->mandelbrot_toplevel__DOT__q)));
    vlSelf->mandelbrot_toplevel__DOT____Vcellout__addr_counter__X 
        = (0x3ffU & vlSelf->mandelbrot_toplevel__DOT__rd_addr);
    vlSelf->mandelbrot_toplevel__DOT____Vcellout__addr_counter__Y 
        = (0x3ffU & (vlSelf->mandelbrot_toplevel__DOT__rd_addr 
                     >> 0xaU));
    if ((1U & (~ (IData)(vlSelf->mandelbrot_toplevel__DOT__ovf)))) {
        __Vdlyvval__mandelbrot_toplevel__DOT__ram__DOT__ram_array__v0 
            = vlSelf->mandelbrot_toplevel__DOT__out;
        __Vdlyvset__mandelbrot_toplevel__DOT__ram__DOT__ram_array__v0 = 1U;
        __Vdlyvdim0__mandelbrot_toplevel__DOT__ram__DOT__ram_array__v0 
            = (0xfffffU & vlSelf->mandelbrot_toplevel__DOT__x_internal);
    }
    if (vlSelf->rst) {
        __Vdly__mandelbrot_toplevel__DOT__rd_addr = 0U;
    } else if ((0xfffffU == vlSelf->mandelbrot_toplevel__DOT__rd_addr)) {
        __Vdly__mandelbrot_toplevel__DOT__rd_addr = 0U;
    } else if (vlSelf->mandelbrot_toplevel__DOT__ovf) {
        __Vdly__mandelbrot_toplevel__DOT__rd_addr = 
            (0xfffffU & ((IData)(1U) + vlSelf->mandelbrot_toplevel__DOT__rd_addr));
    }
    vlSelf->mandelbrot_toplevel__DOT__rd_addr = __Vdly__mandelbrot_toplevel__DOT__rd_addr;
    if (__Vdlyvset__mandelbrot_toplevel__DOT__ram__DOT__ram_array__v0) {
        vlSelf->mandelbrot_toplevel__DOT__ram__DOT__ram_array[__Vdlyvdim0__mandelbrot_toplevel__DOT__ram__DOT__ram_array__v0] 
            = __Vdlyvval__mandelbrot_toplevel__DOT__ram__DOT__ram_array__v0;
    }
    vlSelf->mandelbrot_toplevel__DOT__q = ((~ (IData)(vlSelf->rst)) 
                                           & (IData)(vlSelf->mandelbrot_toplevel__DOT__ovf));
    if (vlSelf->rst) {
        __Vdly__mandelbrot_toplevel__DOT__Mapper__DOT__X = 0U;
        __Vdly__mandelbrot_toplevel__DOT__Mapper__DOT__Y = 0U;
        vlSelf->mandelbrot_toplevel__DOT__ovf = 0U;
    } else if (vlSelf->mandelbrot_toplevel__DOT____Vcellinp__Mapper__en) {
        if ((0x3ffU == (IData)(vlSelf->mandelbrot_toplevel__DOT__Mapper__DOT__X))) {
            if ((0x2ffU == (IData)(vlSelf->mandelbrot_toplevel__DOT__Mapper__DOT__Y))) {
                vlSelf->mandelbrot_toplevel__DOT__ovf = 1U;
                __Vdly__mandelbrot_toplevel__DOT__Mapper__DOT__Y = 0U;
            }
            __Vdly__mandelbrot_toplevel__DOT__Mapper__DOT__X = 0U;
            __Vdly__mandelbrot_toplevel__DOT__Mapper__DOT__Y 
                = (0x3ffU & ((IData)(1U) + (IData)(vlSelf->mandelbrot_toplevel__DOT__Mapper__DOT__Y)));
        } else {
            __Vdly__mandelbrot_toplevel__DOT__Mapper__DOT__X 
                = (0x3ffU & ((IData)(1U) + (IData)(vlSelf->mandelbrot_toplevel__DOT__Mapper__DOT__X)));
        }
    }
    vlSelf->mandelbrot_toplevel__DOT__Mapper__DOT__Y 
        = __Vdly__mandelbrot_toplevel__DOT__Mapper__DOT__Y;
    vlSelf->mandelbrot_toplevel__DOT__Mapper__DOT__X 
        = __Vdly__mandelbrot_toplevel__DOT__Mapper__DOT__X;
    vlSelf->mandelbrot_toplevel__DOT__y_internal = 
        ((IData)(vlSelf->mandelbrot_toplevel__DOT__Mapper__DOT__Y) 
         << 0x15U);
    vlSelf->mandelbrot_toplevel__DOT__x_internal = 
        ((IData)(vlSelf->mandelbrot_toplevel__DOT__Mapper__DOT__X) 
         << 0x15U);
}

VL_INLINE_OPT void Vmandelbrot_toplevel___024root___sequent__TOP__2(Vmandelbrot_toplevel___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmandelbrot_toplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmandelbrot_toplevel___024root___sequent__TOP__2\n"); );
    // Body
    if (vlSelf->mandelbrot_toplevel__DOT__or_out) {
        vlSelf->__Vdly__mandelbrot_toplevel__DOT__counter_mod__DOT__counter_reg = 0U;
        vlSelf->mandelbrot_toplevel__DOT__ovf_it = 0U;
    } else if (vlSelf->enable) {
        if ((0x7fffU == (IData)(vlSelf->mandelbrot_toplevel__DOT__counter_mod__DOT__counter_reg))) {
            vlSelf->__Vdly__mandelbrot_toplevel__DOT__counter_mod__DOT__counter_reg = 0U;
            vlSelf->mandelbrot_toplevel__DOT__ovf_it = 1U;
        } else {
            vlSelf->__Vdly__mandelbrot_toplevel__DOT__counter_mod__DOT__counter_reg 
                = (0x7fffU & ((IData)(1U) + (IData)(vlSelf->mandelbrot_toplevel__DOT__counter_mod__DOT__counter_reg)));
            vlSelf->mandelbrot_toplevel__DOT__ovf_it = 0U;
        }
    }
    vlSelf->mandelbrot_toplevel__DOT__out = vlSelf->mandelbrot_toplevel__DOT__counter_mod__DOT__counter_reg;
    vlSelf->mandelbrot_toplevel__DOT__counter_mod__DOT__counter_reg 
        = vlSelf->__Vdly__mandelbrot_toplevel__DOT__counter_mod__DOT__counter_reg;
}

VL_INLINE_OPT void Vmandelbrot_toplevel___024root___combo__TOP__0(Vmandelbrot_toplevel___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmandelbrot_toplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmandelbrot_toplevel___024root___combo__TOP__0\n"); );
    // Body
    vlSelf->mandelbrot_toplevel__DOT____Vcellinp__Mapper__en 
        = (((IData)(vlSelf->enable) & (IData)(vlSelf->mandelbrot_toplevel__DOT__q_bar)) 
           & (IData)(vlSelf->mandelbrot_toplevel__DOT__or_out));
    vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__s2 
        = (vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__twoab 
           + ((IData)((((QData)((IData)(((IData)(vlSelf->mandelbrot_toplevel__DOT__Mapper__DOT__Y) 
                                         << 0x15U))) 
                        * (QData)((IData)(VL_DIV_III(32, vlSelf->Im_axis_width, (IData)(vlSelf->y_size))))) 
                       >> 0x15U)) + vlSelf->Im_axis_width));
    vlSelf->mandelbrot_toplevel__DOT__real_internal 
        = ((IData)((((QData)((IData)(((IData)(vlSelf->mandelbrot_toplevel__DOT__Mapper__DOT__X) 
                                      << 0x15U))) * (QData)((IData)(
                                                                    VL_DIV_III(32, vlSelf->Re_axis_width, (IData)(vlSelf->x_size))))) 
                    >> 0x15U)) + vlSelf->Re_axis_width);
    vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__s1 
        = (vlSelf->mandelbrot_toplevel__DOT__real_internal 
           + ((IData)((((QData)((IData)(vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__A)) 
                        * (QData)((IData)(vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__A))) 
                       >> 0x15U)) - (IData)((((QData)((IData)(vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__B)) 
                                              * (QData)((IData)(vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__B))) 
                                             >> 0x15U))));
    if (vlSelf->mandelbrot_toplevel__DOT__or_out) {
        vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__muxout2 = 0U;
        vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__muxout1 = 0U;
    } else {
        vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__muxout2 
            = vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__s2;
        vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__muxout1 
            = vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__s1;
    }
}

VL_INLINE_OPT void Vmandelbrot_toplevel___024root___sequent__TOP__3(Vmandelbrot_toplevel___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmandelbrot_toplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmandelbrot_toplevel___024root___sequent__TOP__3\n"); );
    // Body
    vlSelf->mandelbrot_toplevel__DOT__out = ((IData)(vlSelf->mandelbrot_toplevel__DOT__or_out)
                                              ? 0U : (IData)(vlSelf->enable));
}

VL_INLINE_OPT void Vmandelbrot_toplevel___024root___combo__TOP__1(Vmandelbrot_toplevel___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmandelbrot_toplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmandelbrot_toplevel___024root___combo__TOP__1\n"); );
    // Body
    vlSelf->mandelbrot_toplevel__DOT__or_out = ((0x800000U 
                                                 < vlSelf->mandelbrot_toplevel__DOT__real_internal) 
                                                | (IData)(vlSelf->mandelbrot_toplevel__DOT__ovf_it));
}

void Vmandelbrot_toplevel___024root___eval(Vmandelbrot_toplevel___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmandelbrot_toplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmandelbrot_toplevel___024root___eval\n"); );
    // Body
    if ((((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk))) 
         | ((IData)(vlSelf->__VinpClk__TOP__mandelbrot_toplevel__DOT__or_out) 
            & (~ (IData)(vlSelf->__Vclklast__TOP____VinpClk__TOP__mandelbrot_toplevel__DOT__or_out))))) {
        Vmandelbrot_toplevel___024root___sequent__TOP__0(vlSelf);
    }
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        Vmandelbrot_toplevel___024root___sequent__TOP__1(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
    if ((((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk))) 
         | ((IData)(vlSelf->__VinpClk__TOP__mandelbrot_toplevel__DOT__or_out) 
            & (~ (IData)(vlSelf->__Vclklast__TOP____VinpClk__TOP__mandelbrot_toplevel__DOT__or_out))))) {
        Vmandelbrot_toplevel___024root___sequent__TOP__2(vlSelf);
    }
    Vmandelbrot_toplevel___024root___combo__TOP__0(vlSelf);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        Vmandelbrot_toplevel___024root___sequent__TOP__3(vlSelf);
    }
    Vmandelbrot_toplevel___024root___combo__TOP__1(vlSelf);
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
    vlSelf->__Vclklast__TOP____VinpClk__TOP__mandelbrot_toplevel__DOT__or_out 
        = vlSelf->__VinpClk__TOP__mandelbrot_toplevel__DOT__or_out;
    vlSelf->__VinpClk__TOP__mandelbrot_toplevel__DOT__or_out 
        = vlSelf->mandelbrot_toplevel__DOT__or_out;
}

QData Vmandelbrot_toplevel___024root___change_request_1(Vmandelbrot_toplevel___024root* vlSelf);

VL_INLINE_OPT QData Vmandelbrot_toplevel___024root___change_request(Vmandelbrot_toplevel___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmandelbrot_toplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmandelbrot_toplevel___024root___change_request\n"); );
    // Body
    return (Vmandelbrot_toplevel___024root___change_request_1(vlSelf));
}

VL_INLINE_OPT QData Vmandelbrot_toplevel___024root___change_request_1(Vmandelbrot_toplevel___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmandelbrot_toplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmandelbrot_toplevel___024root___change_request_1\n"); );
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    __req |= ((vlSelf->mandelbrot_toplevel__DOT__or_out ^ vlSelf->__Vchglast__TOP__mandelbrot_toplevel__DOT__or_out));
    VL_DEBUG_IF( if(__req && ((vlSelf->mandelbrot_toplevel__DOT__or_out ^ vlSelf->__Vchglast__TOP__mandelbrot_toplevel__DOT__or_out))) VL_DBG_MSGF("        CHANGE: mandelbrot_toplevel.sv:30: mandelbrot_toplevel.or_out\n"); );
    // Final
    vlSelf->__Vchglast__TOP__mandelbrot_toplevel__DOT__or_out 
        = vlSelf->mandelbrot_toplevel__DOT__or_out;
    return __req;
}

#ifdef VL_DEBUG
void Vmandelbrot_toplevel___024root___eval_debug_assertions(Vmandelbrot_toplevel___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmandelbrot_toplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmandelbrot_toplevel___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->enable & 0xfeU))) {
        Verilated::overWidthError("enable");}
    if (VL_UNLIKELY((vlSelf->x_size & 0xfc00U))) {
        Verilated::overWidthError("x_size");}
    if (VL_UNLIKELY((vlSelf->y_size & 0xfc00U))) {
        Verilated::overWidthError("y_size");}
}
#endif  // VL_DEBUG
