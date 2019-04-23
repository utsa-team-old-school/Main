#include "derivative.h" /* include peripheral declarations */
#include "TFC\TFC.h"
#include <math.h>
float computeX(float, unsigned long);
float computeY(float, unsigned long);
//working variables for compute routine
unsigned long ClastTime, CSampleTime, CSampleTimeInSec;
float const xSetPoint = 0;
float xLastInput;
float const xKP = .88, xKI = 1, xKD = 8; //The values that worked: 0.88 8
float const xOutMin = -1, xOutMax = 1;
//end of working variables for compute routine
//working variables for compute routine
//unsigned long ClastTime1, CSampleTime1, CSampleTimeInSec1;
float const ySetPoint = 0;
float yLastInput;
float const yKP = .88, yKI = 1, yKD = 8; //.88 8
float const yOutMin = -1, yOutMax = 1;
//end of working variables for compute routine

int main(void)
{
	TFC_Init();
	float X_pos, Y_pos, X_servo, Y_servo;
	unsigned long CDiffTime;
	for (;;)
	{
		//TFC_Task must be called in your main loop.  This keeps certain processing happy (I.E. Serial port queue check)
		TFC_Task();
		if (TFC_Ticker[0] == 30)
		{
			TFC_Ticker[0] = 0; //reset the Ticker
			//Every 20 mSeconds, update the Servos
			CDiffTime = TFC_Ticker[1];
			TFC_Ticker[1] = 0;
			X_pos = Get_X()+0.09;
			Y_pos = -1 * (Get_Y()-0.15);
			//TERMINAL_PRINTF("X= %.2f      Y= %.2f  \r\n", X_pos, Y_pos);
			//Example, just out put the position X and Y
			Y_servo = computeY(Y_pos, CDiffTime);
			X_servo = computeX(X_pos, CDiffTime);
			//TERMINAL_PRINTF("Adjusted:    X= %.2f      Y= %.2f  \r\n", X_servo, Y_servo);
			//********************************* put your PID controller code here ***************
			//Set the servo positions
			//Cerror = Center;
			TFC_SetServo(1, X_servo + .31);
			//yError = Center;
			TFC_SetServo(0, Y_servo - .05);
		}
	}
	return 0;
}
float computeX(float x, unsigned long time)
{
	float xDInput;
	float xOutput;
	float xError;
	float PplusE, DplusI;
	float timeInSec =(float) time/1000000;
	// float xITerm;

	/*Compute all the working error variables*/
	if(x>0)
	{
		x = x * 1.408450704; //0.8014 - X
	} else 
	{
		x = x * 1.19047619;
	}
	xError = xSetPoint + x;
	if (xError>1)
	{
		xError = 1;
	}
	if (xError<-1)
	{
		xError = -1;
	}
		
	/*yITerm += (yKI * yError);
	if (yITerm > yOutMax)
		yITerm = yOutMax;
	else if (yITerm < yOutMin)
		yITerm = yOutMin;*/
	xDInput = (x - xLastInput);
	//TERMINAL_PRINTF("xDInput= %.10f  \r\n", xDInput);
	
	PplusE = xKP * xError;
	DplusI = xKD * xDInput;
	/*Compute PID Output*/
	xOutput = PplusE /*+ yITerm*/ + DplusI; //0.2205 * E * T - 0.8014 * I
	if (xOutput > xOutMax)
		xOutput = xOutMax;
	else if (xOutput < xOutMin)
		xOutput = xOutMin;

	/*Remember some variables for next time*/
	xLastInput = x;
	return xOutput;
}

float computeY(float y, unsigned long time)
{
	float yDInput;
	float yOutput;
	float yError;
	float timeInSec =(float) time/1000000;
	//float yITerm;

	/*Compute all the working error variables*/
	if(y>0)
	{
		y = y * 2.380952381; //0.932 * Y
	} else
	{
		y = y * 1.587301587;
	}
	yError = ySetPoint + y;
	if (yError>1)
	{
		yError = 1;
	}
	if (yError<-1)
	{
		yError = -1;
	}
	
	/*yITerm += (yKI * yError);
	if (yITerm > yOutMax)
		yITerm = yOutMax;
	else if (yITerm < yOutMin)
		yITerm = yOutMin;*/
	yDInput = (y - yLastInput);
	//TERMINAL_PRINTF("yDInput= %.10f  \r\n", yDInput);
		
	/*Compute PID Output*/
	yOutput = yKP * yError /*+ yITerm*/ + yKD * yDInput; //0.247 * E * T - -0.932 * I
	if (yOutput > yOutMax)
		yOutput = yOutMax;
	else if (yOutput < yOutMin)
		yOutput = yOutMin;

	/*Remember some variables for next time*/
	yLastInput = y;
	return yOutput;
}
