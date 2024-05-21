// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_level.h for the primary calling header

#include "verilated.h"

#include "Vtop_level__Syms.h"
#include "Vtop_level___024root.h"

void Vtop_level___024root___eval_act(Vtop_level___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_level__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_level___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vtop_level___024root___nba_sequent__TOP__0(Vtop_level___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_level__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_level___024root___nba_sequent__TOP__0\n"); );
    // Init
    SData/*14:0*/ __Vdly__top_level__DOT__count_out;
    __Vdly__top_level__DOT__count_out = 0;
    SData/*9:0*/ __Vdly__top_level__DOT__x;
    __Vdly__top_level__DOT__x = 0;
    SData/*9:0*/ __Vdly__top_level__DOT__y;
    __Vdly__top_level__DOT__y = 0;
    IData/*19:0*/ __Vdly__top_level__DOT__rd_addr;
    __Vdly__top_level__DOT__rd_addr = 0;
    IData/*19:0*/ __Vdlyvdim0__top_level__DOT__ram__DOT__ram_array__v0;
    __Vdlyvdim0__top_level__DOT__ram__DOT__ram_array__v0 = 0;
    SData/*14:0*/ __Vdlyvval__top_level__DOT__ram__DOT__ram_array__v0;
    __Vdlyvval__top_level__DOT__ram__DOT__ram_array__v0 = 0;
    CData/*0:0*/ __Vdlyvset__top_level__DOT__ram__DOT__ram_array__v0;
    __Vdlyvset__top_level__DOT__ram__DOT__ram_array__v0 = 0;
    // Body
    __Vdly__top_level__DOT__count_out = vlSelf->top_level__DOT__count_out;
    __Vdly__top_level__DOT__y = vlSelf->top_level__DOT__y;
    __Vdly__top_level__DOT__x = vlSelf->top_level__DOT__x;
    __Vdly__top_level__DOT__rd_addr = vlSelf->top_level__DOT__rd_addr;
    __Vdlyvset__top_level__DOT__ram__DOT__ram_array__v0 = 0U;
    if ((1U & (~ (IData)(vlSelf->top_level__DOT__ovf)))) {
        __Vdlyvval__top_level__DOT__ram__DOT__ram_array__v0 
            = vlSelf->top_level__DOT__count_out;
        __Vdlyvset__top_level__DOT__ram__DOT__ram_array__v0 = 1U;
        __Vdlyvdim0__top_level__DOT__ram__DOT__ram_array__v0 
            = (((IData)(vlSelf->top_level__DOT__y) 
                << 0xaU) | (IData)(vlSelf->top_level__DOT__x));
    }
    if (vlSelf->top_level__DOT__ovf) {
        vlSelf->RGB_out = vlSelf->top_level__DOT__ram__DOT__ram_array
            [vlSelf->top_level__DOT__rd_addr];
    }
    if (vlSelf->rst) {
        __Vdly__top_level__DOT__count_out = 0U;
        __Vdly__top_level__DOT__rd_addr = 0U;
        __Vdly__top_level__DOT__x = 0U;
        __Vdly__top_level__DOT__y = 0U;
        vlSelf->top_level__DOT__ovf = 0U;
    } else {
        if ((0xfffffU == vlSelf->top_level__DOT__rd_addr)) {
            __Vdly__top_level__DOT__rd_addr = 0U;
        } else if (vlSelf->top_level__DOT__ovf) {
            __Vdly__top_level__DOT__rd_addr = (0xfffffU 
                                               & ((IData)(1U) 
                                                  + vlSelf->top_level__DOT__rd_addr));
        }
        if (vlSelf->enable) {
            __Vdly__top_level__DOT__count_out = (0x7fffU 
                                                 & ((IData)(4U) 
                                                    + (IData)(vlSelf->top_level__DOT__count_out)));
            if ((0x3ffU == (IData)(vlSelf->top_level__DOT__x))) {
                if ((0x2ffU == (IData)(vlSelf->top_level__DOT__y))) {
                    vlSelf->top_level__DOT__ovf = 1U;
                    __Vdly__top_level__DOT__y = 0U;
                }
                __Vdly__top_level__DOT__x = 0U;
                __Vdly__top_level__DOT__y = (0x3ffU 
                                             & ((IData)(1U) 
                                                + (IData)(vlSelf->top_level__DOT__y)));
            } else {
                __Vdly__top_level__DOT__x = (0x3ffU 
                                             & ((IData)(1U) 
                                                + (IData)(vlSelf->top_level__DOT__x)));
            }
        }
    }
    vlSelf->top_level__DOT__count_out = __Vdly__top_level__DOT__count_out;
    vlSelf->top_level__DOT__rd_addr = __Vdly__top_level__DOT__rd_addr;
    if (__Vdlyvset__top_level__DOT__ram__DOT__ram_array__v0) {
        vlSelf->top_level__DOT__ram__DOT__ram_array[__Vdlyvdim0__top_level__DOT__ram__DOT__ram_array__v0] 
            = __Vdlyvval__top_level__DOT__ram__DOT__ram_array__v0;
    }
    vlSelf->top_level__DOT__x = __Vdly__top_level__DOT__x;
    vlSelf->top_level__DOT__y = __Vdly__top_level__DOT__y;
}

void Vtop_level___024root___eval_nba(Vtop_level___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_level__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_level___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtop_level___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
}

void Vtop_level___024root___eval_triggers__act(Vtop_level___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_level___024root___dump_triggers__act(Vtop_level___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_level___024root___dump_triggers__nba(Vtop_level___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop_level___024root___eval(Vtop_level___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_level__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_level___024root___eval\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            Vtop_level___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vtop_level___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("top_level.sv", 1, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
                Vtop_level___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vtop_level___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("top_level.sv", 1, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vtop_level___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vtop_level___024root___eval_debug_assertions(Vtop_level___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_level__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_level___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->enable & 0xfeU))) {
        Verilated::overWidthError("enable");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
}
#endif  // VL_DEBUG
