// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmandelbrot_toplevel.h for the primary calling header

#include "Vmandelbrot_toplevel.h"
#include "Vmandelbrot_toplevel__Syms.h"

//==========

void Vmandelbrot_toplevel::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vmandelbrot_toplevel::eval\n"); );
    Vmandelbrot_toplevel__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vmandelbrot_toplevel* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("mandelbrot_toplevel.sv", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vmandelbrot_toplevel::_eval_initial_loop(Vmandelbrot_toplevel__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("mandelbrot_toplevel.sv", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vmandelbrot_toplevel::_sequent__TOP__1(Vmandelbrot_toplevel__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmandelbrot_toplevel::_sequent__TOP__1\n"); );
    Vmandelbrot_toplevel* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*0:0*/ __Vdlyvset__mandelbrot_toplevel__DOT__ram__DOT__ram_array__v0;
    CData/*0:0*/ __Vdly__mandelbrot_toplevel__DOT__q;
    SData/*9:0*/ __Vdly__mandelbrot_toplevel__DOT__Mapper__DOT__X;
    SData/*9:0*/ __Vdly__mandelbrot_toplevel__DOT__Mapper__DOT__Y;
    SData/*14:0*/ __Vdly__mandelbrot_toplevel__DOT__counter_mod__DOT__counter_reg;
    SData/*14:0*/ __Vdlyvval__mandelbrot_toplevel__DOT__ram__DOT__ram_array__v0;
    IData/*19:0*/ __Vdly__mandelbrot_toplevel__DOT__rd_addr;
    IData/*19:0*/ __Vdlyvdim0__mandelbrot_toplevel__DOT__ram__DOT__ram_array__v0;
    // Body
    __Vdly__mandelbrot_toplevel__DOT__counter_mod__DOT__counter_reg 
        = vlTOPp->mandelbrot_toplevel__DOT__counter_mod__DOT__counter_reg;
    __Vdly__mandelbrot_toplevel__DOT__q = vlTOPp->mandelbrot_toplevel__DOT__q;
    __Vdly__mandelbrot_toplevel__DOT__Mapper__DOT__Y 
        = vlTOPp->mandelbrot_toplevel__DOT__Mapper__DOT__Y;
    __Vdly__mandelbrot_toplevel__DOT__rd_addr = vlTOPp->mandelbrot_toplevel__DOT__rd_addr;
    __Vdlyvset__mandelbrot_toplevel__DOT__ram__DOT__ram_array__v0 = 0U;
    __Vdly__mandelbrot_toplevel__DOT__Mapper__DOT__X 
        = vlTOPp->mandelbrot_toplevel__DOT__Mapper__DOT__X;
    vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__A 
        = vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__muxout1;
    vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__B 
        = vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__muxout2;
    __Vdly__mandelbrot_toplevel__DOT__q = ((~ (IData)(vlTOPp->rst)) 
                                           & (IData)(vlTOPp->mandelbrot_toplevel__DOT__ovf));
    if (vlTOPp->mandelbrot_toplevel__DOT__ovf) {
        vlTOPp->RGB_out = vlTOPp->mandelbrot_toplevel__DOT__ram__DOT__ram_array
            [vlTOPp->mandelbrot_toplevel__DOT__rd_addr];
    }
    if (vlTOPp->rst) {
        __Vdly__mandelbrot_toplevel__DOT__rd_addr = 0U;
    } else {
        if ((0xfffffU == vlTOPp->mandelbrot_toplevel__DOT__rd_addr)) {
            __Vdly__mandelbrot_toplevel__DOT__rd_addr = 0U;
        } else {
            if (vlTOPp->mandelbrot_toplevel__DOT__ovf) {
                __Vdly__mandelbrot_toplevel__DOT__rd_addr 
                    = (0xfffffU & ((IData)(1U) + vlTOPp->mandelbrot_toplevel__DOT__rd_addr));
            }
        }
    }
    vlTOPp->X = (0x3ffU & vlTOPp->mandelbrot_toplevel__DOT__rd_addr);
    vlTOPp->Y = (0x3ffU & (vlTOPp->mandelbrot_toplevel__DOT__rd_addr 
                           >> 0xaU));
    if ((1U & (~ (IData)(vlTOPp->mandelbrot_toplevel__DOT__ovf)))) {
        __Vdlyvval__mandelbrot_toplevel__DOT__ram__DOT__ram_array__v0 
            = vlTOPp->mandelbrot_toplevel__DOT__counter_out;
        __Vdlyvset__mandelbrot_toplevel__DOT__ram__DOT__ram_array__v0 = 1U;
        __Vdlyvdim0__mandelbrot_toplevel__DOT__ram__DOT__ram_array__v0 
            = (0xfffffU & (((IData)(vlTOPp->mandelbrot_toplevel__DOT__Mapper__DOT__Y) 
                            << 0xaU) | (IData)(vlTOPp->mandelbrot_toplevel__DOT__Mapper__DOT__Y)));
    }
    vlTOPp->mandelbrot_toplevel__DOT__rd_addr = __Vdly__mandelbrot_toplevel__DOT__rd_addr;
    if (__Vdlyvset__mandelbrot_toplevel__DOT__ram__DOT__ram_array__v0) {
        vlTOPp->mandelbrot_toplevel__DOT__ram__DOT__ram_array[__Vdlyvdim0__mandelbrot_toplevel__DOT__ram__DOT__ram_array__v0] 
            = __Vdlyvval__mandelbrot_toplevel__DOT__ram__DOT__ram_array__v0;
    }
    vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__GENERATOR__DOT__ab_truncated 
        = (0x7fffffffU & (IData)((((QData)((IData)(vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__A)) 
                                   * (QData)((IData)(vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__B))) 
                                  >> 0x15U)));
    vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__twoab 
        = (vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__GENERATOR__DOT__ab_truncated 
           << 1U);
    if (vlTOPp->mandelbrot_toplevel__DOT__or_out) {
        __Vdly__mandelbrot_toplevel__DOT__counter_mod__DOT__counter_reg = 0U;
        vlTOPp->mandelbrot_toplevel__DOT__ovf_it = 0U;
    } else {
        if (vlTOPp->enable) {
            if ((0x7fffU == (IData)(vlTOPp->mandelbrot_toplevel__DOT__counter_mod__DOT__counter_reg))) {
                __Vdly__mandelbrot_toplevel__DOT__counter_mod__DOT__counter_reg = 0U;
                vlTOPp->mandelbrot_toplevel__DOT__ovf_it = 1U;
            } else {
                __Vdly__mandelbrot_toplevel__DOT__counter_mod__DOT__counter_reg 
                    = (0x7fffU & ((IData)(1U) + (IData)(vlTOPp->mandelbrot_toplevel__DOT__counter_mod__DOT__counter_reg)));
                vlTOPp->mandelbrot_toplevel__DOT__ovf_it = 0U;
            }
        }
    }
    vlTOPp->mandelbrot_toplevel__DOT__counter_out = vlTOPp->mandelbrot_toplevel__DOT__counter_mod__DOT__counter_reg;
    if (vlTOPp->rst) {
        __Vdly__mandelbrot_toplevel__DOT__Mapper__DOT__X = 0U;
        __Vdly__mandelbrot_toplevel__DOT__Mapper__DOT__Y = 0U;
        vlTOPp->mandelbrot_toplevel__DOT__ovf = 0U;
    } else {
        if ((((IData)(vlTOPp->enable) & (IData)(vlTOPp->mandelbrot_toplevel__DOT__q_bar)) 
             & (IData)(vlTOPp->mandelbrot_toplevel__DOT__or_out))) {
            if ((0x3ffU == (IData)(vlTOPp->mandelbrot_toplevel__DOT__Mapper__DOT__X))) {
                if ((0x2ffU == (IData)(vlTOPp->mandelbrot_toplevel__DOT__Mapper__DOT__Y))) {
                    vlTOPp->mandelbrot_toplevel__DOT__ovf = 1U;
                    __Vdly__mandelbrot_toplevel__DOT__Mapper__DOT__Y = 0U;
                }
                __Vdly__mandelbrot_toplevel__DOT__Mapper__DOT__X = 0U;
                __Vdly__mandelbrot_toplevel__DOT__Mapper__DOT__Y 
                    = (0x3ffU & ((IData)(1U) + (IData)(vlTOPp->mandelbrot_toplevel__DOT__Mapper__DOT__Y)));
            } else {
                __Vdly__mandelbrot_toplevel__DOT__Mapper__DOT__X 
                    = (0x3ffU & ((IData)(1U) + (IData)(vlTOPp->mandelbrot_toplevel__DOT__Mapper__DOT__X)));
            }
        }
    }
    vlTOPp->mandelbrot_toplevel__DOT__counter_mod__DOT__counter_reg 
        = __Vdly__mandelbrot_toplevel__DOT__counter_mod__DOT__counter_reg;
    vlTOPp->mandelbrot_toplevel__DOT__Mapper__DOT__Y 
        = __Vdly__mandelbrot_toplevel__DOT__Mapper__DOT__Y;
    vlTOPp->mandelbrot_toplevel__DOT__Mapper__DOT__X 
        = __Vdly__mandelbrot_toplevel__DOT__Mapper__DOT__X;
    vlTOPp->mandelbrot_toplevel__DOT__q_bar = (1U & 
                                               (~ (IData)(vlTOPp->mandelbrot_toplevel__DOT__q)));
    vlTOPp->mandelbrot_toplevel__DOT__q = __Vdly__mandelbrot_toplevel__DOT__q;
}

VL_INLINE_OPT void Vmandelbrot_toplevel::_combo__TOP__3(Vmandelbrot_toplevel__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmandelbrot_toplevel::_combo__TOP__3\n"); );
    Vmandelbrot_toplevel* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
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

void Vmandelbrot_toplevel::_eval(Vmandelbrot_toplevel__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmandelbrot_toplevel::_eval\n"); );
    Vmandelbrot_toplevel* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
        vlTOPp->__Vm_traceActivity[1U] = 1U;
    }
    vlTOPp->_combo__TOP__3(vlSymsp);
    vlTOPp->__Vm_traceActivity[2U] = 1U;
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

VL_INLINE_OPT QData Vmandelbrot_toplevel::_change_request(Vmandelbrot_toplevel__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmandelbrot_toplevel::_change_request\n"); );
    Vmandelbrot_toplevel* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vmandelbrot_toplevel::_change_request_1(Vmandelbrot_toplevel__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmandelbrot_toplevel::_change_request_1\n"); );
    Vmandelbrot_toplevel* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vmandelbrot_toplevel::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmandelbrot_toplevel::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((enable & 0xfeU))) {
        Verilated::overWidthError("enable");}
    if (VL_UNLIKELY((x_size & 0xfc00U))) {
        Verilated::overWidthError("x_size");}
    if (VL_UNLIKELY((y_size & 0xfc00U))) {
        Verilated::overWidthError("y_size");}
}
#endif  // VL_DEBUG
