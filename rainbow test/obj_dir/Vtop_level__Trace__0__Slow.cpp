// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop_level__Syms.h"


VL_ATTR_COLD void Vtop_level___024root__trace_init_sub__TOP__0(Vtop_level___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_level__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_level___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+6,"clk", false,-1);
    tracep->declBit(c+7,"enable", false,-1);
    tracep->declBit(c+8,"rst", false,-1);
    tracep->declBus(c+9,"RGB_out", false,-1, 14,0);
    tracep->pushNamePrefix("top_level ");
    tracep->declBit(c+6,"clk", false,-1);
    tracep->declBit(c+7,"enable", false,-1);
    tracep->declBit(c+8,"rst", false,-1);
    tracep->declBus(c+9,"RGB_out", false,-1, 14,0);
    tracep->declBus(c+10,"count_out", false,-1, 14,0);
    tracep->declBit(c+1,"ovf", false,-1);
    tracep->declBus(c+2,"x", false,-1, 9,0);
    tracep->declBus(c+3,"y", false,-1, 9,0);
    tracep->declBus(c+11,"rd_addr", false,-1, 19,0);
    tracep->pushNamePrefix("addr_counter ");
    tracep->declBit(c+6,"clk", false,-1);
    tracep->declBit(c+1,"en", false,-1);
    tracep->declBit(c+8,"rst", false,-1);
    tracep->declBus(c+11,"addr_count", false,-1, 19,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("counter ");
    tracep->declBit(c+6,"clk", false,-1);
    tracep->declBit(c+8,"rst", false,-1);
    tracep->declBit(c+7,"en", false,-1);
    tracep->declBus(c+10,"Count", false,-1, 14,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("pixel ");
    tracep->declBit(c+6,"clk", false,-1);
    tracep->declBit(c+7,"en", false,-1);
    tracep->declBit(c+8,"rst", false,-1);
    tracep->declBit(c+1,"OVF", false,-1);
    tracep->declBus(c+2,"X", false,-1, 9,0);
    tracep->declBus(c+3,"Y", false,-1, 9,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("ram ");
    tracep->declBus(c+12,"ADDRESS_WIDTH", false,-1, 31,0);
    tracep->declBus(c+13,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBit(c+6,"clk", false,-1);
    tracep->declBit(c+4,"WRITE_EN", false,-1);
    tracep->declBit(c+1,"READ_EN", false,-1);
    tracep->declBus(c+11,"rd_addr", false,-1, 19,0);
    tracep->declBus(c+5,"wr_addr", false,-1, 19,0);
    tracep->declBus(c+10,"din", false,-1, 14,0);
    tracep->declBus(c+9,"RGB", false,-1, 14,0);
    tracep->popNamePrefix(2);
}

VL_ATTR_COLD void Vtop_level___024root__trace_init_top(Vtop_level___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_level__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_level___024root__trace_init_top\n"); );
    // Body
    Vtop_level___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtop_level___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtop_level___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtop_level___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vtop_level___024root__trace_register(Vtop_level___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_level__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_level___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vtop_level___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vtop_level___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vtop_level___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtop_level___024root__trace_full_sub_0(Vtop_level___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtop_level___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_level___024root__trace_full_top_0\n"); );
    // Init
    Vtop_level___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop_level___024root*>(voidSelf);
    Vtop_level__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtop_level___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtop_level___024root__trace_full_sub_0(Vtop_level___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_level__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_level___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelf->top_level__DOT__ovf));
    bufp->fullSData(oldp+2,(vlSelf->top_level__DOT__x),10);
    bufp->fullSData(oldp+3,(vlSelf->top_level__DOT__y),10);
    bufp->fullBit(oldp+4,((1U & (~ (IData)(vlSelf->top_level__DOT__ovf)))));
    bufp->fullIData(oldp+5,((((IData)(vlSelf->top_level__DOT__y) 
                              << 0xaU) | (IData)(vlSelf->top_level__DOT__x))),20);
    bufp->fullBit(oldp+6,(vlSelf->clk));
    bufp->fullBit(oldp+7,(vlSelf->enable));
    bufp->fullBit(oldp+8,(vlSelf->rst));
    bufp->fullSData(oldp+9,(vlSelf->RGB_out),15);
    bufp->fullSData(oldp+10,(vlSelf->top_level__DOT__count_out),15);
    bufp->fullIData(oldp+11,(vlSelf->top_level__DOT__rd_addr),20);
    bufp->fullIData(oldp+12,(0x14U),32);
    bufp->fullIData(oldp+13,(0xfU),32);
}
