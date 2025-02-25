LIBRARY IEEE;

USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.STD_LOGIC_UNSIGNED.ALL;
USE IEEE.STD_LOGIC_ARITH.ALL;

--33330000

ENTITY libertacao IS
	GENERIC(bvp   : INTEGER); --bvp = bit vector position
	PORT(clk, btn : IN  STD_LOGIC;
		 led      : OUT STD_LOGIC);
END ENTITY;

ARCHITECTURE dataflow OF libertacao IS
BEGIN
		--"bvp" � a posi��o,  0-1-2;
		PROCESS(clk, btn) IS
			VARIABLE contagem  : UNSIGNED (2 DOWNTO 0) :="111";
			CONSTANT tudo_zero : UNSIGNED (2 DOWNTO 0) :="000";
			VARIABLE count: INTEGER   :=   0;
			VARIABLE x    : STD_LOGIC :=  '0';
 
 		BEGIN
				--CHECA A PRESSIONADA DE BTN E ALTERA A CONTAGEM BINARIA(ATIVAR OU DESATIVAR CIRCUITO)
				IF btn'EVENT AND btn'LAST_VALUE = '1' THEN
					IF contagem  = tudo_zero THEN
						contagem := "111";
					ELSIF contagem /= tudo_zero THEN
					contagem := contagem - 1;
					END IF;
				END IF;
				--CHECA O CLOCK E SE ESTE CIRCUITO ESTA ATIVADO
				IF contagem(bvp) = '1' THEN
					led <= '1';
				ELSIF clk'EVENT AND clk'LAST_VALUE = '0' AND contagem(bvp) = '0' THEN
				count := count + 1;
								IF count = 33330000 THEN
								x     := NOT(x);
								count := 0;
					
								END IF;
								led <= x;	
				--	led <= '0';		
				END IF;
		END PROCESS;
END dataflow;

LIBRARY IEEE;

USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.STD_LOGIC_UNSIGNED.ALL;
USE IEEE.STD_LOGIC_ARITH.ALL;
USE WORK.pacotin.ALL;

ENTITY TOP IS
	PORT(clk, btn: IN  STD_LOGIC;
		 s1, s2, s3: OUT STD_LOGIC);
END ENTITY;

ARCHITECTURE structural OF TOP IS
	COMPONENT led1 generic(bvp : INTEGER);PORT(clk,btn: IN STD_LOGIC; led: OUT STD_LOGIC);END COMPONENT;
	COMPONENT led2 generic(bvp : INTEGER);PORT(clk,btn: IN STD_LOGIC; led: OUT STD_LOGIC);END COMPONENT;
	COMPONENT led3 generic(bvp : INTEGER);PORT(clk,btn: IN STD_LOGIC; led: OUT STD_LOGIC);END COMPONENT;
	FOR ALL: led1 USE ENTITY work.libertacao(dataflow);
	FOR ALL: led2 USE ENTITY work.libertacao(dataflow);
	FOR ALL: led3 USE ENTITY work.libertacao(dataflow);

	SIGNAL filtrado: STD_LOGIC;
BEGIN
			
	
	FILTRO: MAQUINA_DE_ESTADOS PORT MAP (btn,clk,filtrado);
	
	l1: led1 GENERIC MAP(0)   PORT MAP (clk,filtrado, s1);
	l2: led2 GENERIC MAP(1)   PORT MAP (clk,filtrado, s2);
	l3: led3 GENERIC MAP(2)   PORT MAP (clk,filtrado, s3);

END structural;	
	
--33330000
--66660000
--133320000