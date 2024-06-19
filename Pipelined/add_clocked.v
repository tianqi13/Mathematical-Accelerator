module add_clocked(
    input aclk,
    input [31:0] aa,
    input [31:0] bb,
    input [31:0] ab,
    input ld,
    input [31:0] a0_in,
    input [31:0] b0_in,
    output [31:0] a0_out,
    output [31:0] b0_out,
    output [31:0] aa_plus_bb_out,
    output [31:0] aa_minus_bb_out,
    output [31:0] twoab_out,
    output diverged_out
);

reg [31:0] a0_out_reg;
reg [31:0] b0_out_reg;

reg [31:0] aa_plus_bb;
reg [31:0] aa_minus_bb;
reg [31:0] twoab;
reg diverged;

reg [31:0] aa_plus_bb_out_reg;
reg [31:0] aa_minus_bb_out_reg;
reg [31:0] twoab_out_reg;
reg diverged_out_reg;

reg [30:0] ab_truncated;


always@* begin
    if (ld == 1'b1) begin
        aa_plus_bb = 32'b0;
        aa_minus_bb = 32'b0;
        ab_truncated = 32'b0;
        twoab = 32'b0;
        diverged = 1'b0;
    end
    else begin
        aa_plus_bb = aa + bb;
        aa_minus_bb = aa - bb;
        ab_truncated = ab[30:0];
        twoab = {ab_truncated, 1'b0};

        if (aa_plus_bb > 32'h40000000) begin
            diverged = 1'b1;
        end
        else diverged = 1'b0;
    end 
    
end

always@(posedge aclk) begin 
    a0_out_reg <= a0_in;
    b0_out_reg <= b0_in;
    aa_plus_bb_out_reg <= aa_plus_bb;
    aa_minus_bb_out_reg <= aa_minus_bb;
    twoab_out_reg <= twoab;
    diverged_out_reg <= diverged;
    
end 

assign a0_out = a0_out_reg;
assign b0_out = b0_out_reg;
assign aa_plus_bb_out = aa_plus_bb_out_reg;
assign aa_minus_bb_out = aa_minus_bb_out_reg;
assign twoab_out = twoab_out_reg;
assign diverged_out = diverged_out_reg;

endmodule
