module adder (input x1, input x2, input c_in, output sum, output c_out);
	assign
		sum = (x1^x2)^c_in;
	assign
		c_out = ( x1 & x2 ) | ( (x1^x2) & c_in );
endmodule
