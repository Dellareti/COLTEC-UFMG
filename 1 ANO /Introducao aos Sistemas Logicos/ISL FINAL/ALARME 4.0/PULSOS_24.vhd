LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.STD_LOGIC_UNSIGNED.ALL;


ENTITY PULSO_24 IS
	PORT(clk26,conv:IN STD_LOGIC;
		 datac: IN STD_LOGIC_VECTOR(7 DOWNTO 0);
		 sensor_data:BUFFER STD_LOGIC_VECTOR(7 DOWNTO 0));
END ENTITY;

ARCHITECTURE arc OF PULSO_24 IS
	BEGIN
	
	PROCESS(clk26,datac,conv,enable,sensor_data) IS
		VARIABLE co : INTEGER :=0;
	BEGIN
		IF conv = '1' AND RISING_EDGE(clk26) THEN
				co:= co + 1;
				IF co = 30 THEN
					co:=0;
					sensor_data<=datac;
				END IF;
		ELSE
			sensor_data<=sensor_data;
		END IF;
	
	END PROCESS;
END ARCHITECTURE;