USE ieee.std_logic_1164.all;
USE ieee.std_logic_unsigned.all;
USE ieee.numeric_std.all;

ENTITY testbench_regfile is
END testbench_regfile;

ARCHITECTURE test_regfile of testbench_regfile is
signal DW : natural :=4;
signal SIZE : natural :=4;
signal ADRW : natural :=2;
signal A1 :  std_logic_vector; (DW-1 down to 0);
signal C1: std_logic_vector (DW-1 down to 0);
signal ADDR1 : std_logic_vector (ADRW-1 down to 0);
signal WE : std_logic;
signal CLOCK :  std_logic;

COMPONENT regfile
generic 
( dw : natural := 4;
size : natural := 4;
adrw : natural := 2);

port 
( A : in std_logic_vector(dw-1 downto 0);
Addr : in std_logic_vector(adrw-1 downto 0);
we : in std_logic;
clk : in std_logic;
C : out std_logic_vector(dw-1 downto 0));
END COMPONENT;

BEGIN
M1: regfile port map (dw => DW, size => SIZE adrw => ADRW, A => A1, addr => ADDR1, we => WE, clk => CLOCK, c => C1);
 
PROCESS 
BEGIN
	CLOCK <= '1' wait for 250ns;
	CLOCK <= '0' wait for 250ns;
	CLOCK <= '1' wait for 250ns;
	CLOCK <= '0' wait for 250ns;
	CLOCK <= '1' wait for 250ns;
	CLOCK <= '0' wait for 250ns;
	CLOCK <= '1' wait for 250ns;
	CLOCK <= '0' wait for 250ns;
END PROCESS;

PROCESS
BEGIN
	WE <= '1'; ADDRQ <= "00"; A1 <= "0101" wait for 500ns;
	WE <= '1'; ADDRQ <= "00"; A1 <= "1101" wait for 500ns;
	WE <= '1'; ADDRQ <= "00"; A1 <= "0010" wait for 500ns;
	WE <= '1'; ADDRQ <= "00"; A1 <= "1001" wait for 500ns;
	WE <= '1'; ADDRQ <= "00"; A1 <= "0101" wait for 500ns;
	ADRW <= "01"; wait for 500ns;
	ADRW <= "11"; wait for 500ns;
END PROCESS;
END test_regfile