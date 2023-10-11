/*
	名称:TIMER0控制门铃声输出
	说明:按下按键时,蜂鸣器发出叮咚的门铃声

*/
#include<reg51.h>
#include<intrins.h>
#define INT8U unsigned char
#define INT16U unsigned int 

sbit key=P1^7;
sbit doorBell=P3^0;
INT16U p=0;

//延时函数
void delay_ms(INT16U x)
{
	INT8U t;
	while(x--);
	for(t=0;t<120;t++);
}
//主程序
void main()
{
	IE=0x82;//允许T0中断
	TMOD=0x00;//T0工作于模式0(13位模式)
	//初始定时700us
	TH0=(8192-1000)/32;
	TL0=(8192-1000)%32;
	while(1)
	{
		if(key==0)//按下K1时,启动定时器
		{
			delay_ms(10);//消抖
			if(key==0)//按键释放后启动T1
			{
				while(!key);
				TR0=1;
			}
		}
	}
	

	while(1);
}


//T0中断函数
void timer0() interrupt 1
{
	doorBell=~doorBell;
	p++;
	//调整400和800,将声音拖长
	//高音
	if(p<400)
	{
		TH0=(8192-700)/32;
		TL0=(8192-700)%32;
	}
	else if(p<800)//低音
	{
		TH0=(8192-1000)/32;
		TL0=(8192-1000)%32;
	}
	else//关闭
	{
		TR0=0;
		p=0;
	}
}
