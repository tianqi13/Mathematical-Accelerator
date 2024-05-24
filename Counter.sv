// Pointer moves through whole image from top left to bottom right in a rastern pattern and stops at each pixel
// and counts the number of iterations it takes for that specific 'pixel' to diverge. It diverges when the absolute
// value of Z_n is greater than 2. The pixels are assigned a color based on how quickly they diverge. It is assigned
// black if it is in the Mandelbrot set, and therefore never diverges, and red if it diverges. Any color between is purely
// for aesthetic appeal and represents how quickly that point diverges. A true Mandelbrot set is black and white.



module Counter (
  input logic clk,       // Clock input
  input logic rst,       // Reset input (assume active high for this example)
  input logic en,        // Enable input
  output logic [14:0] counter,  // 15-bit counter output
  output logic ovf    // Overflow output
);

  // 15-bit counter register
  logic [14:0] counter_reg;

  always_ff @(posedge clk ) begin
    if (rst) begin
      // Reset the counter and overflow signal
      counter_reg <= 15'd0;
      ovf <= 1'b0;
    end else if (en) begin
      if (counter_reg == 15'h7FFF) begin
        // If counter is at maximum value, set overflow and reset counter
        counter_reg <= 15'd0;
        ovf <= 1'b1;
      end else begin
        // Increment counter and clear overflow
        counter_reg <= counter_reg + 15'd1;
        ovf <= 1'b0;
      end
    end
    counter <= counter_reg;
  end


endmodule
