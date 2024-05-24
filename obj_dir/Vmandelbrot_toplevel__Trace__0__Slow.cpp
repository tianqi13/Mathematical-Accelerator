// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vmandelbrot_toplevel__Syms.h"


VL_ATTR_COLD void Vmandelbrot_toplevel___024root__trace_init_sub__TOP__0(Vmandelbrot_toplevel___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vmandelbrot_toplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmandelbrot_toplevel___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+36,"rst", false,-1);
    tracep->declBit(c+37,"clk", false,-1);
    tracep->declBit(c+38,"enable", false,-1);
    tracep->declBus(c+39,"x_size", false,-1, 9,0);
    tracep->declBus(c+40,"y_size", false,-1, 9,0);
    tracep->declBus(c+41,"Re_axis_width", false,-1, 31,0);
    tracep->declBus(c+42,"Im_axis_width", false,-1, 31,0);
    tracep->declBus(c+43,"RGB_out", false,-1, 14,0);
    tracep->declBus(c+44,"X", false,-1, 9,0);
    tracep->declBus(c+45,"Y", false,-1, 9,0);
    tracep->pushNamePrefix("mandelbrot_toplevel ");
    tracep->declBit(c+36,"rst", false,-1);
    tracep->declBit(c+37,"clk", false,-1);
    tracep->declBit(c+38,"enable", false,-1);
    tracep->declBus(c+39,"x_size", false,-1, 9,0);
    tracep->declBus(c+40,"y_size", false,-1, 9,0);
    tracep->declBus(c+41,"Re_axis_width", false,-1, 31,0);
    tracep->declBus(c+42,"Im_axis_width", false,-1, 31,0);
    tracep->declBus(c+43,"RGB_out", false,-1, 14,0);
    tracep->declBus(c+44,"X", false,-1, 9,0);
    tracep->declBus(c+45,"Y", false,-1, 9,0);
    tracep->declBus(c+46,"Delta_x", false,-1, 31,0);
    tracep->declBus(c+47,"Delta_y", false,-1, 31,0);
    tracep->declBus(c+1,"x_internal", false,-1, 9,0);
    tracep->declBus(c+1,"y_internal", false,-1, 9,0);
    tracep->declBit(c+2,"ovf", false,-1);
    tracep->declBus(c+29,"real_internal", false,-1, 31,0);
    tracep->declBus(c+48,"im_internal", false,-1, 31,0);
    tracep->declBit(c+3,"q", false,-1);
    tracep->declBit(c+4,"q_bar", false,-1);
    tracep->declBus(c+5,"counter_out", false,-1, 14,0);
    tracep->declBit(c+6,"ovf_it", false,-1);
    tracep->declBit(c+30,"or_out", false,-1);
    tracep->declBit(c+31,"div", false,-1);
    tracep->declBus(c+7,"rd_addr", false,-1, 19,0);
    tracep->pushNamePrefix("DIVERGE ");
    tracep->declBus(c+29,"a", false,-1, 31,0);
    tracep->declBus(c+48,"b", false,-1, 31,0);
    tracep->declBit(c+30,"ld", false,-1);
    tracep->declBit(c+37,"clk", false,-1);
    tracep->declBit(c+31,"diverged", false,-1);
    tracep->declBus(c+8,"A", false,-1, 31,0);
    tracep->declBus(c+9,"B", false,-1, 31,0);
    tracep->declBus(c+10,"aaplusbb", false,-1, 31,0);
    tracep->declBus(c+11,"aaminusbb", false,-1, 31,0);
    tracep->declBus(c+12,"twoab", false,-1, 31,0);
    tracep->declBus(c+32,"s1", false,-1, 31,0);
    tracep->declBus(c+33,"s2", false,-1, 31,0);
    tracep->declBus(c+34,"muxout1", false,-1, 31,0);
    tracep->declBus(c+35,"muxout2", false,-1, 31,0);
    tracep->pushNamePrefix("GENERATOR ");
    tracep->declBus(c+8,"a", false,-1, 31,0);
    tracep->declBus(c+9,"b", false,-1, 31,0);
    tracep->declBus(c+11,"aa_minus_bb", false,-1, 31,0);
    tracep->declBus(c+12,"two_ab", false,-1, 31,0);
    tracep->declBus(c+10,"aa_plus_bb", false,-1, 31,0);
    tracep->declBus(c+13,"aa", false,-1, 31,0);
    tracep->declBus(c+14,"bb", false,-1, 31,0);
    tracep->declBus(c+15,"ab", false,-1, 31,0);
    tracep->declBus(c+16,"ab_truncated", false,-1, 30,0);
    tracep->pushNamePrefix("a_a ");
    tracep->declBus(c+56,"WIDTH", false,-1, 31,0);
    tracep->declBus(c+8,"a", false,-1, 31,0);
    tracep->declBus(c+8,"b", false,-1, 31,0);
    tracep->declBus(c+13,"result", false,-1, 31,0);
    tracep->declQuad(c+17,"intermediate", false,-1, 63,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("a_b ");
    tracep->declBus(c+56,"WIDTH", false,-1, 31,0);
    tracep->declBus(c+8,"a", false,-1, 31,0);
    tracep->declBus(c+9,"b", false,-1, 31,0);
    tracep->declBus(c+15,"result", false,-1, 31,0);
    tracep->declQuad(c+19,"intermediate", false,-1, 63,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("b_b ");
    tracep->declBus(c+56,"WIDTH", false,-1, 31,0);
    tracep->declBus(c+9,"a", false,-1, 31,0);
    tracep->declBus(c+9,"b", false,-1, 31,0);
    tracep->declBus(c+14,"result", false,-1, 31,0);
    tracep->declQuad(c+21,"intermediate", false,-1, 63,0);
    tracep->popNamePrefix(3);
    tracep->pushNamePrefix("Mapper ");
    tracep->declBit(c+37,"clock", false,-1);
    tracep->declBit(c+36,"rst", false,-1);
    tracep->declBit(c+49,"en", false,-1);
    tracep->declBus(c+46,"delta_x", false,-1, 31,0);
    tracep->declBus(c+47,"delta_y", false,-1, 31,0);
    tracep->declBus(c+41,"re_axis_width", false,-1, 31,0);
    tracep->declBus(c+42,"im_axis_width", false,-1, 31,0);
    tracep->declBus(c+29,"real_s", false,-1, 31,0);
    tracep->declBus(c+48,"ims", false,-1, 31,0);
    tracep->declBit(c+2,"ovf", false,-1);
    tracep->declBus(c+1,"x", false,-1, 9,0);
    tracep->declBus(c+1,"y", false,-1, 9,0);
    tracep->declBus(c+23,"X", false,-1, 9,0);
    tracep->declBus(c+1,"Y", false,-1, 9,0);
    tracep->declBus(c+50,"XtimesDelta", false,-1, 31,0);
    tracep->declBus(c+51,"YtimesDelta", false,-1, 31,0);
    tracep->pushNamePrefix("DIMENSIONS ");
    tracep->declBit(c+37,"clk", false,-1);
    tracep->declBit(c+49,"en", false,-1);
    tracep->declBit(c+36,"rst", false,-1);
    tracep->declBit(c+2,"OVF", false,-1);
    tracep->declBus(c+23,"X", false,-1, 9,0);
    tracep->declBus(c+1,"Y", false,-1, 9,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("XtimesDELTA ");
    tracep->declBus(c+56,"WIDTH", false,-1, 31,0);
    tracep->declBus(c+24,"a", false,-1, 31,0);
    tracep->declBus(c+46,"b", false,-1, 31,0);
    tracep->declBus(c+50,"result", false,-1, 31,0);
    tracep->declQuad(c+52,"intermediate", false,-1, 63,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("YtimesDELTA ");
    tracep->declBus(c+56,"WIDTH", false,-1, 31,0);
    tracep->declBus(c+25,"a", false,-1, 31,0);
    tracep->declBus(c+47,"b", false,-1, 31,0);
    tracep->declBus(c+51,"result", false,-1, 31,0);
    tracep->declQuad(c+54,"intermediate", false,-1, 63,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("addr_counter ");
    tracep->declBit(c+37,"clk", false,-1);
    tracep->declBit(c+2,"en", false,-1);
    tracep->declBit(c+36,"rst", false,-1);
    tracep->declBus(c+7,"addr_count", false,-1, 19,0);
    tracep->declBus(c+44,"X", false,-1, 9,0);
    tracep->declBus(c+45,"Y", false,-1, 9,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("counter_mod ");
    tracep->declBit(c+37,"clk", false,-1);
    tracep->declBit(c+30,"rst", false,-1);
    tracep->declBit(c+38,"en", false,-1);
    tracep->declBus(c+5,"counter", false,-1, 14,0);
    tracep->declBit(c+6,"ovf", false,-1);
    tracep->declBus(c+26,"counter_reg", false,-1, 14,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("ram ");
    tracep->declBus(c+57,"ADDRESS_WIDTH", false,-1, 31,0);
    tracep->declBus(c+58,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBit(c+37,"clk", false,-1);
    tracep->declBit(c+27,"WRITE_EN", false,-1);
    tracep->declBit(c+2,"READ_EN", false,-1);
    tracep->declBus(c+7,"rd_addr", false,-1, 19,0);
    tracep->declBus(c+28,"wr_addr", false,-1, 19,0);
    tracep->declBus(c+5,"din", false,-1, 14,0);
    tracep->declBus(c+43,"RGB", false,-1, 14,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("top_f ");
    tracep->declBit(c+37,"clk", false,-1);
    tracep->declBit(c+2,"s", false,-1);
    tracep->declBit(c+36,"reset", false,-1);
    tracep->declBit(c+3,"q", false,-1);
    tracep->declBit(c+4,"q_bar", false,-1);
    tracep->popNamePrefix(2);
}

VL_ATTR_COLD void Vmandelbrot_toplevel___024root__trace_init_top(Vmandelbrot_toplevel___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vmandelbrot_toplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmandelbrot_toplevel___024root__trace_init_top\n"); );
    // Body
    Vmandelbrot_toplevel___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vmandelbrot_toplevel___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vmandelbrot_toplevel___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vmandelbrot_toplevel___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vmandelbrot_toplevel___024root__trace_register(Vmandelbrot_toplevel___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vmandelbrot_toplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmandelbrot_toplevel___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vmandelbrot_toplevel___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vmandelbrot_toplevel___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vmandelbrot_toplevel___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vmandelbrot_toplevel___024root__trace_full_sub_0(Vmandelbrot_toplevel___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vmandelbrot_toplevel___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmandelbrot_toplevel___024root__trace_full_top_0\n"); );
    // Init
    Vmandelbrot_toplevel___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vmandelbrot_toplevel___024root*>(voidSelf);
    Vmandelbrot_toplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vmandelbrot_toplevel___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vmandelbrot_toplevel___024root__trace_full_sub_0(Vmandelbrot_toplevel___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vmandelbrot_toplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmandelbrot_toplevel___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullSData(oldp+1,(vlSelf->mandelbrot_toplevel__DOT__Mapper__DOT__Y),10);
    bufp->fullBit(oldp+2,(vlSelf->mandelbrot_toplevel__DOT__ovf));
    bufp->fullBit(oldp+3,(vlSelf->mandelbrot_toplevel__DOT__q));
    bufp->fullBit(oldp+4,(vlSelf->mandelbrot_toplevel__DOT__q_bar));
    bufp->fullSData(oldp+5,(vlSelf->mandelbrot_toplevel__DOT__counter_out),15);
    bufp->fullBit(oldp+6,(vlSelf->mandelbrot_toplevel__DOT__ovf_it));
    bufp->fullIData(oldp+7,(vlSelf->mandelbrot_toplevel__DOT__rd_addr),20);
    bufp->fullIData(oldp+8,(vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__A),32);
    bufp->fullIData(oldp+9,(vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__B),32);
    bufp->fullIData(oldp+10,(((IData)((((QData)((IData)(vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__A)) 
                                        * (QData)((IData)(vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__A))) 
                                       >> 0x15U)) + (IData)(
                                                            (((QData)((IData)(vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__B)) 
                                                              * (QData)((IData)(vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__B))) 
                                                             >> 0x15U)))),32);
    bufp->fullIData(oldp+11,(((IData)((((QData)((IData)(vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__A)) 
                                        * (QData)((IData)(vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__A))) 
                                       >> 0x15U)) - (IData)(
                                                            (((QData)((IData)(vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__B)) 
                                                              * (QData)((IData)(vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__B))) 
                                                             >> 0x15U)))),32);
    bufp->fullIData(oldp+12,(vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__twoab),32);
    bufp->fullIData(oldp+13,((IData)((((QData)((IData)(vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__A)) 
                                       * (QData)((IData)(vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__A))) 
                                      >> 0x15U))),32);
    bufp->fullIData(oldp+14,((IData)((((QData)((IData)(vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__B)) 
                                       * (QData)((IData)(vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__B))) 
                                      >> 0x15U))),32);
    bufp->fullIData(oldp+15,((IData)((((QData)((IData)(vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__A)) 
                                       * (QData)((IData)(vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__B))) 
                                      >> 0x15U))),32);
    bufp->fullIData(oldp+16,(vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__GENERATOR__DOT__ab_truncated),31);
    bufp->fullQData(oldp+17,(((QData)((IData)(vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__A)) 
                              * (QData)((IData)(vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__A)))),64);
    bufp->fullQData(oldp+19,(((QData)((IData)(vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__A)) 
                              * (QData)((IData)(vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__B)))),64);
    bufp->fullQData(oldp+21,(((QData)((IData)(vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__B)) 
                              * (QData)((IData)(vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__B)))),64);
    bufp->fullSData(oldp+23,(vlSelf->mandelbrot_toplevel__DOT__Mapper__DOT__X),10);
    bufp->fullIData(oldp+24,(((IData)(vlSelf->mandelbrot_toplevel__DOT__Mapper__DOT__X) 
                              << 0x15U)),32);
    bufp->fullIData(oldp+25,(((IData)(vlSelf->mandelbrot_toplevel__DOT__Mapper__DOT__Y) 
                              << 0x15U)),32);
    bufp->fullSData(oldp+26,(vlSelf->mandelbrot_toplevel__DOT__counter_mod__DOT__counter_reg),15);
    bufp->fullBit(oldp+27,((1U & (~ (IData)(vlSelf->mandelbrot_toplevel__DOT__ovf)))));
    bufp->fullIData(oldp+28,((0xfffffU & (((IData)(vlSelf->mandelbrot_toplevel__DOT__Mapper__DOT__Y) 
                                           << 0xaU) 
                                          | (IData)(vlSelf->mandelbrot_toplevel__DOT__Mapper__DOT__Y)))),20);
    bufp->fullIData(oldp+29,(vlSelf->mandelbrot_toplevel__DOT__real_internal),32);
    bufp->fullBit(oldp+30,(vlSelf->mandelbrot_toplevel__DOT__or_out));
    bufp->fullBit(oldp+31,((0x800000U < vlSelf->mandelbrot_toplevel__DOT__real_internal)));
    bufp->fullIData(oldp+32,(vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__s1),32);
    bufp->fullIData(oldp+33,(vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__s2),32);
    bufp->fullIData(oldp+34,(vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__muxout1),32);
    bufp->fullIData(oldp+35,(vlSelf->mandelbrot_toplevel__DOT__DIVERGE__DOT__muxout2),32);
    bufp->fullBit(oldp+36,(vlSelf->rst));
    bufp->fullBit(oldp+37,(vlSelf->clk));
    bufp->fullBit(oldp+38,(vlSelf->enable));
    bufp->fullSData(oldp+39,(vlSelf->x_size),10);
    bufp->fullSData(oldp+40,(vlSelf->y_size),10);
    bufp->fullIData(oldp+41,(vlSelf->Re_axis_width),32);
    bufp->fullIData(oldp+42,(vlSelf->Im_axis_width),32);
    bufp->fullSData(oldp+43,(vlSelf->RGB_out),15);
    bufp->fullSData(oldp+44,(vlSelf->X),10);
    bufp->fullSData(oldp+45,(vlSelf->Y),10);
    bufp->fullIData(oldp+46,(VL_DIV_III(32, vlSelf->Re_axis_width, (IData)(vlSelf->x_size))),32);
    bufp->fullIData(oldp+47,(VL_DIV_III(32, vlSelf->Im_axis_width, (IData)(vlSelf->y_size))),32);
    bufp->fullIData(oldp+48,(((IData)((((QData)((IData)(
                                                        ((IData)(vlSelf->mandelbrot_toplevel__DOT__Mapper__DOT__Y) 
                                                         << 0x15U))) 
                                        * (QData)((IData)(
                                                          VL_DIV_III(32, vlSelf->Im_axis_width, (IData)(vlSelf->y_size))))) 
                                       >> 0x15U)) + vlSelf->Im_axis_width)),32);
    bufp->fullBit(oldp+49,((((IData)(vlSelf->enable) 
                             & (IData)(vlSelf->mandelbrot_toplevel__DOT__q_bar)) 
                            & (IData)(vlSelf->mandelbrot_toplevel__DOT__or_out))));
    bufp->fullIData(oldp+50,((IData)((((QData)((IData)(
                                                       ((IData)(vlSelf->mandelbrot_toplevel__DOT__Mapper__DOT__X) 
                                                        << 0x15U))) 
                                       * (QData)((IData)(
                                                         VL_DIV_III(32, vlSelf->Re_axis_width, (IData)(vlSelf->x_size))))) 
                                      >> 0x15U))),32);
    bufp->fullIData(oldp+51,((IData)((((QData)((IData)(
                                                       ((IData)(vlSelf->mandelbrot_toplevel__DOT__Mapper__DOT__Y) 
                                                        << 0x15U))) 
                                       * (QData)((IData)(
                                                         VL_DIV_III(32, vlSelf->Im_axis_width, (IData)(vlSelf->y_size))))) 
                                      >> 0x15U))),32);
    bufp->fullQData(oldp+52,(((QData)((IData)(((IData)(vlSelf->mandelbrot_toplevel__DOT__Mapper__DOT__X) 
                                               << 0x15U))) 
                              * (QData)((IData)(VL_DIV_III(32, vlSelf->Re_axis_width, (IData)(vlSelf->x_size)))))),64);
    bufp->fullQData(oldp+54,(((QData)((IData)(((IData)(vlSelf->mandelbrot_toplevel__DOT__Mapper__DOT__Y) 
                                               << 0x15U))) 
                              * (QData)((IData)(VL_DIV_III(32, vlSelf->Im_axis_width, (IData)(vlSelf->y_size)))))),64);
    bufp->fullIData(oldp+56,(0x20U),32);
    bufp->fullIData(oldp+57,(0x14U),32);
    bufp->fullIData(oldp+58,(0xfU),32);
}
