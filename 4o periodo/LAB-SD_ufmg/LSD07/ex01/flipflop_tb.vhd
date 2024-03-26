library ieee;
use ieee.std_logic_1164.all;

entity flipflop_tb is
end entity flipflop_tb;

architecture testbench of flipflop_tb is
    signal clk, reset, set, d, q, qbar : std_logic;
begin
    dut : entity work.flipflop
        port map (
            clk => clk,
            reset => reset,
            set => set,
            d => d,
            q => q,
            qbar => qbar
        );

    clk_process : process
    begin
        clk <= '0';
        while now < 1000 ns loop
            wait for 10 ns;
            clk <= not clk;
        end loop;
        wait;
    end process;

    reset_process : process
    begin
        reset <= '1';
        wait for 5 ns;
        reset <= '0';
        wait for 10 ns;
        reset <= '1';
        wait for 5 ns;
        reset <= '0';
        wait;
    end process;

    set_process : process
    begin
        set <= '1';
        wait for 12 ns;
        set <= '0';
        wait for 8 ns;
        set <= '1';
        wait for 15 ns;
        set <= '0';
        wait for 25 ns;
        set <= '1';
        wait for 6 ns;
        set <= '0';
        wait;
    end process;

    stimulus_process : process
    begin
        d <= '0';
        wait for 15 ns;
        d <= '1';
        wait for 5 ns;
        d <= '0';
        wait for 20 ns;
        d <= '1';
        wait for 10 ns;
        d <= '0';
        wait;
    end process;

    verification_process : process
    begin
        wait for 1 ns; -- wait for simulation to start
        assert q = '0' report "Error: q should be 0" severity error;
        assert qbar = '1' report "Error: qbar should be 1" severity error;
        wait for 15 ns;
        assert q = '1' report "Error: q should be 1" severity error;
        assert qbar = '0' report "Error: qbar should be 0" severity error;
        wait for 20 ns;
        assert q = '0' report "Error: q should be 0" severity error;
        assert qbar = '1' report "Error: qbar should be 1" severity error;
        wait for 10 ns;
        assert q = '1' report "Error: q should be 1" severity error;
        assert qbar = '0' report "Error: qbar should be 0" severity error;
        wait;
    end process;

end architecture testbench;
