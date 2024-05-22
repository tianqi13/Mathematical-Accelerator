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
