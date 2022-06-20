LIBRARY ieee ;
USE ieee.std_logic_1164.all;

ENTITY testbench_ha IS
END testbench_ha;

ARCHITECTURE test_ha OF testbench_ha IS
signal A1: bit;
signal B1: bit;
signal S1: bit;
signal C1: bit;
COMPONENT ha
port
(A, B : in bit;
 S,C : out bit);
END COMPONENT;

BEGIN 
M1: ha port map (a => A1, b => B1, s => S1, c => C1);
PROCESS
BEGIN
A1 <= '0'; B1 <= '0'; wait for 20 ps;
A1 <= '0'; B1 <= '1'; wait for 20 ps;
A1 <= '1'; B1 <= '0'; wait for 20 ps;
A1 <= '1'; B1 <= '1'; wait for 20 ps;
END PROCESS;
END test_ha;