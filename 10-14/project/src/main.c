/*
	名称:TIMER0,TIMER1,INT0中断控制报警器与旋转灯
	说明:定时器控制报警灯旋转显示,并发出警报声

*/

#include<reg52.h>
#include<intrins.h>
#define INT8U unsigned char
#define INT16U unsigned int 

sbit SPK=P3^7;
INT8U FRQ=0x00;

//延时
void delay_ms(INT16U x)
{
	INT8U t;
	while(x--)
	{
		for(t=0;t<120;t++);
	}
}

//主程序
void main()
{
	P2=0x00;//关闭所有LED
	TMOD=0x11;//两个定时器均工作在模式1
	TH0=0xFE;//定时器初值为0xFE00
	TL0=0x00;
	IT0=1;//下降沿触发INT0中断
	IE=0x8B;//开启0,1,3号中断(INT0,T0,T1)
	IP=0x01;//INT0设为高优先级
	TR0=0;//定时器启停由INT0中断控制,初始为关闭
	TR1=0;
	while(1)//循环过程中递增频率,溢出后再次递增
	{
		FRQ++;
		delay_ms(1);
	}
}

//INT0中断
void ex0_int() interrupt 0
{
	TR0=!TR0;//开启或停止两个定时器,分别控制报警声和LED旋转
	TR1=!TR1;
	if(P2==0x00)
		P2=0xE0;//开启三个灯旋转(0xE0即1110 0000)
	else
		P2=0x00;//关闭所有LED	
}

//TIMER0中断
void Timer0() interrupt 1
{
	TH0=0xFE;
	TL0=FRQ;
	SPK=~SPK;
}

//TIEMR1中断
void Timer1() interrupt 3
{
	TH1=-45000>>8;
	TL1=-45000&0x1F;
	P2=_crol_(P2,1);
}
