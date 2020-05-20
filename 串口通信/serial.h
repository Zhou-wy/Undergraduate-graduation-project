#ifndef _SERIAL_H
#define _SERIAL_H 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <linux/input.h>
#include <pthread.h>
#include <sys/socket.h>
#include <linux/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <pthread.h>
#include "ServoController.h"


//串口所对应的文件名
#define COM1 "/dev/ttyAMA0"
#define SIZE 1024


int Send_Buf();


#define GET_LOW_BYTE(A) ((uint8_t)(A))
//宏函数 获得A的低八位
#define GET_HIGH_BYTE(A) ((uint8_t)((A) >> 8))
//宏函数 获得A的高八位


#define SIZE 1024
#endif
