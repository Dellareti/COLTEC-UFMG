LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.STD_LOGIC_UNSIGNED.ALL;


ENTITY PULSO_24 IS
	PORT(clk26,conv:IN STD_LOGIC;
		 datac: IN STD_LOGIC_VECTOR(7 DOWNTO 0);
		 sensor_data:BUFFER STD_LOGIC_VECTOR(7 DOWNTO 0));
END ENTITY;

ARCHITECTURE arc OF PULSO_24 IS
	SIGNAL enable,l : STD_LOGIC := '0';
	BEGIN
	
	PROCESS(clk26,datac,conv,enable,l,sensor_data) IS
		VARIABLE co : INTEGER :=0;
	BEGIN
		IF RISING_EDGE(clk26) THEN
			l<=conv;
			
		END IF;
	
		IF RISING_EDGE(clk26) AND l = '0' AND conv = '1' AND enable = '0' THEN
			enable <= '1';
		END IF;
				
		IF enable = '1' AND RISING_EDGE(clk26) THEN
				co:= co + 1;
				IF co = 24 THEN
					co:=0;
					sensor_data<=datac;
					enable <= '0';
				END IF;
		ELSE
			sensor_data<=sensor_data;
		END IF;
	
	END PROCESS;
END ARCHITECTURE;