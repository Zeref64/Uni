LIBRARY ieee;
USE ieee.std_logic_1164.all;

ENTITY testbench_flipflop IS
END testbench_flipflop;

ARCHITECTURE test_flipflop OF testbench_flipflop IS
signal D1,CLOCK1,Q1: bit;

COMPONENT flipflop 
port (
D : in bit;
CLOCK : in bit;
Q : out bit);
END COMPONENT;

BEGIN 
M1: flipflop port map (D=>D1, CLOCK=>CLOCK1, Q=>Q1);
PROCESS
BEGIN 
	CLOCK1<= '1'; wait for 250 ns;
	CLOCK1<= '0'; wait for 350 ns; 
	CLOCK1<= '1'; wait for 250 ns;
	CLOCK1<= '0'; wait for 350 ns; 
	CLOCK1<= '1'; wait for 250 ns;
	CLOCK1<= '0'; wait for 350 ns; 
	CLOCK1<= '1'; wait for 250 ns;
	CLOCK1<= '0'; wait for 350 ns; 
END PROCESS;
PROCESS 
BEGIN 
	D1<= '1'; wait for 400 ns;
	D1<= '0'; wait for 600 ns; 
	D1<= '1'; wait for 300 ns;
	D1<= '0'; wait for 250 ns;
	D1<= '1'; wait for 150 ns;
	D1<= '0'; wait for 250 ns;
	D1<= '1'; wait for 300 ns;
	D1<= '0'; wait for 150 ns; 
END PROCESS;
END test_flipflop;


	