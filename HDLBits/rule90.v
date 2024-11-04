// HDLBits - Rule 90 https://hdlbits.01xz.net/wiki/Rule90
module top_module(
    input clk,
    input load,
    input [511:0] data,
    output [511:0] q );
    // register containing previous output
    reg [511:0] p;
    // problem statement asks us to advance each clock cycle
    always @ (posedge clk) begin
        if (load)
        	q = data;
        else begin
            p = q; // store the previous output in p
            // apply rule 90
            q[0] = p[1];
            for (integer i = 1; i < 511; i = i + 1) begin
                q[i] = p[i-1] ^ p[i+1];
            end
            q[511] = p[510];
        end
    end
endmodule