#include "derivative.h" /* include peripheral declarations */
#include "TFC\TFC.h"

void Compute();

int main(void) {
	TFC_Init();
	float X_pos, Y_pos, X_servo, Y_servo;
	float temp;
	/*
	 * for servo 1(short side by #18 = X ): -1.0 is up and 1.0 is down
	 * for servo 0(long side = Y): -1.0 is down and 1.0 is up
	 */
	for (;;) {
		//TFC_Task must be called in your main loop.  This keeps certain processing happy (I.E. Serial port queue check)
		TFC_Task();
		if (TFC_Ticker[0] == 20) {
			TFC_Ticker[0] = 0; //reset the Ticker			
			//Every 20 mSeconds, update the Servos
			X_pos = Get_X();
			Y_pos = -1*Get_Y();
			TERMINAL_PRINTF("X= %.2f      Y= %.2f  \r\n", X_pos, Y_pos);
			//Example, just out put the position X and Y
			Y_servo = Y_pos;
			X_servo = X_pos;
//********************************* put your PID controller code here ***************				    
			//Set the servo positions
			TFC_SetServo(1, X_servo);
			TFC_SetServo(0, Y_servo);
		}
	}
	return 0;
}

void Compute()
{
	float CdInput;
   
      /*Compute all the working error variables*/
      Cerror = CSetpoint - CInput;
      CITerm += (Cki * Cerror);
      if(CITerm > CoutMax) CITerm = CoutMax;
      else if(CITerm < CoutMin) CITerm = CoutMin;
      CdInput = (CInput - ClastInput);
 
      /*Compute PID Output*/
      COutput = Ckp * Cerror + CITerm- Ckd * CdInput;
      if(COutput > CoutMax) COutput = CoutMax;
      else if(COutput < CoutMin) COutput = CoutMin;
 
      /*Remember some variables for next time*/
      ClastInput = CInput;
   
}
