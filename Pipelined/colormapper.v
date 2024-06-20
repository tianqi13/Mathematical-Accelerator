module colormapper(
    input [7:0] x,
    input [7:0] y,
    input [23:0] COLOR2,
    input [3:0] color_case,
    output [7:0] r_mapped, g_mapped, b_mapped
);

wire [7:0] x_int = x; //mandelbrot_output
wire [7:0] y_int = y;

reg [7:0] r_int, g_int, b_int;
assign r_mapped = r_int;
assign g_mapped = g_int;
assign b_mapped = b_int;

wire [23:0] COLOR1 = 24'hFFFFFF;


// Extract RGB components of the colors
wire [7:0] r0 = COLOR1[23:16];
wire [7:0] g0 = COLOR1[15:8];
wire [7:0] b0 = COLOR1[7:0];

wire [7:0] r1 = COLOR2[23:16];
wire [7:0] g1 = COLOR2[15:8];
wire [7:0] b1 = COLOR2[7:0];

localparam [7:0] max  = 8'd160;

wire [8:0] r_step1 = (r1 >= r0) ? (r1 - r0) / (max) : (r0 - r1) / (max);
wire [8:0] g_step1 = (g1 >= g0) ? (g1 - g0) / (max) : (g0 - g1) / (max);
wire [8:0] b_step1 = (b1 >= b0) ? (b1 - b0) / (max) : (b0 - b1) / (max);

reg [8:0] r_plus, g_plus, b_plus, r_min, g_min, b_min;

always @* begin
    case (color_case)
        4'b0000: begin // mango sunrise
            //r_int = 8'b0;
            //g_int = y_int;
            //b_int = x_int;
            r_int = {1'b1, x_int[7:1]};
            g_int = {1'b0, ~x_int[7:1]};
            b_int = {1'b0, x_int[7:2]};
        end
        4'b0001: begin // minecraft
            r_int = (x_int[7] & ~x_int[6]) ? 8'h55 : (~x_int[7] & x_int[6] & x_int[5]) ? 8'hFF : ((~x_int[7]&~x_int[6]&x_int[5])) ? 8'b0 : {(x_int[7]), 1'b1, (x_int[7]), 1'b1, (x_int[7]), 1'b1, (x_int[7]&x_int[6]), (x_int[7]|x_int[6])};
            g_int = (x_int[7] & ~x_int[6]) ? 8'hFF : (~x_int[7] & x_int[6] & x_int[5]) ? 8'h88 : ((~x_int[7]&~x_int[6]&x_int[5])) ? 8'h88 : ((~x_int[7]&x_int[6])) ? 8'hFF : {(x_int[7]&~x_int[6]), (x_int[7]), (~x_int[7]), (x_int[7]), (~x_int[7]), 1'b1, (x_int[7]&~x_int[6]), (1'b1)};
            b_int = (x_int[7] & ~x_int[6]) ? 8'hFF : (~x_int[7] & x_int[6] & x_int[5]) ? 8'hFF : ((~x_int[7]&~x_int[6]&x_int[5])) ? 8'b0 : {(x_int[7] | x_int[6]), (x_int[7] | x_int[6]), (x_int[7] | x_int[6]), ~(x_int[7] & ~x_int[6]), ~(x_int[7] & ~x_int[6]), 1'b1, x_int[7:6]};
        end
        4'b0010: begin // barbie
            r_int = {1'b1, 1'b1, 1'b1, ~x_int[7], ~x_int[6:3]};
            g_int = {~x_int[7], ~x_int[6], ~x_int[5:0]};
            b_int = {1'b1, ~x_int[7], ~x_int[6:1]}; 
        end
        4'b0011: begin // midnight
            r_int = {2'b0, ~x_int[7:2]};
            g_int = {1'b0, x_int[7:1]};
            b_int = {1'b0, 1'b1, x_int[7:2]};
        end
        4'b0100: begin // moon
            r_int = x_int; // edit to take the most significant bits of the rgb number given
            g_int = x_int;
            b_int = x_int;
        end
        4'b0101: begin // retro
            r_int = 8'b0;
            g_int = x_int; // edit to take most significant bits of rgb
            b_int = 8'b0;
        end
        4'b0110: begin // citrus
            r_int = {~x_int[7:6], 1'b1, ~x_int[4:0]};
            g_int = {2'b11, x_int[7], 5'b11111};
            b_int = 8'b0;
        end
        4'b0111: begin // gradient
            r_plus = r0 + r_step1 * x_int;
            g_plus = g0 + g_step1 * x_int;
            b_plus = b0 + b_step1 * x_int;
            r_min  = r0 - r_step1 * x_int;
            g_min  = g0 - g_step1 * x_int;
            b_min  = b0 - b_step1 * x_int;
            // Clip to 8-bit values
            r_int = (r1 >= r0) ? r_plus : r_min;
            g_int = (g1 >= g0) ? g_plus : g_min;
            b_int = (b1 >= b0) ? b_plus : b_min;
        end 
        default: begin
            r_int = 8'b0;
            g_int = x_int;
            b_int = y_int;
        end
    endcase
end

endmodule

