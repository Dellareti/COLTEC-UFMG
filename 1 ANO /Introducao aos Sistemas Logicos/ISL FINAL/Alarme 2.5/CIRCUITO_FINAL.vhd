LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.STD_LOGIC_UNSIGNED.ALL;
USE IEEE.NUMERIC_STD.ALL;
USE IEEE.STD_LOGIC_ARITH.ALL;
USE WORK.COMPONENTES.ALL;


ENTITY TOP_ENTITY IS
	PORT(botao0,botao1,botao2,botao3,botao4,botao5:IN STD_LOGIC;
		 clk66:IN STD_LOGIC;
		 buzzer:BUFFER STD_LOGIC;
		 led_requerimento_senha,led_verde,led_vermelho,led_alarme:OUT STD_LOGIC;
		 leds_distancia:OUT STD_LOGIC_VECTOR(2 DOWNTO 0);
		 A,B,C,D,E,F,G:OUT STD_LOGIC;
		 controle1,controle2,controle3,controle4:OUT STD_LOGIC;
		--PINOS DO CONVERSOR A/D
		 ADC_CSN  		   :OUT STD_LOGIC;
		 clk260khz		   :OUT STD_LOGIC;                  
		 ADC_CNTRL_DATA    :OUT STD_LOGIC;
		 ADC_DATA          :IN STD_LOGIC ;      
         ADC_SSTRB         :IN STD_LOGIC ;     
		 ADC_SHDN          :OUT STD_LOGIC;    
		 sc_ena			   :OUT STD_LOGIC
		);
END ENTITY;

ARCHITECTURE arc OF TOP_ENTITY IS
	SIGNAL b0_filtrado,b1_filtrado,b2_filtrado,b3_filtrado,b4_filtrado,b5_filtrado:STD_LOGIC := '1';

	SIGNAL buzzer_botao,clk260,taxa_de_atualizacao: STD_LOGIC := '0';
	
	SIGNAL distancia : STD_LOGIC_VECTOR(2 DOWNTO 0) := "100";
	
	SIGNAL verificador_geral_ativo,saida_verificador,saida_monitorador,troca_senha_ativa,pulso_nova_senha,enable_contador30seg,estado_do_circuito: STD_LOGIC := '0';
	
	SIGNAL senha_registrador,nova_senha,sensor_data:STD_LOGIC_VECTOR(7 DOWNTO 0) := "00000000";

	SIGNAL display_verif_d1,display_verif_d2,display_troca_d1,display_troca_d2,display_monit_d1,display_monit_d2,dig1_contador,dig2_contador,saida_display1,saida_display2: STD_LOGIC_VECTOR(3 DOWNTO 0):="0000";

	SIGNAL led_verificador_monitorador,led_verificador_geral,ativar_buzzer,buzzer_alarme:STD_LOGIC := '0';
	
	SIGNAL a1,b1,c1,d1,e1,f1,g1: STD_LOGIC := '1';
	SIGNAL a2,b2,c2,d2,e2,f2,g2: STD_LOGIC := '1';
	SIGNAL a3,b3,c3,d3,e3,f3,g3: STD_LOGIC := '1';
	SIGNAL a4,b4,c4,d4,e4,f4,g4: STD_LOGIC := '1';

BEGIN
------------------------------------------------------------------------------
	ADC: ADC_INTERFACE PORT MAP(taxa_de_atualizacao,clk260,'1',ADC_CSN,ADC_CNTRL_DATA,ADC_DATA,ADC_SSTRB,ADC_SHDN,sensor_data);
	GERADOR_260KHz: DIVISOR_DE_FREQUENCIA   GENERIC MAP(128) PORT MAP(clk66,clk260);
	CONVERSOES_P_SEG: DIVISOR_DE_FREQUENCIA GENERIC MAP(666666) PORT MAP(clk66,taxa_de_atualizacao);
														--100 conversoes p/seg
	clk260khz<=clk260;
	sc_ena<='1';

------------------------------------------------------------------------------
--BOTOES
	FILTRO_B0: FILTRO_BOTAO GENERIC MAP(333333) PORT MAP(botao0,clk66,b0_filtrado);
	FILTRO_B1: FILTRO_BOTAO GENERIC MAP(333333) PORT MAP(botao1,clk66,b1_filtrado);
	FILTRO_B2: FILTRO_BOTAO GENERIC MAP(333333) PORT MAP(botao2,clk66,b2_filtrado);
	FILTRO_B3: FILTRO_BOTAO GENERIC MAP(333333) PORT MAP(botao3,clk66,b3_filtrado);
	FILTRO_B4: FILTRO_BOTAO GENERIC MAP(333333) PORT MAP(botao4,clk66,b4_filtrado);
	FILTRO_B5: FILTRO_BOTAO GENERIC MAP(333333) PORT MAP(botao5,clk66,b5_filtrado);

	BEEP_BOTAO: BEEP GENERIC MAP(13333333) PORT MAP(b0_filtrado,b1_filtrado,b2_filtrado,b3_filtrado,b4_filtrado,b5_filtrado,
													clk66,buzzer_botao);

