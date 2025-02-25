LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.STD_LOGIC_UNSIGNED.ALL;
USE IEEE.NUMERIC_STD.ALL;
USE WORK.pacotin.ALL;


ENTITY TOP IS
	PORT(clk66:IN STD_LOGIC;
		 botao             : IN STD_LOGIC;                      
		 ADC_CSN,clk260khz : OUT STD_LOGIC;                      -- Not Chip Select (tied to '0')
		 ADC_CNTRL_DATA    : OUT STD_LOGIC;                      -- DIN signal to ADC
		 ADC_DATA          : IN STD_LOGIC;                       -- DOUT signal from ADC
		 ADC_SSTRB         : IN STD_LOGIC;                       -- Strobe output from ADC
	 	 ADC_SHDN          : OUT STD_LOGIC;                      -- Three level Shutdown for ADC
		 L1,L2,L3,L4:OUT STD_LOGIC);
END ENTITY;
    
ARCHITECTURE arc OF TOP IS
	SIGNAL clk260,btne,enable :STD_LOGIC;
	SIGNAL DATA:STD_LOGIC_VECTOR(7 DOWNTO 0);
BEGIN

--	FILTRO: MAQUINA_DE_ESTADOS PORT MAP(botao,clk66,btn);
	
	DIV_FREQ: PULSOS PORT MAP(clk66,clk260);

	ADC: ADC_INTERFACE PORT MAP(botao,clk260,'1',ADC_CSN,ADC_CNTRL_DATA,ADC_DATA,ADC_SSTRB,ADC_SHDN,DATA);


	clk260khz<=clk260;
	
	PROCESS(botao)IS
		VARIABLE c : INTEGER := 0;
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
	END PROCESS;

END ARCHITECTURE;