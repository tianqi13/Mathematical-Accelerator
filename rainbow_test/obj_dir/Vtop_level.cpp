// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtop_level.h"
#include "Vtop_level__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vtop_level::Vtop_level(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vtop_level__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , enable{vlSymsp->TOP.enable}
    , rst{vlSymsp->TOP.rst}
    , RGB_out{vlSymsp->TOP.RGB_out}
    , X{vlSymsp->TOP.X}
    , Y{vlSymsp->TOP.Y}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vtop_level::Vtop_level(const char* _vcname__)
    : Vtop_level(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vtop_level::~Vtop_level() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vtop_level___024root___eval_debug_assertions(Vtop_level___024root* vlSelf);
#endif  // VL_DEBUG
void Vtop_level___024root___eval_static(Vtop_level___024root* vlSelf);
void Vtop_level___024root___eval_initial(Vtop_level___024root* vlSelf);
void Vtop_level___024root___eval_settle(Vtop_level___024root* vlSelf);
void Vtop_level___024root___eval(Vtop_level___024root* vlSelf);

void Vtop_level::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtop_level::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vtop_level___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vtop_level___024root___eval_static(&(vlSymsp->TOP));
        Vtop_level___024root___eval_initial(&(vlSymsp->TOP));
        Vtop_level___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vtop_level___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vtop_level::eventsPending() { return false; }

uint64_t Vtop_level::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vtop_level::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vtop_level___024root___eval_final(Vtop_level___024root* vlSelf);

VL_ATTR_COLD void Vtop_level::final() {
    Vtop_level___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vtop_level::hierName() const { return vlSymsp->name(); }
const char* Vtop_level::modelName() const { return "Vtop_level"; }
unsigned Vtop_level::threads() const { return 1; }
void Vtop_level::prepareClone() const { contextp()->prepareClone(); }
void Vtop_level::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vtop_level::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vtop_level___024root__trace_init_top(Vtop_level___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vtop_level___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop_level___024root*>(voidSelf);
    Vtop_level__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    Vtop_level___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void Vtop_level___024root__trace_register(Vtop_level___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vtop_level::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vtop_level::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vtop_level___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
