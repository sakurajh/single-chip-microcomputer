#include<REG51.H>



void Timer0_Init()
{
//    TMOD=0x01;  //0000 0001
	TMOD &= 0xF0;		//设置定时器模式
	TMOD |= 0x01;		//设置定时器模式
	TL0 = 0x9C;		//设置定时初值
	TH0 = 0xFF;		//设置定时初值
	TF0 = 0;		//清除TF0标志
	TR0 = 0;		//定时器0不开始计时
}


void Timer0_SetCounter(unsigned int Value)
{
    TH0=Value/256;
    TL0=Value%256;
}

unsigned int Timer0_GetCounter(void)
{
    return (TH0<<8)|TL0;
}


void Timer0_Run(unsigned char Flag)
{
    TR0=Flag;
}