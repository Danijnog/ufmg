-- Seção 5.7, exercicio 1 letra a) - página 68
-- O testbench desse exercicio foi refeito para ler de um arquivo externo, 'data.txt'
library ieee;
use ieee.std_logic_1164.all;

entity read_from_extern is
    port (
        a, b : in std_logic; -- entradas do exercicio
        s : out std_logic -- saida
    );

end read_from_extern;

architecture ex_01_arch of read_from_extern is 
    signal AB : std_logic_vector(1 downto 0); --sinal que vai receber as entradas concatenadas

begin
    AB <= a & b; --vamos meio que concatenar as entradas no sinal AB que declarei e analisar o sinal
        
    my_proc : process (AB) is -- tudo que for realizado dentro do process vai ser feito de maneira sequencial, ou seja, um de cada vez
    begin
        case(AB) is 
            when "01" => s <= '1';
            when "11" => s <= '1';
            when "10" => s <= '1';
            when others => s <= '0';
        end case;

    end process;
end ex_01_arch;
