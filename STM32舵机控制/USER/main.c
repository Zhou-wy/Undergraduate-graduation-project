#include <stdio.h>
#include "SysTick.h"
#include "led.h"
#include "tim.h"
#include "pwm.h"
#include "LobotServoController.h"
#include "control.h"
#include "usart.h"

extern uint8_t Recv_flag;
extern uint8_t UART_RX_BUF[128];
extern uint8_t r;
int main(void)
{
		LED_Init();
		SysTick_Init(72);
		TIM2_10Ms_Interrupt_Init();
		TIM3_PWM_Init(2000,720-1);//50Hz 20ms
		TIM4_PWM_Init(2000,720-1);
		USART1_Init(115200);
		Begin_Flag_Action();		
		while(1)
		{				
		
			if(Recv_flag == 1)
			{
				switch(UART_RX_BUF[3])
						{
							
							case 	CMD_SERVO_MOVE					:	 Con_moveServo() ;break;
							case 	CMD_ACTION_GROUP_STOP		:  ACTION_GROUP_STOP()  ;break;
							case 	CMD_ACTION_GROUP_SPEED	:  Con_CHOOSE_ACTION_GROUP()  ;break;
						}
				Recv_flag=0;		
			}
			

		}
}


//55 55 08 03 01 E8 03 01 07 1C

/*************************************Ê±»ùÖÐ¶Ï*****************************************/
void _10ms_T_interrupt()
{ 
  
  
}

void _50ms_T_interrupt()
{ 
  
}


void _100ms_T_interrupt()
{
		//LED = !LED;
		//Beep = !Beep;
}

void _500ms_T_interrupt()
{
		LED = !LED;
		//Beep = !Beep;
}    



/****************************************************************************************/


