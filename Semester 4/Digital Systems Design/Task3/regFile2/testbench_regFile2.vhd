library ieee;
USE ieee.std_logic_1164.all;
USE ieee.std_logic_unsigned.all;
USE ieee.numeric_std.all;

ENTITY testbench_regfile2 is
END testbench_regfile2;

ARCHITECTURE test_regFile2 of testbench_regFile2 is
signal DW, SIZE :natural:= 4;
signal ADRW :natural := 2;
signal A1 : std_logic_vector(DW-1 downto 0);
signal RADDR1,RADDR2,WADDR: std_logic_vector(ADRW-1 downto 0);
signal WE,CLOCK,RESET: std_logic;
signal B1,C1 :std_logic_vector(DW-1 downto 0);

COMPONENT regFile
generic (
	 dw : natural := 4;
	size : natural := 4;
	adrw : natural := 2);
  port ( A : in std_logic_vector(dw-1 downto 0);
	rAddr1: in std_logic_vector(adrw-1 downto 0);
	rAddr2: in std_logic_vector(adrw-1 downto 0);
	wAddr : in std_logic_vector(adrw-1 downto 0);
	we : in std_logic;
	clk : in std_logic;
	reset : in std_logic;
	B : out std_logic_vector(dw-1 downto 0);
	C : out std_logic_vector(dw-1 downto 0));
END COMPONENT;

BEGIN
M1: regFile port map ( A => A1, raddr1 => RADDR1, raddr2 => RADDR2,
waddr => WADDR, we => WE, clk => CLOCK, reset => RESET, B => B1, C => C1);

PROCESS 
BEGIN

	CLOCK <= '1'; wait for 250 ns;
	CLOCK <= '0'; wait for 250 ns;

	CLOCK <= '1'; wait for 250 ns;
	CLOCK <= '0'; wait for 250 ns;

	CLOCK <= '1'; wait for 250 ns;
	CLOCK <= '0'; wait for 250 ns;

	CLOCK <= '1'; wait for 250 ns;
	CLOCK <= '0'; wait for 250 ns;

	CLOCK <= '1'; wait for 250 ns;
	CLOCK <= '0'; wait for 250 ns;

	CLOCK <= '1'; wait for 250 ns;
	CLOCK <= '0'; wait for 250 ns;
	
END PROCESS;
PROCESS 
BEGIN 
	WE <= '1';
	A1 <= "0101"; WADDR <= "00"; wait for 500 ns;
	A1 <= "1010"; WADDR <= "01"; wait for 500 ns;
	A1 <= "0000"; WADDR <= "10"; wait for 500 ns;
	A1 <= "1111"; WADDR <= "11"; wait for 500 ns;
	WE <= '0';
	RADDR1 <= "00"; 
	RADDR2 <= "10"; wait for 500 ns;
	
	RADDR1 <= "01"; 
	RADDR2 <= "11"; wait for 500 ns;
END PROCESS;
END test_regFile2;