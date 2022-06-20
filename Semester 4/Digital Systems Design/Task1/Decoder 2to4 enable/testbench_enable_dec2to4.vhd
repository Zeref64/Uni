LIBRARY ieee ;
USE ieee.std_logic_1164.all;

ENTITY testbench_enable_dec2to4 IS
END testbench_enable_dec2to4;

ARCHITECTURE test_enable_dec2to4 OF testbench_enable_dec2to4 IS
signal A1: std_logic_vector (2 downto 1);
signal D1: std_logic_vector (4 downto 1);
signal EN1: std_logic;

COMPONENT enable_dec2to4
port 
(a: in std_logic_vector(2 downto 1);
 en: in std_logic;
 d: out std_logic_vector(4 downto 1));
END COMPONENT; 

BEGIN
M1: enable_dec2to4 port map (a => A1, d => D1, en => EN1);
PROCESS
BEGIN
	A1 <="00"; EN1<='0'; wait for 20 ps;
	A1 <="01"; EN1<='0'; wait for 20 ps;	
	A1 <="10"; EN1<='0'; wait for 20 ps;
	A1 <="11"; EN1<='0'; wait for 20 ps;
	A1 <="00"; EN1<='1'; wait for 20 ps;
	A1 <="01"; EN1<='1'; wait for 20 ps;	
	A1 <="10"; EN1<='1'; wait for 20 ps;
	A1 <="11"; EN1<='1'; wait for 20 ps;
END PROCESS;
END test_enable_dec2to4;