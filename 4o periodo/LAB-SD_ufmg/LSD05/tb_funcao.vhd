library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity tb_funcao is
    end tb_funcao;

architecture testbench of tb_funcao is 
    component funcao is 
        port(
            x : in std_logic_vector(3 downto 0);
            y : out std_logic_vector(7 downto 0)
        );
    end component;

    signal X : std_logic_vector(3 downto 0);
    signal Y : std_logic_vector(7 downto 0);

    begin 
        instancia_operation : funcao port map(x => X, y => Y);

        x <= "0000", "1100" after 30 ns, "0101" after 60 ns, x"6" after 90 ns;
        
end testbench;
       

