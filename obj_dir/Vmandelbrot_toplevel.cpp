// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vmandelbrot_toplevel.h"
#include "Vmandelbrot_toplevel__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vmandelbrot_toplevel::Vmandelbrot_toplevel(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vmandelbrot_toplevel__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst{vlSymsp->TOP.rst}
    , enable{vlSymsp->TOP.enable}
    , x_size{vlSymsp->TOP.x_size}
    , y_size{vlSymsp->TOP.y_size}
    , RGB_out{vlSymsp->TOP.RGB_out}
    , X{vlSymsp->TOP.X}
    , Y{vlSymsp->TOP.Y}
    , Re_axis_width{vlSymsp->TOP.Re_axis_width}
    , Im_axis_width{vlSymsp->TOP.Im_axis_width}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vmandelbrot_toplevel::Vmandelbrot_toplevel(const char* _vcname__)
    : Vmandelbrot_toplevel(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vmandelbrot_toplevel::~Vmandelbrot_toplevel() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vmandelbrot_toplevel___024root___eval_initial(Vmandelbrot_toplevel___024root* vlSelf);
void Vmandelbrot_toplevel___024root___eval_settle(Vmandelbrot_toplevel___024root* vlSelf);
void Vmandelbrot_toplevel___024root___eval(Vmandelbrot_toplevel___024root* vlSelf);
QData Vmandelbrot_toplevel___024root___change_request(Vmandelbrot_toplevel___024root* vlSelf);
#ifdef VL_DEBUG
void Vmandelbrot_toplevel___024root___eval_debug_assertions(Vmandelbrot_toplevel___024root* vlSelf);
#endif  // VL_DEBUG
void Vmandelbrot_toplevel___024root___final(Vmandelbrot_toplevel___024root* vlSelf);

static void _eval_initial_loop(Vmandelbrot_toplevel__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vmandelbrot_toplevel___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vmandelbrot_toplevel___024root___eval_settle(&(vlSymsp->TOP));
        Vmandelbrot_toplevel___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = Vmandelbrot_toplevel___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("mandelbrot_toplevel.sv", 1, "",
                "Verilated model didn't DC converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = Vmandelbrot_toplevel___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vmandelbrot_toplevel::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vmandelbrot_toplevel::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vmandelbrot_toplevel___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vmandelbrot_toplevel___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = Vmandelbrot_toplevel___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("mandelbrot_toplevel.sv", 1, "",
                "Verilated model didn't converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = Vmandelbrot_toplevel___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
    // Evaluate cleanup
}

//============================================================
// Utilities

const char* Vmandelbrot_toplevel::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vmandelbrot_toplevel::final() {
    Vmandelbrot_toplevel___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vmandelbrot_toplevel::hierName() const { return vlSymsp->name(); }
const char* Vmandelbrot_toplevel::modelName() const { return "Vmandelbrot_toplevel"; }
unsigned Vmandelbrot_toplevel::threads() const { return 1; }
std::unique_ptr<VerilatedTraceConfig> Vmandelbrot_toplevel::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vmandelbrot_toplevel___024root__trace_init_top(Vmandelbrot_toplevel___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vmandelbrot_toplevel___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vmandelbrot_toplevel___024root*>(voidSelf);
    Vmandelbrot_toplevel__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    Vmandelbrot_toplevel___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void Vmandelbrot_toplevel___024root__trace_register(Vmandelbrot_toplevel___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vmandelbrot_toplevel::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vmandelbrot_toplevel___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
