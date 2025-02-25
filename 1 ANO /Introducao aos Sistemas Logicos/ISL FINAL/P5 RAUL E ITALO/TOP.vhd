LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.STD_LOGIC_UNSIGNED.ALL;
USE IEEE.NUMERIC_STD.ALL;
USE IEEE.STD_LOGIC_ARITH.ALL;
USE WORK.pacotin.ALL;

ENTITY TOP IS
	PORT (bt1,b2,b3,clk: IN  STD_LOGIC;
          cooler,led:OUT STD_LOGIC);
END ENTITY;
    
ARCHITECTURE arc OF TOP IS
	SIGNAL b1:STD_LOGIC;
	SIGNAL ultimoBnt : STD_LOGIC := '0';
	
	CONSTANT periodo_cooler      :INTEGER := 6666666;
	CONSTANT p5_periodo_cooler   :INTEGER := 333333;
	CONSTANT periodo_led         :INTEGER := 1333333;
	CONSTANT p5_periodo_led      :INTEGER := 66666;
	
BEGIN

	FILTRO: MAQUINA_DE_ESTADOS PORT MAP(bt1,clk,b1);
	PROCESS(b1,b2,b3,clk) IS
		--10hz = 100ms COOLER
		--50hz = 20ms  LED
		VARIABLE duty_c: INTEGER :=0;
		VARIABLE duty_l: INTEGER :=0; 
		VARIABLE cont,cont2  : INTEGER :=0;
	BEGIN
	IF RISING_EDGE(clk) THEN
		ultimoBnt <= b1;
		IF b3 = '0' THEN
----------------------------------------------------------------LED
			IF b2 = '1' THEN
				IF b1 = '0' AND ultimoBnt = '1' THEN
				--SUBTRAI
					IF duty_l >= p5_periodo_led THEN
						duty_l := duty_l - p5_periodo_led;
					END IF;
				END IF;
			ELSIF b2 = '0' THEN
				IF b1 = '0' AND ultimoBnt = '1' THEN
				--SOMA
					IF (periodo_led - p5_periodo_led) >= duty_l THEN
						duty_l := duty_l + p5_periodo_led;
					END IF;
				END IF;		
			END IF;			
--------------------------------------------------------------COOLER			
		ELSIF b3 = '1' THEN
			IF b2 = '1' THEN
				IF b1 = '0' AND ultimoBnt = '1' THEN
				--SUBTRAI
					IF duty_c >= p5_periodo_cooler  THEN
						duty_c := duty_c - p5_periodo_cooler;
					END IF;	
				END IF;
			ELSIF b2 = '0' THEN
				IF b1 = '0' AND ultimoBnt = '1' THEN
				--SOMA
					IF (periodo_cooler - p5_periodo_cooler) >= duty_c THEN
						duty_c := duty_c + p5_periodo_cooler;
					END IF;
				END IF;		
			END IF;	
		
		END IF;
	END IF;	
--------------------------------------------------------------CONTADORES	
		IF RISING_EDGE(clk) THEN
			cont := cont + 1;
				IF cont = (duty_l)  THEN
						led <= '0';
				END IF;
				IF cont = periodo_led THEN
					IF duty_l /= 0 THEN
						led<='1';
					END IF;
					cont:=0;
				END IF;
		END IF;
		IF RISING_EDGE(clk) THEN
			cont2 := cont2 + 1;
				IF cont2 = (duty_c)  THEN
						cooler <= '0';
				END IF;
				IF cont2 = periodo_cooler THEN
					IF duty_c /= 0 THEN
						cooler<='1';
					END IF;
					cont2:=0;
				END IF;
		END IF;
	END PROCESS;
	
END ARCHITECTURE;