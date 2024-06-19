module second_add_clocked(
    input aclk,
    input ld,
    input flag_wait,
    input [31:0] aa_plus_bb,
    input [31:0] aa_minus_bb,
    input [31:0] twoab,
    input [31:0] a0_in,
    input [31:0] b0_in,
    output [31:0] a0_out,
    output [31:0] b0_out,
    output [31:0] muxout1_out,
    output [31:0] muxout2_out
);


reg [31:0] muxout1_out_reg;
reg [31:0] muxout2_out_reg;

reg [31:0] muxout1;
reg [31:0] muxout2;

reg [31:0] s1;
reg [31:0] s2;

reg [31:0] a0_out_reg;
reg [31:0] b0_out_reg;

always @*  begin
    s1 = a0_in + aa_minus_bb;
    s2 = b0_in + twoab;

    muxout1 = flag_wait ? 32'b0 : s1;
    muxout2 = flag_wait ? 32'b0 : s2;
end

always @(posedge aclk) begin
    if (ld) begin 
        a0_out_reg <= 32'b0;
        b0_out_reg <= 32'b0;

        muxout1_out_reg <= 32'b0;
        muxout2_out_reg <= 32'b0;
    end 
    else begin
        a0_out_reg <= a0_in;
        b0_out_reg <= b0_in;

        muxout1_out_reg <= muxout1;
        muxout2_out_reg <= muxout2;
    end 
end 
assign a0_out = a0_out_reg;
assign b0_out = b0_out_reg;
assign muxout1_out = muxout1_out_reg;
assign muxout2_out = muxout2_out_reg;

endmodule
