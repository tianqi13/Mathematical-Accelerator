#include "Vmandelbrot_toplevel.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "iostream"
#include "fstream"
#include "bitset"

int main(int argc, char **argv, char **env)
{
    int i;   // keeps track of number of clock cycle simulations
    int clk; // clock signal

    Verilated::commandArgs(argc, argv);

    Vtop_level *top = new Vmandelbrot_toplevel;
    Verilated::traceEverOn(true);
    VerilatedVcdC *tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open("top_test.vcd");

    std::ofstream outputFile("rgbtop_data.txt");
    if (!outputFile.is_open()) {
        std::cerr << "Error: Could not open file for writing." << std::endl;
        exit(1);
    }

    // initialize simulation inputs
    
    top->enable = 1;
    top->rst = 1;

    // run simulation for many clock cylces
    for (i = 0; i < 30000; i++)
    {
        for (clk = 0; clk < 2; clk++)
        {
            tfp->dump(2 * i + clk);
            top->clk = !top->clk;
            top->eval();
        }
        if (i > 4){
            top-> rst = 0;
        }
        if (top->RGB_out != 0){
            std::bitset<15> rgb_binary(top->RGB_out);
            outputFile << rgb_binary << " " << top->X << " " << top->Y << std::endl;
        }

        // either simulation finished, or 'q' is pressed
        if ((Verilated::gotFinish()))
        {
            exit(0);
        }
        // ... exit if finish OR 'q' pressed
    }

    tfp->close();
    std::cout << "sim completed" << std::endl;
    exit(0);
}
