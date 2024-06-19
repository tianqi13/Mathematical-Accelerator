
module state_m(
    input aclk,
    input or_out1,
    input ready,
    input [23:0] rgb_1,
    input [9:0] x1,
    input [9:0] y1,
    output      done,
    output      WEN,
    output [23:0] RGB_out,
    output [9:0] x_coord,
    output [9:0] y_coord
);

localparam  WAIT = 1'd0,   OUT = 1'd1;

reg WEN_reg;
reg [23:0] rgb_out_reg;
reg [23:0] rgb_store;
reg [9:0] x_coord_reg;
reg [9:0] y_coord_reg;
reg done_reg;

reg current_state;
reg next_state;


always @* begin
    case(current_state)
        WAIT:   if (or_out1) next_state = OUT;
                else next_state = current_state;
        OUT:   if (ready) next_state = WAIT;
                else next_state = current_state;
        default: next_state = WAIT;
    endcase 
end 

always @* begin
    case(current_state)
        WAIT:
            begin
                rgb_out_reg = 24'b0;
                x_coord_reg = 10'b1;
                y_coord_reg = 10'b1;

                if(or_out1) rgb_store = rgb_1; 
                else rgb_store = 24'b0;
                
                WEN_reg = 1'b0;
                done_reg = 1'b0;
            end 
        OUT:
            begin 
                rgb_out_reg = rgb_store;
                x_coord_reg = x1;
                y_coord_reg = y1;

                WEN_reg = 1'b1;
                done_reg = ready;
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

always @(posedge aclk) begin 
    current_state <= next_state;
end


assign RGB_out = rgb_out_reg;
assign x_coord = x_coord_reg;
assign y_coord = y_coord_reg;
assign WEN = WEN_reg;
assign done = done_reg;

endmodule
