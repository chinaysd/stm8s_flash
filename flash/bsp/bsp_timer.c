#include "bsp_timer.h"



void Timer_Init(void)
{
	 TIM4_DeInit();
	 TIM4_TimeBaseInit(TIM4_PRESCALER_8,125);
	 TIM4_ITConfig(TIM4_IT_UPDATE,ENABLE);
	 TIM4_Cmd(ENABLE);
}






