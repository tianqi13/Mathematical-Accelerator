module Counter (
    input logic clk,
    input logic rst,
    output logic [14:0] Count
);

always_ff @posedge(clk)
    if (rst) Count 

endmodule 
