// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef _VMANDELBROT_TOPLEVEL__SYMS_H_
#define _VMANDELBROT_TOPLEVEL__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODULE CLASSES
#include "Vmandelbrot_toplevel.h"

// SYMS CLASS
class Vmandelbrot_toplevel__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_activity;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode;  ///< Used by trace routines when tracing multiple models
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vmandelbrot_toplevel*          TOPp;
    
    // CREATORS
    Vmandelbrot_toplevel__Syms(Vmandelbrot_toplevel* topp, const char* namep);
    ~Vmandelbrot_toplevel__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
