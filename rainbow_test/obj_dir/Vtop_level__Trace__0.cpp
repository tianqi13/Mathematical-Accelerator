// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop_level__Syms.h"


void Vtop_level___024root__trace_chg_sub_0(Vtop_level___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtop_level___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_level___024root__trace_chg_top_0\n"); );
    // Init
    Vtop_level___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop_level___024root*>(voidSelf);
    Vtop_level__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtop_level___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vtop_level___024root__trace_chg_sub_0(Vtop_level___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_level__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_level___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgSData(oldp+0,(vlSelf->top_level__DOT__count_out),15);
        bufp->chgBit(oldp+1,(vlSelf->top_level__DOT__ovf));
        bufp->chgSData(oldp+2,(vlSelf->top_level__DOT__x),10);
        bufp->chgSData(oldp+3,(vlSelf->top_level__DOT__y),10);
        bufp->chgIData(oldp+4,(vlSelf->top_level__DOT__rd_addr),20);
        bufp->chgBit(oldp+5,((1U & (~ (IData)(vlSelf->top_level__DOT__ovf)))));
        bufp->chgIData(oldp+6,((((IData)(vlSelf->top_level__DOT__y) 
                                 << 0xaU) | (IData)(vlSelf->top_level__DOT__x))),20);
    }
    bufp->chgBit(oldp+7,(vlSelf->clk));
    bufp->chgBit(oldp+8,(vlSelf->enable));
    bufp->chgBit(oldp+9,(vlSelf->rst));
    bufp->chgSData(oldp+10,(vlSelf->RGB_out),15);
    bufp->chgSData(oldp+11,(vlSelf->X),10);
    bufp->chgSData(oldp+12,(vlSelf->Y),10);
}

void Vtop_level___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_level___024root__trace_cleanup\n"); );
    // Init
    Vtop_level___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop_level___024root*>(voidSelf);
    Vtop_level__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
