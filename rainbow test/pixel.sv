module Pixel (
    input logic clk, 
    input logic en, 
    input logic rst,
    output logic OVF,
    output logic [9:0] X,
    output logic [9:0] Y
);

always_ff @(posedge clk)
    if (rst) begin
        X <= 10'b0;
        Y <= 10'b0;
        OVF <= 1'b0;
    end 

    else if (X == 10'h3FF) begin 
        if (Y == 10'h2FF)
            OVF <= 1;
            Y <= 10'b0;
    end 

    else 
        X <= X + 10'b01



endmodule

