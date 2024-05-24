// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmandelbrot_toplevel.h for the primary calling header

#include "verilated.h"

#include "Vmandelbrot_toplevel___024root.h"

VL_INLINE_OPT void Vmandelbrot_toplevel___024root___sequent__TOP__0(Vmandelbrot_toplevel___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmandelbrot_toplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmandelbrot_toplevel___024root___sequent__TOP__0\n"); );
    // Init
    SData/*9:0*/ __Vdly__mandelbrot_toplevel__DOT__Mapper__DOT__X;
    SData/*9:0*/ __Vdly__mandelbrot_toplevel__DOT__Mapper__DOT__Y;
    IData/*19:0*/ __Vdly__mandelbrot_toplevel__DOT__rd_addr;
    SData/*14:0*/ __Vdly__mandelbrot_toplevel__DOT__counter_mod__DOT__counter_reg;
    IData/*19:0*/ __Vdlyvdim0__mandelbrot_toplevel__DOT__ram__DOT__ram_array__v0;
    SData/*14:0*/ __Vdlyvval__mandelbrot_toplevel__DOT__ram__DOT__ram_array__v0;
    CData/*0:0*/ __Vdlyvset__mandelbrot_toplevel__DOT__ram__DOT__ram_array__v0;
    CData/*0:0*/ __Vdly__mandelbrot_toplevel__DOT__q;
    // Body
    __Vdly__mandelbrot_toplevel__DOT__counter_mod__DOT__counter_reg 
        = vlSelf->mandelbrot_toplevel__DOT__counter_mod__DOT__counter_reg;
    __Vdly__mandelbrot_toplevel__DOT__q = vlSelf->mandelbrot_toplevel__DOT__q;
    __Vdly__mandelbrot_toplevel__DOT__Mapper__DOT__Y 
        = vlSelf->mandelbrot_toplevel__DOT__Mapper__DOT__Y;
    __Vdly__mandelbrot_toplevel__DOT__rd_addr = vlSelf->mandelbrot_toplevel__DOT__rd_addr;
    __Vdlyvset__mandelbrot_toplevel__DOT__ram__DOT__ram_array__v0 = 0U;
    __Vdly__mandelbrot_toplevel__DOT__Mapper__DOT__X 
        = vlSelf->mandelbrot_toplevel__DOT__Mapper__DOT__X;
    vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__A 
        = vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__muxout1;
    vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__B 
        = vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__muxout2;
    if (vlSelf->mandelbrot_toplevel__DOT__ovf) {
        __Vdly__mandelbrot_toplevel__DOT__q = (1U & 
                                               (~ (IData)(vlSelf->rst)));
        vlSelf->RGB_out = vlSelf->mandelbrot_toplevel__DOT__ram__DOT__ram_array
            [vlSelf->mandelbrot_toplevel__DOT__rd_addr];
    } else {
        __Vdly__mandelbrot_toplevel__DOT__q = 0U;
    }
    vlSelf->X = (0x3ffU & vlSelf->mandelbrot_toplevel__DOT__rd_addr);
    vlSelf->Y = (0x3ffU & (vlSelf->mandelbrot_toplevel__DOT__rd_addr 
                           >> 0xaU));
    if ((1U & (~ (IData)(vlSelf->mandelbrot_toplevel__DOT__ovf)))) {
        __Vdlyvval__mandelbrot_toplevel__DOT__ram__DOT__ram_array__v0 
            = vlSelf->mandelbrot_toplevel__DOT__counter_out;
        __Vdlyvset__mandelbrot_toplevel__DOT__ram__DOT__ram_array__v0 = 1U;
        __Vdlyvdim0__mandelbrot_toplevel__DOT__ram__DOT__ram_array__v0 
            = (0xfffffU & (((IData)(vlSelf->mandelbrot_toplevel__DOT__Mapper__DOT__Y) 
                            << 0xaU) | (IData)(vlSelf->mandelbrot_toplevel__DOT__Mapper__DOT__Y)));
    }
    if (vlSelf->rst) {
        __Vdly__mandelbrot_toplevel__DOT__rd_addr = 0U;
        __Vdly__mandelbrot_toplevel__DOT__Mapper__DOT__X = 0U;
        __Vdly__mandelbrot_toplevel__DOT__Mapper__DOT__Y = 0U;
        vlSelf->mandelbrot_toplevel__DOT__ovf = 0U;
    } else {
        if ((0xfffffU == vlSelf->mandelbrot_toplevel__DOT__rd_addr)) {
            __Vdly__mandelbrot_toplevel__DOT__rd_addr = 0U;
        } else if (vlSelf->mandelbrot_toplevel__DOT__ovf) {
            __Vdly__mandelbrot_toplevel__DOT__rd_addr 
                = (0xfffffU & ((IData)(1U) + vlSelf->mandelbrot_toplevel__DOT__rd_addr));
        }
        if ((((IData)(vlSelf->enable) & (IData)(vlSelf->mandelbrot_toplevel__DOT__q_bar)) 
             & (IData)(vlSelf->mandelbrot_toplevel__DOT__or_out))) {
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
    }
    vlSelf->mandelbrot_toplevel__DOT__rd_addr = __Vdly__mandelbrot_toplevel__DOT__rd_addr;
    if (__Vdlyvset__mandelbrot_toplevel__DOT__ram__DOT__ram_array__v0) {
        vlSelf->mandelbrot_toplevel__DOT__ram__DOT__ram_array[__Vdlyvdim0__mandelbrot_toplevel__DOT__ram__DOT__ram_array__v0] 
            = __Vdlyvval__mandelbrot_toplevel__DOT__ram__DOT__ram_array__v0;
    }
    vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__GENERATOR__DOT__ab_truncated 
        = (0x7fffffffU & (IData)((((QData)((IData)(vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__A)) 
                                   * (QData)((IData)(vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__B))) 
                                  >> 0x15U)));
    vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__twoab 
        = (vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__GENERATOR__DOT__ab_truncated 
           << 1U);
    if (vlSelf->mandelbrot_toplevel__DOT__or_out) {
        __Vdly__mandelbrot_toplevel__DOT__counter_mod__DOT__counter_reg = 0U;
        vlSelf->mandelbrot_toplevel__DOT__ovf_it = 0U;
    } else if (vlSelf->enable) {
        if ((0x7fffU == (IData)(vlSelf->mandelbrot_toplevel__DOT__counter_mod__DOT__counter_reg))) {
            __Vdly__mandelbrot_toplevel__DOT__counter_mod__DOT__counter_reg = 0U;
            vlSelf->mandelbrot_toplevel__DOT__ovf_it = 1U;
        } else {
            __Vdly__mandelbrot_toplevel__DOT__counter_mod__DOT__counter_reg 
                = (0x7fffU & ((IData)(1U) + (IData)(vlSelf->mandelbrot_toplevel__DOT__counter_mod__DOT__counter_reg)));
            vlSelf->mandelbrot_toplevel__DOT__ovf_it = 0U;
        }
    }
    vlSelf->mandelbrot_toplevel__DOT__counter_out = vlSelf->mandelbrot_toplevel__DOT__counter_mod__DOT__counter_reg;
    vlSelf->mandelbrot_toplevel__DOT__counter_mod__DOT__counter_reg 
        = __Vdly__mandelbrot_toplevel__DOT__counter_mod__DOT__counter_reg;
    vlSelf->mandelbrot_toplevel__DOT__Mapper__DOT__Y 
        = __Vdly__mandelbrot_toplevel__DOT__Mapper__DOT__Y;
    vlSelf->mandelbrot_toplevel__DOT__Mapper__DOT__X 
        = __Vdly__mandelbrot_toplevel__DOT__Mapper__DOT__X;
    vlSelf->mandelbrot_toplevel__DOT__q_bar = (1U & 
                                               (~ (IData)(vlSelf->mandelbrot_toplevel__DOT__q)));
    vlSelf->mandelbrot_toplevel__DOT__q = __Vdly__mandelbrot_toplevel__DOT__q;
}

VL_INLINE_OPT void Vmandelbrot_toplevel___024root___combo__TOP__0(Vmandelbrot_toplevel___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmandelbrot_toplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmandelbrot_toplevel___024root___combo__TOP__0\n"); );
    // Body
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

void Vmandelbrot_toplevel___024root___eval(Vmandelbrot_toplevel___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmandelbrot_toplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmandelbrot_toplevel___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        Vmandelbrot_toplevel___024root___sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
    Vmandelbrot_toplevel___024root___combo__TOP__0(vlSelf);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
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
