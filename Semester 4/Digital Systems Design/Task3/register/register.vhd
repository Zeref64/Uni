LIBRARY ieee;
USE ieee.std_logic_1164.all;

ENTITY register4 IS
port (
D : in bit_vector(3 downto 0);
clk : in bit;
clr : in bit;
Q : out bit_vector(3 downto 0));
END register4;

ARCHITECTURE dataflow OF register4 IS 
BEGIN
PROCESS (clr,clk)
BEGIN
	IF clr = '0' 
	THEN
		Q<= "0000";
	ELSIF
		clk 'EVENT AND clk= '1' 
	THEN
		Q<= D;
	END IF;
END PROCESS;
END dataflow;