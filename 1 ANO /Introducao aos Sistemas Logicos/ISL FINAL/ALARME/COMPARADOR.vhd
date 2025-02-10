LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY COMPARADOR IS
	PORT( d1,d2,s1,s2:IN  STD_LOGIC_VECTOR(3 DOWNTO 0);
		  clk,enable :IN  STD_LOGIC;
		  c          :BUFFER STD_LOGIC;
		  led        :OUT STD_LOGIC);
END ENTITY;

ARCHITECTURE arc OF COMPARADOR IS 
	SIGNAL aux: STD_LOGIC_VECTOR(7 DOWNTO 0);
BEGIN
	aux(0) <=(d1(0) AND s1(0) AND enable)OR((NOT d1(0)) AND (NOT s1(0)) AND enable);
	aux(1) <=(d1(1) AND s1(1) AND enable)OR((NOT d1(1)) AND (NOT s1(1)) AND enable);
	aux(2) <=(d1(2) AND s1(2) AND enable)OR((NOT d1(2)) AND (NOT s1(2)) AND enable);
	aux(3) <=(d1(3) AND s1(3) AND enable)OR((NOT d1(3)) AND (NOT s1(3)) AND enable);
	aux(4) <=(d2(0) AND s2(0) AND enable)OR((NOT d2(0)) AND (NOT s2(0)) AND enable);
	aux(5) <=(d2(1) AND s2(1) AND enable)OR((NOT d2(1)) AND (NOT s2(1)) AND enable);
	aux(6) <=(d2(2) AND s2(2) AND enable)OR((NOT d2(2)) AND (NOT s2(2)) AND enable);
	aux(7) <=(d2(3) AND s2(3) AND enable)OR((NOT d2(3)) AND (NOT s2(3)) AND enable);
	led<=enable;
	PROCESS (clk,enable,c) IS
	BEGIN
		IF RISING_EDGE(clk) AND enable = '1' THEN
			c <= aux(0) AND aux(1) AND aux(2) AND aux(3) AND aux(4) AND aux(5) AND aux(6) AND aux(7);	
		END IF;
		IF enable = '0' THEN
			c<=c;
		END IF;
	END PROCESS;
END ARCHITECTURE;