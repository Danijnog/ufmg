ghdl -a *.vhd && ghdl -r test_bench --vcd=test.vcd --stop-time=1000ns && gtkwave test.vcd

ghdl -a --ieee=synopsys *.vhd 
chmod 755 script1.bat