-- Seção 5.7, exercicio 1 letra a) - página 68

library ieee;
use ieee.std_logic_1164.all;

entity my_ex01 is
    port (
        a, b : in std_logic; -- entradas do exercicio
        s : out std_logic -- saida
    );

end my_ex01;

architecture my_ex01_arch of my_ex01 is 
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

        -- outra forma de fazer o mesmo exercício, usando "if"
        -- if(AB = "01") then
        --     s <= '1';
        -- elsif(AB = "11") then
        --     s <= '1';
        -- elsif(AB = "10") then
        --     s <= '1';
        -- else
        --     s <= '0';
        -- end if;

    end process;
end my_ex01_arch;
