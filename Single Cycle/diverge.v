module diverge(
    input [31:0] a,
    input [31:0] b,
    input ld,
    input aclk,
    output diverged
);

reg diverged_reg;
wire [31:0] A;
wire [31:0] B;
wire [31:0] aaplusbb;
wire [31:0] aaminusbb;
wire [31:0] twoab;

generator GENERATOR(
    .a(A),
    .b(B),
    .aa_minus_bb(aaminusbb),
    .two_ab(twoab),
    .aa_plus_bb(aaplusbb)
);

reg [31:0] s1;
reg [31:0] s2;

reg [31:0] muxout1;
reg [31:0] muxout2;



always @* begin
    s1 = a + aaminusbb;
    s2 = twoab + b;
    if (aaplusbb > 32'h00800000)
        diverged_reg = 1'b1;

    else 
        diverged_reg = 1'b0;
    muxout1 = ld ? 32'b0 : s1;
    muxout2 = ld ? 32'b0 : s2;
end


ff_div flip(
    .aclk(aclk),
    .s(muxout1),
    .q(A)
);

ff_div flop(
    .aclk(aclk),
    .s(muxout2),
    .q(B)
);


assign diverged = diverged_reg;

endmodule
