module ff_div(
    input aclk,
    input [31:0] s,
    input ld,
    output [31:0] q
);

reg [31:0] s_store;
reg [31:0] q_reg;

localparam  START = 3'd0, 
            NEW_VAL = 3'd1,
            CLK1 = 3'd2, 
            CLK2 = 3'd3, 
            CLK3 = 3'd4;

reg [2:0] current_state = START;
reg [2:0] next_state;

// State transition logic synchronized with the clock
always @(posedge aclk) begin 
    current_state <= next_state;
end

// Next state logic
always @* begin
    case(current_state)
        START:  if(ld) next_state = NEW_VAL;
                else next_state = START;
        NEW_VAL: next_state = CLK1;
        CLK1:    next_state = CLK2;
        CLK2:    next_state = CLK3;
        CLK3:    next_state = NEW_VAL;  // Change transition from CLK3 to START
        default: next_state = START;
    endcase 
end 

always @* begin
    case(current_state)
        START: 
            begin
                s_store = 32'b0;
                q_reg = 32'b0;
            end 

        NEW_VAL:
            begin 
                q_reg = s;
                s_store = s;
            end

        CLK1:
            begin
                q_reg = s_store;
            end 

        CLK2:
            begin 
                q_reg = s_store;
            end 

        CLK3:
            begin
                q_reg = s_store;
            end 


        default:
            begin
                q_reg = s_store;
            end

    endcase
end

assign q = q_reg;

endmodule
