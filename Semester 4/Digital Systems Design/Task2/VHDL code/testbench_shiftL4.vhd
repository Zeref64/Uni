LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.std_logic_unsigned.all;

ENTITY testbench_shiftL4 IS
END testbench_shiftL4;


ARCHITECTURE test_shiftL4 OF testbench_shiftL4 IS
signal enable, sin, clock,load: std_logic;
signal q,d: std_logic_vector (3 downto 0);

COMPONENT shiftL4 
GENERIC ( N : INTEGER := 4);
PORT ( 
D : IN STD_LOGIC_VECTOR(N-1 DOWNTO 0) ;
Enable : IN STD_LOGIC ;
Load : IN STD_LOGIC ;
Sin : IN STD_LOGIC ;
Clock : IN STD_LOGIC ;
Q : OUT STD_LOGIC_VECTOR(N-1 DOWNTO 0) ) ;
END COMPONENT;

BEGIN 
M1: shiftL4 port map (Enable=>enable, Sin=>sin, Clock=>clock, Q=>q, D=>d, Load=>load);
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
	clock<= '0'; wait for 10 ns; 
	clock<= '0'; wait for 10 ns;
  					--200 ns total
	clock<= '1'; wait for 10 ns;
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
load<= '1'; sin<= '0';
	d<= "1001"; wait for 20 ns;
load<= '0';
	sin<= '1'; wait for 20 ns;
	sin<= '0'; wait for 20 ns;
	sin<= '0'; wait for 20 ns;
	sin<= '1'; wait for 20 ns;
	sin<= '0'; wait for 20 ns;
	sin<= '0'; wait for 20 ns;
	sin<= '1'; wait for 20 ns;
enable<= '0';
	sin<= '1'; wait for 20 ns;
	sin<= '0'; wait for 20 ns; --200 ns

END PROCESS;
END test_shiftL4;