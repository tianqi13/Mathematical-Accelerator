// This module generates the necessary numbers that provide all the information about a Mandelbrot set.

module generator(
    input logic [31:0] a,
    input logic [31:0] b,
    output logic [31:0] aa_minus_bb,
    output logic [31:0] two_ab,
    output logic [31:0] aa_plus_bb
);

logic [31:0] aa;
logic [31:0] bb;
logic [31:0] ab;

multiplier a_a(
    .a(a),
    .b(a),
    .result(aa)
);

multiplier b_b(
    .a(b),
    .b(b),
    .result(bb)
);

multiplier a_b(
    .a({1'b0, X, 21'b0}),
    .b(delta),  //what??
    .result(ab)
);

logic [30:0] ab_truncated;
always_comb begin
    aa_minus_bb = aa - bb;
    aa_plus_bb = aa + bb;
    ab_truncated = ab[30:0];
    two_ab = {ab_truncated, 1'b0};
end


endmodule
