module pixel_generator(
input           out_stream_aclk,
input           s_axi_lite_aclk,
input           axi_resetn,
input           periph_resetn,

//Stream output PPPP
output [31:0]   out_stream_tdata,
output [3:0]    out_stream_tkeep,
output          out_stream_tlast,
input           out_stream_tready,
output          out_stream_tvalid,
output [0:0]    out_stream_tuser, 

//AXI-Lite S
input [AXI_LITE_ADDR_WIDTH-1:0]     s_axi_lite_araddr,
output          s_axi_lite_arready,
input           s_axi_lite_arvalid,

input [AXI_LITE_ADDR_WIDTH-1:0]     s_axi_lite_awaddr,
output          s_axi_lite_awready,
input           s_axi_lite_awvalid,

input           s_axi_lite_bready,
output [1:0]    s_axi_lite_bresp,
output          s_axi_lite_bvalid,

output [31:0]   s_axi_lite_rdata,
input           s_axi_lite_rready,
output [1:0]    s_axi_lite_rresp,
output          s_axi_lite_rvalid,

input  [31:0]   s_axi_lite_wdata,
output          s_axi_lite_wready,
input           s_axi_lite_wvalid

);

//localparam X_SIZE = 640;
//localparam Y_SIZE = 480;

parameter  REG_FILE_SIZE = 8;

localparam REG_FILE_AWIDTH = $clog2(REG_FILE_SIZE);
parameter  AXI_LITE_ADDR_WIDTH = 8;

localparam AWAIT_WADD_AND_DATA = 3'b000;
localparam AWAIT_WDATA = 3'b001;
localparam AWAIT_WADD = 3'b010;
localparam AWAIT_WRITE = 3'b100;
localparam AWAIT_RESP = 3'b101;

localparam AWAIT_RADD = 2'b00;
localparam AWAIT_FETCH = 2'b01;
localparam AWAIT_READ = 2'b10;

localparam AXI_OK = 2'b00;
localparam AXI_ERR = 2'b10;

reg [31:0]                          regfile [REG_FILE_SIZE-1:0];
reg [REG_FILE_AWIDTH-1:0]           writeAddr, readAddr;
reg [31:0]                          readData, writeData;
reg [1:0]                           readState = AWAIT_RADD;
reg [2:0]                           writeState = AWAIT_WADD_AND_DATA;

//Read from the register file
always @(posedge s_axi_lite_aclk) begin
    
    readData <= regfile[readAddr];

    if (!axi_resetn) begin
    readState <= AWAIT_RADD;
    end

    else case (readState)

        AWAIT_RADD: begin
            if (s_axi_lite_arvalid) begin
                readAddr <= s_axi_lite_araddr[2+:REG_FILE_AWIDTH];
                readState <= AWAIT_FETCH;
            end
        end

        AWAIT_FETCH: begin
            readState <= AWAIT_READ;
        end

        AWAIT_READ: begin
            if (s_axi_lite_rready) begin
                readState <= AWAIT_RADD;
            end
        end

        default: begin
            readState <= AWAIT_RADD;
        end

    endcase
end

assign s_axi_lite_arready = (readState == AWAIT_RADD);
assign s_axi_lite_rresp = (readAddr < REG_FILE_SIZE) ? AXI_OK : AXI_ERR;
assign s_axi_lite_rvalid = (readState == AWAIT_READ);
assign s_axi_lite_rdata = readData;

//Write to the register file, use a state machine to track address write, data write and response read events
always @(posedge s_axi_lite_aclk) begin

    if (!axi_resetn) begin
        writeState <= AWAIT_WADD_AND_DATA;
    end

    else case (writeState)

        AWAIT_WADD_AND_DATA: begin  //Idle, awaiting a write address or data
            case ({s_axi_lite_awvalid, s_axi_lite_wvalid})
                2'b10: begin
                    writeAddr <= s_axi_lite_awaddr[2+:REG_FILE_AWIDTH];
                    writeState <= AWAIT_WDATA;
                end
                2'b01: begin
                    writeData <= s_axi_lite_wdata;
                    writeState <= AWAIT_WADD;
                end
                2'b11: begin
                    writeData <= s_axi_lite_wdata;
                    writeAddr <= s_axi_lite_awaddr[2+:REG_FILE_AWIDTH];
                    writeState <= AWAIT_WRITE;
                end
                default: begin
                    writeState <= AWAIT_WADD_AND_DATA;
                end
            endcase        
        end

        AWAIT_WDATA: begin //Received address, waiting for data
            if (s_axi_lite_wvalid) begin
                writeData <= s_axi_lite_wdata;
                writeState <= AWAIT_WRITE;
            end
        end

        AWAIT_WADD: begin //Received data, waiting for address
            if (s_axi_lite_awvalid) begin
                writeAddr <= s_axi_lite_awaddr[2+:REG_FILE_AWIDTH];
                writeState <= AWAIT_WRITE;
            end
        end

        AWAIT_WRITE: begin //Perform the write
            regfile[writeAddr] <= writeData;
            writeState <= AWAIT_RESP;
        end

        AWAIT_RESP: begin //Wait to send response
            if (s_axi_lite_bready) begin
                writeState <= AWAIT_WADD_AND_DATA;
            end
        end

        default: begin
            writeState <= AWAIT_WADD_AND_DATA;
        end
    endcase
