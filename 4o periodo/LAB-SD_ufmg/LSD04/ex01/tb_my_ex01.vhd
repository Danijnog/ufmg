library ieee;
use ieee.std_logic_1164.all;

entity tb_my_ex01 is
    end tb_my_ex01;

architecture test of tb_my_ex01 is
    component my_ex01 is
        port(
            a, b : in std_logic;
            s : out std_logic
        );  
    end component my_ex01;

    signal A, B, S : std_logic;

    begin 
        instancia_my_ex01 : my_ex01 port map (a => A, b => B, s => S); 
        A <= '0', '1' after 20 ns, '0' after 60 ns;
        B <= '0', '0' after 20 ns, '1' after 60 ns;
end test;
      