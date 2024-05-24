module mandelbrot_toplevel(
    input logic rst,
    input logic clk,
    input logic enable,
    input logic [9:0] x_size,
    input logic [9:0] y_size,
    input logic [31:0] Re_axis_width,
    input logic [31:0] Im_axis_width,
    output logic [14:0] RGB_out, 
    output logic [9:0] X,
    output logic [9:0] Y
);


//mapper wires
logic [31:0] Delta_x = Re_axis_width/x_size;
logic [31:0] Delta_y = Im_axis_width/y_size;
logic [31:0] x_internal;  // real coordinate
logic [31:0] y_internal;  // imag coordinate
logic ovf;  //overflow due to finish image generation 

logic [31:0] real_internal;
logic [31:0] im_internal;

logic q;   //top flipflop output 
logic q_bar;    //~q
logic [14:0] out;  //out of the bottom flipflop
logic ovf_it; //overflow for iteration stop (size larger then 2) 

logic or_out;   //output of the or gate
logic div;  //diverged output 

mapper Mapper (
    .clock(clk),
    .rst(rst),
    .en(enable & q_bar & or_out),  //later
    .delta_x(Delta_x),
    .delta_y(Delta_y),
    .re_axis_width(Re_axis_width),
    .im_axis_width(Im_axis_width),
    .real_s(real_internal),
    .ims(im_internal),
    .ovf(ovf),
    .x(x_internal),
    .y(y_internal)
);

diverge DIVERGE(
    .a(real_internal),
    .b(im_internal),
    .ld(or_out),
    .clk(clk),
    .diverged(div)
);

logic [19:0] rd_addr;
Addr_counter addr_counter(
    .clk(clk),
    .rst(rst),
    .en(ovf),
    .addr_count(rd_addr),
    .X(x_internal),
    .Y(y_internal)
);

Counter counter_mod(
    .clk(clk),
    .rst(or_out),
    .en(enable),
    .counter(out),
    .ovf(ovf_it)
);

Ram ram(
    .clk(clk),
    .WRITE_EN(~ovf),
    .READ_EN(ovf),
    .rd_addr(rd_addr),
    .wr_addr({y_internal,x_internal}),
    .din(out),  // count_out
    .RGB(RGB_out)
);

always_comb begin
    or_out = div || ovf_it;
end

always_ff @(posedge clk) begin
    if(or_out==1'b1)
        out <= 1'b0;
    else
        out <= enable;
    ovf_it <= ~out;
    if (rst)
        q <= 1'b0;
    else
        q <= ovf;
    q_bar <= ~q;
end

endmodule
