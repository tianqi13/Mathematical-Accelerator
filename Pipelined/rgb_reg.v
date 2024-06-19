module rgb_reg(
    input aclk,       // Clock input
    input store,          
    input [23:0] rgb_1,     
    input [23:0] rgb_2,
    input [23:0] rgb_3,     
    input [23:0] rgb_4,    
    input [9:0] x1,
    input [9:0] y1,
    input [9:0] x2,
    input [9:0] y2,
    input [9:0] x3,
    input [9:0] y3,
    input [9:0] x4,
    input [9:0] y4,
    input       ready,
    output WEN,  
    output [23:0] rgb_out,
    output [9:0] x_coord,
    output [9:0] y_coord,
    output done
);

reg WEN_reg;
reg [23:0] rgb_out_reg;
reg [9:0] x_coord_reg;
reg [9:0] y_coord_reg;
reg done_reg;

localparam  WAIT = 3'd0, 
            OUT1 = 3'd1, 
            OUT2 = 3'd2, 
            OUT3 = 3'd3, 
            OUT4 = 3'd4;

reg [2:0] current_state;
reg [2:0] next_state;

always @(posedge aclk) begin 
    current_state <= next_state;
end

always @* begin
    case(current_state)
        WAIT:   if (store) next_state = OUT1;
                else next_state = current_state;
        OUT1:   if (ready) next_state = OUT2;
                else next_state = current_state;
        OUT2:   if (ready) next_state = OUT3;
                else next_state = current_state;
        OUT3:   if (ready) next_state = OUT4;
                else next_state = current_state;
        OUT4:   if (ready) next_state = WAIT;
                else next_state = current_state;
        default: next_state = WAIT;
    endcase 
end 

always @* begin
    case(current_state)
        OUT1:
            begin
                rgb_out_reg = rgb_1;
                x_coord_reg = x1;
                y_coord_reg = y1;

                WEN_reg = 1'b1;
                done_reg = 1'b0;
            end 
        OUT2:
            begin 
                rgb_out_reg = rgb_2;
                x_coord_reg = x2;
                y_coord_reg = y2;

                WEN_reg = 1'b1;
                done_reg = 1'b0;
            end 
        OUT3:
            begin
                rgb_out_reg = rgb_3;
                x_coord_reg = x3;
                y_coord_reg = y3;

                WEN_reg = 1'b1;
                done_reg = 1'b0;
            end 
        OUT4:
            begin
                rgb_out_reg = rgb_4;
                x_coord_reg = x4;
                y_coord_reg = y4;
                WEN_reg = 1'b1;
                done_reg = ready;

            end
        WAIT:
            begin 
                rgb_out_reg = 24'b0;
                x_coord_reg = 10'b1;
                y_coord_reg = 10'b1;

                WEN_reg = 1'b0;
                done_reg = 1'b0;
            end

        default:
            begin
                rgb_out_reg = 24'b0;
                x_coord_reg = 10'b1;
                y_coord_reg = 10'b1;

                WEN_reg = 1'b0;
                done_reg = 1'b0;
            end

    endcase
end

assign rgb_out = rgb_out_reg;
assign x_coord = x_coord_reg;
assign y_coord = y_coord_reg;
assign WEN = WEN_reg;
assign done = done_reg;

endmodule 
