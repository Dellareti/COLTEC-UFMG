LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.STD_LOGIC_UNSIGNED.ALL;
USE IEEE.NUMERIC_STD.ALL;
USE IEEE.STD_LOGIC_ARITH.ALL;
USE WORK.COMPONENTES.ALL;

ENTITY TOP IS
	PORT(botao0,botao1,botao2,botao3,botao4,botao5:IN STD_LOGIC;
		 clk66:IN STD_LOGIC;
		 led_verde,T1,T2,T3,T4,T5,T6: OUT STD_LOGIC;
		 led_requerimento_de_senha:OUT STD_LOGIC;
		 a1,b1,c1,d1,e1,f1,g1:buffer STD_LOGIC;
		 a2,b2,c2,d2,e2,f2,g2:OUT STD_LOGIC;
		 a3,b3,c3,d3,e3,f3,g3:OUT STD_LOGIC;
		 a4,b4,c4,d4,e4,f4,g4:OUT STD_LOGIC;
		 led_distancia_1,led_distancia_2,led_distancia_3:OUT STD_LOGIC;
		 sensor:IN STD_LOGIC_VECTOR(7 DOWNTO 0);
		 SENHA:OUT STD_LOGIC_VECTOR(7 DOWNTO 0);
		 buzzer,led_alarme:OUT STD_LOGIC;
		 b0:buffer std_logic;
		 DISTANCIA:out std_logic_vector(7 downto 0));
END ENTITY;

ARCHITECTURE CIRCUITO_COMPLETO OF TOP IS
	SIGNAL botao0_filtrado,botao1_filtrado,botao2_filtrado,botao3_filtrado,botao4_filtrado,botao5_filtrado:STD_LOGIC;
	SIGNAL ativador_cont30seg,ativar_alarme,buzzer_botao,alarme_buzzer:STD_LOGIC;
	SIGNAL verif_ativo,saida_verificador_senha,saida_verificador_monitorador,estado_do_circuito,pulsos_registrador: STD_LOGIC ;
	SIGNAL troca_senha_ativa:STD_LOGIC ;
	SIGNAL bit1_distancia,bit2_distancia,bit3_distancia,monitorador_verif_ativo,led_monitorador_senha:STD_LOGIC;
	SIGNAL distancia_set:STD_LOGIC_VECTOR(2 DOWNTO 0);

	SIGNAL display_verif_d1,display_verif_d2,display_troca_d1,display_troca_d2,display_monit_d1,display_monit_d2,display_senha1,display_senha2,digito_tempo_1,digito_tempo_2:STD_LOGIC_VECTOR(3 DOWNTO 0);
	SIGNAL nova_senha_registrador_8bits,senha_registrador_8bits,sensor_data:STD_LOGIC_VECTOR(7 DOWNTO 0);
BEGIN
				sensor_data<=sensor;
				T1<=verif_ativo;
				T2<=troca_senha_ativa;
				T3<=led_monitorador_senha;
				T4<=ativador_cont30seg;
				T5<=estado_do_circuito;
				T6<=pulsos_registrador;
				DISTANCIA<=sensor_data;

-------------------------------------------------------------------------- BOTOES
										--333333 = 5ms
	FILTRO_DIG0: FILTRO_BOTAO GENERIC MAP(10) PORT MAP(botao0,clk66,botao0_filtrado);
	FILTRO_DIG1: FILTRO_BOTAO GENERIC MAP(10) PORT MAP(botao1,clk66,botao1_filtrado);
	FILTRO_DIG2: FILTRO_BOTAO GENERIC MAP(10) PORT MAP(botao2,clk66,botao2_filtrado);
	FILTRO_DIG3: FILTRO_BOTAO GENERIC MAP(10) PORT MAP(botao3,clk66,botao3_filtrado);
	FILTRO_DIG4: FILTRO_BOTAO GENERIC MAP(10) PORT MAP(botao4,clk66,botao4_filtrado);
	FILTRO_DIG5: FILTRO_BOTAO GENERIC MAP(10) PORT MAP(botao5,clk66,botao5_filtrado);

							--13333333
	BEEP_BTN: BEEP GENERIC MAP(10) PORT MAP(botao0_filtrado OR botao1_filtrado OR botao2_filtrado OR botao3_filtrado OR botao4_filtrado OR botao5_filtrado,clk66,buzzer_botao);
 
 buzzer<= (alarme_buzzer OR buzzer_botao);

