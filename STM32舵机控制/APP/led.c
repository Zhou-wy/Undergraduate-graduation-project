/*


*/

#include "led.h"

/*******************************************************************************
* �� �� ��         : LED_Init
* ��������		   		: LED��ʼ������
* ��    ��         : ��
* ��    ��         : ��
*******************************************************************************/
void LED_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;//����ṹ�����
	GPIO_InitTypeDef GPIO_InitStructure1;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_9;  //ѡ����Ҫ���õ�IO��
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;	 //�����������ģʽ
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;	  //���ô�������
	GPIO_Init(GPIOB,&GPIO_InitStructure); 	   /* ��ʼ��GPIO */	
	GPIO_SetBits(GPIOB,GPIO_Pin_9);   //��LED�˿����ߣ�Ϩ������LED
	
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC ,ENABLE);	
	GPIO_InitStructure1.GPIO_Pin=GPIO_Pin_13;  //ѡ����Ҫ���õ�IO��
	GPIO_InitStructure1.GPIO_Mode=GPIO_Mode_Out_PP;	 //�����������ģʽ
	GPIO_InitStructure1.GPIO_Speed=GPIO_Speed_50MHz;	  //���ô�������
	GPIO_Init(GPIOC,&GPIO_InitStructure1); 	   /* ��ʼ��GPIO */
	GPIO_ResetBits(GPIOC,GPIO_Pin_13);   //��LED�˿����ߣ�Ϩ������LED
}

