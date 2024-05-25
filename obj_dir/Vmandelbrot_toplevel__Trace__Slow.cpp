// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vmandelbrot_toplevel__Syms.h"


//======================

void Vmandelbrot_toplevel::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vmandelbrot_toplevel::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vmandelbrot_toplevel__Syms* __restrict vlSymsp = static_cast<Vmandelbrot_toplevel__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vmandelbrot_toplevel::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vmandelbrot_toplevel::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vmandelbrot_toplevel__Syms* __restrict vlSymsp = static_cast<Vmandelbrot_toplevel__Syms*>(userp);
    Vmandelbrot_toplevel* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vmandelbrot_toplevel::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vmandelbrot_toplevel__Syms* __restrict vlSymsp = static_cast<Vmandelbrot_toplevel__Syms*>(userp);
    Vmandelbrot_toplevel* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
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
        tracep->declBit(c+36,"mandelbrot_toplevel rst", false,-1);
        tracep->declBit(c+37,"mandelbrot_toplevel clk", false,-1);
        tracep->declBit(c+38,"mandelbrot_toplevel enable", false,-1);
        tracep->declBus(c+39,"mandelbrot_toplevel x_size", false,-1, 9,0);
        tracep->declBus(c+40,"mandelbrot_toplevel y_size", false,-1, 9,0);
        tracep->declBus(c+41,"mandelbrot_toplevel Re_axis_width", false,-1, 31,0);
        tracep->declBus(c+42,"mandelbrot_toplevel Im_axis_width", false,-1, 31,0);
        tracep->declBus(c+43,"mandelbrot_toplevel RGB_out", false,-1, 14,0);
        tracep->declBus(c+44,"mandelbrot_toplevel X", false,-1, 9,0);
        tracep->declBus(c+45,"mandelbrot_toplevel Y", false,-1, 9,0);
        tracep->declBus(c+46,"mandelbrot_toplevel Delta_x", false,-1, 31,0);
        tracep->declBus(c+47,"mandelbrot_toplevel Delta_y", false,-1, 31,0);
        tracep->declBus(c+1,"mandelbrot_toplevel x_internal", false,-1, 9,0);
        tracep->declBus(c+1,"mandelbrot_toplevel y_internal", false,-1, 9,0);
        tracep->declBit(c+2,"mandelbrot_toplevel ovf", false,-1);
        tracep->declBus(c+29,"mandelbrot_toplevel real_internal", false,-1, 31,0);
        tracep->declBus(c+48,"mandelbrot_toplevel im_internal", false,-1, 31,0);
        tracep->declBit(c+3,"mandelbrot_toplevel q", false,-1);
        tracep->declBit(c+4,"mandelbrot_toplevel q_bar", false,-1);
        tracep->declBus(c+5,"mandelbrot_toplevel counter_out", false,-1, 14,0);
        tracep->declBit(c+6,"mandelbrot_toplevel ovf_it", false,-1);
        tracep->declBit(c+30,"mandelbrot_toplevel or_out", false,-1);
        tracep->declBit(c+31,"mandelbrot_toplevel div", false,-1);
        tracep->declBus(c+7,"mandelbrot_toplevel rd_addr", false,-1, 19,0);
        tracep->declBit(c+37,"mandelbrot_toplevel Mapper clock", false,-1);
        tracep->declBit(c+36,"mandelbrot_toplevel Mapper rst", false,-1);
        tracep->declBit(c+49,"mandelbrot_toplevel Mapper en", false,-1);
        tracep->declBus(c+46,"mandelbrot_toplevel Mapper delta_x", false,-1, 31,0);
        tracep->declBus(c+47,"mandelbrot_toplevel Mapper delta_y", false,-1, 31,0);
        tracep->declBus(c+41,"mandelbrot_toplevel Mapper re_axis_width", false,-1, 31,0);
        tracep->declBus(c+42,"mandelbrot_toplevel Mapper im_axis_width", false,-1, 31,0);
        tracep->declBus(c+29,"mandelbrot_toplevel Mapper real_s", false,-1, 31,0);
        tracep->declBus(c+48,"mandelbrot_toplevel Mapper ims", false,-1, 31,0);
        tracep->declBit(c+2,"mandelbrot_toplevel Mapper ovf", false,-1);
        tracep->declBus(c+1,"mandelbrot_toplevel Mapper x", false,-1, 9,0);
        tracep->declBus(c+1,"mandelbrot_toplevel Mapper y", false,-1, 9,0);
        tracep->declBus(c+8,"mandelbrot_toplevel Mapper X", false,-1, 9,0);
        tracep->declBus(c+1,"mandelbrot_toplevel Mapper Y", false,-1, 9,0);
        tracep->declBus(c+50,"mandelbrot_toplevel Mapper XtimesDelta", false,-1, 31,0);
        tracep->declBus(c+51,"mandelbrot_toplevel Mapper YtimesDelta", false,-1, 31,0);
        tracep->declBit(c+37,"mandelbrot_toplevel Mapper DIMENSIONS clk", false,-1);
        tracep->declBit(c+49,"mandelbrot_toplevel Mapper DIMENSIONS en", false,-1);
        tracep->declBit(c+36,"mandelbrot_toplevel Mapper DIMENSIONS rst", false,-1);
        tracep->declBit(c+2,"mandelbrot_toplevel Mapper DIMENSIONS OVF", false,-1);
        tracep->declBus(c+8,"mandelbrot_toplevel Mapper DIMENSIONS X", false,-1, 9,0);
        tracep->declBus(c+1,"mandelbrot_toplevel Mapper DIMENSIONS Y", false,-1, 9,0);
        tracep->declBus(c+9,"mandelbrot_toplevel Mapper XtimesDELTA a", false,-1, 31,0);
        tracep->declBus(c+46,"mandelbrot_toplevel Mapper XtimesDELTA b", false,-1, 31,0);
        tracep->declBus(c+50,"mandelbrot_toplevel Mapper XtimesDELTA result", false,-1, 31,0);
        tracep->declQuad(c+52,"mandelbrot_toplevel Mapper XtimesDELTA intermediate", false,-1, 63,0);
        tracep->declBus(c+10,"mandelbrot_toplevel Mapper YtimesDELTA a", false,-1, 31,0);
        tracep->declBus(c+47,"mandelbrot_toplevel Mapper YtimesDELTA b", false,-1, 31,0);
        tracep->declBus(c+51,"mandelbrot_toplevel Mapper YtimesDELTA result", false,-1, 31,0);
        tracep->declQuad(c+54,"mandelbrot_toplevel Mapper YtimesDELTA intermediate", false,-1, 63,0);
        tracep->declBus(c+29,"mandelbrot_toplevel DIVERGE a", false,-1, 31,0);
        tracep->declBus(c+48,"mandelbrot_toplevel DIVERGE b", false,-1, 31,0);
        tracep->declBit(c+30,"mandelbrot_toplevel DIVERGE ld", false,-1);
        tracep->declBit(c+37,"mandelbrot_toplevel DIVERGE clk", false,-1);
        tracep->declBit(c+31,"mandelbrot_toplevel DIVERGE diverged", false,-1);
        tracep->declBus(c+11,"mandelbrot_toplevel DIVERGE A", false,-1, 31,0);
        tracep->declBus(c+12,"mandelbrot_toplevel DIVERGE B", false,-1, 31,0);
        tracep->declBus(c+13,"mandelbrot_toplevel DIVERGE aaplusbb", false,-1, 31,0);
        tracep->declBus(c+14,"mandelbrot_toplevel DIVERGE aaminusbb", false,-1, 31,0);
        tracep->declBus(c+15,"mandelbrot_toplevel DIVERGE twoab", false,-1, 31,0);
        tracep->declBus(c+32,"mandelbrot_toplevel DIVERGE s1", false,-1, 31,0);
        tracep->declBus(c+33,"mandelbrot_toplevel DIVERGE s2", false,-1, 31,0);
        tracep->declBus(c+34,"mandelbrot_toplevel DIVERGE muxout1", false,-1, 31,0);
        tracep->declBus(c+35,"mandelbrot_toplevel DIVERGE muxout2", false,-1, 31,0);
        tracep->declBus(c+11,"mandelbrot_toplevel DIVERGE GENERATOR a", false,-1, 31,0);
        tracep->declBus(c+12,"mandelbrot_toplevel DIVERGE GENERATOR b", false,-1, 31,0);
        tracep->declBus(c+14,"mandelbrot_toplevel DIVERGE GENERATOR aa_minus_bb", false,-1, 31,0);
        tracep->declBus(c+15,"mandelbrot_toplevel DIVERGE GENERATOR two_ab", false,-1, 31,0);
        tracep->declBus(c+13,"mandelbrot_toplevel DIVERGE GENERATOR aa_plus_bb", false,-1, 31,0);
        tracep->declBus(c+16,"mandelbrot_toplevel DIVERGE GENERATOR aa", false,-1, 31,0);
        tracep->declBus(c+17,"mandelbrot_toplevel DIVERGE GENERATOR bb", false,-1, 31,0);
        tracep->declBus(c+18,"mandelbrot_toplevel DIVERGE GENERATOR ab", false,-1, 31,0);
        tracep->declBus(c+19,"mandelbrot_toplevel DIVERGE GENERATOR ab_truncated", false,-1, 30,0);
        tracep->declBus(c+11,"mandelbrot_toplevel DIVERGE GENERATOR a_a a", false,-1, 31,0);
        tracep->declBus(c+11,"mandelbrot_toplevel DIVERGE GENERATOR a_a b", false,-1, 31,0);
        tracep->declBus(c+16,"mandelbrot_toplevel DIVERGE GENERATOR a_a result", false,-1, 31,0);
        tracep->declQuad(c+20,"mandelbrot_toplevel DIVERGE GENERATOR a_a intermediate", false,-1, 63,0);
        tracep->declBus(c+12,"mandelbrot_toplevel DIVERGE GENERATOR b_b a", false,-1, 31,0);
        tracep->declBus(c+12,"mandelbrot_toplevel DIVERGE GENERATOR b_b b", false,-1, 31,0);
        tracep->declBus(c+17,"mandelbrot_toplevel DIVERGE GENERATOR b_b result", false,-1, 31,0);
        tracep->declQuad(c+22,"mandelbrot_toplevel DIVERGE GENERATOR b_b intermediate", false,-1, 63,0);
        tracep->declBus(c+11,"mandelbrot_toplevel DIVERGE GENERATOR a_b a", false,-1, 31,0);
        tracep->declBus(c+12,"mandelbrot_toplevel DIVERGE GENERATOR a_b b", false,-1, 31,0);
        tracep->declBus(c+18,"mandelbrot_toplevel DIVERGE GENERATOR a_b result", false,-1, 31,0);
        tracep->declQuad(c+24,"mandelbrot_toplevel DIVERGE GENERATOR a_b intermediate", false,-1, 63,0);
        tracep->declBit(c+37,"mandelbrot_toplevel addr_counter clk", false,-1);
        tracep->declBit(c+2,"mandelbrot_toplevel addr_counter en", false,-1);
        tracep->declBit(c+36,"mandelbrot_toplevel addr_counter rst", false,-1);
        tracep->declBus(c+7,"mandelbrot_toplevel addr_counter addr_count", false,-1, 19,0);
        tracep->declBus(c+44,"mandelbrot_toplevel addr_counter X", false,-1, 9,0);
        tracep->declBus(c+45,"mandelbrot_toplevel addr_counter Y", false,-1, 9,0);
        tracep->declBit(c+37,"mandelbrot_toplevel counter_mod clk", false,-1);
        tracep->declBit(c+30,"mandelbrot_toplevel counter_mod rst", false,-1);
        tracep->declBit(c+38,"mandelbrot_toplevel counter_mod en", false,-1);
        tracep->declBus(c+5,"mandelbrot_toplevel counter_mod counter", false,-1, 14,0);
        tracep->declBit(c+6,"mandelbrot_toplevel counter_mod ovf", false,-1);
        tracep->declBus(c+26,"mandelbrot_toplevel counter_mod counter_reg", false,-1, 14,0);
        tracep->declBus(c+56,"mandelbrot_toplevel ram ADDRESS_WIDTH", false,-1, 31,0);
        tracep->declBus(c+57,"mandelbrot_toplevel ram DATA_WIDTH", false,-1, 31,0);
        tracep->declBit(c+37,"mandelbrot_toplevel ram clk", false,-1);
        tracep->declBit(c+27,"mandelbrot_toplevel ram WRITE_EN", false,-1);
        tracep->declBit(c+2,"mandelbrot_toplevel ram READ_EN", false,-1);
        tracep->declBus(c+7,"mandelbrot_toplevel ram rd_addr", false,-1, 19,0);
        tracep->declBus(c+28,"mandelbrot_toplevel ram wr_addr", false,-1, 19,0);
        tracep->declBus(c+5,"mandelbrot_toplevel ram din", false,-1, 14,0);
        tracep->declBus(c+43,"mandelbrot_toplevel ram RGB", false,-1, 14,0);
        tracep->declBit(c+37,"mandelbrot_toplevel top_f clk", false,-1);
        tracep->declBit(c+2,"mandelbrot_toplevel top_f s", false,-1);
        tracep->declBit(c+36,"mandelbrot_toplevel top_f reset", false,-1);
        tracep->declBit(c+3,"mandelbrot_toplevel top_f q", false,-1);
        tracep->declBit(c+4,"mandelbrot_toplevel top_f q_bar", false,-1);
    }
}

