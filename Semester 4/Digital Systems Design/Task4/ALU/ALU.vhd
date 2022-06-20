LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.STD_LOGIC_UNSIGNED.ALL;
USE IEEE.NUMERIC_STD.ALL;

ENTITY ALU is port (
ALUin1: in std_logic_vector(3 downto 0);
ALUin2: in std_logic_vector(3 downto 0);
ALUctrl: in std_logic_vector(3 downto 0);
ALUout1: out std_logic_vector(3 downto 0);
zero: out std_logic);
end ALU;

ARCHITECTURE BEHAVIOURAL OF ALU IS 
SIGNAL OUTPUT: STD_LOGIC_VECTOR(3 DOWNTO 0);
BEGIN
PROCESS (ALUctrl, ALUin1, ALUin2)	
	BEGIN
	IF ALUctrl = "0000" THEN
		OUTPUT <= ALUin1 AND ALUin2;
	ELSIF ALUctrl = "0001" THEN
		OUTPUT <= ALUin1 OR ALUin2;
	ELSIF ALUctrl = "0010" THEN
		OUTPUT <= ALUin1 + ALUin2;

	ELSIF ALUctrl = "0110" THEN
		OUTPUT <= ALUin1 - ALUin2;
	ELSIF ALUctrl = "0111" THEN
		IF ALUin1 - ALUin2 < 0 THEN
			OUTPUT <= "0001";
		ELSE 
			OUTPUT <= "0000";
		END IF;
	END IF;
END PROCESS;
ALUout1 <= OUTPUT;

WITH OUTPUT SELECT
zero <= '1' WHEN "0000",
        '0' WHEN OTHERS;

END BEHAVIOURAL;