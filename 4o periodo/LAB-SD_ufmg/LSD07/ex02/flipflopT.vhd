--Flip Flop tipo T
-- 'T- vem de 'toggle', que significa 'troca', 'inversao'
-- O output de um flip flop do tipo T é dependente tanto do input D quanto do atual valor da saída do flip flop
-- No flip flop tipo T, se o valor de t for 1 então o valor da saída irá inverter seu estado anterior 
-- se o valor de t for 0, então o valor da saída permanece em seu estado anterior

library ieee;
use ieee.std_logic_1164.all;

entity flipflop_t is 
    port (
        clk : in std_logic; -- clock
        reset : in std_logic; -- entrada de reset
        set : in std_logic; -- entrada do set
        t : in std_logic; -- entrada do flip flop
        q, q_barrado : out std_logic -- saida q
    );
    end entity;

architecture main of flipflop_t is 
    signal t_tmp : std_logic; -- sinal intermediário que é necessário no flip flop tipo T

    begin
    my_process : process(clk, reset, set)
        begin
            if(clk'event and clk='1') then 
                t_tmp <= t XOR t_tmp;
                q_barrado <= not (t XOR t_tmp);
            
            elsif(set = '0') then
                t_tmp <= '1';
                q_barrado <= '0';
            
            elsif(reset = '0') then
                t_tmp <= '1';
                q_barrado <= '0';
            
            end if;
        end process;
        q <= t_tmp; --atribuição final a saida 'q'
    end main;
