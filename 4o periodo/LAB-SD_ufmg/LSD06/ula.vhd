-- Implementação de uma ULA de 8 bits
-- Para compilar e executar se desejar: certifique-se de ter o ghdl e gtkwave instalados primeiramente, e depois execute os comandos abaixo:
-- "ghdl -a *.vhd"
-- "ghdl -e funcao"
-- "ghdl -r tb_funcao --vcd=test.vcd"
-- "gtkwave test.vcd"

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity ula is 
    port (
        x, y : in std_logic_vector(7 downto 0); --entradas de 8 bits
        seletor : in std_logic_vector(2 downto 0); --seletor para identificar qual processo vai ser executado
        s : out std_logic_vector(7 downto 0)
    );
end entity;

architecture main of ula is 
    begin 

        my_proc : process(seletor) is 
        begin

            if(seletor = "000") then --operação de soma
                s <= std_logic_vector(unsigned(x) + unsigned(y)); 
            
            elsif(seletor = "001") then --operação de subtração
                s <= std_logic_vector(unsigned(x) + unsigned(y));
            
            elsif(seletor = "010") then --operação incremento
                s <= std_logic_vector(unsigned(x) + 1);
            
            elsif(seletor = "011") then --operação decremento
                s <= std_logic_vector(unsigned(x) - 1);

            elsif(seletor = "100") then --operação and
                s <= std_logic_vector(unsigned(x) and unsigned(y));
            
            elsif(seletor = "110") then --operação or
                s <= std_logic_vector(unsigned(x) or unsigned(y));
            
            elsif(seletor = "111") then --operação xor
                s <= std_logic_vector(unsigned(x) xor unsigned(y));
            
            else 
                s <= std_logic_vector(unsigned(x) or unsigned(y) srl 1);
            
            end if;

        end process;

end main;
