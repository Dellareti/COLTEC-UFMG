LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.STD_LOGIC_UNSIGNED.ALL;
USE IEEE.NUMERIC_STD.ALL;
USE IEEE.STD_LOGIC_ARITH.ALL;


ENTITY GERADOR_DE_PULSO IS
	GENERIC(contador:INTEGER:=100);
	PORT(clk66,enable:IN STD_LOGIC;
		 pulso:OUT STD_LOGIC);
END ENTITY;

ARCHITECTURE arc OF GERADOR_DE_PULSO IS
	SIGNAL allow:STD_LOGIC := '1';
BEGIN
	PROCESS(clk66,allow,enable)IS
		VARIABLE cont : INTEGER :=0;
	BEGIN	
		IF enable = '1' AND allow = '1' THEN
			IF RISING_EDGE(clk66) THEN
				cont:=cont+1;
				pulso <= '1';
					IF cont = contador THEN
						allow <= '0';
						pulso<='0';
					END IF;
			END IF;		
		ELSIF enable = '0' AND allow = '0' THEN
			allow <= '1';
			cont:=0;
		END IF;
	END PROCESS;
END ARCHITECTURE;