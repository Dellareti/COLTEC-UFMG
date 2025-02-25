LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;


ENTITY REGISTRADOR_8BITS_SENHA IS
	PORT(a:IN STD_LOGIC_VECTOR(7 DOWNTO 0);
		 clk,pulso:IN STD_LOGIC;
		 b:OUT STD_LOGIC_VECTOR(7 DOWNTO 0));
END ENTITY;

ARCHITECTURE arc OF REGISTRADOR_8BITS_SENHA IS
	SIGNAL ultimo:STD_LOGIC:='0';
BEGIN
	PROCESS(clk)IS
	BEGIN
		IF RISING_EDGE(clk) THEN
			ultimo<=pulso;
			IF pulso = '1' AND ultimo = '0' THEN
				b<=a;
			END IF;			
		END IF;
	END PROCESS;
END ARCHITECTURE;