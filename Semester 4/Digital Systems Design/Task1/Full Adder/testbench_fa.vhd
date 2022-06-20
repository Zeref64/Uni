LIBRARY ieee ;
USE ieee.std_logic_1164.all;

entity testbench_fa is
end testbench_fa;
ARCHITECTURE test_fa of testbench_fa IS
signal A1: std_logic;
signal B1: std_logic ;
signal Cin1: std_logic ;
signal S1: std_logic ;
signal Cout1: std_logic ;

COMPONENT fa
port ( 
A, B, Cin : in std_logic;
S, Cout : out std_logic);
END COMPONENT;
BEGIN 
M1: fa port map (A => A1, B => B1, Cin => Cin1, S => S1, Cout => Cout1);
PROCESS
BEGIN
    A1<='0'; B1<='0'; Cin1<='0'; wait for 20 ps;
    A1<='0'; B1<='0'; Cin1<='1'; wait for 20 ps;
    A1<='0'; B1<='1'; Cin1<='0'; wait for 20 ps;
    A1<='0'; B1<='1'; Cin1<='1'; wait for 20 ps;
    A1<='1'; B1<='0'; Cin1<='0'; wait for 20 ps;
    A1<='1'; B1<='0'; Cin1<='1'; wait for 20 ps;
    A1<='1'; B1<='1'; Cin1<='0'; wait for 20 ps;
    A1<='1'; B1<='1'; Cin1<='1'; wait for 20 ps;
END PROCESS;
END test_fa;
