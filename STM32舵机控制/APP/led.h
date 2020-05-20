#ifndef _LED_H
#define _LED_H

#include "system.h"


void LED_Init(void);
/*  LED时钟端口、引脚定义 */
#define LED PBout(9)
#define Beep PCout(13)
#endif
