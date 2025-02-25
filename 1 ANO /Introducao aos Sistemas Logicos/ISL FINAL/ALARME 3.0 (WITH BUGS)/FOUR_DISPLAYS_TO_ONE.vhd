LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.STD_LOGIC_UNSIGNED.ALL;
USE IEEE.NUMERIC_STD.ALL;
USE IEEE.STD_LOGIC_ARITH.ALL;

ENTITY  FOUR_DISPLAYS_TO_ONE IS
	PORT(a1,b1,c1,d1,e1,f1,g1:IN STD_LOGIC;
		 a2,b2,c2,d2,e2,f2,g2:IN STD_LOGIC;
		 a3,b3,c3,d3,e3,f3,g3:IN STD_LOGIC;
		 a4,b4,c4,d4,e4,f4,g4:IN STD_LOGIC;
		 clk:IN STD_LOGIC;
		 A,B,C,D,E,F,G,controle1,controle2,controle3,controle4:OUT STD_LOGIC
		 );
END ENTITY;

ARCHITECTURE arc OF FOUR_DISPLAYS_TO_ONE IS
BEGIN
	PROCESS(clk)IS
		VARIABLE cont:INTEGER := 0;
	BEGIN
		IF RISING_EDGE(clk) THEN
			cont:= cont + 1;
					IF cont >= 0 AND cont <= 20 THEN
						controle1<='0';
						controle2<='1';
						controle3<='1';
						controle4<='1';
					ELSIF 	cont > 20 AND cont <= 25 THEN
						controle1<='1';
						controle2<='1';
						controle3<='1';
						controle4<='1';
						A<=a2;
						B<=b2;
						C<=c2;
						D<=d2;
						E<=e2;
						F<=f2;
						G<=g2;
					ELSIF 	cont > 25 AND cont <= 45 THEN
						controle1<='1';
						controle2<='0';
						controle3<='1';
						controle4<='1';
					ELSIF 	cont > 45 AND cont <= 50 THEN
						controle1<='1';
						controle2<='1';
						controle3<='1';
						controle4<='1';
						A<=a3;
						B<=b3;
						C<=c3;
						D<=d3;
						E<=e3;
						F<=f3;
						G<=g3;
					ELSIF 	cont > 50 AND cont <= 70 THEN
						controle1<='1';
						controle2<='1';
						controle3<='0';
						controle4<='1';
					ELSIF 	cont > 70 AND cont <= 75 THEN
						controle1<='1';
						controle2<='1';
						controle3<='1';
						controle4<='1';
						A<=a4;
						B<=b4;
						C<=c4;
						D<=d4;
						E<=e4;
						F<=f4;
						G<=g4;
					ELSIF 	cont > 75 AND cont <= 95 THEN
						controle1<='1';
						controle2<='1';
						controle3<='1';
						controle4<='0';
					ELSIF 	cont > 95 AND cont <= 100 THEN
						controle1<='1';
						controle2<='1';
						controle3<='1';
						controle4<='1';
						A<=a1;
						B<=b1;
						C<=c1;
						D<=d1;
						E<=e1;
						F<=f1;
						G<=g1;
					ELSIF cont > 1000 THEN
						cont:=0;
					END IF;
		END IF;
	END PROCESS;
END ARCHITECTURE;