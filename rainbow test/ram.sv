module Ram #(
    parameter ADDRESS_WIDTH = 20,
            DATA_WIDTH = 15
)(
    input logic clk,
    input logic WRITE_EN,
    input logic READ_EN,
    input logic [ADDRESS_WIDTH-1:0] rd_addr,
    input logic [ADDRESS_WIDTH-1:0] wr_addr,
    input logic [DATA_WIDTH-1:0] din,
    output logic [DATA_WIDTH-1:0] dout

);

logic [DATA_WIDTH-1:0] ram_array [2**ADDRESS_WIDTH-1:0];


always_ff @(posedge clk) begin
    if (WRITE_EN ==1'b1)
        ram_array[wr_addr] <=din;
    if (READ_EN == 1'b1)
        dout <= ram_array[rd_addr];
end 
endmodule

