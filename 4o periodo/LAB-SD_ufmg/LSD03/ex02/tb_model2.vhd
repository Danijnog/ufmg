library ieee;
use ieee.std_logic_1164.all;

entity tb_model2 is
    end tb_model2;

architecture test of tb_model2 is

    component model_2 is 
        port (
            a, b, c, d : in std_logic;
            s : out std_logic
        );
    end component;

    signal A, B, C, D, S: std_logic; -- sinais de entrada e saida

    begin 
        instancia_model_2 : model_2 port map (a=>A, b=>B, c=>C, d=>D, s=>S); -- defini os valores abaixo para testar, que mudam com o passar de um intervalo de tempo (40 ns, 80 ns, 160 ns)
        A <= '0', '1' after 40 ns, '0' after 80 ns, '1' after 160 ns;
        B <= '1', '0' after 40 ns, '1' after 80 ns, '0' after 160 ns;
        C <= '0', '0' after 40 ns, '1' after 80 ns, '0' after 160 ns;
        D <= '1', '1' after 40 ns, '1' after 80 ns, '0' after 160 ns;
end test;