---------------------------------------------------------------------------------------

	REGISTRADOR_8BITS_SENHA: REGISTRADOR_8BITS_ARMAZENAMENTO PORT MAP(nova_senha_registrador_8bits,pulsos_registrador,'1','0',senha_registrador_8bits);
	SENHA<=senha_registrador_8bits;

	CHANGE_PASSWD: TROCA_SENHA PORT MAP(botao4_filtrado,(NOT estado_do_circuito)AND clk66,
										botao1_filtrado,botao2_filtrado,botao3_filtrado,troca_senha_ativa,
										display_troca_d1,display_troca_d2,nova_senha_registrador_8bits,pulsos_registrador);


	ATIVA_DESATIVA: VERIFICADOR_SENHA PORT MAP((NOT estado_do_circuito) AND botao0_filtrado,botao1_filtrado,botao2_filtrado,botao3_filtrado,
											   clk66,senha_registrador_8bits,display_verif_d1,display_verif_d2,
											   verif_ativo,saida_verificador_senha);

	ESTADO_CIRCUITO: TROCA_ESTADO PORT MAP(saida_verificador_senha,saida_verificador_monitorador,clk66,estado_do_circuito);
	
	led_verde<= NOT estado_do_circuito;
--------------------------------------------------------------------------------------------- TROCA DISTANCIA
	TROCA_DISTANCIA: CONTADOR_ANEL_3BITS PORT MAP(botao5_filtrado,NOT estado_do_circuito,
												  bit1_distancia,bit2_distancia,bit3_distancia);
	
	led_distancia_1<=bit1_distancia;
	led_distancia_2<=bit2_distancia;
	led_distancia_3<=bit3_distancia;
--------------------------------------------------------------------------------------------- DISPLAYS 7-SEG
	
	SELECIONAR_DISPLAY: SELETOR PORT MAP(clk66,verif_ativo,troca_senha_ativa,monitorador_verif_ativo,
										 display_verif_d1,display_verif_d2,display_troca_d1,display_troca_d2,
										 display_monit_d1,display_monit_d2,
										 display_senha1,display_senha2);


	DISPLAY1: DECODIFICADOR_BCD_7SEG PORT MAP(display_senha1,a1,b1,c1,d1,e1,f1,g1);
	DISPLAY2: DECODIFICADOR_BCD_7SEG PORT MAP(display_senha2,a2,b2,c2,d2,e2,f2,g2);
	DISPLAY3: DECODIFICADOR_BCD_7SEG PORT MAP(digito_tempo_1,a3,b3,c3,d3,e3,f3,g3);
	DISPLAY4: DECODIFICADOR_BCD_7SEG PORT MAP(digito_tempo_2,a4,b4,c4,d4,e4,f4,g4);

--------------------------------------------------------------------------------------------------
	distancia_set(2)<=bit1_distancia;
	distancia_set(1)<=bit2_distancia;
	distancia_set(0)<=bit3_distancia;
	
	led_requerimento_de_senha <= verif_ativo OR led_monitorador_senha;											 
												 
    MONITORADOR_DE_PRESENCA: MONITORADOR PORT MAP(distancia_set,sensor_data,senha_registrador_8bits,
												 botao1_filtrado,botao2_filtrado,botao3_filtrado,estado_do_circuito,clk66,
												 monitorador_verif_ativo,display_monit_d1,display_monit_d2,ativador_cont30seg,
												 saida_verificador_monitorador,b0);

	




--
--ENTITY MONITORADOR IS
--	PORT(distancia:IN STD_LOGIC_VECTOR(2 DOWNTO 0);
--		 sensor,senha_reg: IN  STD_LOGIC_VECTOR(7 DOWNTO 0);
--		 b1,b2,b3,enable,clk:IN STD_LOGIC;
--		 led_requer_senha:OUT STD_LOGIC;
--		 dig1,dig2:OUT STD_LOGIC_VECTOR(3 DOWNTO 0);
--		 cont30seg:BUFFER STD_LOGIC;
--		 confirm:OUT STD_LOGIC;
--		 b0:BUFFER STD_LOGIC);
--END ENTITY;




	led_monitorador_senha<=monitorador_verif_ativo;
	
	TIMER: CONTADOR_30SEG PORT MAP(clk66,ativador_cont30seg,digito_tempo_1,digito_tempo_2,ativar_alarme);
							--33333333
	ALARME:FREQ_ALARME GENERIC MAP(10) PORT MAP(clk66,ativar_alarme,alarme_buzzer);
	led_alarme<=alarme_buzzer;

END ARCHITECTURE;