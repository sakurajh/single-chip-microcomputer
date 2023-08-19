#include<REG51.H>
#include"Delay.h"
#include<INTRINS.H>


//蜂鸣器端口
sbit Buzzer=P2^5;

//蜂鸣器私有延时函数,延时500us
void Buzzer_Delay500us()		//@11.0592MHz
{
	unsigned char i;

	_nop_();
	i = 227;
	while (--i);
}

//蜂鸣器发声  ms 时长
void Buzzzer_Time(unsigned int ms)
{
    unsigned int i;
    for(i=0;i<ms*2;i++)
    {
        Buzzer=!Buzzer;
        Buzzer_Delay500us();
    }
}