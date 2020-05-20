#include "control.h"
#include "usart.h"
#include <stdio.h>
#include <string.h>
#include "LobotServoController.h"
#include "led.h"
#include "SysTick.h"

extern uint8_t UART_RX_BUF[128];
struct RobotServo servos[8];
uint8_t temp = 0;

/*********************************************************************************
 * Function:  ACTION_GROUP_STOP
 * Description:控制所有舵机通知运动
 * Parameters:  
 * Return:       无
 * Others:
 **********************************************************************************/
void ACTION_GROUP_STOP(void)
{


			TIM_SetCompare1(TIM3,FULL_OPEN);
			TIM_SetCompare2(TIM3,FULL_CLOSE);
			TIM_SetCompare3(TIM3,FULL_CLOSE);
			TIM_SetCompare4(TIM3,FULL_CLOSE);
			TIM_SetCompare1(TIM4,FULL_CLOSE);
			TIM_SetCompare2(TIM4,FULL_CLOSE);
			TIM_SetCompare3(TIM4,FULL_CLOSE);
	//		TIM_SetCompare4(TIM4,FULL_CLOSE);
	//		TIM_Cmd(TIM3,DISABLE); //使能定时器
	//		TIM_Cmd(TIM4,DISABLE); //使能定时器
}

void ACTION_GROUP_RUN(void)
{


			TIM_SetCompare1(TIM3,FULL_CLOSE);
			TIM_SetCompare2(TIM3,FULL_OPEN);
			TIM_SetCompare3(TIM3,FULL_OPEN);
			TIM_SetCompare4(TIM3,FULL_OPEN);
			TIM_SetCompare1(TIM4,FULL_OPEN);
			TIM_SetCompare2(TIM4,FULL_OPEN);
			TIM_SetCompare3(TIM4,FULL_OPEN);
			TIM_SetCompare4(TIM4,FULL_OPEN);
	//		TIM_Cmd(TIM3,DISABLE); //使能定时器
	//		TIM_Cmd(TIM4,DISABLE); //使能定时器
}
/*********************************************************************************
 * Function:  Con_ACTION_GROUP_RUN
 * Description: 控制多个舵机完成一组动作
 * Parameters:   
                  
 * Return:       
 * Others:
 **********************************************************************************/
void contorl_ACTION(struct RobotServo arr[],uint16_t num,uint16_t Time)
{
	uint8_t i = 0;
	if(num>8 || num<1)
		  return;
	for(i = 0; i < num; i++)
	{
			
			if(arr[i].Position>2100 ||arr[i].Position<1500)//切记：根据实际情况改变限宽，以防超过舵机的极限旋转角度
			{
				return ;
			}
			switch(arr[i].ID)
			{
			
				case 1:TIM_SetCompare1(TIM3,arr[i].Position);break;
				case 2:TIM_SetCompare2(TIM3,arr[i].Position); break;
				case 3:TIM_SetCompare3(TIM3,arr[i].Position);break;
				case 4:TIM_SetCompare4(TIM3,arr[i].Position);break;			
				case 5:TIM_SetCompare1(TIM4,arr[i].Position);break;
				case 6:TIM_SetCompare2(TIM4,arr[i].Position);break;
				case 7:TIM_SetCompare3(TIM4,arr[i].Position);break;
				case 8:TIM_SetCompare4(TIM4,arr[i].Position);break;
				default:
					return ;
				
			}
	
	}
}

/*********************************************************************************
 * Function:  Con_moveServo
 * Description：解析控制一个舵机的数据
 * Parameters:  无
 * Return:       无
 * Others:		生成结构体steer
 **********************************************************************************/
