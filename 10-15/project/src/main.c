/*
	名称:TIMER0,TIMER1,TIMER2实现外部信号计数与显示
	说明:T0,T1均工作于计数器方式,T2工作于16位自动重装方式
		均实现了对外部输入信号的计数功能
		计数值最大均为65535,即:0xFFFF

*/

#include<reg52.h>
sfr T2MOD =0xC9;//reg52.h中没定义,在此添加sfr定义
sbit SW1=P1^5;
sbit SW2=P1^6;
sbit SW3=P1^7;
//主程序
void main()
{
	//设置T/C0,T/C1为计数器,工作于方式1(16位)
	TMOD=0x55;
	//设置T2引脚计数时钟输入,默认为递增计数
	T2MOD=0x00;
	//设置TIMER2为计数器
	C_T2=1;
	//T2工作于自动重装模式(上溢时重装0x0000)
	RCAP2H=0x00;
	RCAP2L=0x00;
	//三者初值均为0x00
	TH0=0x00;
	TL0=0x00;
	TH1=0x00;
	TL1=0x00;
	TH2=0x00;
	TL2=0x00;
	//启动三个定时器/计数器
	TR0=1;
	TR1=1;
	TR2=1;
	while(1)
	{
		if(!SW1)//通过P2,P0端口显示T0二进制计数值
		{
			P2=~TH0;
			P0=~TL0;
		}
		else if(!SW2)//通过P2,P0端口显示T1二进制计数值
		{
			P2=~TH1;
			P0=~TL1;
		}
		else if(!SW3)//通过P2,P0端口显示T2二进制计数值
		{
			P2=~TH2;
			P0=~TL2;
		}
	}
}
