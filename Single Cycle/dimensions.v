// Performs raster pattern
// Overflow is only high when it is finished generating the image

module dimensions (
    input aclk,  
    input en,
    input aresetn,
    output [9:0] X1,
    output [9:0] Y1
);

reg [9:0] X1_reg;
reg [9:0] Y1_reg;

always @(posedge aclk) begin
    if (aresetn) begin
        X1_reg <= 10'b0;
        Y1_reg <= 10'b0;
    end 
    else if (en) begin
        if (X1_reg == 10'd1023) begin        // 3FF = 1023 multiple of 4!!
            if (Y1_reg == 10'd767) begin    // 2FF = 767
                Y1_reg <= 10'b0;
                X1_reg <= 10'b0;
            end else begin
                Y1_reg <= Y1_reg + 10'b01;
                X1_reg <= 10'b0;
            end
        end else begin
            X1_reg <= X1_reg + 10'b01;
        end
    end
end

assign X1 = X1_reg;
assign Y1= Y1_reg;

endmodule
