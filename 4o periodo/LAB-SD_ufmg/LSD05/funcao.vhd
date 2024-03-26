-- Exercicio: implementar a função f(x) = r * x * not(x), sendo r=2 p/ qualquer valor de x e assumindo no max 4 bits pra representação
-- Para compilar e executar se desejar: certifique-se de ter o ghdl e gtkwave instalados primeiramente, e depois execute os comandos abaixo:
-- "ghdl -a *.vhd"
-- "ghdl -e funcao"
-- "ghdl -r tb_funcao --vcd=test.vcd"
-- "gtkwave test.vcd"

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity funcao is 
    port(
        x : in std_logic_vector(3 downto 0); -- entrada da função pedida no exercicio
        y : out std_logic_vector(7 downto 0) -- o resultado da multiplicação de dois numeros de 4 bits pode resultar em um numero de até 8 bits
    );
end entity;

architecture main of funcao is 

    begin 
        y <= std_logic_vector(unsigned(x) * not(unsigned(x)) sll 1);  -- o sll 1 é pra realizar o deslocamento de 1 bit pra esquerda, ou seja, multiplicar por 2 

    end main;

