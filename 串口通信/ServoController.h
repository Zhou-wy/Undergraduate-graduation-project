/*******************************************************************************
* ????: LobotServoController.h
* ??: ???ֻ?????Ƽ?
* ????20160806
* LSCϵ?ж???ư??ο???ʾ??
*******************************************************************************/

#ifndef LOBOTSERVOCONTROLLER_H_
#define LOBOTSERVOCONTROLLER_H_

#include "bool.h"
#include <stdarg.h>
#include <string.h>
#define FRAME_HEADER 0x55             //֡ͷ
#define CMD_SERVO_MOVE 0x03           //?????ָ??
#define CMD_ACTION_GROUP_RUN 0x06     //??????ָ??
#define CMD_ACTION_GROUP_STOP 0x07    //ֹͣ????ָ??
#define CMD_ACTION_GROUP_SPEED 0x0B   //???????????
#define CMD_GET_BATTERY_VOLTAGE 0x0F  //????????ָ??

extern bool isUartRxCompleted;
extern uint8_t LobotRxBuf[16];
extern uint16_t batteryVolt;
extern void receiveHandle(void);
uint8_t LobotTxBuf[128];  //???????
typedef struct _lobot_servo_ {  //??ID,??Ŀ????
	uint8_t ID;
	uint16_t Position;
} LobotServo;


void moveServo(uint8_t servoID, uint16_t Position, uint16_t Time);
void moveServosByArray(LobotServo servos[], uint8_t Num, uint16_t Time);
void moveServos(uint8_t Num, uint16_t Time, ...);
void runActionGroup(uint8_t numOfAction, uint16_t Times);
void stopActionGroup(void);
void setActionGroupSpeed(uint8_t numOfAction, uint16_t Speed);
void setAllActionGroupSpeed(uint16_t Speed);
void getBatteryVoltage(void);



#endif
