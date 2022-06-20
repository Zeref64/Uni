library ieee;
USE ieee.std_logic_1164.all;
USE ieee.std_logic_unsigned.all;
USE ieee.numeric_std.all;

ENTITY testbench_register is
END testbench_register;

ARCHITECTURE test_register of testbench_register is
signal D1,Q1 : bit_vector (3 downto 0);
signal CLOCK,CLEAR : bit;

COMPONENT register4
port (
D : in bit_vector(3 downto 0);
clk : in bit;
clr : in bit;
Q : out bit_vector(3 downto 0));
END COMPONENT;

BEGIN
M1: register4 port map (D=>D1, clk=>CLOCK, clr=>CLEAR, Q=>Q1);
PROCESS 
BEGIN 
    CLOCK <= '0'; wait for 250 ns;
    CLOCK <= '1'; wait for 250 ns; 
    CLOCK <= '0'; wait for 250 ns;
    CLOCK <= '1'; wait for 250 ns; 
    CLOCK <= '0'; wait for 250 ns;
    CLOCK <= '1'; wait for 250 ns; 
    CLOCK <= '0'; wait for 250 ns;
    CLOCK <= '1'; wait for 250 ns; 
END PROCESS;
PROCESS 
BEGIN 
    CLEAR <= '1';
D1 <= "0010"; wait for 500 ns;
D1 <= "1110"; wait for 500 ns;
D1 <= "1010"; wait for 500 ns;
    CLEAR <= '0';
D1 <= "0000"; wait for 500 ns;
END PROCESS;
END test_register;
