LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.STD_LOGIC_UNSIGNED.ALL;
USE IEEE.STD_LOGIC_ARITH.ALL;

ENTITY LED_PISCANTE IS
	GENERIC(tempo:INTEGER:=5);
	PORT (enable,clk:IN STD_LOGIC;
		  saida: BUFFER STD_LOGIC);
END ENTITY;

ARCHITECTURE arc OF LED_PISCANTE IS
BEGIN
	PROCESS(clk,enable)IS
		VARIABLE cont:INTEGER:=0;
	BEGIN
		IF RISING_EDGE(clk) AND enable = '1' THEN
			IF cont < tempo THEN
				cont:= cont + 1;
			ELSIF cont = tempo THEN
				cont:=0;
				saida<= NOT saida;
			END IF;
		ELSIF RISING_EDGE(clk) AND enable = '0' THEN
			cont:=0;
			saida<='0';
		END IF;
	END PROCESS;
END ARCHITECTURE;