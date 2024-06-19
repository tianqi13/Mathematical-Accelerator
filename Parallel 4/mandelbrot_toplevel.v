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

wire or_out1;   // output of the or gate
wire or_out2;
wire or_out3;   
wire or_out4;

reg or_out1_reg;   // output of the or gate
reg or_out2_reg;
reg or_out3_reg;   
reg or_out4_reg;

reg and_out_reg; 
wire and_out;

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

wire div1;  // diverged output 
wire div2;  // diverged output #
wire div3;  // diverged output 
wire div4; 
// Instantiate diverge module
diverge Diverge1(
    .a(re_internal1),
    .b(im_internal1),
    .ld(done || aresetn), 
    .aclk(aclk),
    .diverged(div1)
);

diverge Diverge2(
    .a(re_internal2),
    .b(im_internal2),
    .ld(done || aresetn),
    .aclk(aclk),
    .diverged(div2)
);

diverge Diverge3(
    .a(re_internal3),
    .b(im_internal3),
    .ld(done || aresetn), 
    .aclk(aclk),
    .diverged(div3)
);

diverge Diverge4(
    .a(re_internal4),
    .b(im_internal4),
    .ld(done || aresetn),
    .aclk(aclk),
    .diverged(div4)
);

wire ovf_it1; // overflow for iteration stop (size larger than 2) 
wire ovf_it2; // overflow for iteration stop (size larger than 2) 
wire ovf_it3; // overflow for iteration stop (size larger than 2) 
wire ovf_it4; // overflow for iteration stop (size larger than 2wire

wire [23:0] counter_out1;  // out of the bottom counter
wire [23:0] counter_out2;  // out of the bottom counter
wire [23:0] counter_out3;  // out of the bottom counter
wire [23:0] counter_out4;  // out of the bottom countwi

wire [23:0] rgb_out1;  // out of the bottom counter
wire [23:0] rgb_out2;  // out of the bottom counter
wire [23:0] rgb_out3;  // out of the bottom counter
wire [23:0] rgb_out4;  // out of the bottom counter


wire flag1;
wire flag2;
wire flag3;
wire flag4;
// Instantiate counter iteration module
Counter_iteration counter_it1(
    .aclk(aclk),
    .clr(done),
    .aresetn(aresetn),  //NEEDS UPDATE 
    .counter(counter_out1),
    .ovf(ovf_it1)
);

buffer Buffer1(
    .aclk(aclk),
    .clr(done),
    .hit(or_out1),
    .count(counter_out1),
    .flag(flag1),
    .rgb_out(rgb_out1)
);

// Instantiate counter iteration module
Counter_iteration counter_it2(
    .aclk(aclk),
    .clr(done),   //NEEDS UPDATE
    .aresetn(aresetn),
    .counter(counter_out2),
    .ovf(ovf_it2)
);

buffer Buffer2(
    .aclk(aclk),
    .clr(done),
    .hit(or_out2),
    .count(counter_out2),
    .flag(flag2),
    .rgb_out(rgb_out2)
);

Counter_iteration counter_it3(
    .aclk(aclk),
    .clr(done),  //NEEDS UPDATE 
    .aresetn(aresetn),
    .counter(counter_out3),
    .ovf(ovf_it3)
);

buffer Buffer3(
    .aclk(aclk),
    .clr(done),
    .hit(or_out3),
    .count(counter_out3),
    .flag(flag3),
    .rgb_out(rgb_out3)
);

// Instantiate counter iteration module
Counter_iteration counter_it4(
    .aclk(aclk),
    .clr(done),   //NEEDS UPDATE
    .aresetn(aresetn),
    .counter(counter_out4),
    .ovf(ovf_it4)
);

buffer Buffer4(
    .aclk(aclk),
    .clr(done),
    .hit(or_out4),
    .count(counter_out4),
    .flag(flag4),
    .rgb_out(rgb_out4)
);

//reg wEN;
//reg [23:0] rgb_write;
//wire [9:0] x_coord;
//wire [9:0] y_coord;
wire done;

rgb_reg RGB_Reg(
    .aclk(aclk),
    .store(and_out),
    .rgb_1(rgb_out1),
    .rgb_2(rgb_out2),
    .rgb_3(rgb_out3),
    .rgb_4(rgb_out4),
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

// Always block for or_out logic
always @* begin
    or_out1_reg = div1 || ovf_it1;
    or_out2_reg = div2 || ovf_it2;
    or_out3_reg = div3 || ovf_it3;
    or_out4_reg = div4 || ovf_it4;
    and_out_reg = flag1 && flag2 && flag3 && flag4;
end

assign and_out = and_out_reg;
assign or_out1 = or_out1_reg;
assign or_out2 = or_out2_reg;
assign or_out3 = or_out3_reg;
assign or_out4 = or_out4_reg;
endmodule

