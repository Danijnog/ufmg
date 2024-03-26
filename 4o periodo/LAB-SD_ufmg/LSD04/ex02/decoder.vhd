-- Seção 5.7, exercicio 7, pagina 69
-- Implementação de um 3:8 decoder usando process statement

library ieee;
use ieee.std_logic_1164.all;

entity decoder is 
    port(
        a, b, c : in std_logic;
        s0, s1, s2, s3, s4, s5, s6, s7 : out std_logic
    );
end decoder;

--importante: olhar a tabela verdade nesse link para compreender a lógica da arquitetura https://www.ques10.com/p/46463/3-to-8-decoder-and-truth-table-of-3-to-8-decoder/
architecture main of decoder is 
    signal ABC : std_logic_vector(2 downto 0); -- vou usar um sinal para armazenar um vetor do tamanho de 3 bits: por exemplo "001"

    begin
        ABC <= a & b & c; -- concatenando e armazendo os valores de a, b, c no sinal ABC que declarei

        proc: process (ABC) is -- processamento do sinal ABC, agora dentro do process o código é executado de maneira sequencial
        begin 
 
            if(ABC = "000") then
                s0 <= '1'; s1 <= '0'; s2 <= '0'; s3 <= '0'; s4 <= '0'; s5 <= '0'; s6 <= '0'; s7 <= '0';

            elsif(ABC = "001") then
                s0 <= '0'; s1 <= '1'; s2 <= '0'; s3 <= '0'; s4 <= '0'; s5 <= '0'; s6 <= '0'; s7 <= '0';

            elsif(ABC = "010") then
                s0 <= '0'; s1 <= '0'; s2 <= '1'; s3 <= '0'; s4 <= '0'; s5 <= '0'; s6 <= '0'; s7 <= '0';
            
            elsif(ABC = "011") then
                s0 <= '0'; s1 <= '0'; s2 <= '0'; s3 <= '1'; s4 <= '0'; s5 <= '0'; s6 <= '0'; s7 <= '0';
                
            elsif(ABC = "100") then
                s0 <= '0'; s1 <= '0'; s2 <= '0'; s3 <= '0'; s4 <= '1'; s5 <= '0'; s6 <= '0'; s7 <= '0';

            elsif(ABC = "101") then
                s0 <= '0'; s1 <= '0'; s2 <= '0'; s3 <= '0'; s4 <= '0'; s5 <= '1'; s6 <= '0'; s7 <= '0';

            elsif(ABC = "110") then
                s0 <= '0'; s1 <= '0'; s2 <= '0'; s3 <= '0'; s4 <= '0'; s5 <= '0'; s6 <= '1'; s7 <= '0';

            elsif(ABC = "111") then
                s0 <= '0'; s1 <= '0'; s2 <= '0'; s3 <= '0'; s4 <= '0'; s5 <= '0'; s6 <= '0'; s7 <= '1';
            end if;
            
        end process;
end main;