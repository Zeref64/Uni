LIBRARY ieee;
USE ieee.std_logic_1164.all;

ENTITY flipflop_r is port (
D : in bit;
CLOCK : in bit;
Rstn: in bit;
Q : out bit);
END flipflop_r;

ARCHITECTURE dataflow OF flipflop_r IS
BEGIN
PROCESS (CLOCK,Rstn)
BEGIN  
	IF Rstn= '0' THEN
		Q<= '0';
	ELSIF CLOCK 'EVENT AND CLOCK= '0' THEN 
		Q<=D;
	END IF;
END PROCESS;
END dataflow;