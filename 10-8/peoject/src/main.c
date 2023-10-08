/*
	名称:定时器控制单只LED闪烁
	说明:TIMER0控制LED闪烁

*/
#include<reg51.h>
#define INT8U unsigned char
#define INT16U unsigned int 

INT16U count=0;
//主程序
void main()
{
	TMOD=0x00;//T0工作于模式0(13位模式)

	//5ms定时
	TH0=(8192-5000)>>5;//等同于:TH0=(8192-5000)/32;
	TL0=(8192-5000)&0x1F;//等同于:TH0=(8192-5000)%32;

	IE=0x82;//允许T0中断
	TR0=1;//启动T0
	while(1);
}

//T0中断函数
void led_flash() interrupt 1
{
	TH0=(8192-5000)>>5;
	TL0=(8192-5000)&0x1F;
	if(++count==50)//累加形成5ms*50=250ms定时开关LED
	{
		P0=~P0;//P0端口的LED整体闪烁
		count=0;
	}
}

