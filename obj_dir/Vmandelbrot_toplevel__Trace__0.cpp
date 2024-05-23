// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vmandelbrot_toplevel__Syms.h"


void Vmandelbrot_toplevel___024root__trace_chg_sub_0(Vmandelbrot_toplevel___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vmandelbrot_toplevel___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmandelbrot_toplevel___024root__trace_chg_top_0\n"); );
    // Init
    Vmandelbrot_toplevel___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vmandelbrot_toplevel___024root*>(voidSelf);
    Vmandelbrot_toplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vmandelbrot_toplevel___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vmandelbrot_toplevel___024root__trace_chg_sub_0(Vmandelbrot_toplevel___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vmandelbrot_toplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmandelbrot_toplevel___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0U])) {
        bufp->chgIData(oldp+0,(vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__twoab),32);
        bufp->chgIData(oldp+1,(vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__GENERATOR__DOT__ab_truncated),31);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgIData(oldp+2,(vlSelf->mandelbrot_toplevel__DOT__x_internal),32);
        bufp->chgIData(oldp+3,(vlSelf->mandelbrot_toplevel__DOT__y_internal),32);
        bufp->chgBit(oldp+4,(vlSelf->mandelbrot_toplevel__DOT__ovf));
        bufp->chgBit(oldp+5,(vlSelf->mandelbrot_toplevel__DOT__q));
        bufp->chgBit(oldp+6,(vlSelf->mandelbrot_toplevel__DOT__q_bar));
        bufp->chgIData(oldp+7,(vlSelf->mandelbrot_toplevel__DOT__rd_addr),20);
        bufp->chgIData(oldp+8,(vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__A),32);
        bufp->chgIData(oldp+9,(vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__B),32);
        bufp->chgIData(oldp+10,(((IData)((((QData)((IData)(vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__A)) 
                                           * (QData)((IData)(vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__A))) 
                                          >> 0x15U)) 
                                 + (IData)((((QData)((IData)(vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__B)) 
                                             * (QData)((IData)(vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__B))) 
                                            >> 0x15U)))),32);
        bufp->chgIData(oldp+11,(((IData)((((QData)((IData)(vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__A)) 
                                           * (QData)((IData)(vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__A))) 
                                          >> 0x15U)) 
                                 - (IData)((((QData)((IData)(vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__B)) 
                                             * (QData)((IData)(vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__B))) 
                                            >> 0x15U)))),32);
        bufp->chgIData(oldp+12,((IData)((((QData)((IData)(vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__A)) 
                                          * (QData)((IData)(vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__A))) 
                                         >> 0x15U))),32);
        bufp->chgIData(oldp+13,((IData)((((QData)((IData)(vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__B)) 
                                          * (QData)((IData)(vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__B))) 
                                         >> 0x15U))),32);
        bufp->chgQData(oldp+14,(((QData)((IData)(vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__A)) 
                                 * (QData)((IData)(vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__A)))),64);
        bufp->chgQData(oldp+16,(((QData)((IData)(vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__B)) 
                                 * (QData)((IData)(vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__B)))),64);
        bufp->chgSData(oldp+18,(vlSelf->mandelbrot_toplevel__DOT__Mapper__DOT__X),10);
        bufp->chgSData(oldp+19,(vlSelf->mandelbrot_toplevel__DOT__Mapper__DOT__Y),10);
        bufp->chgIData(oldp+20,(((IData)(vlSelf->mandelbrot_toplevel__DOT__Mapper__DOT__X) 
                                 << 0x15U)),32);
        bufp->chgIData(oldp+21,(((IData)(vlSelf->mandelbrot_toplevel__DOT__Mapper__DOT__Y) 
                                 << 0x15U)),32);
        bufp->chgSData(oldp+22,(vlSelf->mandelbrot_toplevel__DOT____Vcellout__addr_counter__X),10);
        bufp->chgSData(oldp+23,(vlSelf->mandelbrot_toplevel__DOT____Vcellout__addr_counter__Y),10);
        bufp->chgBit(oldp+24,((1U & (~ (IData)(vlSelf->mandelbrot_toplevel__DOT__ovf)))));
        bufp->chgIData(oldp+25,((0xfffffU & vlSelf->mandelbrot_toplevel__DOT__x_internal)),20);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        bufp->chgIData(oldp+26,(vlSelf->mandelbrot_toplevel__DOT__real_internal),32);
        bufp->chgBit(oldp+27,(vlSelf->mandelbrot_toplevel__DOT__or_out));
        bufp->chgBit(oldp+28,((0x800000U < vlSelf->mandelbrot_toplevel__DOT__real_internal)));
        bufp->chgIData(oldp+29,(vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__s1),32);
        bufp->chgIData(oldp+30,(vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__s2),32);
        bufp->chgIData(oldp+31,(vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__muxout1),32);
        bufp->chgIData(oldp+32,(vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__muxout2),32);
        bufp->chgBit(oldp+33,(vlSelf->mandelbrot_toplevel__DOT____Vcellinp__Mapper__en));
    }
    bufp->chgBit(oldp+34,(vlSelf->rst));
    bufp->chgBit(oldp+35,(vlSelf->clk));
    bufp->chgBit(oldp+36,(vlSelf->enable));
    bufp->chgSData(oldp+37,(vlSelf->x_size),10);
    bufp->chgSData(oldp+38,(vlSelf->y_size),10);
    bufp->chgIData(oldp+39,(vlSelf->Re_axis_width),32);
    bufp->chgIData(oldp+40,(vlSelf->Im_axis_width),32);
    bufp->chgSData(oldp+41,(vlSelf->RGB_out),15);
    bufp->chgSData(oldp+42,(vlSelf->X),10);
    bufp->chgSData(oldp+43,(vlSelf->Y),10);
    bufp->chgIData(oldp+44,(VL_DIV_III(32, vlSelf->Re_axis_width, (IData)(vlSelf->x_size))),32);
    bufp->chgIData(oldp+45,(VL_DIV_III(32, vlSelf->Im_axis_width, (IData)(vlSelf->y_size))),32);
    bufp->chgIData(oldp+46,(((IData)((((QData)((IData)(
                                                       ((IData)(vlSelf->mandelbrot_toplevel__DOT__Mapper__DOT__Y) 
                                                        << 0x15U))) 
                                       * (QData)((IData)(
                                                         VL_DIV_III(32, vlSelf->Im_axis_width, (IData)(vlSelf->y_size))))) 
                                      >> 0x15U)) + vlSelf->Im_axis_width)),32);
    bufp->chgSData(oldp+47,(vlSelf->mandelbrot_toplevel__DOT__out),15);
    bufp->chgBit(oldp+48,(vlSelf->mandelbrot_toplevel__DOT__ovf_it));
    bufp->chgIData(oldp+49,((IData)((((QData)((IData)(
                                                      ((IData)(vlSelf->mandelbrot_toplevel__DOT__Mapper__DOT__X) 
                                                       << 0x15U))) 
                                      * (QData)((IData)(
                                                        VL_DIV_III(32, vlSelf->Re_axis_width, (IData)(vlSelf->x_size))))) 
                                     >> 0x15U))),32);
    bufp->chgIData(oldp+50,((IData)((((QData)((IData)(
                                                      ((IData)(vlSelf->mandelbrot_toplevel__DOT__Mapper__DOT__Y) 
                                                       << 0x15U))) 
                                      * (QData)((IData)(
                                                        VL_DIV_III(32, vlSelf->Im_axis_width, (IData)(vlSelf->y_size))))) 
                                     >> 0x15U))),32);
    bufp->chgQData(oldp+51,(((QData)((IData)(((IData)(vlSelf->mandelbrot_toplevel__DOT__Mapper__DOT__X) 
                                              << 0x15U))) 
                             * (QData)((IData)(VL_DIV_III(32, vlSelf->Re_axis_width, (IData)(vlSelf->x_size)))))),64);
    bufp->chgQData(oldp+53,(((QData)((IData)(((IData)(vlSelf->mandelbrot_toplevel__DOT__Mapper__DOT__Y) 
                                              << 0x15U))) 
                             * (QData)((IData)(VL_DIV_III(32, vlSelf->Im_axis_width, (IData)(vlSelf->y_size)))))),64);
    bufp->chgSData(oldp+55,(vlSelf->mandelbrot_toplevel__DOT__counter_mod__DOT__counter_reg),15);
}

void Vmandelbrot_toplevel___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmandelbrot_toplevel___024root__trace_cleanup\n"); );
    // Init
    Vmandelbrot_toplevel___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vmandelbrot_toplevel___024root*>(voidSelf);
    Vmandelbrot_toplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
}
