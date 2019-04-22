/** ###################################################################
**     Filename    : ProcessorExpert.c
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2013-01-03, 14:56, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :	in:		B0 = Seat Sensor, B1 = Belt Sensor, B2 = Thermometer, C17 = Thermal Camera, C16 = Comm status
**     							E2 = PIR (Right), D2 = PIR (Left)
**     					out:	A12 = Status of child to Sender, A13 = Relay 1-1 (thermal), E5 = Relay 1-2 (everything), B9 = Relay 2-1 (Lights)
**     							C2 = buzzer
**     Contents    :
**         No public methods
**
** ###################################################################*/
/* MODULE ProcessorExpert */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "CsIO1.h"
#include "IO1.h"
#include "ADC1.h"
#include "DMA1.h"
#include "TU1.h"
#include "A12.h"
#include "BitIoLdd1.h"
#include "A13.h"
#include "BitIoLdd2.h"
#include "E5.h"
#include "BitIoLdd3.h"
#include "B9.h"
#include "BitIoLdd4.h"
#include "C17.h"
#include "BitIoLdd6.h"
#include "C16.h"
#include "BitIoLdd5.h"
#include "C2.h"
#include "BitIoLdd7.h"
#include "E2.h"
#include "BitIoLdd8.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */
#include "my.h"

// size of the channel configuration array
#define ADC_CHANNELS_COUNT 3
#define True 1
#define False 0

// value for CFG2 array selecting MUX A pins or default
#define PIN_A (0) 
// value for CFG2 array selecting MUX B pins
#define PIN_B (ADC_CFG2_MUXSEL_MASK)

// configuration array for channels - channel numbers. Should ends with 0x1F which stops conversion
// second configuration array corresponding to channels selecting A/B pins
// For example: 0 + PIN_A corresponds to the pin ADC0_SE0,   5 + PIN_5 selects the pin ADC0_SE5b
// You can use these arrays to reorder the measurement as you need
const uint8_t ChannelsCfg [ADC_CHANNELS_COUNT + 1] =  { 8,       9,     12,   0x1F };
const uint8_t ChannelsCfg2[ADC_CHANNELS_COUNT + 1] =  {PIN_A, PIN_A, PIN_A,    0 };

// buffer for resulting measured values
uint16_t MeasuredValues[ADC_CHANNELS_COUNT];

// flag for end of measurement
bool Measured;
bool childInSeat;
bool childInCar, motion1;
bool tooHotTeensy, tooHotTherm;
bool comm;
float temp;


/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/
  /* Write your local variable definition here */
  byte i;
  /*** Processor Expert internal initialisation. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialisation.                    ***/

  printf ("Hello!\r\n");

  // reset flag 
  Measured = FALSE;
  C17_SetDir(False);
  C16_SetDir(False);
  // Initialise ADC now
  ADC1_Init();
  // Initialise DMA now  
  DMA1_Init();
  // loop forever  
  while (TRUE) {
    tooHotTeensy = C17_GetVal();
    comm = C16_GetVal();
    motion1 = E2_GetVal();			// PIR Motion Detector
    if(comm)
    {
    	printf("communicating\n");
    } else
    {
    	printf("not communicating\n");
    }
	// clear flag  
	Measured = FALSE;	
	// reset DMA0 destination pointer to beginning of the buffer 
	DMA_DAR0 = (uint32_t) &MeasuredValues;
	// reset DMA1 source pointer (MUX switching writes)
	DMA_SAR1 = (uint32_t) &ChannelsCfg2;
	// reset DMA2 source pointer (channel switching and conversion start writes)
	DMA_SAR2 = (uint32_t) &ChannelsCfg;
	// number of total bytes to be transfered from the ADC result register A 
	DMA_DSR_BCR0 = ADC_CHANNELS_COUNT * 2;
	// set number of total bytes to be transfered to the ADC0_CFG2 
	DMA_DSR_BCR1 = ADC_CHANNELS_COUNT + 1;
	// set number of total bytes to be transfered to the ADC0_SC1A.  
	DMA_DSR_BCR2 = ADC_CHANNELS_COUNT + 1;
    // start first DMA1 transfer (selects mux, then fires channel 2 to select channel which starts the conversion)
    DMA_DCR1 |= DMA_DCR_START_MASK;
    // wait till it's all measured
	while (!Measured) {}	  
	// print all measured values to console
	
	/*
	 * The following takes temp
	 */
	temp = MeasuredValues[2]/64.06926407;
	if (temp >= 86) tooHotTherm = TRUE;
	else tooHotTherm = FALSE;
	printf ("%f",temp);
	
	/*
	 * The following senses motion in car
	 */
	if (motion1) childInCar = True;
	else childInCar = False;
	
	/*
	 * This senses if the child is in the seat
	 */
	if (MeasuredValues[0]>30000 && MeasuredValues[1]<30000)childInSeat = True;
	else childInSeat = False;
	
	/*
	 * if child is in seat tell transmitter
	 */
	if (childInSeat || childInCar) A12_SetVal();	// A12 is to arduino sender HIGH
	else A12_ClrVal();						// A12 is to arduino sender LOW
	
	/*
	 * if the kid is in the seat and not buckeled up
	 * set off buzzer
	 */
	if (MeasuredValues[0]>30000 && MeasuredValues[1]>30000)
	{
		C2_SetVal();
	} else
	{
		C2_ClrVal();
	}
	
	/*
	 * if the radio's can't communicate and the child is in the seat then
	 * turn on the lights
	 */
	if(!comm && (childInSeat || childInCar))
	{
		B9_SetVal(); // turn on lights
	} else
	{
		B9_ClrVal(); // turn off lights
	}
	
	/*
	 * if either of the temp sensors sense it's too hot
	 * and the child is in the seat then turn on the ac
	 * system
	 */
	if ((tooHotTeensy || tooHotTherm) && childInSeat)
	{
		A13_SetVal(); 	// turn on AC
		E5_SetVal();	// turn on Therm
	} else
	{
		A13_ClrVal();	// turn off AC
		E5_ClrVal();	// turn off Therm
	}
	
	/*
	 * print out values of analog signals
	 */
	for (i=0; i<ADC_CHANNELS_COUNT; i++) {
		printf ("%7u", (uint16_t) MeasuredValues[i]);
	}  	  
	printf ("\n");
	// wait for some time to slow down output
	TU1_ResetCounter(TU1_DeviceData);
	while (TU1_GetCounterValue(TU1_DeviceData) < 50000) {}
  } 
  
  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END ProcessorExpert */
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
