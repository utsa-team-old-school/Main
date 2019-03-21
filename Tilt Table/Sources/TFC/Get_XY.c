/*
 * Get_XY.c
 * 
 *
 *  Created on: Mar 29, 2017
 *      Author: Paul
 *  This contains functions for reading the position on the tilt table
 *  it calls the Pot function to get the analog value and it 
 *  switches the GPIO pins from 3.3 & Gnd to Tristate so each X and Y can be read
 *  GPIO uses LEDs  PTB 8.9.10.11  and Pots use  PTB3,2 which are ADC0_SE13 and 12 for X and Y
 *  The touch panel has electrodes on one surface  L & R  and on other surface F  &  B
 *  The connector for the 5x7 pads is set up 8=B   9=F   10=L   11=R
 *  We multiplex between 3.3/GND and Tri/Tri  to Tri/Tri and 3.3/Gnd to ge Y and X readings
 *  We will let the TFC_InitGPIO() do the initial set up of GPIO
 */
#include "TFC\TFC.h"

float Get_X(){
	//Get X   Make the 0-3.3 V gradient across X and read pot 0  with Y tristated

return TFC_ReadPot(0);
}

float Get_Y(){
	//Get Y   Make the 0-3.3 V gradient across Y and read pot 1  with X tristated

return TFC_ReadPot(1);
}
