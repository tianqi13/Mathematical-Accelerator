module mapper(
    input aclk,
    input aresetn,
    input en,
    input [31:0] zoom_factor,
    input [31:0] re_lower,
    input [31:0] im_upper,
    output [31:0] re_position1,
    output [31:0] im_position1,
    output [9:0] x1,
    output [9:0] y1
);

wire [9:0] x_internal1;
wire [9:0] y_internal1;

wire [31:0] X1timesZF;
wire [31:0] Y1timesZF;

// Instantiate the dimensions module
dimensions Dimensions (
    .aclk(aclk),
    .en(en),
    .aresetn(aresetn),
    .X1(x_internal1),
    .Y1(y_internal1)
);

// Instantiate the XtimesDELTA multiplier
multiplier X1timesDELTA (
    .a({ 1'b0 , x_internal1, 21'b0}),
    .b(zoom_factor),
    .result(X1timesZF)
);

// Instantiate the YtimesDELTA multiplier
multiplier Y1timesDELTA (
    .a({ 1'b0, y_internal1, 21'b0}),
    .b(zoom_factor),
    .result(Y1timesZF)
);

assign x1 = x_internal1;
assign y1 = y_internal1;
assign re_position1 = X1timesZF + re_lower;
assign im_position1 = -Y1timesZF + im_upper; //maybe error here?

endmodule
