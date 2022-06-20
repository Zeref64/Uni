LIBRARY ieee ;
USE ieee.std_logic_1164.all;

entity dec2to4 is
port (
a: in std_logic_vector(2 downto 1);
d: out std_logic_vector(4 downto 1));
end dec2to4;
architecture dataflow of dec2to4 is
BEGIN
process (a)
BEGIN
    CASE a IS
    WHEN "00" => d<="1000";
    WHEN "01" => d<="0100";
    WHEN "10" => d<="0010";
    WHEN "11" => d<="0001";
    WHEN OTHERS => d<="1111";
    END CASE;
END process;
END dataflow;