-------------------------------------------------------------------------------
--BUZZER
	buzzer<= buzzer_botao OR buzzer_alarme;

--LEDS
	led_requerimento_senha<=verificador_geral_ativo OR led_verificador_monitorador;
	led_verde<=(NOT estado_do_circuito);
	led_vermelho<=estado_do_circuito;
	leds_distancia<=distancia;
	led_alarme<=buzzer;
-------------------------------------------------------------------------------
--DISPLAYS
	DISPLAY_SELECT: SELETOR PORT MAP(clk66,verificador_geral_ativo,troca_senha_ativa,led_verificador_monitorador,
									 display_verif_d1,display_verif_d2,display_troca_d1,display_troca_d2,
									 display_monit_d1,display_monit_d2,
									 saida_display1,saida_display2);
									 
	DECODER0: DECODIFICADOR_BCD_7SEG PORT MAP(saida_display1,a1,b1,c1,d1,e1,f1,g1);
	DECODER1: DECODIFICADOR_BCD_7SEG PORT MAP(saida_display2,a2,b2,c2,d2,e2,f2,g2);
	DECODER2: DECODIFICADOR_BCD_7SEG PORT MAP(dig1_contador ,a3,b3,c3,d3,e3,f3,g3);
	DECODER3: DECODIFICADOR_BCD_7SEG PORT MAP(dig2_contador ,a4,b4,c4,d4,e4,f4,g4);
			
	DISPLAY_CONTROLLER: FOUR_DISPLAYS_TO_ONE PORT MAP(a1,b1,c1,d1,e1,f1,g1,
													  a2,b2,c2,d2,e2,f2,g2,
													  a3,b3,c3,d3,e3,f3,g3,
													  a4,b4,c4,d4,e4,f4,g4,   clk66,
													  A,B,C,D,E,F,G,
													  controle1,controle2,controle3,controle4);		
														
																					 
-------------------------------------------------------------------------------
	
	VERIFICADOR_GERAL: VERIFICADOR_SENHA PORT MAP(b0_filtrado,b1_filtrado,b2_filtrado,b3_filtrado,
												  clk66,NOT estado_do_circuito,senha_registrador,display_verif_d1,display_verif_d2,verificador_geral_ativo,saida_verificador);
	
	ESTADO: TROCA_ESTADO PORT MAP(saida_verificador,saida_monitorador,clk66,estado_do_circuito);

--	PORT(v_ativo,m_ativo,verificador,monitorador,clk:IN STD_LOGIC;
--		 estado:BUFFER STD_LOGIC);

-------------------------------------------------------------------------------
															  --O circuito deve estar em 0(inativo)
	TROCA_DISTANCIA: CONTADOR_ANEL_3BITS PORT MAP(b5_filtrado,clk66,NOT estado_do_circuito,distancia(0),distancia(1),distancia(2));
-------------------------------------------------------------------------------
	TROCA_A_SENHA: TROCA_SENHA PORT MAP(estado_do_circuito AND (NOT verificador_geral_ativo),clk66,b1_filtrado,b2_filtrado,b3_filtrado,b4_filtrado,
									   troca_senha_ativa,display_troca_d1,display_troca_d2,nova_senha,pulso_nova_senha);
	

	REG_SENHA: REGISTRADOR_8BITS_SENHA PORT MAP(nova_senha,clk66,pulso_nova_senha,senha_registrador);
-------------------------------------------------------------------------------
	MONITORADOR_DISTANCIA: MONITORADOR PORT MAP(distancia,sensor_data,senha_registrador,b1_filtrado,b2_filtrado,b3_filtrado,
												estado_do_circuito,clk66,led_verificador_monitorador,
												display_monit_d1,display_monit_d2,enable_contador30seg,
												saida_monitorador);
												
	TIMER: CONTADOR_30SEG  PORT MAP(clk66,enable_contador30seg,dig1_contador,dig2_contador,ativar_buzzer);

	ALARME: FREQ_ALARME GENERIC MAP(10) PORT MAP(clk66,ativar_buzzer,buzzer_alarme);


END ARCHITECTURE;