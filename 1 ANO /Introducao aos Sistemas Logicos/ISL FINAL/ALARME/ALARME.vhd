LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE WORK.COMPONENTES.ALL;

--FREQUENCIA DE 1Hz
ENTITY FREQ_ALARME IS
	GENERIC(frequencia:INTEGER:=33333333);
	PORT(clk66,enable:IN STD_LOGIC;
		saida:BUFFER STD_LOGIC);
END ENTITY;


ARCHITECTURE arc OF FREQ_ALARME IS
BEGIN
	PROCESS(clk66,enable)IS
		VARIABLE cont:INTEGER:=0;
	BEGIN
		IF RISING_EDGE(clk66) AND enable = '1' THEN
		--33333333
			IF cont < frequencia THEN
				cont:= cont + 1;
			ELSIF cont = frequencia THEN
				cont:=0;
				saida<= NOT saida;
			END IF;
		END IF;
	END PROCESS;
END ARCHITECTURE;

LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE WORK.COMPONENTES.ALL;

ENTITY BEEP IS
	GENERIC(tempo:INTEGER:=13333333);
	PORT(pulso,clk:IN STD_LOGIC;
		beep:BUFFER STD_LOGIC);
END ENTITY;

ARCHITECTURE arc OF BEEP IS
	SIGNAL enable : STD_LOGIC := '0';
BEGIN
--BEEP DO BOTAO       cont = 13333333 
--BEEP DE CONFIRMAÇÃO cont = 66666666

beep <= enable;

	PROCESS(clk,pulso,enable) IS
		VARIABLE cont:INTEGER:=0;
	BEGIN
		IF pulso = '1' AND enable = '0' THEN 
			enable <= '1';
		ELSIF enable = '1' AND RISING_EDGE(clk) THEN 	
			cont := cont + 1;
				IF cont = tempo THEN	 
					cont := 0;
					enable <= '0';
				END IF;
		END IF;
	END PROCESS;	
END ARCHITECTURE;