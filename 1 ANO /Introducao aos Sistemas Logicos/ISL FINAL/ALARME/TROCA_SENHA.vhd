LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.STD_LOGIC_UNSIGNED.ALL;
USE IEEE.NUMERIC_STD.ALL;
USE IEEE.STD_LOGIC_ARITH.ALL;
USE WORK.COMPONENTES.ALL;

ENTITY TROCA_SENHA IS
	PORT(saida_verif,clk,b1,b2,b3:IN STD_LOGIC;
		circuito_ativo: OUT STD_LOGIC;
		senha1,senha2: BUFFER STD_LOGIC_VECTOR(3 DOWNTO 0);
		senha_reg: OUT STD_LOGIC_VECTOR(7 DOWNTO 0);
		senha_trocada: BUFFER STD_LOGIC);
END ENTITY;

ARCHITECTURE arc OF TROCA_SENHA IS
	SIGNAL ultima_saida,ultimob1,ultimob2,ultimob3,enable: STD_LOGIC := '0';
BEGIN
	circuito_ativo<=enable;
	senha_reg(7 DOWNTO 4)<=senha2; 	senha_reg(3 DOWNTO 0)<=senha1;
PROCESS(saida_verif,clk) IS
	VARIABLE cont:INTEGER := 0;
BEGIN
IF RISING_EDGE(clk) THEN
	ultima_saida<=saida_verif;
	ultimob1<=b1;
	ultimob2<=b2;
	ultimob3<=b3;
	IF (saida_verif = '1' AND ultima_saida = '0')THEN
		enable<='1';
	END IF;
	IF enable = '1' THEN
		IF b1 = '1' AND ultimob1 = '0' THEN
			IF senha1 < "1001" THEN
				senha1 <= senha1 + '1';
			ELSIF senha1 = "1001" THEN
				senha1 <= "0000";
			END IF;
		END IF;
		IF b2 = '1' AND ultimob2 = '0' THEN
			IF senha2 < "1001" THEN
				senha2 <= senha2 + '1';
			ELSIF senha2 = "1001" THEN
				senha2 <= "0000";
			END IF;
		END IF;
		IF b3 = '1' AND ultimob3 = '0' THEN
			senha_trocada<='1';
			enable  <= '0';
		END IF;
	END IF;
END IF;
IF RISING_EDGE(clk) THEN
		IF senha_trocada = '1' THEN
		cont := cont + 1;
		IF cont = 70 THEN
			cont:=0;
			senha_trocada<='0';
		END IF;
	END IF;
END IF;
END PROCESS;
END ARCHITECTURE;