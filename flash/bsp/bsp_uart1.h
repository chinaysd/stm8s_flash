#ifndef _BSP_UART1_H_
#define _BSP_UART1_H_

#include "stm8s_conf.h"











void Uart1_Init(void);
void Uart1_SendByte(unsigned char Byte);
void Uart1_SendString(unsigned char *pBuf);
void SendData_Number(int16_t wNumber);
#endif
