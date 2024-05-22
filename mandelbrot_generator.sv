// Generates the Mandelbrot set
// Z = Z^2 + C where C = a0 + ib0

module mandelbrot_generator(
    input logic clk,
    input logic [31:0] z,
    input logic [31:0] a0,
    input logic [31:0] b0
);

initial z = a0 + b0i

generator GENERATOR(
    .clk(clk);
    .a()
)

always_ff @(posedge clk) begin
    if(aa_plus_bb > 4) diverge

end

endmodule
