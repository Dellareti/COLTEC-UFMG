LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.STD_LOGIC_UNSIGNED.ALL;
USE IEEE.STD_LOGIC_ARITH.ALL;

ENTITY ADC_INTERFACE IS
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
END ADC_INTERFACE;

ARCHITECTURE ADC_CONT OF ADC_INTERFACE IS

	SIGNAL ADC_RESET : STD_LOGIC;							--Reset ADC state after each conversion
	SIGNAL START, SEL2, SEL1, SEL0, UNI_BIP, SGL_DIF, PD1, PD0 : STD_LOGIC;	--ADC Control characters
	SIGNAL CLKGEN_COUNT : STD_LOGIC_VECTOR(7 DOWNTO 0);		--Count used to generate CLK_260KHZ
	SIGNAL ADC_STATE	: STD_LOGIC_VECTOR(4 DOWNTO 0);		--State signal used in statemachine to create ADC control writes
	SIGNAL DIG_RESULT	: STD_LOGIC_VECTOR(7 DOWNTO 0);		--shift register to catch input data from ADC
	SIGNAL SR_CAPTURE	: STD_LOGIC_VECTOR(9 DOWNTO 0);	--Used to locate the first 8 bits after the falling edge of ADC_SSTRB

BEGIN

	ADC_CSN		<= '0';					-- CHIP SELECT' = Sempre selecionado
	ADC_SHDN  <= '1';         -- SHUTDOWN' = Nunca desliga o chip

	--Control signals:
	START	<= '1';		--start conversion
	SEL2	<= '1';		--
	SEL1	<= '0';		--Sel2 and not sel1 selects channel 1
	SEL0	<= '0';		--Dont care
	UNI_BIP	<= '1';		--select unipolar conversion
	SGL_DIF	<= '1';		--select single ended signal
	PD1		<= '1';		--Fully operational
	PD0		<= '1';		--External clock mode


	ADC_RESET <= RESET AND MOD_ENABLE;							--Either reset is active or Single LCD write has completed

	--Increment states to generate ADC control characters
	PROCESS(CLK_260KHZ, ADC_RESET)
	BEGIN
		IF ADC_RESET = '0' THEN									--Reset counter to begin write sequesnce
			ADC_STATE <= (OTHERS=>'0');
		ELSE
			IF CLK_260KHZ'EVENT AND CLK_260KHZ = '1' THEN
				IF ADC_STATE <= "01000" THEN					--Count up to 8 then stop
					ADC_STATE <= ADC_STATE + 1;
				ELSE
					NULL;
				END IF;
			ELSE
				NULL;
			END IF;
		END IF;
	END PROCESS;


	--ADC controller statemachine
	PROCESS(CLK_260KHZ, RESET)
	BEGIN
		IF RESET = '0' THEN
			DIG_RESULT <= (OTHERS=>'0');
			SR_CAPTURE <= (OTHERS=>'0');
			ADC_CNTRL_DATA <= '0';
		ELSE
			IF CLK_260KHZ'EVENT AND CLK_260KHZ = '1' THEN

		  -- Registrador de deslocamento que recebe os dados do ADC
				DIG_RESULT(0) <= ADC_DATA;
				FOR I IN 1 TO 7 LOOP
					DIG_RESULT(I) <= DIG_RESULT(I-1);
				END LOOP;
		
				CASE ADC_STATE IS						--Create ADC control signals
					WHEN "00000" =>
						NULL;
					WHEN "00001" =>
						ADC_CNTRL_DATA <= START;		--'1' start conversion
					WHEN "00010" =>
						ADC_CNTRL_DATA <= SEL2;			--Sel2 and not sel1 selects channel 1
					WHEN "00011" =>
						ADC_CNTRL_DATA <= SEL1;			--Sel2 and not sel1 selects channel 1
					WHEN "00100" =>
						ADC_CNTRL_DATA <= SEL0;			--Dont care
					WHEN "00101" =>
						ADC_CNTRL_DATA <= UNI_BIP;		--select unipolar conversion
					WHEN "00110" =>
						ADC_CNTRL_DATA <= SGL_DIF;		--select single ended signal
					WHEN "00111" =>
						ADC_CNTRL_DATA <= PD1;			--Fully operational
					WHEN "01000" =>
						ADC_CNTRL_DATA <= PD0;			--External clock mode
					WHEN "01001" =>
						ADC_CNTRL_DATA <= '0';			--Reset to Zero
					WHEN OTHERS =>
						NULL;
				END CASE;
			
		  -- Borda de descida do SSTRB indica que o cado come�ou a sair do ADC
				SR_CAPTURE(0) <= ADC_SSTRB;
				SR_CAPTURE(1) <= SR_CAPTURE(0) AND ADC_SSTRB;


		  -- Registrador de deslocamento
		  -- Quando o bit 9 foi 1, ent�o o dado est� no DIG_RESULT
				FOR J IN 2 TO 9 LOOP
					SR_CAPTURE(J) <= SR_CAPTURE(J-1);
				END LOOP;      
				
				--Carrega o dado na sa�da depois que tiver lido os 8 bits
				IF SR_CAPTURE(9) = '1' THEN				
					DATA <= DIG_RESULT;
				ELSE
					NULL;
				END IF;
			ELSE
				NULL;
			END IF;
		END IF;
	END PROCESS;

END ADC_CONT;