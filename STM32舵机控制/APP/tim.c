#include "tim.h"

static u16 Init_times=0;

void TIM2_10Ms_Interrupt_Init(void)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure; 
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);	//ʹ��TIM2
	TIM_DeInit(TIM2);		//��λTIM2
	
	//����TIM2��ʼ������
	TIM_TimeBaseStructure.TIM_Period = TIM2_Period;
	TIM_TimeBaseStructure.TIM_Prescaler = TIM2_Prescaler;
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM2,&TIM_TimeBaseStructure);		

	TIM_ClearITPendingBit(TIM2, TIM_IT_Update); 	//���TIM2�жϱ�־
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);		//����������ж�
	
	//�жϲ�����ʼ��
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&NVIC_InitStructure);		

	TIM_Cmd(TIM2,ENABLE);		//������ʱ��     ��Ҫʱ�������
}



//��ʱ���ж�
void TIM2_IRQHandler(void)                     
{

	 if( TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET )
	 {
				TIM_ClearITPendingBit(TIM2, TIM_IT_Update); 	    //���TIM3�жϱ�־
        Init_times++;
        _10ms_T_interrupt();
        if(Init_times%2==0)
        {
            _50ms_T_interrupt();         }

        if(Init_times%5==0)
        {
            _100ms_T_interrupt(); 
        }
        if(Init_times%25==0)
        {
            _500ms_T_interrupt(); 
        } 				

        if(Init_times==5000)   
            Init_times=1;           
    }
}



