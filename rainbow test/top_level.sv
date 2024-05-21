module top_level(
    input  logic clk,
    input  logic rst,
    input  logic clr,
    output logic [14:0] RGB_out
);

Counter counter(
    .clk(clk),
    .rst(rst),
    .count()
);

Ram ram(
    .clk(clk),
    .rst(rst),
    .WRITE_EN(),
    .READ_EN(),
    .rd_addr(),
    .wr_addr(),
    .din(),
    .out()
);

Pixel pixel(
    
)
endmodule 

