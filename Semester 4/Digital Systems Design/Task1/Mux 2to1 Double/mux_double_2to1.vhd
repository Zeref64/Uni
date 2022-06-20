LIBRARY ieee ;
USE ieee.std_logic_1164.all;

entity mux_double_2to1 is
port
(a, b: in std_logic_vector(2 downto 0);
 s: in std_logic;
 d: out std_logic_vector(2 downto 0));
end mux_double_2to1;

architecture dataflow of mux_double_2to1 is 
BEGIN
	d <= a WHEN s='1' ELSE b;
end dataflow;