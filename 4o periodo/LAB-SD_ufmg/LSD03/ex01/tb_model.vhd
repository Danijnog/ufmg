-- Testbench automatically generated online
-- at https://vhdl.lapinoo.net
-- Generation date : 16.3.2023 01:22:58 UTC

-- Esse testbench foi gerado de forma automatica, na verdade poderia ter feito um testbench mais simples, igual no ex02

library ieee;
use ieee.std_logic_1164.all;

entity tb_model is
end tb_model;

architecture tb of tb_model is

    component model_1
        port (a : in std_logic;
              b : in std_logic;
              c : in std_logic;
              d : in std_logic;
              s : out std_logic);
    end component;

    signal A : std_logic;
    signal B : std_logic;
    signal C : std_logic;
    signal D : std_logic;
    signal S : std_logic;

    constant TbPeriod : time := 1000 ns; -- EDIT Put right period here
    signal TbClock : std_logic := '0';
    signal TbSimEnded : std_logic := '0';

begin

    dut : model_1
    port map (a => A,
              b => B,
              c => C,
              d => D,
              s => S);

    -- Clock generation
    TbClock <= not TbClock after TbPeriod/2 when TbSimEnded /= '1' else '0';

    --  EDIT: Replace YOURCLOCKSIGNAL below by the name of your clock as I haven't guessed it
    --  YOURCLOCKSIGNAL <= TbClock;

    stimuli : process
    begin
        A <= '1'; --inicializei para testar esses valores
        B <= '0';
        C <= '0';
        D <= '1';
        wait for 40 ns; --depois disso mudo os valores da entrada pra ver se a saída irá mudar também
        A <= '0';
        B <= '1';
        C <= '1';
        D <= '0';

        -- EDIT Add stimuli here
        wait for 100 * TbPeriod;

        -- Stop the clock and hence terminate the simulation
        TbSimEnded <= '1';
        wait;
    end process;

end tb;

-- Configuration block below is required by some simulators. Usually no need to edit.

configuration cfg_tb_model of tb_model is
    for tb
    end for;
end cfg_tb_model;