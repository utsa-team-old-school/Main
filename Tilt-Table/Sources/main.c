#include "derivative.h" /* include peripheral declarations */
#include "TFC\TFC.h"
int main(void) {
	TFC_Init();
	float X_pos, Y_pos, X_servo, Y_servo;
	for (;;) {
		//TFC_Task must be called in your main loop.  This keeps certain processing happy (I.E. Serial port queue check)
		TFC_Task();
		if (TFC_Ticker[0] == 20) {
			TFC_Ticker[0] = 0; //reset the Ticker			
			//Every 20 mSeconds, update the Servos
			X_pos = Get_X();
			Y_pos = Get_Y();
			TERMINAL_PRINTF("X= %.2f      Y= %.2f  \r\n", X_pos, Y_pos);
			//Example, just out put the position X and Y
			Y_servo = Y_pos;
			X_servo = X_pos;
//********************************* put your PID controller code here ***************				    
			//Set the servo positions
			TFC_SetServo(0, X_servo);
			TFC_SetServo(1, Y_servo);
		}
	}
	return 0;
}
