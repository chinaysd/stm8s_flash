#include "system.h"


TIMEOUT_PARA   TimeOut_Para[2];
extern unsigned char Uaer1RxByte[10];

unsigned char ubFrameDone;
unsigned int  RevDelayTime;


void System_Init(void)
{
	TimeOutDet_Init();
    Led_Init();
    //Test_Flash_Init();
    Timer_Init();
	Uart1_Init();
	EepromInitial();
	enableInterrupts();

	Uart1_SendString("**************************************************\r\n");
    Uart1_SendString("***************Welcome to My Studio***************\r\n");
    Uart1_SendString("**************************************************\r\n");
    Uart1_SendString("****************Lesson 6 - Eeprom*****************\r\n");
    Uart1_SendString("**************************************************\r\n");
    Uart1_SendString("Current Blinking Period is:   ");
    SendData_Number(uwEEP_BlinkPeriod);
    Uart1_SendString("ms\r\n");
    
    RevDelayTime = uwEEP_BlinkPeriod;
}

void System_Handle(void)
{
	static unsigned char Cnts;
	#if 1
    if(!ubFrameDone){
       ubFrameDone = 1;
	   RevDelayTime = (unsigned int)(Uaer1RxByte[2]<<8) | (unsigned int)Uaer1RxByte[3];
	   EepromWriteSection(EE_BLINK_PERIOD,(uint8_t *)&RevDelayTime);
	   Uart1_SendString("----------------------------"); 
	   SendData_Number(RevDelayTime);
	   Uart1_SendString("ms\t\n"); 
	   memset(&Uaer1RxByte,0,sizeof(Uaer1RxByte)/sizeof(unsigned char));
	}
	#endif
	if(TimeOutDet_Check(&TimeOut_Para[0])){
       TimeOut_Record(&TimeOut_Para[0],RevDelayTime);
	    ++ Cnts;
		if(Cnts & 0x01)
		{
		  LED_SET(1);
		}
		else 
		{ 
		  LED_SET(0);
		}
	}
}











