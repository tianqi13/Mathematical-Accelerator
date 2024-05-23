// This module maps the pixel coordinates (X and Y) onto the complex plane displaying the Mandelbrot visualisation.

module mapper(
    input logic clock,
    input logic rst,
    input logic en,
    input logic [31:0] delta_x,
    input logic [31:0] delta_y,
    input logic [31:0] re_axis_width,
    input logic [31:0] im_axis_width,
    output logic [31:0] real_s,
    output logic [31:0] ims,
    output logic        ovf,
    output logic [31:0] x,
    output logic [31:0] y
);

logic [9:0]  X;
logic [9:0]  Y;
logic [31:0] XtimesDelta;
logic [31:0] YtimesDelta;

dimensions DIMENSIONS(
    .clk(clock),
    .en(en),
    .rst(rst),
    .OVF(ovf),
    .X(X),
    .Y(Y)
);

multiplier XtimesDELTA(
    .a({1'b0, X, 21'b0}),
    .b(delta_x),
    .result(XtimesDelta)
);

multiplier YtimesDELTA(
    .a({1'b0, Y, 21'b0}),
    .b(delta_y),
    .result(YtimesDelta)
);

always_comb begin
    x = {1'b0, X, 21'b0};
    y = {1'b0, Y, 21'b0};
    real_s = XtimesDelta + re_axis_width;
    ims = YtimesDelta + im_axis_width;
end

endmodule
