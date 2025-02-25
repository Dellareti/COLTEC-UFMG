LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY TROCA_ESTADO IS
	PORT(verificador,monitorador,clk:IN STD_LOGIC;
		 estado:BUFFER STD_LOGIC);
END ENTITY;

ARCHITECTURE arc OF TROCA_ESTADO IS
	SIGNAL ultimo_verif,ultimo_monit:STD_LOGIC;
BEGIN
	PROCESS(clk,verificador,monitorador)IS
	BEGIN
		IF RISING_EDGE(clk) THEN
			ultimo_verif<=verificador;
			ultimo_monit<=monitorador;
				IF (verificador = '1' AND ultimo_verif = '0') OR (verificador = '0' AND ultimo_verif = '1') OR (monitorador = '1' AND ultimo_monit = '0') OR (monitorador = '0' AND ultimo_monit = '1') THEN
					estado<= NOT estado;
				END IF;
		END IF;
	END PROCESS;
END ARCHITECTURE;