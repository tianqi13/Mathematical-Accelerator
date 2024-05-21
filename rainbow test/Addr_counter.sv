module Addr_counter(
    input logic clk, 
    input logic en, 
    input logic rst, 
    output logic [19:0] addr_counter
);

always_ff @(posedge clk or posedge rst)
begin
    if (rst)
        addr_counter <= 20'b0;
    else if (addr_counter == 20'hFFFFF)
        addr_counter <= 20'b0;
    else if (en)
        addr_counter <= addr_counter + 20'b01;
end

endmodule
