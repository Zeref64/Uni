library ieee;
USE ieee.std_logic_1164.all;
USE ieee.std_logic_unsigned.all;
USE ieee.numeric_std.ALL;
entity regFile is 
generic ( dw : natural := 4;
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
end regfile;
architecture behavioral of regFile is

type regArray is array(0 to size-1) of std_logic_vector(dw-1 downto 0);
signal regFile : regArray;

begin 
	process(clk)
	begin
		if (reset = '1') then
		 regFile(0) <= "0000";
		 regFile(1) <= "0000";
		 regFile(2) <= "0000";
		 regFile(3) <= "0000";
		else
		if (clk'event and clk='0') then
		 if we='1' then
		  regFile(to_integer(unsigned(wAddr))) <= A;
		  else
		  B <= regFile(to_integer(unsigned(rAddr1))); 
 		  C <= regFile(to_integer(unsigned(rAddr2))); 
		  end if;
		 end if;
		end if;

end process;
end behavioral;