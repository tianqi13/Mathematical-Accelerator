module mandelbrot_toplevel.sv(
    input logic rst,
    input logic clk,
    input logic en,
    input logic x_size,
    input logic y_size,
);

mapper MAPPER (

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
