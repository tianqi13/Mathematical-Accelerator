module Counter_iteration #(
  parameter WAIT_CYCLES = 3
)(
  input aclk, 
  input clr,
  input aresetn,   
  input [23:0] max_iterations,    
  input div,
  output [23:0] counter,  
  output or_out
);

localparam  WAIT        = 3'd0,
            MULTIPLIER  = 3'd1, 
            ADD         = 3'd2, 
            SECOND_ADD  = 3'd3, 
            FF          = 3'd4, 
            DIVERGED    = 3'd5,
            OVERFLOWED  = 3'd6;

reg [2:0] current_state;
reg [2:0] next_state;

reg [23:0] counter_reg;
reg or_out_reg;

reg [1:0] wait_counter;  // Counter to keep track of WAIT cycles


reg [23:0] counter_in;
reg or_out_in;


always @(posedge aclk) begin 
    if (clr || aresetn) begin
      counter_reg <= 24'h0;
      or_out_reg <= 1'b0;
      wait_counter <= 1'b0;

      if (WAIT_CYCLES == 2'b0) begin
        current_state <= MULTIPLIER;
      end
      else begin
        current_state <= WAIT;
      end 
    end 

    else begin
      current_state <= next_state;
      counter_reg <= counter_in;
      or_out_reg <= or_out_in;

      if (current_state == WAIT && wait_counter < WAIT_CYCLES) begin
        wait_counter <= wait_counter + 1;
      end 
      else if (current_state != WAIT) begin
        wait_counter <= 0;
      end
    end 
end

always @* begin
    case(current_state)
        MULTIPLIER:   next_state = ADD;
        ADD:          next_state = SECOND_ADD;                   
        SECOND_ADD:   if (div) next_state = DIVERGED;  
                      else next_state = FF;                 
        FF:           if (or_out) next_state = OVERFLOWED;
                      else next_state = MULTIPLIER;                   
        DIVERGED:     if (clr) next_state = MULTIPLIER; 
                      else next_state = DIVERGED; 
        OVERFLOWED:   if (clr) next_state = MULTIPLIER; 
                      else next_state = OVERFLOWED;
        WAIT:         if (wait_counter < WAIT_CYCLES - 1) 
                        next_state = WAIT;
                      else 
                        next_state = MULTIPLIER;             
        default: next_state = WAIT;
    endcase 
end 

always @* begin
    case(current_state)
        MULTIPLIER:
            begin
              counter_in = counter;
              or_out_in = 1'b0;
            end 
        ADD:
            begin 
              counter_in = counter;
              or_out_in = 1'b0;
            end 
        SECOND_ADD:
            begin
              counter_in = counter;

              if (counter + 24'h4 > max_iterations) begin
                or_out_in = 1'b1;
              end

              else begin 
                or_out_in = 1'b0;
              end

            end 
        FF:
            begin
              if (or_out) begin
                counter_in = counter;
                or_out_in = 1'b1;
              end

              else begin 
                counter_in = counter + 24'h4;
                or_out_in = 1'b0;
              end
            end 
        DIVERGED:
            begin 
              counter_in = counter;
                or_out_in = 1'b1;
            end
        OVERFLOWED:
            begin
              counter_in = counter;
              or_out_in = 1'b1;
            end
        WAIT:
            begin 
              counter_in = counter;
              or_out_in = 1'b0;
            end

        default:
            begin
              counter_in = 24'h0;
              or_out_in = 1'b0;
            end

    endcase
end

assign counter = counter_reg;
assign or_out = or_out_reg;

endmodule