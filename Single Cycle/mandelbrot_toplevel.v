module mandelbrot_toplevel(
    input aresetn,
    input aclk,
    input [31:0] zoom_f,
    input [31:0] Re_lower,
    input [31:0] Im_upper,
    input Ready,
    output  [23:0] RGB_out, 
    output       wEN,
    output  [9:0] x_coord,
    output  [9:0] y_coord
);

// Internal signals
wire [9:0] x_internal1;  // real coordinate
wire [9:0] y_internal1;  // imag coordinate

wire [31:0] re_internal1;
wire [31:0] im_internal1;

wire or_out1;   // output of the or gate

reg or_out1_reg;   // output of the or gate

// Instantiate mapper module
mapper Mapper (
    .aclk(aclk),
    .aresetn(aresetn),
    .en(done),  
    .zoom_factor(zoom_f),
    .re_lower(Re_lower),
    .im_upper(Im_upper),
    .re_position1(re_internal1),
    .im_position1(im_internal1),
    .x1(x_internal1),
    .y1(y_internal1)
);

wire div1;  // diverged output 

// Instantiate diverge module
diverge Diverge1(
    .a(re_internal1),
    .b(im_internal1),
    .ld(done || aresetn), 
    .aclk(aclk),
    .diverged(div1)
);

wire ovf_it1; // overflow for iteration stop (size larger than 2) 
wire [23:0] counter_out1;  // out of the bottom counter

// Instantiate counter iteration module
Counter_iteration counter_it1(
    .aclk(aclk),
    .clr(done),
    .aresetn(aresetn),  //NEEDS UPDATE 
    .counter(counter_out1),
    .ovf(ovf_it1)
);

wire done;

state_m State_Machine(
    .aclk(aclk),
    .or_out1(or_out1),
    .ready(Ready),
    .rgb_1(counter_out1),
    .x1(x_internal1),
    .y1(y_internal1),
    .done(done),
    .WEN(wEN),
    .RGB_out(RGB_out),
    .x_coord(x_coord),
    .y_coord(y_coord)
);

// Always block for or_out logic
always @* begin
    or_out1_reg = div1 || ovf_it1;
end

assign or_out1 = or_out1_reg;

endmodule


