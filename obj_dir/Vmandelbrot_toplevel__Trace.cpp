// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vmandelbrot_toplevel__Syms.h"


void Vmandelbrot_toplevel::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    Vmandelbrot_toplevel__Syms* __restrict vlSymsp = static_cast<Vmandelbrot_toplevel__Syms*>(userp);
    Vmandelbrot_toplevel* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Vmandelbrot_toplevel::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    Vmandelbrot_toplevel__Syms* __restrict vlSymsp = static_cast<Vmandelbrot_toplevel__Syms*>(userp);
    Vmandelbrot_toplevel* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgSData(oldp+0,(vlTOPp->mandelbrot_toplevel__DOT__Mapper__DOT__Y),10);
            tracep->chgBit(oldp+1,(vlTOPp->mandelbrot_toplevel__DOT__ovf));
            tracep->chgBit(oldp+2,(vlTOPp->mandelbrot_toplevel__DOT__q));
            tracep->chgBit(oldp+3,(vlTOPp->mandelbrot_toplevel__DOT__q_bar));
            tracep->chgSData(oldp+4,(vlTOPp->mandelbrot_toplevel__DOT__counter_out),15);
            tracep->chgBit(oldp+5,(vlTOPp->mandelbrot_toplevel__DOT__ovf_it));
            tracep->chgIData(oldp+6,(vlTOPp->mandelbrot_toplevel__DOT__rd_addr),20);
            tracep->chgSData(oldp+7,(vlTOPp->mandelbrot_toplevel__DOT__Mapper__DOT__X),10);
            tracep->chgIData(oldp+8,(((IData)(vlTOPp->mandelbrot_toplevel__DOT__Mapper__DOT__X) 
                                      << 0x15U)),32);
            tracep->chgIData(oldp+9,(((IData)(vlTOPp->mandelbrot_toplevel__DOT__Mapper__DOT__Y) 
                                      << 0x15U)),32);
            tracep->chgIData(oldp+10,(vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__A),32);
            tracep->chgIData(oldp+11,(vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__B),32);
            tracep->chgIData(oldp+12,(((IData)((((QData)((IData)(vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__A)) 
                                                 * (QData)((IData)(vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__A))) 
                                                >> 0x15U)) 
                                       + (IData)((((QData)((IData)(vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__B)) 
                                                   * (QData)((IData)(vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__B))) 
                                                  >> 0x15U)))),32);
            tracep->chgIData(oldp+13,(((IData)((((QData)((IData)(vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__A)) 
                                                 * (QData)((IData)(vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__A))) 
                                                >> 0x15U)) 
                                       - (IData)((((QData)((IData)(vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__B)) 
                                                   * (QData)((IData)(vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__B))) 
                                                  >> 0x15U)))),32);
            tracep->chgIData(oldp+14,(vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__twoab),32);
            tracep->chgIData(oldp+15,((IData)((((QData)((IData)(vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__A)) 
                                                * (QData)((IData)(vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__A))) 
                                               >> 0x15U))),32);
            tracep->chgIData(oldp+16,((IData)((((QData)((IData)(vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__B)) 
                                                * (QData)((IData)(vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__B))) 
                                               >> 0x15U))),32);
            tracep->chgIData(oldp+17,((IData)((((QData)((IData)(vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__A)) 
                                                * (QData)((IData)(vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__B))) 
                                               >> 0x15U))),32);
            tracep->chgIData(oldp+18,(vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__GENERATOR__DOT__ab_truncated),31);
            tracep->chgQData(oldp+19,(((QData)((IData)(vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__A)) 
                                       * (QData)((IData)(vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__A)))),64);
            tracep->chgQData(oldp+21,(((QData)((IData)(vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__B)) 
                                       * (QData)((IData)(vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__B)))),64);
            tracep->chgQData(oldp+23,(((QData)((IData)(vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__A)) 
                                       * (QData)((IData)(vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__B)))),64);
            tracep->chgSData(oldp+25,(vlTOPp->mandelbrot_toplevel__DOT__counter_mod__DOT__counter_reg),15);
            tracep->chgBit(oldp+26,((1U & (~ (IData)(vlTOPp->mandelbrot_toplevel__DOT__ovf)))));
            tracep->chgIData(oldp+27,((0xfffffU & (
                                                   ((IData)(vlTOPp->mandelbrot_toplevel__DOT__Mapper__DOT__Y) 
                                                    << 0xaU) 
                                                   | (IData)(vlTOPp->mandelbrot_toplevel__DOT__Mapper__DOT__Y)))),20);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[2U])) {
            tracep->chgIData(oldp+28,(vlTOPp->mandelbrot_toplevel__DOT__real_internal),32);
            tracep->chgBit(oldp+29,(vlTOPp->mandelbrot_toplevel__DOT__or_out));
            tracep->chgBit(oldp+30,((0x800000U < vlTOPp->mandelbrot_toplevel__DOT__real_internal)));
            tracep->chgIData(oldp+31,(vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__s1),32);
            tracep->chgIData(oldp+32,(vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__s2),32);
            tracep->chgIData(oldp+33,(vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__muxout1),32);
            tracep->chgIData(oldp+34,(vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__muxout2),32);
        }
        tracep->chgBit(oldp+35,(vlTOPp->rst));
        tracep->chgBit(oldp+36,(vlTOPp->clk));
        tracep->chgBit(oldp+37,(vlTOPp->enable));
        tracep->chgSData(oldp+38,(vlTOPp->x_size),10);
        tracep->chgSData(oldp+39,(vlTOPp->y_size),10);
        tracep->chgIData(oldp+40,(vlTOPp->Re_axis_width),32);
        tracep->chgIData(oldp+41,(vlTOPp->Im_axis_width),32);
        tracep->chgSData(oldp+42,(vlTOPp->RGB_out),15);
        tracep->chgSData(oldp+43,(vlTOPp->X),10);
        tracep->chgSData(oldp+44,(vlTOPp->Y),10);
        tracep->chgIData(oldp+45,(VL_DIV_III(32, vlTOPp->Re_axis_width, (IData)(vlTOPp->x_size))),32);
        tracep->chgIData(oldp+46,(VL_DIV_III(32, vlTOPp->Im_axis_width, (IData)(vlTOPp->y_size))),32);
        tracep->chgIData(oldp+47,(((IData)((((QData)((IData)(
                                                             ((IData)(vlTOPp->mandelbrot_toplevel__DOT__Mapper__DOT__Y) 
                                                              << 0x15U))) 
                                             * (QData)((IData)(
                                                               VL_DIV_III(32, vlTOPp->Im_axis_width, (IData)(vlTOPp->y_size))))) 
                                            >> 0x15U)) 
                                   + vlTOPp->Im_axis_width)),32);
        tracep->chgBit(oldp+48,((((IData)(vlTOPp->enable) 
                                  & (IData)(vlTOPp->mandelbrot_toplevel__DOT__q_bar)) 
                                 & (IData)(vlTOPp->mandelbrot_toplevel__DOT__or_out))));
        tracep->chgIData(oldp+49,((IData)((((QData)((IData)(
                                                            ((IData)(vlTOPp->mandelbrot_toplevel__DOT__Mapper__DOT__X) 
                                                             << 0x15U))) 
                                            * (QData)((IData)(
                                                              VL_DIV_III(32, vlTOPp->Re_axis_width, (IData)(vlTOPp->x_size))))) 
                                           >> 0x15U))),32);
        tracep->chgIData(oldp+50,((IData)((((QData)((IData)(
                                                            ((IData)(vlTOPp->mandelbrot_toplevel__DOT__Mapper__DOT__Y) 
                                                             << 0x15U))) 
                                            * (QData)((IData)(
                                                              VL_DIV_III(32, vlTOPp->Im_axis_width, (IData)(vlTOPp->y_size))))) 
                                           >> 0x15U))),32);
        tracep->chgQData(oldp+51,(((QData)((IData)(
                                                   ((IData)(vlTOPp->mandelbrot_toplevel__DOT__Mapper__DOT__X) 
                                                    << 0x15U))) 
                                   * (QData)((IData)(
                                                     VL_DIV_III(32, vlTOPp->Re_axis_width, (IData)(vlTOPp->x_size)))))),64);
        tracep->chgQData(oldp+53,(((QData)((IData)(
                                                   ((IData)(vlTOPp->mandelbrot_toplevel__DOT__Mapper__DOT__Y) 
                                                    << 0x15U))) 
                                   * (QData)((IData)(
                                                     VL_DIV_III(32, vlTOPp->Im_axis_width, (IData)(vlTOPp->y_size)))))),64);
    }
}

void Vmandelbrot_toplevel::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vmandelbrot_toplevel__Syms* __restrict vlSymsp = static_cast<Vmandelbrot_toplevel__Syms*>(userp);
    Vmandelbrot_toplevel* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
        vlTOPp->__Vm_traceActivity[1U] = 0U;
        vlTOPp->__Vm_traceActivity[2U] = 0U;
    }
}
