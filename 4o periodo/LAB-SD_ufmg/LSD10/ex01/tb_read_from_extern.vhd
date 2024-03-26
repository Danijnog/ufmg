library ieee;
use ieee.std_logic_1164.all;
use std.textio.all;
use ieee.std_logic_textio.all;

entity tb_read_from_extern is
    end tb_read_from_extern;

architecture tb_arch of tb_read_from_extern is 
    component read_from_extern is
        port (
            a, b : in std_logic;
            s    : out std_logic
        );
    end component;

    signal A, B, S : std_logic;

    -- buffer para armazenar o texto do arquivo a ser lido
    file input_buf : text; --text é uma palavra chave

    begin
        instancia_read_from_extern : read_from_extern port map(a => A, b => B, s => S);

    proc : process
        variable read_line : line; -- le a linha uma por uma do arquivo

        variable val_col1, val_col2 : std_logic;
        variable val_SPACE : character; --para espaços do arquivo

        begin 

            file_open(input_buf, "data.txt", read_mode);

            while not endfile(input_buf) loop 
                readline(input_buf, read_line);
                read(read_line, val_col1);
                read(read_line, val_SPACE);
                read(read_line, val_col2);

                a <= val_col1;
                b <= val_col2;

                wait for 20 ns;
            end loop;

            file_close(input_buf);
            wait;
        end process;
    end tb_arch;