void Vmandelbrot_toplevel::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vmandelbrot_toplevel::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vmandelbrot_toplevel__Syms* __restrict vlSymsp = static_cast<Vmandelbrot_toplevel__Syms*>(userp);
    Vmandelbrot_toplevel* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vmandelbrot_toplevel::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vmandelbrot_toplevel__Syms* __restrict vlSymsp = static_cast<Vmandelbrot_toplevel__Syms*>(userp);
    Vmandelbrot_toplevel* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullSData(oldp+1,(vlTOPp->mandelbrot_toplevel__DOT__Mapper__DOT__Y),10);
        tracep->fullBit(oldp+2,(vlTOPp->mandelbrot_toplevel__DOT__ovf));
        tracep->fullBit(oldp+3,(vlTOPp->mandelbrot_toplevel__DOT__q));
        tracep->fullBit(oldp+4,(vlTOPp->mandelbrot_toplevel__DOT__q_bar));
        tracep->fullSData(oldp+5,(vlTOPp->mandelbrot_toplevel__DOT__counter_out),15);
        tracep->fullBit(oldp+6,(vlTOPp->mandelbrot_toplevel__DOT__ovf_it));
        tracep->fullIData(oldp+7,(vlTOPp->mandelbrot_toplevel__DOT__rd_addr),20);
        tracep->fullSData(oldp+8,(vlTOPp->mandelbrot_toplevel__DOT__Mapper__DOT__X),10);
        tracep->fullIData(oldp+9,(((IData)(vlTOPp->mandelbrot_toplevel__DOT__Mapper__DOT__X) 
                                   << 0x15U)),32);
        tracep->fullIData(oldp+10,(((IData)(vlTOPp->mandelbrot_toplevel__DOT__Mapper__DOT__Y) 
                                    << 0x15U)),32);
        tracep->fullIData(oldp+11,(vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__A),32);
        tracep->fullIData(oldp+12,(vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__B),32);
        tracep->fullIData(oldp+13,(((IData)((((QData)((IData)(vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__A)) 
                                              * (QData)((IData)(vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__A))) 
                                             >> 0x15U)) 
                                    + (IData)((((QData)((IData)(vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__B)) 
                                                * (QData)((IData)(vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__B))) 
                                               >> 0x15U)))),32);
        tracep->fullIData(oldp+14,(((IData)((((QData)((IData)(vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__A)) 
                                              * (QData)((IData)(vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__A))) 
                                             >> 0x15U)) 
                                    - (IData)((((QData)((IData)(vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__B)) 
                                                * (QData)((IData)(vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__B))) 
                                               >> 0x15U)))),32);
        tracep->fullIData(oldp+15,(vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__twoab),32);
        tracep->fullIData(oldp+16,((IData)((((QData)((IData)(vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__A)) 
                                             * (QData)((IData)(vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__A))) 
                                            >> 0x15U))),32);
        tracep->fullIData(oldp+17,((IData)((((QData)((IData)(vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__B)) 
                                             * (QData)((IData)(vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__B))) 
                                            >> 0x15U))),32);
        tracep->fullIData(oldp+18,((IData)((((QData)((IData)(vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__A)) 
                                             * (QData)((IData)(vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__B))) 
                                            >> 0x15U))),32);
        tracep->fullIData(oldp+19,(vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__GENERATOR__DOT__ab_truncated),31);
        tracep->fullQData(oldp+20,(((QData)((IData)(vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__A)) 
                                    * (QData)((IData)(vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__A)))),64);
        tracep->fullQData(oldp+22,(((QData)((IData)(vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__B)) 
                                    * (QData)((IData)(vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__B)))),64);
        tracep->fullQData(oldp+24,(((QData)((IData)(vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__A)) 
                                    * (QData)((IData)(vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__B)))),64);
        tracep->fullSData(oldp+26,(vlTOPp->mandelbrot_toplevel__DOT__counter_mod__DOT__counter_reg),15);
        tracep->fullBit(oldp+27,((1U & (~ (IData)(vlTOPp->mandelbrot_toplevel__DOT__ovf)))));
        tracep->fullIData(oldp+28,((0xfffffU & (((IData)(vlTOPp->mandelbrot_toplevel__DOT__Mapper__DOT__Y) 
                                                 << 0xaU) 
                                                | (IData)(vlTOPp->mandelbrot_toplevel__DOT__Mapper__DOT__Y)))),20);
        tracep->fullIData(oldp+29,(vlTOPp->mandelbrot_toplevel__DOT__real_internal),32);
        tracep->fullBit(oldp+30,(vlTOPp->mandelbrot_toplevel__DOT__or_out));
        tracep->fullBit(oldp+31,((0x800000U < vlTOPp->mandelbrot_toplevel__DOT__real_internal)));
        tracep->fullIData(oldp+32,(vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__s1),32);
        tracep->fullIData(oldp+33,(vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__s2),32);
        tracep->fullIData(oldp+34,(vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__muxout1),32);
        tracep->fullIData(oldp+35,(vlTOPp->mandelbrot_toplevel__DOT__DIVERGE__DOT__muxout2),32);
        tracep->fullBit(oldp+36,(vlTOPp->rst));
        tracep->fullBit(oldp+37,(vlTOPp->clk));
        tracep->fullBit(oldp+38,(vlTOPp->enable));
        tracep->fullSData(oldp+39,(vlTOPp->x_size),10);
        tracep->fullSData(oldp+40,(vlTOPp->y_size),10);
        tracep->fullIData(oldp+41,(vlTOPp->Re_axis_width),32);
        tracep->fullIData(oldp+42,(vlTOPp->Im_axis_width),32);
        tracep->fullSData(oldp+43,(vlTOPp->RGB_out),15);
        tracep->fullSData(oldp+44,(vlTOPp->X),10);
        tracep->fullSData(oldp+45,(vlTOPp->Y),10);
        tracep->fullIData(oldp+46,(VL_DIV_III(32, vlTOPp->Re_axis_width, (IData)(vlTOPp->x_size))),32);
        tracep->fullIData(oldp+47,(VL_DIV_III(32, vlTOPp->Im_axis_width, (IData)(vlTOPp->y_size))),32);
        tracep->fullIData(oldp+48,(((IData)((((QData)((IData)(
                                                              ((IData)(vlTOPp->mandelbrot_toplevel__DOT__Mapper__DOT__Y) 
                                                               << 0x15U))) 
                                              * (QData)((IData)(
                                                                VL_DIV_III(32, vlTOPp->Im_axis_width, (IData)(vlTOPp->y_size))))) 
                                             >> 0x15U)) 
                                    + vlTOPp->Im_axis_width)),32);
        tracep->fullBit(oldp+49,((((IData)(vlTOPp->enable) 
                                   & (IData)(vlTOPp->mandelbrot_toplevel__DOT__q_bar)) 
                                  & (IData)(vlTOPp->mandelbrot_toplevel__DOT__or_out))));
        tracep->fullIData(oldp+50,((IData)((((QData)((IData)(
                                                             ((IData)(vlTOPp->mandelbrot_toplevel__DOT__Mapper__DOT__X) 
                                                              << 0x15U))) 
                                             * (QData)((IData)(
                                                               VL_DIV_III(32, vlTOPp->Re_axis_width, (IData)(vlTOPp->x_size))))) 
                                            >> 0x15U))),32);
        tracep->fullIData(oldp+51,((IData)((((QData)((IData)(
                                                             ((IData)(vlTOPp->mandelbrot_toplevel__DOT__Mapper__DOT__Y) 
                                                              << 0x15U))) 
                                             * (QData)((IData)(
                                                               VL_DIV_III(32, vlTOPp->Im_axis_width, (IData)(vlTOPp->y_size))))) 
                                            >> 0x15U))),32);
        tracep->fullQData(oldp+52,(((QData)((IData)(
                                                    ((IData)(vlTOPp->mandelbrot_toplevel__DOT__Mapper__DOT__X) 
                                                     << 0x15U))) 
                                    * (QData)((IData)(
                                                      VL_DIV_III(32, vlTOPp->Re_axis_width, (IData)(vlTOPp->x_size)))))),64);
        tracep->fullQData(oldp+54,(((QData)((IData)(
                                                    ((IData)(vlTOPp->mandelbrot_toplevel__DOT__Mapper__DOT__Y) 
                                                     << 0x15U))) 
                                    * (QData)((IData)(
                                                      VL_DIV_III(32, vlTOPp->Im_axis_width, (IData)(vlTOPp->y_size)))))),64);
        tracep->fullIData(oldp+56,(0x14U),32);
        tracep->fullIData(oldp+57,(0xfU),32);
    }
}
