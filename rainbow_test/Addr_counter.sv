module Addr_counter(
    input logic clk, 
    input logic en, 
    input logic rst, 
    output logic [19:0] addr_count
    output logic [9:0] X,
    output logic [9:0] Y
);

always_ff @(posedge clk)
begin
    if (rst)
        addr_count <= 20'b0;
    else if (addr_count == 20'hFFFFF)
        addr_count <= 20'b0;
    else if (en)
        addr_count <= addr_count + 20'b01;
        X <= {addr_count[9:0]}
        Y <= {addr_count[19:10]}
end

endmodule
