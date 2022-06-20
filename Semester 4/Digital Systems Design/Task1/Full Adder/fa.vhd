LIBRARY ieee;
USE ieee.std_logic_1164.all;

ENTITY fa IS
port ( 
A, B, Cin : in std_logic;
S, Cout : out std_logic);
END fa;

ARCHITECTURE dataflow of fa IS
BEGIN
PROCESS (A,B,Cin)
BEGIN
	S <= (A XOR B);
	Cout <= ( (Cin AND (A XOR B) ) OR (A AND B));
END PROCESS;
END dataflow;
