#include<REG51.H>
#include"Delay.h"
#include"UART.h"

unsigned char Sec;


void main()
{
    UART_Init();
    while(1)
    {

    }
}

void UART_Routine() interrupt 4
{
   if(RI==1)
   {
     P2=~SBUF;
     UART_SendByte(SBUF);
     RI=0;
   }
}