#ifndef _LED_H
#define _LED_H

#include "system.h"


void LED_Init(void);
/*  LEDʱ�Ӷ˿ڡ����Ŷ��� */
#define LED PBout(9)
#define Beep PCout(13)
#endif
