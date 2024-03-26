-- Testbench da ula de 8 bits

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity tb_ula is
    end tb_ula;

architecture main of tb_ula is 
    component ula is 
        port(
            x, y : in std_logic_vector(7 downto 0);
            seletor : in std_logic_vector(2 downto 0);
            s : out std_logic_vector(7 downto 0)
        );
end component;

    signal X, Y, S : std_logic_vector(7 downto 0);
    signal SELETOR : std_logic_vector(2 downto 0);

    begin 
        instancia_ula : ula port map(x => X, y => Y, seletor => SELETOR, s => S);

        x <= "00000001";
        y <= "00000111";
        seletor <= "000", "001" after 30 ns, "010" after 60 ns,
        "011" after 90 ns, "100" after 120 ns, "110" after 150 ns, "111" after 180 ns, "101" after 210 ns;

end main;


