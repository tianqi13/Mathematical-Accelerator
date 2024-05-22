module ram_top(
    input  logic clk,
    input  logic enable,
    input  logic rst,
    output logic [14:0] RGB_out, // (5, 5, 5)
    output logic [9:0] X,
    output logic [9:0] Y
);

logic [14:0] count_out;
Counter counter(
    .clk(clk),
    .rst(rst),
    .en(enable),
    .Count(count_out)
);

logic ovf;
logic [9:0] x;
logic [9:0] y;

dimensions Dimensions(    // Pull X and Y coordinates (in pixels)
    .clk(clk), 
    .en(enable), 
    .rst(rst),
    .OVF(ovf),
    .X(x),
    .Y(y) 
);

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
