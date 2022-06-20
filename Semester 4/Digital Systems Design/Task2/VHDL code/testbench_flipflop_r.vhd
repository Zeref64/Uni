LIBRARY ieee;
USE ieee.std_logic_1164.all;

ENTITY testbench_flipflop_r IS
END testbench_flipflop_r;

ARCHITECTURE test_flipflop_r OF testbench_flipflop_r IS
signal D1,CLOCK1,Rstn1,Q1: bit;

COMPONENT flipflop_r
port (
D : in bit;
CLOCK : in bit;
Rstn: in bit;
Q : out bit);
END COMPONENT;

BEGIN
M1: flipflop_r port map (D=>D1, CLOCK=>CLOCK1, Rstn=>Rstn1, Q=>Q1);
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
	Rstn1<= '1'; wait for 1800 ns;
	Rstn1<= '0'; wait for 600 ns;
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
END test_flipflop_r;
