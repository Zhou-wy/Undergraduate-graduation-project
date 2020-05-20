#include "pwm.h"

/*******************************************************************************
* �� �� ��         : TIM3_CH1_PWM_Init
* ��������		   : TIM3ͨ��1 PWM��ʼ������
* ��    ��         : per:��װ��ֵ
					 psc:��Ƶϵ��
* ��    ��         : ��
*******************************************************************************/
void TIM3_PWM_Init(u16 per,u16 psc)
{
		TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
		TIM_OCInitTypeDef TIM_OCInitStructure;
		GPIO_InitTypeDef GPIO_InitStructure;
	
		/* ����ʱ�� */
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);

		/*  ����GPIO��ģʽ��IO�� */
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOC,&GPIO_InitStructure);
	
		GPIO_PinRemapConfig(GPIO_FullRemap_TIM3,ENABLE);//�ı�ָ���ܽŵ�ӳ��	
		TIM_TimeBaseInitStructure.TIM_Period=per;   //�Զ�װ��ֵ
		TIM_TimeBaseInitStructure.TIM_Prescaler=psc; //��Ƶϵ��
		TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1;
		TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up; //�������ϼ���ģʽ
		TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitStructure);	
		
		TIM_OCInitStructure.TIM_OCMode=TIM_OCMode_PWM1;
		TIM_OCInitStructure.TIM_OCPolarity=TIM_OCPolarity_Low;
		TIM_OCInitStructure.TIM_OutputState=TIM_OutputState_Enable;
		
		TIM_OC1Init(TIM3,&TIM_OCInitStructure); //����Ƚ�ͨ��1��ʼ��
		TIM_OC2Init(TIM3,&TIM_OCInitStructure); //����Ƚ�ͨ��2��ʼ��
		TIM_OC3Init(TIM3,&TIM_OCInitStructure); //����Ƚ�ͨ��3��ʼ��
		TIM_OC4Init(TIM3,&TIM_OCInitStructure); //����Ƚ�ͨ��4��ʼ��
		
		TIM_OC1PreloadConfig(TIM3,TIM_OCPreload_Enable); //ʹ��TIMx�� CCR1 �ϵ�Ԥװ�ؼĴ���
		TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);  //ʹ��TIMx�� CCR1 �ϵ�Ԥװ�ؼĴ���
		TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);  //ʹ��TIMx�� CCR1 �ϵ�Ԥװ�ؼĴ���
		TIM_OC4PreloadConfig(TIM3, TIM_OCPreload_Enable);  //ʹ��TIMx�� CCR1 �ϵ�Ԥװ�ؼĴ���
		
		TIM_ARRPreloadConfig(TIM3,ENABLE);//ʹ��Ԥװ�ؼĴ���	
		TIM_Cmd(TIM3,ENABLE); //ʹ�ܶ�ʱ��
}


//B6-9
void TIM4_PWM_Init(u16 per,u16 psc)
{  
		TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
		TIM_OCInitTypeDef TIM_OCInitStructure;
		GPIO_InitTypeDef GPIO_InitStructure;
	
		/* ����ʱ�� */
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE);
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);

		/*  ����GPIO��ģʽ��IO�� */
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOB,&GPIO_InitStructure);
	
	//	GPIO_PinRemapConfig(GPIO_FullRemap_TIM4,ENABLE);//�ı�ָ���ܽŵ�ӳ��	
		
		TIM_TimeBaseInitStructure.TIM_Period=per;   //�Զ�װ��ֵ
		TIM_TimeBaseInitStructure.TIM_Prescaler=psc; //��Ƶϵ��
		TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1;
		TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up; //�������ϼ���ģʽ
		TIM_TimeBaseInit(TIM4,&TIM_TimeBaseInitStructure);	
		
		TIM_OCInitStructure.TIM_OCMode=TIM_OCMode_PWM1;
		TIM_OCInitStructure.TIM_OCPolarity=TIM_OCPolarity_Low;
		TIM_OCInitStructure.TIM_OutputState=TIM_OutputState_Enable;
		
		TIM_OC1Init(TIM4,&TIM_OCInitStructure); //����Ƚ�ͨ��1��ʼ��
		TIM_OC2Init(TIM4,&TIM_OCInitStructure); //����Ƚ�ͨ��2��ʼ��
		TIM_OC3Init(TIM4,&TIM_OCInitStructure); //����Ƚ�ͨ��3��ʼ��
		//TIM_OC4Init(TIM4,&TIM_OCInitStructure); //����Ƚ�ͨ��4��ʼ��
		
		TIM_OC1PreloadConfig(TIM4,TIM_OCPreload_Enable); //ʹ��TIMx�� CCR1 �ϵ�Ԥװ�ؼĴ���
		TIM_OC2PreloadConfig(TIM4,TIM_OCPreload_Enable);  //ʹ��TIMx�� CCR1 �ϵ�Ԥװ�ؼĴ���
		TIM_OC3PreloadConfig(TIM4,TIM_OCPreload_Enable);  //ʹ��TIMx�� CCR1 �ϵ�Ԥװ�ؼĴ���
		//TIM_OC4PreloadConfig(TIM4,TIM_OCPreload_Enable);  //ʹ��TIMx�� CCR1 �ϵ�Ԥװ�ؼĴ���
		
		TIM_ARRPreloadConfig(TIM4,ENABLE);//ʹ��Ԥװ�ؼĴ���	
		TIM_Cmd(TIM4,ENABLE); //ʹ�ܶ�ʱ��
}

