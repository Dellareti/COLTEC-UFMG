LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
--USE IEEE.STD_LOGIC_UNSIGNED.ALL;
USE IEEE.NUMERIC_STD.ALL;
USE IEEE.STD_LOGIC_ARITH.ALL;
USE WORK.pacotin.ALL;


ENTITY TOP IS
	PORT(clk66:IN STD_LOGIC;
		 botao             : IN STD_LOGIC;                      
		 ADC_CSN,clk260khz : OUT STD_LOGIC;                      -- Not Chip Select (tied to '0')
		 ADC_CNTRL_DATA    : OUT STD_LOGIC;                      -- DIN signal to ADC
		 ADC_DATA          : IN STD_LOGIC;                       -- DOUT signal from ADC
		 ADC_SSTRB         : IN STD_LOGIC;                       -- Strobe output from ADC
	 	 ADC_SHDN          : OUT STD_LOGIC;                      -- Three level Shutdown for ADC
		 L1,L2,L3,L4:OUT STD_LOGIC;
		sc_ena,cooler:OUT STD_LOGIC);
END ENTITY;
    
ARCHITECTURE arc OF TOP IS
	SIGNAL clk260,btn,enable,converte:STD_LOGIC;
	SIGNAL DATA:STD_LOGIC_VECTOR(7 DOWNTO 0);
	SIGNAL aux: INTEGER;
	SIGNAL duty_l:INTEGER:=0;	
	
	function bv2I (bv: STD_LOGIC_VECTOR) return integer is

	variable result, onebit: integer := 0;

	begin

	myloop: for i in bv'low to bv'high loop onebit := 0; if bv(i) = '1' then onebit := 2**(i-bv'low); end if;

	result := result + onebit; end loop myloop;

	return (result); end bv2I;
	
BEGIN
	sc_ena<='1';
	FILTRO: MAQUINA_DE_ESTADOS PORT MAP(botao,clk66,btn);
	
	DIV_FREQ: PULSOS GENERIC MAP(128) PORT MAP(clk66,clk260);
	

	ADC: ADC_INTERFACE PORT MAP(converte,clk260,'1',ADC_CSN,ADC_CNTRL_DATA,ADC_DATA,ADC_SSTRB,ADC_SHDN,DATA);
	
	CONVERSOES:PULSOS GENERIC MAP(1333333) PORT MAP(clk66,converte);
	
	clk260khz<=clk260;
	
	PROCESS(botao,enable,clk260)IS
		VARIABLE c,cont : INTEGER := 0;
	BEGIN
		IF botao = '1' AND  botao'LAST_VALUE = '0' THEN
			enable <= '1';
		END IF;
		IF enable = '1' THEN
			IF RISING_EDGE(clk260) THEN
				c:=c +1;
					IF c = 24 THEN 
						c:=0;
						L1<=DATA(7);
						L2<=DATA(6);
						L3<=DATA(5);
						L4<=DATA(4);
					END IF;		
			END IF;
		END IF;
		
		IF (RISING_EDGE(CLK66)) THEN
		
		 aux <= bv2I(DATA);
		 duty_l <= 26039 * aux;
		 
		END IF;
		
		
		IF RISING_EDGE(clk66) THEN
			cont := cont + 1;
			
			IF (cont < duty_l) THEN
				cooler <= '1';
			ELSE
				cooler <= '0';
			END IF;
			
			IF (cont >= 6666000) THEN
				cont := 0;
			END IF;	
		END IF;
		
	END PROCESS;

END ARCHITECTURE;