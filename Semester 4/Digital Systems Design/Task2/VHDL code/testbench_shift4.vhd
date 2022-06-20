LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.std_logic_unsigned.all;

ENTITY testbench_shift4 IS
END testbench_shift4;


ARCHITECTURE test_shift4 OF testbench_shift4 IS
signal enable, sin, clock: std_logic;
signal q: std_logic_vector (3 downto 0);

COMPONENT shift4 
port (
Enable : IN STD_LOGIC;
Sin : IN STD_LOGIC;
Clock : IN STD_LOGIC;
Q : OUT STD_LOGIC_VECTOR(3 DOWNTO 0):="0000");
END COMPONENT;

BEGIN 
M1: shift4 port map (Enable=>enable, Sin=>sin, Clock=>clock, Q=>q);
PROCESS 
BEGIN 
	clock<= '0'; wait for 10 ns; 
	clock<= '0'; wait for 10 ns; 
	clock<= '0'; wait for 10 ns; 
	clock<= '0'; wait for 10 ns; 
	clock<= '0'; wait for 10 ns; 
	clock<= '0'; wait for 10 ns; 
	clock<= '0'; wait for 10 ns; 
	clock<= '0'; wait for 10 ns; 
	clock<= '0'; wait for 10 ns;  --180 ns total
	clock<= '1'; wait for 10 ns;
	clock<= '1'; wait for 10 ns;
	clock<= '1'; wait for 10 ns;
	clock<= '1'; wait for 10 ns;
	clock<= '1'; wait for 10 ns;
	clock<= '1'; wait for 10 ns;
	clock<= '1'; wait for 10 ns;
	clock<= '1'; wait for 10 ns;
	clock<= '1'; wait for 10 ns;
END PROCESS;
PROCESS
BEGIN
enable<= '1';
	sin<= '1'; wait for 20 ns;
	sin<= '0'; wait for 20 ns;
	sin<= '0'; wait for 20 ns;
	sin<= '1'; wait for 20 ns;
	sin<= '0'; wait for 20 ns;
	sin<= '0'; wait for 20 ns;
	sin<= '1'; wait for 20 ns;
enable<= '0';
	sin<= '1'; wait for 20 ns;
	sin<= '0'; wait for 20 ns; --180 ns

END PROCESS;
END test_shift4;