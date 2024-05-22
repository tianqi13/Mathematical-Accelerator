// This module multiplies 2 32 bit numbers and truncates the result to produce a 32 bit output.

module multiplier #(
    parameter WIDTH = 32
)(
    input  logic [WIDTH-1:0] a,   // assuming form S,BBBBBBBBBB.DDDDDDDDDDDDDDDDDDDDD (1 sign, 10 bits of data, and 21 decimals)
    input  logic [WIDTH-1:0] b,
    output logic [WIDTH-1:0] result
);

logic [2*WIDTH-1:0] intermediate;

assign intermediate = a*b;
assign result = intermediate[52:21];

endmodule
