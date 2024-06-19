module mux_state (
  input aclk, 
  input ld,  
  input aresetn,  
  input [31:0] a_old,
  input [31:0] b_old,
  input [31:0] a1,
  input [31:0] b1,
  input [31:0] a2,
  input [31:0] b2,
  input [31:0] a3,
  input [31:0] b3,
  input [31:0] a4,
  input [31:0] b4,  
  input juliacase,
  input [31:0] a0_julia,
  input [31:0] b0_julia,
  output [31:0] a0,
  output [31:0] b0,
  output flag_wait
);

localparam  IDLE    = 3'd0,
            STATE1  = 3'd1, 
            STATE2  = 3'd2, 
            STATE3  = 3'd3, 
            STATE4  = 3'd4,
            WAIT = 3'd5;

reg [2:0] current_state;
reg [2:0] next_state;

reg [31:0] a0_reg;
reg [31:0] b0_reg;

reg flag_wait_reg;

always @(posedge aclk) begin
  if (aresetn) begin 
    current_state <= WAIT;
  end 
  else begin 
    current_state <= next_state;
  end 
end

always @* begin
    case(current_state)
        STATE1: next_state = STATE2;
        STATE2: next_state = STATE3;                   
        STATE3: next_state = STATE4;              
        STATE4: next_state = IDLE;                  
        IDLE:   if (ld) next_state = WAIT; 
                else next_state = IDLE; 
        WAIT: next_state = STATE1;

        default: next_state = WAIT;
    endcase 
end 

always @* begin
    case(current_state)
        STATE1:
            begin
              a0_reg = a1;
              b0_reg = b1;
              flag_wait_reg = 1'b1;
            end 
        STATE2:
            begin 
              a0_reg = a2;
              b0_reg = b2;
              flag_wait_reg = 1'b1;
            end 
        STATE3:
            begin
              a0_reg = a3;
              b0_reg = b3;
              flag_wait_reg = 1'b0;
            end 
        STATE4: 
            begin
              a0_reg = a4;
              b0_reg = b4;
              flag_wait_reg = 1'b0;
            end 
        IDLE: 
            begin
              a0_reg = (juliacase) ? a0_julia : a_old;
              b0_reg = (juliacase) ? b0_julia : b_old;
              flag_wait_reg = 1'b0;
            end
        WAIT: begin
              a0_reg = 32'b0;
              b0_reg = 32'b0;
              flag_wait_reg = 1'b1;
            end  
        default:
            begin
              a0_reg = 32'b0;
              b0_reg = 32'b0;
              flag_wait_reg = 1'b0;
            end
       
    endcase
end

assign a0 = a0_reg;
assign b0 = b0_reg;
assign flag_wait = flag_wait_reg;

endmodule
