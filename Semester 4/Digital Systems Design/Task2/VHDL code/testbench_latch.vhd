LIBRARY ieee;
USE ieee.std_logic_1164.all;

ENTITY testbench_latch IS
END testbench_latch;

ARCHITECTURE test_latch OF testbench_latch IS
signal D1,EN1,Q1: bit;

COMPONENT latch 
port (
D : in bit;
EN : in bit;
Q : out bit);
END COMPONENT;

BEGIN 
M1: latch port map (D=>D1, EN=>EN1, Q=>Q1);
PROCESS
BEGIN
	EN1<= '1'; wait for 150 ns;
	EN1<= '0'; wait for 250 ns;
	EN1<= '1'; wait for 150 ns;
	EN1<= '0'; wait for 250 ns;
	EN1<= '1'; wait for 150 ns;
	EN1<= '0'; wait for 250 ns;
END PROCESS;
PROCESS 
BEGIN 
	D1<='1'; wait for 250 ns;
	D1<='0'; wait for 350 ns;
	D1<='1'; wait for 275 ns;
	D1<='0'; wait for 150 ns;
	D1<='1'; wait for 50 ns;
	D1<='0'; wait for 125 ns;
END PROCESS;
END test_latch;


