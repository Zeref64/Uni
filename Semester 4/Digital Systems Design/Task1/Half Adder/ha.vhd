LIBRARY ieee ;
USE ieee.std_logic_1164.all;

entity ha is port (
A, B : in bit;
S,C : out bit);
end ha;

ARCHITECTURE dataflow of ha IS 
BEGIN
process (a,b)
BEGIN
s <= (A XOR B);
c <= (A AND B);
END PROCESS;
END dataflow;