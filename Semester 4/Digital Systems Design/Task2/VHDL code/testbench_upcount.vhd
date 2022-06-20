LIBRARY ieee;
USE ieee.std_logic_1164.all;

ENTITY testbench_upcount IS
END testbench_upcount;

ARCHITECTURE test_upcount OF testbench_upcount IS
signal Clock1,Clear1: std_logic;
signal Q1: std_logic_vector (1 downto 0);

COMPONENT upcount 
PORT (
Clear, Clock : IN STD_LOGIC ;
Q : OUT STD_LOGIC_VECTOR(1 DOWNTO 0));
END COMPONENT;

BEGIN 
M1: upcount port map (Clock=>Clock1, Clear=>Clear1, Q=>Q1);
PROCESS
BEGIN
	Clock1<= '0'; wait for 10 ns;
	Clock1<= '1'; wait for 10 ns; 
	Clock1<= '0'; wait for 10 ns;
	Clock1<= '1'; wait for 10 ns; 
	Clock1<= '0'; wait for 10 ns;
	Clock1<= '1'; wait for 10 ns; 
	Clock1<= '0'; wait for 10 ns;
	Clock1<= '1'; wait for 10 ns; 
	Clock1<= '0'; wait for 10 ns;
	Clock1<= '1'; wait for 10 ns; 
	Clock1<= '0'; wait for 10 ns;
	Clock1<= '1'; wait for 10 ns; 
	Clock1<= '0'; wait for 10 ns;
	Clock1<= '1'; wait for 10 ns;  	 --140 ns total

END PROCESS;
PROCESS
BEGIN 
	Clear1<='0'; wait for 100 ns;
	Clear1<='1'; wait for 20 ns;  --120 ns total
END PROCESS;
END test_upcount;