end

assign s_axi_lite_awready = (writeState == AWAIT_WADD_AND_DATA || writeState == AWAIT_WADD);
assign s_axi_lite_wready = (writeState == AWAIT_WADD_AND_DATA || writeState == AWAIT_WDATA);
assign s_axi_lite_bvalid = (writeState == AWAIT_RESP);
assign s_axi_lite_bresp = (writeAddr < REG_FILE_SIZE) ? AXI_OK : AXI_ERR;

//assign RGBXY = {R, G, B, X, Y};

wire [31:0] zoom_f, Re_lower, Im_upper;
wire [15:0] X_dimensions_wire, Y_dimensions_wire;
wire [23:0] max_iterations;

//regfile 0 is colour_case, down in colormapper 

// assign zoom_f = regfile[1][31:0]; 
// assign Im_upper = regfile[2][31:0];
// assign Re_lower = regfile[3][31:0];
// assign X_dimensions_wire = regfile[4][15:0];
// assign Y_dimensions_wire = regfile[4][31:16];
// assign max_iterations = regfile[5][23:0];

assign zoom_f = 32'h00199999; 
assign Im_upper = 32'h18000000;
assign Re_lower = 32'hE0000000;
assign X_dimensions_wire = 16'd640;
assign Y_dimensions_wire = 16'd480;
assign max_iterations = 24'h3FF;

wire [31:0] reg_julia_a0, reg_julia_b0;
wire juliavmandelbrot;

// assign reg_julia_a0 = regfile[6][31:0];
// assign reg_julia_b0 = regfile[7][31:0];
// assign juliavmandelbrot = regfile[0][4];

assign reg_julia_a0 = 32'hE8872B03;
assign reg_julia_b0 = 32'h0;
assign juliavmandelbrot = 1'b0;

wire [9:0] X, Y;
wire [23:0] RGB_out;
wire wEN;
wire [7:0] R, G, B;

mandelbrot_toplevel instance0 (
    .aresetn(~periph_resetn),
    .aclk(out_stream_aclk),
    .zoom_f(zoom_f),
    .Re_lower(Re_lower),
    .Im_upper(Im_upper),
    .X_dimensions(X_dimensions_wire),
    .Y_dimensions(Y_dimensions_wire),
    .max_iterations(max_iterations),
    .Ready(ready),
    .RGB_out(RGB_out), 
    .wEN(wEN),
    .x_coord(X),
    .y_coord(Y),
    .juliaset_a0(reg_julia_a0),
    .juliaset_b0(reg_julia_b0),
    .juliacase_value(juliavmandelbrot)
);

//assign {R, G, B} = RGB_out;
assign R = RGB_out[23:16];
assign G = RGB_out[15:8];
assign B = RGB_out[7:0];

wire [7:0] R_internal, G_internal, B_internal;

wire first = (X == 0) && (Y == 0);
wire lastx = (X == (X_dimensions_wire - 1));
wire lasty = (Y == (Y_dimensions_wire - 1));

wire [3:0] color_case_0;
assign color_case_0 = regfile[0][3:0];
// assign color_case_0 = 4'd0;


wire [23:0] COLOR2_CUSTOM;
assign COLOR2_CUSTOM = regfile[0][28:5];
// assign COLOR2_CUSTOM = 24'b0;

wire ready;

colormapper colormapping0 (
    .x(B),
    .y(G),
    .COLOR2(COLOR2_CUSTOM),
    .color_case(color_case_0),
    .gradient_mode(1'b1),
    .r_mapped(R_internal), 
    .g_mapped(G_internal), 
    .b_mapped(B_internal)
);

packer pixel_packer(    .aclk(out_stream_aclk),
                        .aresetn(periph_resetn),
                        .r(R_internal), .g(G_internal), .b(B_internal),
                        .eol(lastx), .in_stream_ready(ready), .valid(wEN), .sof(first),
                        .out_stream_tdata(out_stream_tdata), .out_stream_tkeep(out_stream_tkeep),
                        .out_stream_tlast(out_stream_tlast), .out_stream_tready(out_stream_tready),
                        .out_stream_tvalid(out_stream_tvalid), .out_stream_tuser(out_stream_tuser) );

endmodule
