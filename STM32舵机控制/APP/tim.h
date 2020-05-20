#ifndef _TIM_H
#define _TIM_H
#include "stm32f10x.h"
#include "stm32f10x_tim.h"

#define TIM2_Period     (10000-1)  //10ms

#define TIM2_Prescaler  (72-1)

void _10ms_T_interrupt(void);
void _50ms_T_interrupt(void);
void _100ms_T_interrupt(void);
void _500ms_T_interrupt(void);
void TIM2_10Ms_Interrupt_Init(void);    //初始化定时器中断




#endif 
