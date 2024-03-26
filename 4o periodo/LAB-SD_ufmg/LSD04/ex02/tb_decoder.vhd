library ieee;
use ieee.std_logic_1164.all;

entity tb_decoder is
    end entity;

architecture test of tb_decoder is 
    component decoder is 
        port(
            a, b, c : in std_logic;
            s0, s1, s2, s3, s4, s5, s6, s7 : out std_logic
        );
    end component decoder;

    signal A, B, C, S0, S1, S2, S3, S4, S5, S6, S7 : std_logic;

    begin
        instancia_decoder : decoder port map(
            a => A,
            b => B,
            c => C,
            s0 => S0,
            s1 => S1,
            s2 => S2,
            s3 => S3,
            s4 => S4,
            s5 => S5,
            s6 => S6,
            s7 => S7
        );
        A <= '0', '1' after 30 ns, '0' after 60 ns;
        B <= '1', '0' after 30 ns, '1' after 60 ns;
        C <= '0', '1' after 30 ns, '0' after 60 ns;
end test;