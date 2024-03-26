library ieee;
use ieee.std_logic_1164.all;

entity flipflopT_tb is 
end entity;

architecture test of flipflopT_tb is 
    component flipflop_t is 
        port (
            clk : in std_logic;
            reset : in std_logic; -- entrada de reset
            set : in std_logic; -- entrada do preset
            t : in std_logic; -- entrada do flip flop
            q, q_barrado : out std_logic -- saida q
        );
    end component;

    signal CLK, RESET, SET, T, Q, Q_BARRADO : std_logic;

    begin
        instancia_flipflop_t : flipflop_t port map(clk => CLK, reset => RESET, set => SET,
        t => T, q => Q, q_barrado => Q_BARRADO);

        clk_generate : process
        begin
            while now < 1000 ns loop
                clk <= '0';
                wait for 30 ns;
                clk <= '1';
                wait for 30 ns;
                clk <= '0';
            end loop;
            wait;
        end process;
        
        reset_generate: process
        begin 
            reset <= '0';
            wait for 20 ns;
            reset <= '1';
            wait for 10 ns;
            reset <= '0';
            wait for 20 ns;
            wait;
        end process;

        set_generate: process
        begin 
            set <= '0';
            wait for 30 ns;
            set <= '1';
            wait for 20 ns;
            set <= '0';
            wait for 30 ns;
            wait;
        end process;

        entrada_generate: process 
        begin 
            t <= '1';
            wait for 10 ns;
            t <= '0';
            wait for 5 ns;
            t <= '1';
            wait for 10 ns;
            wait;
        end process;

end architecture;