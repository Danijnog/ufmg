library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity BinToHex is    port (
        A : in std_logic_vector(3 downto 0);
        H : out std_logic_vector(0 to 6)
    );
end BinToHex;
architecture Behavioral of BinToHex is
begin    process(A)
    begin        case A is
            when "0000" => H <= "0000001"; -- 0 em hexadecimal            
            when "0001" => H <= "1001111"; -- 1 em hexadecimal
            when "0010" => H <= "0010010"; -- 2 em hexadecimal            
            when "0011" => H <= "0000110"; -- 3 em hexadecimal
            when "0100" => H <= "1001100"; -- 4 em hexadecimal            
            when "0101" => H <= "0100100"; -- 5 em hexadecimal
            when "0110" => H <= "0100000"; -- 6 em hexadecimal            
            when "0111" => H <= "0001111"; -- 7 em hexadecimal
            when "1000" => H <= "0000000"; -- 8 em hexadecimal            
            when "1001" => H <= "0001100"; -- 9 em hexadecimal
            when "1010" => H <= "0001000"; -- A em hexadecimal            
            when "1011" => H <= "1100000"; -- B em hexadecimal
            when "1100" => H <= "0110001"; -- C em hexadecimal            
            when "1101" => H <= "1000010"; -- D em hexadecimal
            when "1110" => H <= "0110000"; -- E em hexadecimal            
            when "1111" => H <= "0111000"; -- F em hexadecimal
            when others => H <= "XXXXXXX"; -- Entrada inválida (saída indeterminada)        
        end case;
    end process;
end Behavioral;