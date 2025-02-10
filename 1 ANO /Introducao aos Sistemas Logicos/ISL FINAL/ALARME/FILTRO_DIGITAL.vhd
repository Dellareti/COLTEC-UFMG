LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.STD_LOGIC_UNSIGNED.ALL;
USE IEEE.NUMERIC_STD.ALL;


ENTITY FILTRO_BOTAO IS
	GENERIC(frequencia:INTEGER :=333333);
	PORT (botao,clk: IN  STD_LOGIC;
          botao_filtrado:OUT STD_LOGIC);
END ENTITY;
    
ARCHITECTURE arc OF FILTRO_BOTAO IS
	TYPE ESTADO IS ( REALIZAR_AMOSTRAGEM, AGUARDAR );
	SIGNAL shift_reg :STD_LOGIC_VECTOR(7 DOWNTO 0):="00000000";
	SIGNAL state : ESTADO := REALIZAR_AMOSTRAGEM;
	SIGNAL saida:STD_LOGIC := '1';
BEGIN
	botao_filtrado <= NOT saida;
	
PROCESS(clk) IS
	VARIABLE cont: INTEGER := 0 ;
BEGIN
	IF RISING_EDGE(clk) THEN
		CASE state IS
			WHEN REALIZAR_AMOSTRAGEM =>
				shift_reg(7) <= botao;
				shift_reg(6 DOWNTO 0) <= shift_reg(7 DOWNTO 1);
				state <= AGUARDAR;
			WHEN AGUARDAR =>
		--	333333 = 5 ms
				IF cont < frequencia THEN
					cont:= cont + 1;
				ELSIF cont = frequencia THEN
					cont:=0;
					state <= REALIZAR_AMOSTRAGEM;
				END IF;
		END CASE;
	
		IF shift_reg = "11111111" THEN
			saida<= '1';
		ELSIF shift_reg = "00000000" THEN
			saida<='0';
		ELSE
			saida<=saida;
		END IF;
	END IF;
END PROCESS;

END ARCHITECTURE;