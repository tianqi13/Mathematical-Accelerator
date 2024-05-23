#!/bin/sh
#cleanup
rm -rf obj-dir
rm -f mandelbrot_toplevel.vcd

#run Verilator to translate Verilog into c++,including c++ testbench
verilator -Wall --cc --trace mandelbrot_toplevel.sv --exe top_tb.cpp

#build C++ project via make automatically generated by Verilator
make -j -C obj_dir/ -f Vmandelbrot_toplevel.mk Vmandelbrot_toplevel

# run executable simulation file
obj_dir/Vmandelbrot_toplevel