// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmandelbrot_toplevel.h for the primary calling header

#include "verilated.h"

#include "Vmandelbrot_toplevel__Syms.h"
#include "Vmandelbrot_toplevel___024root.h"

void Vmandelbrot_toplevel___024root___ctor_var_reset(Vmandelbrot_toplevel___024root* vlSelf);

Vmandelbrot_toplevel___024root::Vmandelbrot_toplevel___024root(Vmandelbrot_toplevel__Syms* symsp, const char* name)
    : VerilatedModule{name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vmandelbrot_toplevel___024root___ctor_var_reset(this);
}

void Vmandelbrot_toplevel___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vmandelbrot_toplevel___024root::~Vmandelbrot_toplevel___024root() {
}
