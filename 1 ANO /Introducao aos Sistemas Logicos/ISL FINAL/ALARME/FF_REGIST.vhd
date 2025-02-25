LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY FF_D IS
	PORT(d,clk,enable,clear:IN STD_LOGIC;
		 q,q_not:BUFFER STD_LOGIC);
END ENTITY;

ARCHITECTURE arc OF FF_D IS
BEGIN
	PROCESS(clk,enable,clear) IS 
	BEGIN
		IF RISING_EDGE(clk) AND enable = '1' THEN
			q<=d;
		END IF;
		IF clear = '1' THEN
			q<='0';
		END IF;
	END PROCESS;
	q_not <= NOT q;
END ARCHITECTURE;


LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY FF_JK IS
	PORT(j,k,clk,enable,clear,preset:IN STD_LOGIC;
		 q,q_not:BUFFER STD_LOGIC);
END ENTITY;

ARCHITECTURE arc OF FF_JK IS
BEGIN
	PROCESS(clk,enable,clear,preset) IS 
	BEGIN
		IF  RISING_EDGE(clk) AND enable = '1' THEN
			IF j = '0' AND k = '0' THEN
				q<=q;
			ELSIF j = '0' AND k= '1' THEN
				q<='0';
			ELSIF j = '1' AND k= '0' THEN
				q<='1';
			ELSIF j = '1' AND k= '1' THEN
				q<=NOT q;
			END IF;
		END IF;
		IF clear = '1' AND enable = '1' THEN
			q<='0';
		END IF;
		IF preset = '1' AND enable = '1' THEN
			q<='1';
		END IF;
	END PROCESS;
	q_not <= NOT q;
END ARCHITECTURE;


LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE WORK.COMPONENTES.ALL;

ENTITY REGISTRADOR_8BITS_ARMAZENAMENTO IS
	PORT(a:IN  STD_LOGIC_VECTOR(7 DOWNTO 0);	
		 clk,enable,clear: IN STD_LOGIC;
		 b:OUT  STD_LOGIC_VECTOR(7 DOWNTO 0));
END ENTITY;

ARCHITECTURE arc OF REGISTRADOR_8BITS_ARMAZENAMENTO IS
	SIGNAL d:STD_LOGIC_VECTOR (7 DOWNTO 0);
BEGIN
	FF0: FF_D PORT MAP(d(0),clk,enable,clear,b(0));
	FF1: FF_D PORT MAP(d(1),clk,enable,clear,b(1));
	FF2: FF_D PORT MAP(d(2),clk,enable,clear,b(2));
	FF3: FF_D PORT MAP(d(3),clk,enable,clear,b(3));
	FF4: FF_D PORT MAP(d(4),clk,enable,clear,b(4));
	FF5: FF_D PORT MAP(d(5),clk,enable,clear,b(5));
	FF6: FF_D PORT MAP(d(6),clk,enable,clear,b(6));
	FF7: FF_D PORT MAP(d(7),clk,enable,clear,b(7));

PROCESS(clk,clear,a) IS
BEGIN
	IF clear = '1' THEN
	d<="00000000";
	ELSE
	d<=a;
	END IF;
END PROCESS;
END ARCHITECTURE;