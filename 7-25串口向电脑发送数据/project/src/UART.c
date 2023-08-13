#include <REG51.H>

void UART_Init()
{
    SCON=0X40;
    PCON=0;
	TMOD &= 0x0F;		//设置定时器模式
	TMOD |= 0x20;		//设置定时器模式
    TL1 = 0xFA;		//设定定时初值
	TH1 = 0xFA;		//设定定时器重装值
    ET1=0;
    TR1 = 1;
}
void UART_SendByte(unsigned char Byte)
{
    SBUF=Byte;
    while(TI==0);
    TI=0;
}