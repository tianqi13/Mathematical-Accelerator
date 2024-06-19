module buffer(
    input aclk,       // Clock input
    input clr,       
    input hit,     
    input [23:0] count,    
    output flag,   
    output [23:0] rgb_out 
);

reg flag_reg;
reg [23:0] rgb_out_reg;

always @(posedge aclk) begin
    if (clr) flag_reg <= 1'b0;

    if (hit) begin
        if (flag_reg == 1'b1) rgb_out_reg <= rgb_out_reg;

        else begin 
            flag_reg <= 1'b1;
            rgb_out_reg <= count;
        end
    end 
end 

assign flag = flag_reg;
assign rgb_out = rgb_out_reg;

endmodule 

