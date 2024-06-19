module multiplier (
    input [31:0] a,   // assuming form S,BBBBBBBBBB.DDDDDDDDDDDDDDDDDDDDD (1 sign, 10 bits of data, and 21 decimals)
    input [31:0] b,
    output [31:0] result
);

reg [63:0] intermediate;
reg [31:0] twos_complement1;
reg [31:0] twos_complement2;
reg [31:0] result_reg;

always @* begin
    if (a[31] == 1'b1 && b[31] == 1'b0) begin
        twos_complement1 = ~a + 1'b1;
        twos_complement2 = 32'b0;
        intermediate = twos_complement1 * b;
        intermediate = ~(intermediate - 1'b1);
        result_reg = intermediate[52:21];
    end
    else if (a[31] == 1'b0 && b[31] == 1'b1) begin
        twos_complement2 = ~b + 1'b1;
        twos_complement1 = 32'b0;
        intermediate = twos_complement2 * a;
        result_reg = intermediate[52:21];
        result_reg = ~(result_reg - 1'b1); 
    end
    else if (a[31] == 1'b1 && b[31] == 1'b1) begin
        twos_complement1 = ~a + 1'b1;
        twos_complement2 = ~b + 1'b1;
        intermediate = twos_complement1 * twos_complement2;
        result_reg = intermediate[52:21];
    end
    else begin
        twos_complement1 = 32'b0;
        twos_complement2 = 32'b0;
        intermediate = a * b;
        result_reg = intermediate[52:21]; 
    end
end

assign result = result_reg;

endmodule
