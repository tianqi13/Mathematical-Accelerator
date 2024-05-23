module diverge(
    input logic [31:0] a,
    input logc [31:0] b,
    input logic ld,
    input logic clk,
    output logic diverged
);

logic [31:0] A;
logic [31:0] B;
logic [31:0] aaplusbb;
logic [31:0] aaminusbb;
logic [31:0] twoab;

generator GENERATOR(
    .a(A),
    .b(B),
    .aa_minus_bb(aaminusbb),
    .two_ab(twoab),
    .aa_plus_bb(aaplusbb)
);

logic [31:0] s1;
logic [31:0] s2;

logic [31:0] muxout1;
logic [31:0] muxout2;

always_comb begin
    s1 = a + aaminusbb;
    s2 = twoab + b;
    if (a > 8'h00800000) 
        diverged = 1;
    else 
        diverged = 0;  
    muxout1 = ld? 32'b0 : s1;
    muxout2 = ld? 32'b0 : s2;

end



always_ff @(posedge clk) begin
    A <= muxout1;
    B <= muxout2;
end

endmodule

