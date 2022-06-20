LIBRARY ieee ;
USE ieee.std_logic_1164.all;

entity dec4to16 is port (
a: in std_logic_vector( 4 downto 1);
d: out std_logic_vector(16 downto 1));
END dec4to16;

ARCHITECTURE dataflow of dec4to16 IS 
BEGIN
process (a)
BEGIN
	CASE a IS
	WHEN  "0000" => d <= "1000000000000000";
	WHEN  "0001" => d <= "0100000000000000";
	WHEN  "0010" => d <= "0010000000000000";
	WHEN  "0011" => d <= "0001000000000000";
	WHEN  "0100" => d <= "0000100000000000";
	WHEN  "0101" => d <= "0000010000000000";
	WHEN  "0110" => d <= "0000001000000000";
	WHEN  "0111" => d <= "0000000100000000";
	WHEN  "1000" => d <= "0000000010000000";
	WHEN  "1001" => d <= "0000000001000000";
	WHEN  "1010" => d <= "0000000000100000";
	WHEN  "1011" => d <= "0000000000010000";
	WHEN  "1100" => d <= "0000000000001000";
	WHEN  "1101" => d <= "0000000000000100";
	WHEN  "1110" => d <= "0000000000000010";
	WHEN  "1111" => d <= "0000000000000001";
	WHEN  OTHERS => d <= "0000000000000000";
	END CASE;
END PROCESS;
END dataflow;