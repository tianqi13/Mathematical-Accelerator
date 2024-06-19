module mandelbrot_toplevel(
    input aresetn,
    input aclk,
    input [31:0] zoom_f,
    input [31:0] Re_lower,
    input [31:0] Im_upper,
    input Ready,
    input [15:0] X_dimensions,
    input [15:0] Y_dimensions,
    input [23:0] max_iterations,
    input   [31:0] juliaset_a0, juliaset_b0,
    input          juliacase_value,
    output  [23:0] RGB_out, 
    output       wEN,
    output  [9:0] x_coord,
    output  [9:0] y_coord
);

// Internal signals
wire [9:0] x_internal1;  // real coordinate
wire [9:0] y_internal1;  // imag coordinate
wire [9:0] x_internal2;  
wire [9:0] y_internal2;
wire [9:0] x_internal3;  // real coordinate
wire [9:0] y_internal3;  // imag coordinate
wire [9:0] x_internal4;  
wire [9:0] y_internal4;

wire [31:0] re_internal1;
wire [31:0] im_internal1;
wire [31:0] re_internal2;
wire [31:0] im_internal2;
wire [31:0] re_internal3;
wire [31:0] im_internal3;
wire [31:0] re_internal4;
wire [31:0] im_internal4;

// Instantiate mapper module
mapper Mapper (
    .aclk(aclk),
    .aresetn(aresetn),
    .en(done),  
    .zoom_factor(zoom_f),
    .re_lower(Re_lower),
    .im_upper(Im_upper),
    .X_size(X_dimensions),
    .Y_size(Y_dimensions),
    .re_position1(re_internal1),
    .im_position1(im_internal1),
    .re_position2(re_internal2),
    .im_position2(im_internal2),
    .re_position3(re_internal3),
    .im_position3(im_internal3),
    .re_position4(re_internal4),
    .im_position4(im_internal4),
    .x1(x_internal1),
    .y1(y_internal1),
    .x2(x_internal2),
    .y2(y_internal2),
    .x3(x_internal3),
    .y3(y_internal3),
    .x4(x_internal4),
    .y4(y_internal4)
);

wire div;

wire flag_wait;

black_hole ALU(
    .aclk(aclk),
    .ld(done),
    .aresetn(aresetn),
    .a1(re_internal1),
    .b1(im_internal1),
    .a2(re_internal2),
    .b2(im_internal2),
    .a3(re_internal3),
    .b3(im_internal3),
    .a4(re_internal4),
    .b4(im_internal4),
    .julia_a0(juliaset_a0),
    .julia_b0(juliaset_b0),
    .julia_VS_mandelbrot(juliacase_value),
    .diverged(div)
);

wire or_out1;   // output of the or gate
wire or_out2;
wire or_out3;   
wire or_out4;

wire [23:0] counter_out1;
wire [23:0] counter_out2;
wire [23:0] counter_out3;
wire [23:0] counter_out4;

Counter_iteration #(
    .WAIT_CYCLES(2'd1) 
) counter_it1 (
    .aclk(aclk),
    .clr(done),
    .aresetn(aresetn),
    .max_iterations(max_iterations), 
    .div(div),
    .counter(counter_out1),
    .or_out(or_out1)
);

Counter_iteration #(
    .WAIT_CYCLES(2'd2) 
) counter_it2 (
    .aclk(aclk),
    .clr(done),
    .aresetn(aresetn),
    .max_iterations(max_iterations), 
    .div(div),
    .counter(counter_out2),
    .or_out(or_out2)
);

Counter_iteration #(
    .WAIT_CYCLES(2'd3) 
) counter_it3 (
    .aclk(aclk),
    .clr(done),
    .aresetn(aresetn),
    .max_iterations(max_iterations), 
    .div(div),
    .counter(counter_out3),
    .or_out(or_out3)
);


Counter_iteration #(
    .WAIT_CYCLES(3'd4) 
) counter_it4 (
    .aclk(aclk),
    .clr(done),
    .aresetn(aresetn),
    .max_iterations(max_iterations), 
    .div(div),
    .counter(counter_out4),
    .or_out(or_out4)
);

reg and_out_reg;
wire and_out;

// Always block for or_out logic
always @* begin
    and_out_reg = or_out1 && or_out2 && or_out3 && or_out4;
end

assign and_out = and_out_reg;

wire done;

rgb_reg RGB_Reg(
    .aclk(aclk),
    .store(and_out),
    .rgb_1(counter_out1),
    .rgb_2(counter_out2),
    .rgb_3(counter_out3),
    .rgb_4(counter_out4),
    .x1(x_internal1),
    .y1(y_internal1),
    .x2(x_internal2),
    .y2(y_internal2),
    .x3(x_internal3),
    .y3(y_internal3),
    .x4(x_internal4),
    .y4(y_internal4),
    .ready(Ready),
    .WEN(wEN),
    .rgb_out(RGB_out), 
    .x_coord(x_coord),
    .y_coord(y_coord),
    .done(done)
);

endmodule

