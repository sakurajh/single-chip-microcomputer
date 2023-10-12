/*
	名称:TIMER0控制交通指示灯
	说明:绿灯黄灯红灯根据设置循环闪烁

*/

#include<reg52.h>
#define INT8U unsigned char
#define INT16U unsigned int 

sbit RED_EW=P0^0;//东西方向
sbit YELLOW_EW=P0^1;
sbit GREEN_EW=P0^2;

sbit RED_SN=P0^3;//南北方向
sbit YELLOW_SN=P0^4;
sbit GREEN_SN=P0^5;

//延时倍数
INT8U Time_Count=0;
//闪烁次数
INT8U Flash_Count=0;
//灯闪烁方式
INT8U type=1;

//T0中断
void Timer0() interrupt 1
{
	TH0=-50000/256;
	TL0=-50000%256;
	switch(type)
	{
		case 1:
		{
			//东西方向绿灯亮
			RED_EW=0;
			YELLOW_EW=0;
			GREEN_EW=1;
			//南北方向红灯亮
			RED_SN=1;
			YELLOW_SN=0;
			GREEN_SN=0;

			//5s
			if(++Time_Count!=100)
				return;
			Time_Count=0;
			type=2;//切换变化方式
			break;
		}
		case 2:
		{
			if(++Time_Count!=8)
				return;
			Time_Count=0;
			//关闭绿灯
			GREEN_EW=0;
			//东西方向黄灯闪烁
			YELLOW_EW=~YELLOW_EW;
			if(++Flash_Count!=10)
				return;
			Flash_Count=0;
			type=3;
			break;
		}
		case 3:
		{
			//东西方向红灯亮
			RED_EW=1;
			YELLOW_EW=0;
			GREEN_EW=0;
			//南北方向绿灯亮
			RED_SN=0;
			YELLOW_SN=0;
			GREEN_SN=1;

			if(++Time_Count!=100)
				return;
			Time_Count=0;
			type=4;
			break;
		}
		case 4:
		{
			if(++Time_Count!=8)
				return;
			Time_Count=0;
			//南北方向黄灯闪烁
			YELLOW_SN=~YELLOW_SN;
			GREEN_SN=0;
			if(++Flash_Count!=10)
				return;
			Flash_Count=0;
			type=1;//循环
		}
	}
}

//主程序
void main()
{
	TMOD=0x01;//定时器0工作在方式1
	IE=0x82;//允许定时器0中断
	TR0=1;//启动定时器0
	while(1);
}
