// Pointer moves through whole image from top left to bottom right in a rastern pattern and stops at each pixel
// and counts the number of iterations it takes for that specific 'pixel' to diverge. It diverges when the absolute
// value of Z_n is greater than 2. The pixels are assigned a color based on how quickly they diverge. It is assigned
// black if it is in the Mandelbrot set, and therefore never diverges, and red if it diverges. Any color between is purely
// for aesthetic appeal and represents how quickly that point diverges. A true Mandelbrot set is black and white.

module Counter (
    input logic clk,
    input logic rst,
    input logic en,
    output logic [14:0] Count
);

always_ff @(posedge clk)
    if (rst) 
        Count <= 15'b0;
    else if (en)
        Count <= Count + 15'b1;


endmodule 
