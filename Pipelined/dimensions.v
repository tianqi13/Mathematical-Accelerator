// Performs raster pattern
// Overflow is only high when it is finished generating the image

module dimensions (
    input aclk,  
    input en,
    input aresetn,
    input [15:0] width, height,
    output [9:0] X1,
    output [9:0] Y1,
    output [9:0] X2,
    output [9:0] Y2,
    output [9:0] X3,
    output [9:0] Y3,
    output [9:0] X4,
    output [9:0] Y4

);

reg [9:0] X1_reg;
reg [9:0] Y1_reg;
reg [9:0] X2_reg;
reg [9:0] Y2_reg;
reg [9:0] X3_reg;
reg [9:0] Y3_reg;
reg [9:0] X4_reg;
reg [9:0] Y4_reg;

always @(posedge aclk) begin
    if (aresetn) begin
        X1_reg <= 10'b0;
        Y1_reg <= 10'b0;
        X2_reg <= 10'b1;
        Y2_reg <= 10'b0;
        X3_reg <= 10'b10;
        Y3_reg <= 10'b0;
        X4_reg <= 10'b11;
        Y4_reg <= 10'b0;
    end 
    else if (en) begin
        if (X4_reg == width-16'b1) begin        // 3FF = 1023 multiple of 4!!
            if (Y4_reg == height - 16'b1) begin    // 2FF = 767
                Y1_reg <= 10'b0;
                X1_reg <= 10'b0;
                Y2_reg <= 10'b0;
                X2_reg <= 10'b1;
                Y3_reg <= 10'b0;
                X3_reg <= 10'b10;
                Y4_reg <= 10'b0;
                X4_reg <= 10'b11;
            end else begin
                Y1_reg <= Y1_reg + 10'b01;
                Y2_reg <= Y2_reg + 10'b01;
                Y3_reg <= Y3_reg + 10'b01;
                Y4_reg <= Y4_reg + 10'b01;
                X1_reg <= 10'b0;
                X2_reg <= 10'b1;
                X3_reg <= 10'b10;
                X4_reg <= 10'b11;
            end
        end else begin
            X1_reg <= X1_reg + 10'b100;
            X2_reg <= X2_reg + 10'b100;
            X3_reg <= X3_reg + 10'b100;
            X4_reg <= X4_reg + 10'b100; //increment by 4
        end
    end
end

assign X1 = X1_reg;
assign Y1= Y1_reg;
assign X2= X2_reg;
assign Y2= Y2_reg;
assign X3= X3_reg;
assign Y3= Y3_reg;
assign X4= X4_reg;
assign Y4= Y4_reg;

endmodule
