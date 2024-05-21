module counter (
    input logic clk,
    input logic rst,
    output logic [14:0] Count
);

always_ff @posedge(clk)
    if (rst) 
        Count <= 15'b0;
    else 
        Count <= Count + 15'b0100;


endmodule 
