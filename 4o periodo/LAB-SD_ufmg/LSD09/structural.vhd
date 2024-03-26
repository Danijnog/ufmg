-- Exercicio 3, página 132, letra c
library ieee;
use ieee.std_logic_1164.all;

entity structural is 
    port (
        a : in std_logic;
        b : in std_logic;
        c : in std_logic;
        f : out std_logic
    );
end entity;

architecture main of structural is 

    component and1
        port (entrada_1, entrada_2 : in std_logic;
            saida_1      : out std_logic);
end component;

    component or1 
        port (entrada_3, entrada_4 : in std_logic;
            saida_2      : out std_logic);
end component;

    begin 

        a1 : and1 port map(entrada_1 => b, entrada_2 => a, saida_1 => f);



end main;
