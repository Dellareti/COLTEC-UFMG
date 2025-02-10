LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.STD_LOGIC_UNSIGNED.ALL;
USE IEEE.NUMERIC_STD.ALL;
USE IEEE.STD_LOGIC_ARITH.ALL;
USE WORK.COMPONENTES.ALL;


ENTITY MONITORADOR IS
	PORT(distancia:IN STD_LOGIC_VECTOR(2 DOWNTO 0);
		 sensor,senha_reg: IN  STD_LOGIC_VECTOR(7 DOWNTO 0);
		 b1,b2,b3,enable,clk:IN STD_LOGIC;
		 led_requer_senha:OUT STD_LOGIC;
		 dig1,dig2:OUT STD_LOGIC_VECTOR(3 DOWNTO 0);
		 cont30seg:BUFFER STD_LOGIC;
		 confirm:OUT STD_LOGIC;
		 b0:BUFFER STD_LOGIC);
END ENTITY;

--QUANTO MAIOR O VALOR DO SENSOR, MAIOR A DISTANCIA
--A ENTRADA DISTANCIA FUNCIONA ASSIM:
--	100 = PERTO;
--  010 = MEDIO;
--  001 = LONGE;

ARCHITECTURE arc OF MONITORADOR IS
	SIGNAL confirmacao,ultimo_confirmacao :STD_LOGIC;
	SIGNAL ultimo_sensor:STD_LOGIC_VECTOR(7 DOWNTO 0) ;
BEGIN

	CLKS:  DIVISOR_DE_FREQUENCIA GENERIC MAP (400)PORT MAP(clk,b0);
	VERIF: VERIFICADOR_SENHA PORT MAP(NOT b0 AND enable,b1,b2,b3,clk,enable,senha_reg,dig1,dig2,led_requer_senha,confirmacao);

	confirm<=confirmacao;
	PROCESS(distancia,clk,enable) IS
	BEGIN 
	IF RISING_EDGE(clk) THEN
		ultimo_sensor <= sensor;
		ultimo_confirmacao<=confirmacao;
	END IF;
		IF RISING_EDGE(clk) THEN
			IF cont30seg = '1' AND ((confirmacao = '1' AND ultimo_confirmacao = '0') OR	(confirmacao = '0' AND ultimo_confirmacao = '1')) THEN	
					cont30seg<='0';
			END IF;	
		IF RISING_EDGE(clk) THEN
			IF enable = '1' THEN
				IF distancia = "100" THEN
					IF sensor <= "00001000" THEN
						IF sensor /= ultimo_sensor THEN
							cont30seg<='1';
						END IF;					
					END IF;
				ELSIF distancia = "010" THEN
					IF sensor <= "10000000" THEN
						IF sensor /= ultimo_sensor  THEN
							cont30seg<='1';
						END IF;					
					END IF;
				ELSIF distancia = "001" THEN	
					IF sensor <= "11111111" THEN
						IF sensor /= ultimo_sensor THEN
							cont30seg<='1';
						END IF;					
					END IF;
				END IF;	
			END IF;
		END IF;
	END IF;
	END PROCESS;
END ARCHITECTURE;