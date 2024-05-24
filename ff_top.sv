
module ff_top(
    input logic clk,
    input logic s,
    input logic reset,
    output logic q,
    output logic q_bar
);

always_ff @(posedge clk) begin
    if (reset)
        q <= 1'b0;
    else
        q <= s;
    q_bar <= ~q;
end

endmodule
