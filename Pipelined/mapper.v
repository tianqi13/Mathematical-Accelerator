module mapper(
    input aclk,
    input aresetn,
    input en,
    input [31:0] zoom_factor,
    input [31:0] re_lower,
    input [31:0] im_upper,
    input [15:0] X_size, Y_size,
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

reg [9:0] x1_reg;
reg [9:0] y1_reg;
reg [9:0] x2_reg;
reg [9:0] y2_reg;
reg [9:0] x3_reg;
reg [9:0] y3_reg;
reg [9:0] x4_reg;
reg [9:0] y4_reg;

reg [31:0] re_position1_reg;
reg [31:0] im_position1_reg;
reg [31:0] re_position2_reg;
reg [31:0] im_position2_reg;
reg [31:0] re_position3_reg;
reg [31:0] im_position3_reg;
reg [31:0] re_position4_reg;
reg [31:0] im_position4_reg;


// Instantiate the dimensions module
dimensions Dimensions (
    .aclk(aclk),
    .en(en),
    .aresetn(aresetn),
    .width(X_size),
    .height(Y_size),
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
multiplier #(.N(52)) X1timesDELTA (
    .a({ 1'b0 , x_internal1, 21'b0}),
    .b(zoom_factor),
    .result(X1timesZF)
);

// Instantiate the YtimesDELTA multiplier
multiplier #(.N(52)) Y1timesDELTA (
    .a({ 1'b0, y_internal1, 21'b0}),
    .b(zoom_factor),
    .result(Y1timesZF)
);

multiplier #(.N(52)) X2timesDELTA (
    .a({ 1'b0 , x_internal2, 21'b0}),
    .b(zoom_factor),
    .result(X2timesZF)
);

// Instantiate the YtimesDELTA multiplier
multiplier #(.N(52)) Y2timesDELTA (
    .a({ 1'b0, y_internal2, 21'b0}),
    .b(zoom_factor),
    .result(Y2timesZF)
);

multiplier #(.N(52)) X3timesDELTA (
    .a({ 1'b0 , x_internal3, 21'b0}),
    .b(zoom_factor),
    .result(X3timesZF)
);

// Instantiate the YtimesDELTA multiplier
multiplier #(.N(52)) Y3timesDELTA (
    .a({ 1'b0, y_internal3, 21'b0}),
    .b(zoom_factor),
    .result(Y3timesZF)
);

multiplier #(.N(52)) X4timesDELTA (
    .a({ 1'b0 , x_internal4, 21'b0}),
    .b(zoom_factor),
    .result(X4timesZF)
);

// Instantiate the YtimesDELTA multiplier
multiplier #(.N(52)) Y4timesDELTA (
    .a({ 1'b0, y_internal4, 21'b0}),
    .b(zoom_factor),
    .result(Y4timesZF)
);

always @(posedge aclk) begin 
    x1_reg <= x_internal1;
    y1_reg <= y_internal1;
    re_position1_reg <= X1timesZF + re_lower;
    im_position1_reg <= -Y1timesZF + im_upper;

    x2_reg <= x_internal2;
    y2_reg <= y_internal2;
    re_position2_reg <= X2timesZF + re_lower;
    im_position2_reg <= -Y2timesZF + im_upper;

    x3_reg <= x_internal3;
    y3_reg <= y_internal3;
    re_position3_reg <= X3timesZF + re_lower;
    im_position3_reg <= -Y3timesZF + im_upper;

    x4_reg <= x_internal4;
    y4_reg <= y_internal4;
    re_position4_reg <= X4timesZF + re_lower;
    im_position4_reg <= -Y4timesZF + im_upper;
end 

assign x1 = x1_reg; 
assign y1 = y1_reg; 
assign re_position1 = re_position1_reg;
assign im_position1 = im_position1_reg;

assign x2 = x2_reg; 
assign y2 = y2_reg; 
assign re_position2 = re_position2_reg;
assign im_position2 = im_position2_reg;

assign x3 = x3_reg; 
assign y3 = y3_reg; 
assign re_position3 = re_position3_reg;
assign im_position3 = im_position3_reg;

assign x4 = x4_reg; 
assign y4 = y4_reg; 
assign re_position4 = re_position4_reg;
assign im_position4 = im_position4_reg;

endmodule
