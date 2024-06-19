module generator(
    input [31:0] a,
    input [31:0] b,
    output [31:0] aa_minus_bb,
    output [31:0] two_ab,
    output [31:0] aa_plus_bb
);

reg [31:0] aa_minus_bb_reg;
reg [31:0] two_ab_reg;
reg [31:0] aa_plus_bb_reg;

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

wire [30:0] ab_truncated;

assign ab_truncated = ab[30:0]; //moved outside of always comb block

always @* begin
    aa_minus_bb_reg = aa - bb;
    aa_plus_bb_reg = aa + bb;
    two_ab_reg = {ab_truncated, 1'b0};
end

assign aa_minus_bb = aa_minus_bb_reg;
assign two_ab = two_ab_reg;
assign aa_plus_bb = aa_plus_bb_reg;

endmodule
