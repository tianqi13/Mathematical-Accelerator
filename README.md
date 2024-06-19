# ELEC50015 - Electronics Design Project 2

This repository contains the files used to generate a Mandelbrot and Julia Sets on a PYNQ-Z1 FPGA board, done as part of our Y2 Electronics Design Project at Imperial College London. 

### Overview
- [Group Information](#group-information)
- [Project Introduction](#project-introduction)
- [Version Control](#version-control)


### Group Information 
Our team consisted of:
1. [Bruno Duaso](https://github.com/duasob) EIE
2. [Constance de Lamarliere](https://github.com/constancegdl) EIE
3. [Dylan Winters](https://github.com/diw22) EEE
4. [Jaime Narvaez](https://github.com/Jaimenarvaezh) EEE
5. [Oliver Hannibal](https://github.com/oliver905) EEE
6. [Tianqi Hu](https://github.com/tianqi13) EIE

### Project Introduction 
The project aim was to display a visualisation of a mathematical function that is computed in real time. We chose to visualise Mandelbrot fractals, a self-similar structure that produces visually captivating images. 

To accelerate computational throughput, we implemented our calculations on a PYNQ-Z1 FPGA. We developed several versions of this Mandelbrot Generator, from Single Cycle to Parallel and finally Pipelined implementation. Our most efficient version generated an image 600 times faster than a C++ script. 


We further developed the user interface, integrating functions such as scrolling, zooming in and out, as well as Julia Sets. 


### Version Control 
The 3 versions are: 
1. [Single Cycle]
2. [Parallel_4]
3. [Pipelined] 

All versions contain a different mandelbrot_toplevel.v module. This module outputs the 24 bit RGB values of a Mandelbrot frame in a raster order. These RGB values are fed into packer.v, which packs 4 of these RGB values into 3 32 bit values and is output to downstream logic. Essentially, the mandelbrot_toplevel.module along with packer.v are instantiated in the top level module pixel_generator.v. 

#### Single Cycle: 
This version calculates the RGB value of 1 pixel value at a time. This was also successfully synthesised on the FPGA. 

#### Parallel_4:
This version calculates the RGB value of 4 pixels at a time. However, synthesising this on the FPGA gives a distorted image, as this version expects the calculation to be done in one clock cycle. In such a resource intensive version, this expectation is highly unrealistic and hence timing violations popped up. Therefore it is not recommended to synthesise this version on the FPGA. However, one can still simulate this using the provided testbench and python files. 

#### Pipelined:
This is the final version. This version calculates the RGB value of 4 pixels at a time, but only one calculation block is used and each pixel is fed into the block one at a time. Each step of the calculation is clocked, so essentially the calculation takes 4 clock cycles. This step allowed us to successfully generate a perfect mandelbrot image on the FPGA, whilst utilising around the same amount of resources as the Single Cycle. It is highly recommended to synthesise this version and to try this out on your own. 


### Simulate on VSCode 
The synthesising process on Vivado is time consuming. An alternative way to view the Mandelbrot generated is to clone this repository onto your computer, and open on VSCode. The testbench file is generate_tb.v. This file simulates the pixel_generator.v file and prints each 32 bit value (from packer.v) and its corresponding xCount and yCount to a text file .txt. Run this file until you see the line: simulation complete in the terminal. 

Now, run the 4to3converter.py script. This python script contains a state machine that emulates the one in packer.v, essentially decoding the 32 bit concatenated value back to 24 bit RGB values. A new .txt file is generated containing the RGB values in order. 

Finally, run the photogen.py script. This python script reads each line in the .txt file and produces a .png image. You can now view the result of the simulation -- you should see that a Mandelbrot is generated!


### Bitstream and Hardware Handoff files 
You will find the generated .bit and .hwh files for each version in the corresponding branches. To run these files on the Jupyter notebook, download these files onto your computer. 

Connect your PYNQ-Z1 boards to your computer. The default IP address of the PYNQ board is 192.168.2.99. Open File Explorer on your computer and go to the Network folder. In the search bar, key in "//192.168.2.99". This should take you to an interface with a folder named Xillinx. Open this folder and drag the .bit and .hwh file into this folder. Make sure to rename both files to the same name. 

Now, open the board's Jupyter Notebook by typing the board's IP address in the search bar of a Search Engine such as Google. If the board is connected properly, a Jupyter Notebook should generate and ask for a password. The default password is xilinx. 

Upload the 

