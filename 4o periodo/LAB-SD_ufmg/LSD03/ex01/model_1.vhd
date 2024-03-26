-- Exercicio 4.8, numero 1 letra b)

library ieee;
use ieee.std_logic_1164.all;

entity model_1 is 
    port (
        a, b, c, d: in std_logic; -- são as 4 entradas que pede o exercicio
        s : out std_logic -- saída do exercicio
    );
end model_1;

architecture main of model_1 is  
    signal A1, A2, A3 : std_logic; -- defini 3 sinais intermediários que vão auxiliar no resultado final

    begin 
        A1 <= ((NOT a) AND c AND (NOT d));
        A2 <= ((NOT b) AND c);
        A3 <= (b AND c AND (NOT d));
        s <= A1 OR A2 OR A3;
end main;