module black_hole(
    input aclk,
    input ld,
    input aresetn,
    input [31:0] a1,
    input [31:0] b1,
    input [31:0] a2,
    input [31:0] b2,
    input [31:0] a3,
    input [31:0] b3,
    input [31:0] a4,
    input [31:0] b4,
    input [31:0] julia_a0,
    input [31:0] julia_b0,
    input julia_VS_mandelbrot,
    output diverged
);

wire [31:0] a0;
wire [31:0] b0;

mux_state multiplexer(
    .aclk(aclk),
    .ld(ld),
    .aresetn(aresetn),
    .a_old(a0_outf),
    .b_old(b0_outf),
    .a1(a1),
    .b1(b1),
    .a2(a2),
    .b2(b2),
    .a3(a3),
    .b3(b3),
    .a4(a4),
    .b4(b4),
    .a0(a0),
    .b0(b0),
    .juliacase(julia_VS_mandelbrot),
    .a0_julia(julia_a0),
    .b0_julia(julia_b0),
    .flag_wait(flag_wait)
);

wire [31:0] A; //from ff
wire [31:0] B; //from ff

wire [31:0] a0_outm;
wire [31:0] b0_outm;

wire [31:0] aa;
wire [31:0] bb;
wire [31:0] ab;

multiplier_clocked stage1(
    .aclk(aclk),
    .a(A), //from ff
    .b(B), //from ff
    .ld(ld),
    .a0_in(a0), //from mux
    .b0_in(b0), //from mux
    .a0_out(a0_outm),
    .b0_out(b0_outm),
    .aa_out(aa),
    .bb_out(bb),
    .ab_out(ab)
);


wire [31:0] aa_plus_bb;
wire [31:0] aa_minus_bb;
wire [31:0] twoab;
wire [31:0] a0_outa;
wire [31:0] b0_outa;

add_clocked stage2(
    .aclk(aclk),
    .aa(aa),
    .bb(bb),
    .ab(ab),
    .ld(ld),
    .a0_in(a0_outm),
    .b0_in(b0_outm),
    .a0_out(a0_outa),
    .b0_out(b0_outa),
    .aa_plus_bb_out(aa_plus_bb),
    .aa_minus_bb_out(aa_minus_bb),
    .twoab_out(twoab),
    .diverged_out(diverged)
);

wire [31:0] a0_outc;
wire [31:0] b0_outc;
wire [31:0] muxout1;
wire [31:0] muxout2;

second_add_clocked stage3(
    .aclk(aclk),
    .ld(ld),
    .flag_wait(flag_wait),
    .aa_plus_bb(aa_plus_bb),
    .aa_minus_bb(aa_minus_bb),
    .twoab(twoab),
    .a0_in(a0_outa),
    .b0_in(b0_outa),
    .a0_out(a0_outc),
    .b0_out(b0_outc),
    .muxout1_out(muxout1),
    .muxout2_out(muxout2)
);

wire [31:0] a0_outf;
wire [31:0] b0_outf;

ff_div flip(
    .aclk(aclk),
    .ld(ld),
    .aresetn(aresetn),
    .s1(muxout1),
    .s2(muxout2),
    .a0_in(a0_outc),
    .b0_in(b0_outc),
    .a0_out(a0_outf), //to mux
    .b0_out(b0_outf), //to mux
    .q1(A),
    .q2(B) 
);


endmodule
