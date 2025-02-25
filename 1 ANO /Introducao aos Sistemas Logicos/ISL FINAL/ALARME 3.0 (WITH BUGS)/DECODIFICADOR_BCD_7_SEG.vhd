LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;


ENTITY DECODIFICADOR_BCD_7SEG IS
PORT (dig : IN STD_LOGIC_VECTOR (3 DOWNTO 0);
	  a,b,c,d,e,f,g: OUT STD_LOGIC);
END ENTITY;

ARCHITECTURE decoder OF DECODIFICADOR_BCD_7SEG IS
BEGIN
	PROCESS(dig) IS
	BEGIN
		IF dig= "0000" THEN
			a<='0';	b<='0';	c<='0';	d<='0';	e<='0';	f<='0';	g<='1';
		ELSIF dig = "0001" THEN
			a<='1';	b<='0';	c<='0';	d<='1';	e<='1';	f<='1';	g<='1';
		ELSIF dig = "0010" THEN
			a<='0';	b<='0';	c<='1';	d<='0';	e<='0';	f<='1';	g<='0';
		ELSIF dig = "0011" THEN
			a<='0';	b<='0';	c<='0';	d<='0';	e<='1';	f<='1';	g<='0';
		ELSIF dig = "0100" THEN
			a<='1';	b<='0';	c<='0';	d<='1';	e<='1';	f<='0';	g<='0';
		ELSIF dig = "0101" THEN
			a<='0';	b<='1';	c<='0';	d<='0';	e<='1';	f<='0';	g<='0';
		ELSIF dig = "0110" THEN
			a<='0';	b<='1';	c<='0';	d<='0';	e<='0';	f<='0';	g<='0';
		ELSIF dig = "0111" THEN
			a<='0';	b<='0';	c<='0';	d<='1';	e<='1';	f<='1';	g<='1';
		ELSIF dig = "1000" THEN
			a<='0';	b<='0';	c<='0';	d<='0';	e<='0';	f<='0';	g<='0';
		ELSIF dig = "1001" THEN
			a<='0';	b<='0';	c<='0';	d<='0';	e<='1';	f<='0';	g<='0';
		ELSE
			a<='1';	b<='1';	c<='1';	d<='1';	e<='1';	f<='1';	g<='1';
		END IF;
	END PROCESS;
END ARCHITECTURE;