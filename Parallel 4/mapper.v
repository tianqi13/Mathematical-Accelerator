module mapper(
    input aclk,
    input aresetn,
    input en,
    input [31:0] zoom_factor,
    input [31:0] re_lower,
    input [31:0] im_upper,
    output [31:0] re_position1,
    output [31:0] im_position1,
    output [31:0] re_position2,
    output [31:0] im_position2,
    output [31:0] re_position3,
    output [31:0] im_position3,
    output [31:0] re_position4,
    output [31:0] im_position4,
    output [9:0] x1,
    output [9:0] y1,
    output [9:0] x2,
    output [9:0] y2,
    output [9:0] x3,
    output [9:0] y3,
    output [9:0] x4,
    output [9:0] y4
);

wire [9:0] x_internal1;
wire [9:0] y_internal1;
wire [9:0] x_internal2;
wire [9:0] y_internal2;
wire [31:0] X1timesZF;
wire [31:0] Y1timesZF;
wire [31:0] X2timesZF;
wire [31:0] Y2timesZF;
wire [9:0] x_internal3;
wire [9:0] y_internal3;
wire [9:0] x_internal4;
wire [9:0] y_internal4;
wire [31:0] X3timesZF;
wire [31:0] Y3timesZF;
wire [31:0] X4timesZF;
wire [31:0] Y4timesZF;

// Instantiate the dimensions module
dimensions Dimensions (
    .aclk(aclk),
    .en(en),
    .aresetn(aresetn),
    .X1(x_internal1),
    .Y1(y_internal1),
    .X2(x_internal2),
    .Y2(y_internal2),
    .X3(x_internal3),
    .Y3(y_internal3),
    .X4(x_internal4),
    .Y4(y_internal4)
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

multiplier X2timesDELTA (
    .a({ 1'b0 , x_internal2, 21'b0}),
    .b(zoom_factor),
    .result(X2timesZF)
);

// Instantiate the YtimesDELTA multiplier
multiplier Y2timesDELTA (
    .a({ 1'b0, y_internal2, 21'b0}),
    .b(zoom_factor),
    .result(Y2timesZF)
);

multiplier X3timesDELTA (
    .a({ 1'b0 , x_internal3, 21'b0}),
    .b(zoom_factor),
    .result(X3timesZF)
);

// Instantiate the YtimesDELTA multiplier
multiplier Y3timesDELTA (
    .a({ 1'b0, y_internal3, 21'b0}),
    .b(zoom_factor),
    .result(Y3timesZF)
);

multiplier X4timesDELTA (
    .a({ 1'b0 , x_internal4, 21'b0}),
    .b(zoom_factor),
    .result(X4timesZF)
);

// Instantiate the YtimesDELTA multiplier
multiplier Y4timesDELTA (
    .a({ 1'b0, y_internal4, 21'b0}),
    .b(zoom_factor),
    .result(Y4timesZF)
);


assign x1 = x_internal1;
assign y1 = y_internal1;
assign re_position1 = X1timesZF + re_lower;
assign im_position1 = -Y1timesZF + im_upper;

assign x2 = x_internal2;
assign y2 = y_internal2;
assign re_position2 = X2timesZF + re_lower;
assign im_position2 = -Y2timesZF + im_upper;

assign x3 = x_internal3;
assign y3 = y_internal3;
assign re_position3 = X3timesZF + re_lower;
assign im_position3 = -Y3timesZF + im_upper;

assign x4 = x_internal4;
assign y4 = y_internal4;
assign re_position4 = X4timesZF + re_lower;
assign im_position4 = -Y4timesZF + im_upper;

endmodule
