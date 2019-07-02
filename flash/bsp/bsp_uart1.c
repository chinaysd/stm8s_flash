#include "bsp_uart1.h"



#define RxDataComplete()    UART1_GetFlagStatus(UART1_FLAG_TXE)
  
#define DisableRxData()     UART1_ITConfig(UART1_IT_RXNE_OR,DISABLE)
#define EnableRxData()      UART1_ITConfig(UART1_IT_RXNE_OR,ENABLE)




void Uart1_Init(void)
{
	UART1_DeInit();
    
    //19200bps, 8bit, 1 stopbit, both rx and tx
    UART1_Init(9600, UART1_WORDLENGTH_8D, UART1_STOPBITS_1, UART1_PARITY_NO, 
                UART1_SYNCMODE_CLOCK_DISABLE, UART1_MODE_TXRX_ENABLE);
                
    UART1_ClearFlag(UART1_FLAG_RXNE);
    
    //Enable Rx interrupt
    UART1_ITConfig(UART1_IT_RXNE_OR, ENABLE);
    
    UART1_Cmd(ENABLE); 
}

void Uart1_SendByte(unsigned char Byte)
{
	UART1_SendData8(Byte);
	while(!RxDataComplete());
}

void Uart1_SendString(unsigned char *pBuf)
{
	DisableRxData();
	while(*pBuf != 0){
          Uart1_SendByte(*pBuf ++);
	}
	EnableRxData();
}

/*******************************************************************************
* Function Name  : SendData_Number.
* Description    : Convert a number to string then send it to PC
* Input          : String address that need to send
* Output         : None.
* Return         : None.
*******************************************************************************/
void SendData_Number(int16_t wNumber)
{
  uint8_t ubTempBuf[7] = {0};
    uint8_t ubPreNoneZero = 0;
    uint16_t uwDivide = 0;
    uint16_t uwTempValue = 0;
    uint8_t ubLength = 0;
    
    //If the value is negative, then print "-" before value
    if(wNumber < 0)
    {
        ubTempBuf[ubLength++] = '-';
        wNumber = wNumber * (-1);
    }
    
    //Convert number to string
    for (uwDivide = 10000; uwDivide > 0; uwDivide /= 10)
    {
        uwTempValue = wNumber / uwDivide;

        if (uwTempValue || ubPreNoneZero)
        {
            //Convert number to ascii
            ubTempBuf[ubLength++] = uwTempValue + '0';
            wNumber -= (uwTempValue * uwDivide);
            //Set this flag, so we can recognize 0 as payload because the higher digit is non-zero
            ubPreNoneZero = 1;
        }
    }
    //Set 0 at the end of buffer
    ubTempBuf[ubLength++] = 0;
    
    Uart1_SendString(&ubTempBuf[0]);
}

















