LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.STD_LOGIC_UNSIGNED.ALL;
USE IEEE.NUMERIC_STD.ALL;
USE IEEE.STD_LOGIC_ARITH.ALL;
USE WORK.COMPONENTES.ALL;

ENTITY SELETOR IS
	PORT(clk,verif,troca,monitorador:IN STD_LOGIC;
		 d1_verif,d2_verif,d1_troca,d2_troca,d1_monitorador,d2_monitorador: IN STD_LOGIC_VECTOR(3 DOWNTO 0);
		disp1,disp2:OUT STD_LOGIC_VECTOR(3 DOWNTO 0));
END ENTITY;

ARCHITECTURE arc OF SELETOR IS
BEGIN
	
	PROCESS(clk,verif,troca,d1_verif,d2_verif,d1_troca,d2_troca,monitorador,d1_monitorador,d2_monitorador) IS
	BEGIN
	IF RISING_EDGE(clk)THEN
		IF verif = '1' AND troca = '0' AND monitorador = '0' THEN
			disp1<=d1_verif;
			disp2<=d2_verif;
		ELSIF troca = '1' AND verif = '0'AND monitorador = '0' THEN
			disp1<=d1_troca;
			disp2<=d2_troca;
		ELSIF monitorador = '1' AND troca = '0' AND verif = '0' THEN
			disp1<=d1_monitorador;
			disp2<=d2_monitorador;
		ELSIF(verif = '1' AND troca = '1' AND monitorador = '1') OR (verif = '0' AND troca = '0' AND monitorador = '0') THEN
			disp1<="1111";
			disp2<="1111";
		END IF;
	END IF;
	END PROCESS;
END ARCHITECTURE;