#include "derivative.h" /* include peripheral declarations */
#include "TFC\TFC.h"

int main(void)
{
	uint32_t t,i=0;
	
	TFC_Init();
	
	for(;;)
	{	   
		//TFC_Task must be called in your main loop.  This keeps certain processing happy (I.E. Serial port queue check)
			TFC_Task();

			while (!TFC_PUSH_BUTTON_0_PRESSED) continue;
					{

						TFC_Ticker[0] =0;
						while (TFC_Ticker[0]<=1000)
						{
							TFC_SetServo(0,(0));
							TFC_HBRIDGE_ENABLE;
							TFC_SetMotorPWM(0,0);
						}
						while (TFC_Ticker[0]<= 4000 )
						{
						TFC_SetServo(0,-1);
						TFC_HBRIDGE_ENABLE;
						TFC_SetMotorPWM(.7,.7);
						}
						while (TFC_Ticker[0]<= 6000 )
						{
							TFC_SetServo(0,.1);
							TFC_HBRIDGE_ENABLE;
							TFC_SetMotorPWM(.7,.7);
						}
						while (TFC_Ticker[0]<= 8000 )
						{
						TFC_SetServo(0,1);
						TFC_HBRIDGE_ENABLE;
						TFC_SetMotorPWM(.7,.7);
						}	
						while (TFC_Ticker[0]<= 10000 )
						{
							TFC_SetServo(0,(0));
							TFC_HBRIDGE_ENABLE;
							TFC_SetMotorPWM(.7,.7);
						}	
						while (TFC_Ticker[0]<= 12000 )
						{
							TFC_SetServo(0,(0));
							TFC_HBRIDGE_ENABLE;
							TFC_SetMotorPWM(0,0);
						}			
					}
				}
	
	return 0;
}
