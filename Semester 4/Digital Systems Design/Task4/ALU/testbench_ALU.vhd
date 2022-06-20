LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.std_logic_unsigned.all;
USE ieee.numeric_std.all;

ENTITY testbench_ALU IS 
END testbench_ALU;

ARCHITECTURE test_ALU OF testbench_ALU IS
signal ALUin1_A, ALUin2_A, ALUctrl_A, ALUout1_A : std_logic_vector (3 downto 0);
signal zero1: std_logic; 

COMPONENT ALU
port (
 ALUin1: in std_logic_vector(3 downto 0);
 ALUin2: in std_logic_vector(3 downto 0);
 ALUctrl: in std_logic_vector(3 downto 0);
 ALUout1: out std_logic_vector(3 downto 0);
 zero: out std_logic);
END COMPONENT;

BEGIN
M1: ALU port map (ALUin1=>ALUin1_A, ALUin2=>ALUin2_A, ALUctrl=>ALUctrl_A, ALUout1=>ALUout1_A, zero=>zero1);
PROCESS
BEGIN
    ALUctrl_A <="0010"; ALUin1_A <="0010"; ALUin2_A <="0100"; wait for 100 ns;
    ALUctrl_A <="0000"; ALUin1_A <="0100"; ALUin2_A <="1111"; wait for 100 ns;
    ALUctrl_A <="0001"; ALUin1_A <="0100"; ALUin2_A <="1111"; wait for 100 ns;
    ALUctrl_A <="0110"; ALUin1_A <="0100"; ALUin2_A <="0010"; wait for 100 ns;
    ALUctrl_A <="0110"; ALUin1_A <="0100"; ALUin2_A <="0110"; wait for 100 ns;
    ALUctrl_A <="0111"; ALUin1_A <="0100"; ALUin2_A <="0110"; wait for 100 ns;
END PROCESS;
END test_ALU;