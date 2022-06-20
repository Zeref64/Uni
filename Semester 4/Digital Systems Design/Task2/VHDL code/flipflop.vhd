LIBRARY ieee;
USE ieee.std_logic_1164.all;

ENTITY flipflop is port (
D : in bit;
CLOCK : in bit;
Q : out bit);
END flipflop;

ARCHITECTURE dataflow OF flipflop IS
BEGIN 
PROCESS (CLOCK)
BEGIN 
	IF CLOCK 'EVENT AND CLOCK='1'
	THEN
		Q<= D;
	END IF;
END PROCESS;
END dataflow;