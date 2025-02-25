LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.STD_LOGIC_UNSIGNED.ALL;
USE IEEE.NUMERIC_STD.ALL;
USE IEEE.STD_LOGIC_ARITH.ALL;
USE WORK.COMPONENTES.ALL;


ENTITY CONVERSOR_COMPLETO IS
	PORT(clk66:IN STD_LOGIC;
		 ADC_CSN  		   :OUT STD_LOGIC;
		 clk260 		   :BUFFER STD_LOGIC;                  
		 ADC_CNTRL_DATA    :OUT STD_LOGIC;
		 ADC_DATA          :IN STD_LOGIC ;      
         ADC_SSTRB         :IN STD_LOGIC ;     
		 ADC_SHDN          :OUT STD_LOGIC;    
		 sc_ena  		   :OUT STD_LOGIC;
		 sensor_data:BUFFER STD_LOGIC_VECTOR(7 DOWNTO 0);
		 led1,led2,led3,led4: OUT STD_LOGIC
		);
END ENTITY;

ARCHITECTURE arc OF CONVERSOR_COMPLETO IS
	SIGNAL data : STD_LOGIC_VECTOR(7 DOWNTO 0) := "00000000";
	SIGNAL taxa_de_atualizacao : STD_LOGIC := '0';
BEGIN
	sc_ena<='1';
	
	ADC: ADC_INTERFACE PORT MAP('1',clk260,'1',ADC_CSN,ADC_CNTRL_DATA,ADC_DATA,ADC_SSTRB,ADC_SHDN,data);
	PUL_24: PULSO_24 PORT MAP(clk260,'1',data,sensor_data);

	CONV_P_SEG: DIVISOR_DE_FREQUENCIA   	GENERIC MAP(666600) PORT MAP(clk66,taxa_de_atualizacao);
	GERADOR_260KHz: DIVISOR_DE_FREQUENCIA   GENERIC MAP(128) PORT MAP(clk66,clk260);

	led1<=sensor_data(7);
	led2<=sensor_data(6);
	led3<=sensor_data(5);
	led4<=sensor_data(4);


END ARCHITECTURE;