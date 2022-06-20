LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.std_logic_unsigned.all;

ENTITY shift4 IS
PORT ( 
Enable : IN STD_LOGIC;
Sin : IN STD_LOGIC;
Clock : IN STD_LOGIC;
Q : OUT STD_LOGIC_VECTOR(3 DOWNTO 0):="0000");
END shift4 ;

ARCHITECTURE dataflow OF shift4 IS 

BEGIN 
PROCESS (Clock)
BEGIN
	IF Clock 'EVENT AND Clock= '1' 
	THEN 
		IF Enable= '1' 
		THEN 
			Q(0)<=Q(1);
			Q(1)<=Q(2);
			Q(2)<=Q(3);
			Q(3)<=Sin;
		END IF;
	END IF;

END PROCESS;
END dataflow;