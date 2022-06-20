LIBRARY ieee ;
USE ieee.std_logic_1164.all;

entity mux_4to1 is port (
 a: in std_logic_vector(4 downto 1);
 s: in std_logic_vector(2 downto 1);
 d: out std_logic);
end mux_4to1;

architecture dataflow of mux_4to1 is
BEGIN 

process (s)

BEGIN
  if (s="00") then
        d <= a(1);
    elsif (s="01") then 
        d <= a(2);
    elsif (s="10") then
        d <= a(3);
    else
        d <= a(4); 
    end if;
END process;
END dataflow;