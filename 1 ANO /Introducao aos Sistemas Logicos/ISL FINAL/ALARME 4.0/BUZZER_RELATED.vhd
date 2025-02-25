LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.NUMERIC_STD.ALL;

ENTITY BEEP IS
	GENERIC(tempo:INTEGER:=13333333 );
	PORT(b0,b1,b2,b3,b4,b5,clk:IN STD_LOGIC;
		beep:BUFFER STD_LOGIC);
END ENTITY;

ARCHITECTURE arc OF BEEP IS
	SIGNAL enable : STD_LOGIC := '0';
	SIGNAL ultimo_b0,ultimo_b1,ultimo_b2,ultimo_b3,ultimo_b4,ultimo_b5 :STD_LOGIC := '1';
	
BEGIN
--BEEP DO BOTAO       cont = 13333333 
--BEEP DE CONFIRMAÇÃO cont = 66666666

	beep <= enable;

	PROCESS(clk,b0,b1,b2,b3,b4,b5,enable,ultimo_b0,ultimo_b1,ultimo_b2,ultimo_b3,ultimo_b4,ultimo_b5) IS
		VARIABLE cont:INTEGER:=0;
	BEGIN
		IF RISING_EDGE(clk) THEN
			ultimo_b0 <= b0; ultimo_b1<= b1; ultimo_b2<= b2; ultimo_b3 <= b3; ultimo_b4 <= b4; ultimo_b5<= b5;
		END IF;
		IF ((ultimo_b0 = '1' AND b0 = '0')OR(ultimo_b1 = '1' AND b1 = '0')OR(ultimo_b2 = '1' AND b2 = '0')OR(ultimo_b3 = '1' AND b3 = '0')OR(ultimo_b4 = '1' AND b4 = '0')OR(ultimo_b5 = '1' AND b5 = '0')) AND enable = '0' THEN 
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


LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;

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
		IF RISING_EDGE(clk66) THEN
			IF enable = '1' THEN
				--33333333
				IF cont < frequencia THEN
					cont:= cont + 1;
				ELSIF cont = frequencia THEN
					cont:=0;
					saida<= NOT saida;
				END IF;
			ELSIF enable = '0' THEN
				saida<='0';
			END IF;
		END IF;
	END PROCESS;
END ARCHITECTURE;