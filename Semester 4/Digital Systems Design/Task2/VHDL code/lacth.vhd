LIBRARY ieee;
USE ieee.std_logic_1164.all;

ENTITY latch IS 
port (
D : in bit;
EN : in bit;
Q : out bit);
END latch;

ARCHITECTURE dataflow OF latch IS 
BEGIN
PROCESS (D,En)
BEGIN 
	IF EN='1' 
	THEN
		Q <=D;
	END IF;
END PROCESS;
END dataflow;