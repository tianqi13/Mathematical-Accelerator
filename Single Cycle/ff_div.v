module ff_div(
    input aclk,
    input [31:0] s,
    output [31:0] q
);
reg [31:0] q_reg;

always @(posedge aclk) begin
    q_reg <= s;
end

assign q = q_reg;
endmodule
