LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;

PACKAGE COMPONENTES IS

COMPONENT FILTRO_BOTAO IS
	GENERIC(frequencia:INTEGER :=13333333 );
	PORT (botao,clk: IN  STD_LOGIC;
          botao_filtrado:OUT STD_LOGIC);
END COMPONENT;


COMPONENT BEEP IS
	GENERIC(tempo:INTEGER:=10);
	PORT(b0,b1,b2,b3,b4,b5,clk:IN STD_LOGIC;
		beep:BUFFER STD_LOGIC);
END COMPONENT;


COMPONENT VERIFICADOR_SENHA IS
	PORT(b0,b1,b2,b3,clk,enable_geral:IN STD_LOGIC;
		 senha_reg:IN STD_LOGIC_VECTOR(7 DOWNTO 0);
		 dig1,dig2:OUT STD_LOGIC_VECTOR(3 DOWNTO 0);
		 circuito_ativo: OUT STD_LOGIC;
		 confirmacao:BUFFER STD_LOGIC);
END COMPONENT;


COMPONENT TROCA_ESTADO IS
	PORT(verificador,monitorador,clk:IN STD_LOGIC;
		 estado:BUFFER STD_LOGIC);
END COMPONENT;


COMPONENT CONTADOR_ANEL_3BITS IS
	PORT(b4,clk,enable:IN STD_LOGIC;
	saida0,saida1,saida2:OUT STD_LOGIC);
END COMPONENT;


COMPONENT REGISTRADOR_8BITS_SENHA IS
	PORT(a:IN STD_LOGIC_VECTOR(7 DOWNTO 0);
		 clk,pulso:IN STD_LOGIC;
		 b:OUT STD_LOGIC_VECTOR(7 DOWNTO 0));
END COMPONENT;


COMPONENT TROCA_SENHA IS
	PORT(estado_do_circuito,clk,b1,b2,b3,b4:IN STD_LOGIC;
		circuito_ativo: OUT STD_LOGIC;
		senha1,senha2: BUFFER STD_LOGIC_VECTOR(3 DOWNTO 0);
		senha_reg: OUT STD_LOGIC_VECTOR(7 DOWNTO 0);
		senha_trocada: BUFFER STD_LOGIC);
END COMPONENT;


COMPONENT FREQ_ALARME IS
	GENERIC(frequencia:INTEGER:=33333333);
	PORT(clk66,enable:IN STD_LOGIC;
		saida:BUFFER STD_LOGIC);
END COMPONENT;


COMPONENT MONITORADOR IS
	PORT(distancia:IN STD_LOGIC_VECTOR(2 DOWNTO 0);
		 sensor,senha_reg: IN  STD_LOGIC_VECTOR(7 DOWNTO 0);
		 b1,b2,b3,enable,clk:IN STD_LOGIC;
		 led_requer_senha:OUT STD_LOGIC;
		 dig1,dig2:OUT STD_LOGIC_VECTOR(3 DOWNTO 0);
		 cont30seg:BUFFER STD_LOGIC;
		 confirm:OUT STD_LOGIC;
		 b0:BUFFER STD_LOGIC);
END COMPONENT;


COMPONENT CONTADOR_30SEG IS
	PORT(clk,enable:IN STD_LOGIC;
		 d1:BUFFER STD_LOGIC_VECTOR(3 DOWNTO 0);
		 d2:BUFFER STD_LOGIC_VECTOR(3 DOWNTO 0);
		 cheguei_ao_zero:OUT STD_LOGIC);
END COMPONENT;


COMPONENT SELETOR IS
	PORT(clk,verif,troca,monitorador:IN STD_LOGIC;
		 d1_verif,d2_verif,d1_troca,d2_troca,d1_monitorador,d2_monitorador: IN STD_LOGIC_VECTOR(3 DOWNTO 0);
		disp1,disp2:OUT STD_LOGIC_VECTOR(3 DOWNTO 0));
END COMPONENT;


COMPONENT DECODIFICADOR_BCD_7SEG IS
PORT (dig : IN STD_LOGIC_VECTOR (3 DOWNTO 0);
	  a,b,c,d,e,f,g: OUT STD_LOGIC);
END COMPONENT;


COMPONENT  FOUR_DISPLAYS_TO_ONE IS
	PORT(a1,b1,c1,d1,e1,f1,g1:IN STD_LOGIC;
		 a2,b2,c2,d2,e2,f2,g2:IN STD_LOGIC;
		 a3,b3,c3,d3,e3,f3,g3:IN STD_LOGIC;
		 a4,b4,c4,d4,e4,f4,g4:IN STD_LOGIC;
		 clk:IN STD_LOGIC;
		 A,B,C,D,E,F,G,controle1,controle2,controle3,controle4:OUT STD_LOGIC
		 );
END COMPONENT;


COMPONENT ADC_INTERFACE IS
	PORT 	(
			RESET             : IN STD_LOGIC;                       -- System reset
			CLK_260KHZ		  : IN STD_LOGIC;                       -- External clock for ADC
			MOD_ENABLE		  : IN STD_LOGIC;	                    -- Module enable
			ADC_CSN           : OUT STD_LOGIC;                      -- Not Chip Select (tied to '0')
			ADC_CNTRL_DATA    : OUT STD_LOGIC;                      -- DIN signal to ADC
			ADC_DATA          : IN STD_LOGIC;                       -- DOUT signal from ADC
			ADC_SSTRB         : IN STD_LOGIC;                       -- Strobe output from ADC
			ADC_SHDN          : OUT STD_LOGIC;                      -- Three level Shutdown for ADC
			DATA              : OUT STD_LOGIC_VECTOR(7 DOWNTO 0)    --Address for UFM
			);
END COMPONENT;


COMPONENT DIVISOR_DE_FREQUENCIA IS
	GENERIC(cont:INTEGER:=10);
	PORT(clk66:IN STD_LOGIC;
		 clk_dividido:BUFFER STD_LOGIC);
END COMPONENT;

END PACKAGE;