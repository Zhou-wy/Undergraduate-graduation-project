#ifndef _CONTROL_H
#define _CONTROL_H
#include "system.h"
#include "usart.h"
#include "stdio.h"
#include "led.h"

#define FULL_OPEN 1810 //ȫ��״̬ռ�ձ�6%���ߵ�ƽʱ��1.15ms
#define FULL_CLOSE 1890//ȫ��״̬ռ�ձ�10%���ߵ�ƽʱ��1.95ms
typedef unsigned          char uint8_t;
typedef unsigned short     int uint16_t;


struct Con_One_Steer
{
			uint8_t servoID;//���ƶ�������
			uint8_t Steernum;//���ƶ���ĸ���
			uint16_t Time;//�˶�ʱ��
			uint16_t Position;//�˶���λ��
};

struct RobotServo
{  //���ID,���Ŀ��λ��
	uint8_t ID;
	uint16_t Position;
} ;



void display(void);
extern	int num;
void contorl_test(int ii);
void Con_moveServo(void);
void Con_CHOOSE_ACTION_GROUP(void);
void Con_ACTION_GROUP_SPEED(void);
void ACTION_GROUP_STOP(void);
void ACTION_GROUP_RUN(void);

void ACTION_GROUP_STONE(void);
void ACTION_GROUP_SHEAR(void);
void ACTION_GROUP_CLOTH(void);
void Begin_Flag_Action(void);
#endif 
