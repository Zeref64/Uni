LIBRARY ieee ;
USE ieee.std_logic_1164.all;

entity testbench_dec2to4 is
end testbench_dec2to4;

architecture test_dec2to4 of testbench_dec2to4 is
signal A1: std_logic_vector (2 downto 1);
signal D1: std_logic_vector (2 downto 1);

component dec2to4
port
(a: in std_logic_vector(2 downto 1);
 d: out std_logic_vector(4 downto 1));
 end component;

begin
M1: dec2to4 port map (a => A1, d => D1);
process 
begin
	A1 <="00"; wait for 20 ps;
	A1 <="01"; wait for 20 ps;
	A1 <="10"; wait for 20 ps;
	A1 <="11"; wait for 20 ps;
end process;
end test_dec2to4;