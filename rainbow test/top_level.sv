module top_level(
    input  logic clk,
    input  logic enable,
    input  logic rst,
    output logic [14:0] RGB_out
);

logic [14:0] count_out;
Counter counter(
    .clk(clk),
    .rst(rst),
    .en(enable),
    .count(count_out)
);

logic ovf;
logic [9:0] x;
logic [9:0] y;

Pixel pixel(
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
    .addr_counter(rd_addr)
);


Ram ram(
    .clk(clk),
    .WRITE_EN(~ovf),
    .READ_EN(ovf),
    .rd_addr(rd_addr),
    .wr_addr({y,x}),
    .din(count_out),
    .out(RGB_out)
);


endmodule 

