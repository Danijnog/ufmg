-- Exercicio 4.8, numero 2 letra b)

library ieee;
use ieee.std_logic_1164.all;

entity model_2 is
    port (
        a, b, c, d : in std_logic; -- entradas do exercicio
        s : out std_logic -- saida

    );
end model_2;

architecture main of model_2 is
    signal t_sign : std_logic_vector(3 downto 0);

    begin
        t_sign <= (a & b & c & d); -- concatenacao de sinais

        with(t_sign) select -- o exercicio pede pra faze de forma condicional (uso do 'when', por exemplo) e de atribuiçaõ de sinal selecionado (uso do 'select' com o sinal t_sign)
                s <= '1' when "0000" | "0001"  -- através da tabela verdade vemos que os valores que geram '1' na saida são os que estão escritos em seguida de 'when'
                | "0010" | "0011" | "0100" | "0110"
                | "0111" | "1111",
                '0' when others;
end main;


