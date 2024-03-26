-- Exercicio 2, página 108

library ieee;
use ieee.std_logic_1164.all;

entity fsm is 
    port(
        clock  : in std_logic;
        x1, x2 : in std_logic;
        z      : out std_logic;
        y1, y0 : out std_logic;

        reset   : in std_logic --nRst é o reset negado
    );
    end entity;

architecture main of fsm is 
  
    type state_type is (ST0, ST1, ST2); --No exercício temos 3 estados que a fsm pode estar

    signal current_state, next_state : state_type; --Sinal que é do tipo state_type que criamos

    begin
        process(clock, reset, next_state) is -- Parte sequencial
        begin
            if(reset = '1') then
                current_state <= ST0;

            elsif(rising_edge(clock)) then 
                current_state <= next_state;
            end if;
        end process;
        
        process(current_state, x1, x2) -- Parte combinacional
        begin
            y0 <= '0'; --Inicializando os valores
            y1 <= '0';
            z  <= '0';
            case (current_state) is
                when ST0 =>
                    y1 <= '1'; -- Saida de dentro da fsm
                    y0 <= '0'; -- Saida de dentro da fsm
                    z  <= '0';
                    if(x1 = '1') then
                        next_state <= ST1;
                    else
                        next_state <= ST0;
                    end if;

                when ST1 =>
                    y1 <= '0';
                    y0 <= '1';
                    if(x2 = '1') then
                        next_state <= ST2;
                        z <= '0';
                    else 
                        next_state <= ST0;
                        z <= '1';
                    end if;
 
                when ST2 =>
                    y1 <= '1';
                    y0 <= '1';
                    if(x2 = '1') then --Nesse caso, na figura quando x2 = 1, a fsm permanece no estado de ST2
                        z <= '0';
                        next_state <= ST2; 
                    else
                        z <= '1';
                        next_state <= ST0;
                    end if;
                
                when others => 
                    y1 <= '0';
                    y0 <= '0';
                    next_state <= ST0;
            end case;
        end process;
end architecture;