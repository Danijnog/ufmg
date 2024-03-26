-- Testbench do arquivo fsm.vhd
library ieee;
use IEEE.Std_logic_1164.all;
use IEEE.Numeric_Std.all;

entity tb_fsm is
end;

architecture bench of tb_fsm is

  component fsm 
      port(
          clock  : in std_logic;
          x1, x2 : in std_logic;
          z      : out std_logic;
          y1, y0 : out std_logic;
          reset   : in std_logic
      );
      end component;

  signal clock: std_logic;
  signal x1, x2: std_logic;
  signal z: std_logic;
  signal y1, y0: std_logic;
  signal reset: std_logic ;

  constant clock_period: time := 10 ns;
  signal stop_the_clock: boolean;

begin

  uut: fsm port map ( clock => clock,
                      x1    => x1,
                      x2    => x2,
                      z     => z,
                      y1    => y1,
                      y0    => y0,
                      reset => reset );


    reset_generate : process
    begin 
        reset <= '0';
        wait for 15 ns;
        reset <= '1';
        wait for 15 ns;
        reset <= '0';
        wait for 15 ns;
        reset <= '1';
        wait for 15 ns;
        reset <= '0';
        wait for 15 ns;
        reset <= '1';
        wait for 40 ns;
        reset <= '0';
        wait;
    end process;

    entrada_generate : process
    begin 
        x1 <= '1';
        x2 <= '0';
        wait for 10 ns;
        x1 <= '0';
        x2 <= '1';
        wait for 10 ns;
        x1 <= '1';
        x2 <= '0';
        wait for 15 ns;
        x1 <= '1';
        x2 <= '1';
        wait for 15 ns;
        x1 <= '0';
        x2 <= '0';
        wait for 15 ns;
        x1 <= '0';
        x2 <= '1';
        wait for 15 ns;
        x1 <= '1';
        x2 <= '0';
        wait for 15 ns;
        x2 <= '1';
        wait;
    end process;
    -- Put test bench stimulus code here

    stop_the_clock <= false;
  clocking: process
  begin
    while not stop_the_clock loop
      clock <= '0', '1' after clock_period / 2;
      wait for clock_period;
    end loop;
    wait;
  end process;

end;
  