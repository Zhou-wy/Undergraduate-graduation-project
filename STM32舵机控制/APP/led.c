/*


*/

#include "led.h"

/*******************************************************************************
* 函 数 名         : LED_Init
* 函数功能		   		: LED初始化函数
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void LED_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;//定义结构体变量
	GPIO_InitTypeDef GPIO_InitStructure1;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_9;  //选择你要设置的IO口
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;	 //设置推挽输出模式
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;	  //设置传输速率
	GPIO_Init(GPIOB,&GPIO_InitStructure); 	   /* 初始化GPIO */	
	GPIO_SetBits(GPIOB,GPIO_Pin_9);   //将LED端口拉高，熄灭所有LED
	
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC ,ENABLE);	
	GPIO_InitStructure1.GPIO_Pin=GPIO_Pin_13;  //选择你要设置的IO口
	GPIO_InitStructure1.GPIO_Mode=GPIO_Mode_Out_PP;	 //设置推挽输出模式
	GPIO_InitStructure1.GPIO_Speed=GPIO_Speed_50MHz;	  //设置传输速率
	GPIO_Init(GPIOC,&GPIO_InitStructure1); 	   /* 初始化GPIO */
	GPIO_ResetBits(GPIOC,GPIO_Pin_13);   //将LED端口拉高，熄灭所有LED
}

