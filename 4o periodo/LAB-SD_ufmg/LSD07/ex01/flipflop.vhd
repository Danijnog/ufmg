library ieee;
use ieee.std_logic_1164.all;

entity flipflop is 
    port (
        clk, reset, set: in std_logic;
        d : in std_logic;
        q, qbar : out std_logic
    );
end flipflop;

architecture arch of flipflop is
begin
    process (clk, reset, set)
    begin
        if reset = '1' then
            q <= '0';
            qbar <= '1';
        elsif set = '1' then
            q <= '1';
            qbar <= '0';
        elsif rising_edge(clk) then
            q <= d;
            qbar <= not d;
        end if;
    end process;
end arch;
