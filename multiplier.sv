// This module multiplies 2 32 bit numbers and truncates the result to produce a 32 bit output.

module multiplier(
    input  logic [31:0] a,   // assuming form S,BBBBBBBBBB.DDDDDDDDDDDDDDDDDDDDD (1 sign, 10 bits of data, and 21 decimals)
    input  logic [31:0] b,
    output logic [31:0] result
);

logic [63:0] intermediate;

assign intermediate = a*b;
assign result = intermediate[52:21];

endmodule
