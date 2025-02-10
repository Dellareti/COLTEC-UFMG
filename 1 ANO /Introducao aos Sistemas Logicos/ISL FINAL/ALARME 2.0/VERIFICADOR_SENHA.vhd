LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.STD_LOGIC_UNSIGNED.ALL;
USE IEEE.NUMERIC_STD.ALL;
USE IEEE.STD_LOGIC_ARITH.ALL;

ENTITY VERIFICADOR_SENHA IS
	PORT(b0,b1,b2,b3,clk,enable_geral:IN STD_LOGIC;
		 --BOTÕES
		 --b0    > ativa/desativa;
		 --b1/b2 > trocam senha;
		 --b3    > confirma senha;
		 senha_reg:IN STD_LOGIC_VECTOR(7 DOWNTO 0);
		 dig1,dig2:OUT STD_LOGIC_VECTOR(3 DOWNTO 0);
		 circuito_ativo: OUT STD_LOGIC;
		 confirmacao:BUFFER STD_LOGIC);
END ENTITY;

ARCHITECTURE arc OF VERIFICADOR_SENHA IS
	SIGNAL ultimob0,ultimob1,ultimob2,ultimob3,enable: STD_LOGIC :='0';
	SIGNAL senha1,senha2:STD_LOGIC_VECTOR(3 DOWNTO 0):="0000";
BEGIN
--dig1 = LSB
--dig2 = MSB

	dig1<=senha1;
	dig2<=senha2;
	circuito_ativo<=enable;
PROCESS(clk,enable,b1,b2,b3) IS
BEGIN
IF RISING_EDGE(clk) THEN
	ultimob0<=b0;	ultimob1<=b1;	ultimob2<=b2;	ultimob3<=b3;
	
	IF b0 = '1' AND ultimob0 = '0' AND enable = '0' AND enable_geral = '1' THEN
		enable<= '1';
	END IF;

	IF enable_geral = '0' THEN
		enable <= '0';
		senha1<="0000";
		senha2<="0000";
	END IF;
	IF enable = '1'  THEN
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
			IF senha_reg(3 DOWNTO 0) = senha1 AND senha_reg(7 DOWNTO 4) = senha2 THEN
				confirmacao <= NOT confirmacao;
				enable  <= '0';
				senha1<="0000";
				senha2<="0000";
			END IF;
		END IF;
	END IF;
END IF;
END PROCESS;
END ARCHITECTURE;