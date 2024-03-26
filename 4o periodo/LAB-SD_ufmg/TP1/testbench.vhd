library ieee;use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity Testbench is
 end Testbench;

architecture Behavioral of Testbench is
    component BinToHex is
        port (
            A : in std_logic_vector(3 downto 0);            
            H : out std_logic_vector(6 downto 0)
        );
    end component;

    signal A_tb : std_logic_vector(3 downto 0);
    signal H_tb : std_logic_vector(6 downto 0);

begin
    DUT : BinToHex    port map (
        A => A_tb,        H => H_tb
    );
    -- Estímulos de entrada    
    stim_proc : process
    begin        -- Teste 1: Entrada "0000"
        A_tb <= "0000";        wait for 10 ns;
                -- Teste 2: Entrada "1010"
        A_tb <= "1010";        wait for 10 ns;
                -- Teste 3: Entrada "1101"
        A_tb <= "1101";        wait for 10 ns;
                -- Adicione mais casos de teste aqui, se necessário
                wait;
    end process;
    -- Processo de exibição de resultados    
    display_proc : process
    begin        
        wait for 50 ns;
                -- Exibir resultados
        report "Teste 1 - Entrada: " & integer'image(to_integer(unsigned(A_tb))) & ", Saída: " & integer'image(to_integer(unsigned(H_tb)));        
        wait for 10 ns;        
        -- Exibir resultados        report "Teste 2 - Entrada: " & integer'image(to_integer(unsigned(A_tb))) & ", Saída: " & integer'image(to_integer(unsigned(H_tb)));
                wait for 10 ns;
                -- Exibir resultados
        report "Teste 3 - Entrada: " & integer'image(to_integer(unsigned(A_tb))) & ", Saída: " & integer'image(to_integer(unsigned(H_tb)));        
        -- Adicione mais exibições de resultados para casos de teste adicionais, se necessário        
        wait;    
    end process;
end Behavioral;