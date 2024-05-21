module Addr_counter(
    input logic clk, 
    input logic en, 
    input logic rst, 
    output logic [19:0] addr_count
);

always_ff @(posedge clk)
begin
    if (rst)
        addr_count <= 20'b0;
    else if (addr_count == 20'hFFFFF)
        addr_count <= 20'b0;
    else if (en)
        addr_count <= addr_count + 20'b01;
end

endmodule
