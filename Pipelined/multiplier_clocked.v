module multiplier_clocked(
    input aclk,
    input [31:0] a,   
    input [31:0] b,
    input ld,
    input [31:0] a0_in,
    input [31:0] b0_in,
    output [31:0] a0_out,
    output [31:0] b0_out,
    output [31:0] aa_out,
    output [31:0] bb_out,
    output [31:0] ab_out
);

reg [31:0] a0_out_reg;
reg [31:0] b0_out_reg;
reg [31:0] aa_out_reg;
reg [31:0] bb_out_reg;
reg [31:0] ab_out_reg;
wire [31:0] aa;
wire [31:0] bb;
wire [31:0] ab;

multiplier a_a (
    .a(a),
    .b(a),
    .result(aa)
);

multiplier b_b (
    .a(b),
    .b(b),
    .result(bb)
);

multiplier a_b (
    .a(a),
    .b(b),
    .result(ab)
);

always @(posedge aclk) begin
    if (ld) begin 
        a0_out_reg <= 32'b0;
        b0_out_reg <= 32'b0;
        aa_out_reg <= 32'b0;
        bb_out_reg <= 32'b0;
        ab_out_reg <= 32'b0;
    end 

    else begin
        a0_out_reg <= a0_in;
        b0_out_reg <= b0_in;
        aa_out_reg <= aa;
        bb_out_reg <= bb;
        ab_out_reg <= ab;
    end
end

assign a0_out = a0_out_reg;
assign b0_out = b0_out_reg;
assign aa_out = aa_out_reg;
assign bb_out = bb_out_reg;
assign ab_out = ab_out_reg;

endmodule
