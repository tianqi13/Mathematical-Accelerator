// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VMANDELBROT_TOPLEVEL__SYMS_H_
#define VERILATED_VMANDELBROT_TOPLEVEL__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vmandelbrot_toplevel.h"

// INCLUDE MODULE CLASSES
#include "Vmandelbrot_toplevel___024root.h"

// SYMS CLASS (contains all model state)
class Vmandelbrot_toplevel__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vmandelbrot_toplevel* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vmandelbrot_toplevel___024root TOP;

    // CONSTRUCTORS
    Vmandelbrot_toplevel__Syms(VerilatedContext* contextp, const char* namep, Vmandelbrot_toplevel* modelp);
    ~Vmandelbrot_toplevel__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