void Con_moveServo(void)
{	
	uint8_t index = 7;
//	struct Con_One_Steer _steer;
	uint8_t num=0;
	if(UART_RX_BUF[2]==3*UART_RX_BUF[4]+5)
	{
			
			num = (UART_RX_BUF[2]-5)/3;
			if(UART_RX_BUF[4]==num)
			{		
					volatile uint16_t Time=0;
					Time=UART_RX_BUF[5] | UART_RX_BUF[6]<<8;
					printf("Time:%d\n",Time);
				
					for (temp = 0; temp < num; temp++)  //遍历所有控制舵机的ID
					{		

						servos[temp].ID  = UART_RX_BUF[index++] ; 					//解析ID								
						servos[temp].Position = UART_RX_BUF[index] | UART_RX_BUF[index+1]<<8;								//解析位置					
						index+=2;
						printf("ID:%d,Posi:%d\r\n",servos[temp].ID,servos[temp].Position);
					}
					
					contorl_ACTION(servos,num,Time);
					memset(UART_RX_BUF,0,128);
				
			}		
	}	

}
void ACTION_GROUP_STONE(void)
{


			TIM_SetCompare1(TIM3,FULL_OPEN);
			TIM_SetCompare2(TIM3,FULL_CLOSE);
			TIM_SetCompare3(TIM3,FULL_CLOSE);
			TIM_SetCompare4(TIM3,FULL_CLOSE);
			TIM_SetCompare1(TIM4,FULL_CLOSE);
			TIM_SetCompare2(TIM4,FULL_CLOSE);
			TIM_SetCompare3(TIM4,FULL_CLOSE);
			//TIM_SetCompare4(TIM4,FULL_CLOSE);

}

void ACTION_GROUP_CLOTH(void)
{


			TIM_SetCompare1(TIM3,FULL_CLOSE);//1号舵机
			TIM_SetCompare2(TIM3,FULL_OPEN);//2号舵机
			TIM_SetCompare3(TIM3,FULL_OPEN);//3号舵机
			TIM_SetCompare4(TIM3,FULL_OPEN);//4号舵机
			TIM_SetCompare1(TIM4,FULL_OPEN);//5号舵机
			TIM_SetCompare2(TIM4,FULL_CLOSE);//6号舵机
			TIM_SetCompare3(TIM4,FULL_CLOSE);//7号舵机
			//TIM_SetCompare4(TIM4,FULL_CLOSE);//8号舵机

}


void ACTION_GROUP_SHEAR(void)
{


			TIM_SetCompare1(TIM3,FULL_OPEN);
			TIM_SetCompare2(TIM3,FULL_OPEN);
			TIM_SetCompare3(TIM3,FULL_OPEN);
			TIM_SetCompare4(TIM3,FULL_CLOSE);
			TIM_SetCompare1(TIM4,FULL_CLOSE);
			TIM_SetCompare2(TIM4,FULL_CLOSE);
			TIM_SetCompare3(TIM4,FULL_CLOSE);
			//TIM_SetCompare4(TIM4,FULL_CLOSE);

}

/*********************************************************************************
	* Function:  Con_ACTION_GROUP_STOP_STONE
	* Description:控制三个动作(石头，剪刀，布)
	* Parameters:  无
	* Return:       无
	* Others:		
 **********************************************************************************/

void Con_CHOOSE_ACTION_GROUP(void)
{
	if(UART_RX_BUF[2] == 5 && UART_RX_BUF[3] == CMD_ACTION_GROUP_SPEED)
	{
			switch(UART_RX_BUF[4])
			{
				case 0x01://石头
					{
							ACTION_GROUP_STONE();
					};break;
				case 0x02://剪刀
					{
							ACTION_GROUP_SHEAR();
				
					};break;
				case 0x03://布
					{
							ACTION_GROUP_CLOTH();
				
					};break;			
			}	
	
	}

}

void Begin_Flag_Action(void)
{
	ACTION_GROUP_CLOTH();
	delay_ms(400);	
	ACTION_GROUP_STONE();
	delay_ms(400);
	ACTION_GROUP_CLOTH();
	delay_ms(400);	
	ACTION_GROUP_STONE();
	delay_ms(400);	
}


void Con_ACTION_GROUP_SPEED(void)
{



}

void display(void)
{


}
