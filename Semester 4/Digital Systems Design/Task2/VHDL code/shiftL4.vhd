LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.std_logic_unsigned.all;

ENTITY shiftL4 IS
GENERIC ( N : INTEGER := 4);
PORT ( 
D : IN STD_LOGIC_VECTOR(N-1 DOWNTO 0) ;
Enable : IN STD_LOGIC ;
Load : IN STD_LOGIC ;
Sin : IN STD_LOGIC ;
Clock : IN STD_LOGIC ;
Q : OUT STD_LOGIC_VECTOR(N-1 DOWNTO 0):= "0000" ) ;
END shiftL4 ;

ARCHITECTURE dataflow OF shiftL4 IS 
signal tmp: STD_LOGIC_VECTOR(3 DOWNTO 0) ;

BEGIN 
PROCESS (Clock)
BEGIN
	IF Clock 'EVENT AND Clock= '1' THEN 
		IF Enable= '1' 
		THEN
			IF Load= '0'
			 THEN 
				tmp<=Q;
				Q(0)<=Q(1);
				Q(1)<=Q(2);
				Q(2)<=Q(3);
				Q(3)<=Sin;
			ELSE 
				Q<=D;
			END IF;
		END IF;
	END IF;

END PROCESS;
END dataflow;