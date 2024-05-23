module mandelbrot_toplevel.sv(
    input logic rst,
    input logic clk,
    input logic en,
    input logic [9:0] x_size,
    input logic [9:0] y_size,
    input logic [31:0] re_axis_width,
    input logic [31:0] im_axis_width,
);

logic [31:0] delta = re_axis_width/x_size;
logic [31:0] a,  // real coordinate
logic [31:0] b   // imag coordinate

mapper MAPPER (
    .clk(clk);
    .X(x_size);
    .Y(y_size);
    .delta(delta);
    .re_axis_width(re_axis_width);
    .im_axis_width(im_axis_width);
    .a(a);  // real coordinate
    .b(b);   // imag coordinate
)

logic [19:0] rd_addr;
Addr_counter addr_counter(
    .clk(clk),
    .rst(rst),
    .en(ovf),
    .addr_count(rd_addr),
    .X(X),
    .Y(Y)
);

Ram ram(
    .clk(clk),
    .WRITE_EN(~ovf),
    .READ_EN(ovf),
    .rd_addr(rd_addr),
    .wr_addr({y,x}),
    .din(count_out),  // input
    .RGB(RGB_out)
);

endmodule
