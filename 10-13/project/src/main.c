/*
	名称:TIMER1控制音阶演奏
	说明:使用定时器中断控制演奏一段音阶,K1控制播放

*/

#include<reg52.h>
#include<intrins.h>
#define INT8U unsigned char
#define INT16U unsigned int 

INT8U i=0;//音符索引
sbit SPK=P2^0;//扬声器输出引脚
sbit K1=P3^6;//按键输入引脚
//14个音符在TIMER1模式0下的定时/计数寄存器初值表
code INT8U hight_list[]=
{
	0,226,229,232,234,
	236,238,240,241,243,
	244,245,246,247,248
};
code INT8U lower_list[]=
{
	0,4,12,9,20,
	2,8,6,2,22,
	5,26,1,4,2
};

//延时
void delay_ms(INT16U x)
{
	INT8U t;
	while(x--)
	{
		for(t=0;t<120;t++);
	}
}

//T1中断
void Timer1() interrupt 3
{
	SPK=!SPK;//音频脉冲输出
	TH1=hight_list[i];//加载第i个音符的延时初值
	TL1=lower_list[i];

}

//主程序
void main()
{
	IE=0x88;//T1中断
	TMOD=0x00;//模式0
	while(1)
	{
		if(!K1)
		{
			delay_ms(10);//消抖
			if(!K1)
			{
				for(i=1;i<15;i++)//输出14个音符
				{
					TR1=1;
					delay_ms(500);//播放一个音符
					TR1=0;
					delay_ms(50);//播放停顿50ms
				}
			}
		}
	}
}
