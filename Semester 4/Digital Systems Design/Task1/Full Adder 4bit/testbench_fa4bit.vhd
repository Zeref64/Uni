LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.numeric_std.all;

ENTITY testbench_fa4bit IS
END testbench_fa4bit;

ARCHITECTURE test_fa4bit of testbench_fa4bit IS
signal Cin1: std_logic;
signal X1: std_logic_vector(3 downto 0);
signal Y1: std_logic_vector(3 downto 0);
signal S1: std_logic_vector(3 downto 0);
signal Cout1: std_logic;
 
COMPONENT fa4bit
port(
C_in : IN std_logic;
X, Y : IN std_logic_vector(3 DOWNTO 0);
S : OUT std_logic_vector(3 DOWNTO 0);
C_out : OUT std_logic);
END COMPONENT;
BEGIN 
M1: fa4bit port map (C_in => Cin1, X => X1, Y => Y1, S => S1, C_out => Cout1);
PROCESS
BEGIN
    X1<="0000"; Y1<="0000"; Cin1<='0'; wait for 20 ps;
    X1<="1111"; Y1<="1111"; Cin1<='0'; wait for 20 ps;
    X1<="1111"; Y1<="1111"; Cin1<='1'; wait for 20 ps;
    X1<=std_logic_vector(to_unsigned(3,X1'length)); Y1<=std_logic_vector(to_unsigned(5,Y1'length)); Cin1<='0'; wait for 20 ps;
    X1<=std_logic_vector(to_signed(-2,X1'length)); Y1<=std_logic_vector(to_unsigned(3,Y1'length)); Cin1<='0'; wait for 20 ps;
    X1<=std_logic_vector(to_signed(-8,X1'length)); Y1<=std_logic_vector(to_unsigned(7,Y1'length)); Cin1<='0'; wait for 20 ps;
END PROCESS;
END test_fa4bit;
