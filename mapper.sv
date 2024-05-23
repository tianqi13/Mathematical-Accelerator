// This module maps the pixel coordinates (X and Y) onto the complex plane displaying the Mandelbrot visualisation.

module mapper(
    input logic clk,
    input logic rst,
    input logic en,
    input logic [9:0]  X,
    input logic [9:0]  Y,
    input logic [31:0] delta_x,
    input logic [31:0] delta_y,
    input logic [31:0] re_axis_width,
    input logic [31:0] im_axis_width,
    output logic [31:0] a,  // real coordinate
    output logic [31:0] b   // imag coordinate
);

logic [31:0] XtimesDelta;
logic [31:0] YtimesDelta;

multiplier XtimesDELTA(
    .clk(clk);
    .a({1'b0, X, 21'b0});
    .b(delta_x);
    .result(XtimesDelta);
)

multiplier YtimesDELTA(
    .clk(clk);
    .a({1'b0, Y, 21'b0});
    .b(delta_y);
    .result(YtimesDelta);
)

assign a = XtimesDelta + re_axis_width;
assign b = YtimesDelta + im_axis_width;

endmodule
