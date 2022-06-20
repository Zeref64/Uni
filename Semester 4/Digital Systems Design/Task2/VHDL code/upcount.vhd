LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.std_logic_unsigned.all;

ENTITY upcount IS 
PORT (
Clear, Clock : IN STD_LOGIC ;
Q : OUT STD_LOGIC_VECTOR(1 DOWNTO 0));
END upcount ;

ARCHITECTURE dataflow OF upcount IS
signal count: STD_LOGIC_VECTOR(1 DOWNTO 0) :="00";

BEGIN
PROCESS (Clock)
BEGIN
	IF Clock 'EVENT AND Clock='1' 
	THEN 
		IF Clear= '0' 
		THEN
			count<= count + '1';
		ELSE 
			count<= "00";
		END IF;
	END IF;
END PROCESS;
Q<= count;
END dataflow;