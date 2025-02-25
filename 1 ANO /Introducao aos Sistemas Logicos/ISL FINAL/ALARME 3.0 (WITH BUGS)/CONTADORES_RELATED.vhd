LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.STD_LOGIC_UNSIGNED.ALL;



ENTITY CONTADOR_30SEG IS
	PORT(clk,enable:IN STD_LOGIC;
		 d1:BUFFER STD_LOGIC_VECTOR(3 DOWNTO 0);
		 d2:BUFFER STD_LOGIC_VECTOR(3 DOWNTO 0);
		 cheguei_ao_zero:OUT STD_LOGIC);
END ENTITY;


ARCHITECTURE arc OF CONTADOR_30SEG IS
 SIGNAL a1:STD_LOGIC_VECTOR(3 DOWNTO 0):="0000";
 SIGNAL a2:STD_LOGIC_VECTOR(3 DOWNTO 0):="0011";
 SIGNAL clk1s: STD_LOGIC:='0';
BEGIN
	d1<=a1;
	d2<=a2;
--66666666
	PROCESS (clk) IS
		VARIABLE cont:INTEGER:=0;
	BEGIN
		IF RISING_EDGE(clk) THEN
			IF cont < 10 THEN
				cont:= cont + 1;
			ELSIF cont = 10 THEN
				cont:=0;
				clk1s<= NOT clk1s;
			END IF;
		END IF;
	END PROCESS;

	PROCESS (clk1s,enable,a1,a2) IS
	BEGIN
		IF RISING_EDGE(clk1s) AND enable = '1' THEN
			IF a1 = "0000" AND a2 > "0000" THEN
				a1 <= "1001";
				a2 <= a2 - '1';
			ELSIF a1 > "0000" THEN
				a1 <= a1 - '1';
			END IF;
		ELSIF RISING_EDGE(clk1s) AND enable = '0' THEN
			a1<="0000";
			a2<="0011";			
		END IF;
		IF a1 = "000" AND a2 = "000" THEN
			cheguei_ao_zero<='1';
		ELSE
			cheguei_ao_zero<='0';
		END IF;
	END PROCESS;
END ARCHITECTURE;

LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;


ENTITY CONTADOR_ANEL_3BITS IS
	PORT(b4,clk,enable:IN STD_LOGIC;
	saida0,saida1,saida2:OUT STD_LOGIC);
END ENTITY;

ARCHITECTURE arc OF CONTADOR_ANEL_3BITS IS
	SIGNAL s0   :STD_LOGIC := '1';
	SIGNAL s1,s2:STD_LOGIC := '0';
	SIGNAL ultimo :STD_LOGIC := '1';
BEGIN
	saida0<=s0;
	saida1<=s1;
	saida2<=s2;
	
	PROCESS(clk,enable,b4,s0,s1,s2,ultimo) IS
	BEGIN
	IF RISING_EDGE(clk) AND enable = '1' THEN
		ultimo<=b4;
		IF b4 = '0' AND ultimo = '1' AND enable = '1' THEN
			IF s0 = '1' AND s1 = '0' AND s2 = '0' THEN
				s0<='0';
				s1<='1';
				s2<='0';
			ELSIF s0 = '0' AND s1 = '1' AND s2 = '0' THEN
				s0<='0';
				s1<='0';
				s2<='1';
			ELSIF s0 = '0' AND s1 = '0' AND s2 = '1' THEN
				s0<='1';
				s1<='0';
				s2<='0';
			END IF;
		END IF;
	END IF;
	END PROCESS;
END ARCHITECTURE;