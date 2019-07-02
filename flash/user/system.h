#ifndef _SYSTEM_H_
#define _SYSTEM_H_

#include "stm8s_conf.h"
#include "bsp_led.h"
#include "bsp_flash.h"
#include "bsp_timer.h"
#include "bsp_uart1.h"
#include "TimeOut.h"
#include "string.h"
#include "EepromMap.h"











void System_Init(void);
void System_Handle(void);

#endif

