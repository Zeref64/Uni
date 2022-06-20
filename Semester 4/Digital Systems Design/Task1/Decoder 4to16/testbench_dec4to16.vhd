LIBRARY ieee ;
USE ieee.std_logic_1164.all;

ENTITY testbench_dec4to16 IS
END testbench_dec4to16;

ARCHITECTURE test_dec4to16 OF testbench_dec4to16 IS
signal A1: std_logic_vector (4 downto 1);
signal D1: std_logic_vector (16 downto 1);

COMPONENT dec4to16
port
(a: in std_logic_vector( 4 downto 1);
d: out std_logic_vector(16 downto 1));
END COMPONENT; 
BEGIN
M1: dec4to16 port map (a => A1, d => D1);
PROCESS 
BEGIN
A1 <="0000"; wait for 20 ps;
A1 <="0001"; wait for 20 ps;
A1 <="0010"; wait for 20 ps;
A1 <="0011"; wait for 20 ps;
A1 <="0100"; wait for 20 ps;
A1 <="0101"; wait for 20 ps;
A1 <="0110"; wait for 20 ps;
A1 <="0111"; wait for 20 ps;
A1 <="1000"; wait for 20 ps;
A1 <="1001"; wait for 20 ps;
A1 <="1010"; wait for 20 ps;
A1 <="1011"; wait for 20 ps;
A1 <="1100"; wait for 20 ps;
A1 <="1101"; wait for 20 ps;
A1 <="1110"; wait for 20 ps;
A1 <="1111"; wait for 20 ps;
END PROCESS;
END test_dec4to16;