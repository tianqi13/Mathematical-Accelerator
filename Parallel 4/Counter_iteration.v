module Counter_iteration (
  input aclk,       // Clock input
  input clr,
  input aresetn,       // Reset input (assume active high for this example)
  output [23:0] counter,  // 24-bit counter output
  output ovf   // Overflow output
);

  // 24-bit counter register
  reg [23:0] counter_reg;
  reg [23:0] counter_reg1;
  reg ovf_reg;
  always @(posedge aclk) begin
    if (clr || aresetn) begin
      // Reset the counter and overflow signal
      counter_reg <= 24'h0;
      ovf_reg <= 1'b0;
    end else begin
      if (counter_reg >= 24'h3FF) begin
        counter_reg <= counter_reg;
        ovf_reg <= 1'b1;
      end else begin
        // Increment counter and clear overflow
        counter_reg <= counter_reg + 24'd1;
        ovf_reg <= 1'b0;
      end
    end
   counter_reg1 <= counter_reg;
  end

assign counter = counter_reg1;
assign ovf = ovf_reg;
endmodule
