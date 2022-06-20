LIBRARY ieee;
USE ieee.std_logic_1164.all;

ENTITY fa4bit IS
port(
C_in : IN std_logic;
X, Y : IN std_logic_vector(3 DOWNTO 0);
S : OUT std_logic_vector(3 DOWNTO 0);
C_out : OUT std_logic);
END fa4bit;

ARCHITECTURE dataflow of fa4bit IS
signal C: std_logic_vector (3 downto 0);

COMPONENT fa
port ( 
A, B, Cin : in std_logic;
S, Cout : out std_logic);
END COMPONENT;

BEGIN 
M0: fa port map ( A => X(0), B => Y(0), Cin => C_in,
Cout => C(0), S => S(0));

M1: fa port map ( A => X(1), B => Y(1), Cin => C(0),
Cout => C(1), S => S(1));

M2: fa port map ( A => X(2), B => Y(2), Cin => C(1),
Cout => C(2), S => S(2));

M3: fa port map ( A => X(3), B => Y(3), Cin => C(2),
Cout => C(3), S => S(3));

C_out <= C(3);
END dataflow;