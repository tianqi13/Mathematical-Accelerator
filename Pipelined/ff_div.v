module ff_div(
    input aclk,
    input ld,
    input aresetn,
    input [31:0] s1,
    input [31:0] s2,
    input [31:0] a0_in,
    input [31:0] b0_in,
    output [31:0] a0_out,
    output [31:0] b0_out,
    output [31:0] q1,
    output [31:0] q2
);
reg [31:0] q1_reg;
reg [31:0] q2_reg;
reg [31:0] a0_out_reg;
reg [31:0] b0_out_reg;

always @(posedge aclk) begin
    if (ld || aresetn) begin 
        q1_reg <= 32'b0;
        q2_reg <= 32'b0;
        a0_out_reg <= 32'b0;
        b0_out_reg <= 32'b0;
    end 

    else begin
        q1_reg <= s1;
        q2_reg <= s2;
        a0_out_reg <= a0_in;
        b0_out_reg <= b0_in;
    end 
end

assign q1 = q1_reg;
assign q2 = q2_reg;
assign a0_out = a0_out_reg;
assign b0_out = b0_out_reg;

endmodule
