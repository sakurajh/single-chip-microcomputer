/*
	名称:INT0中断计数
	说明:按下计数键K1触发中断,中断程序累加计数
		计数值显示在三个数码管上,按下清零键K2数码管清零

*/
#include<reg51.h>
#include<intrins.h>
#define INT8U unsigned char
#define INT16U unsigned int 

//共阳极0-9的数码管段码表
code INT8U CA_Table[]=
{
	0xC0,0xF9,
	0xA4,0xB0,
	0x99,0x92,
	0x82,0xF8,
	0x80,0x90,
	0xFF//黑屏
};
//计数器值分解后的给位
INT8U show_buffer[]={0,0,0};
INT16U count=0;
sbit clear_key=P3^6;
//延时
void delay_ms(INT16U x)
{
	INT8U t;
	while(x--)
	{
		for(t=0;t<120;t++);
	}
}
//数码管显示计数值
void refresh_show()
{
	//获取三个数位
	show_buffer[0]=count/100;
	show_buffer[1]=count%100/10;
	show_buffer[2]=count%10;

	if(show_buffer[0]==0)//高位为0时不显示
	{
		show_buffer[0]=10;
		//高位为0时,第二位为0,也不显示
		if(show_buffer[1]==0)
			show_buffer[1]=10;
	}
	P0=CA_Table[show_buffer[0]];
	P1=CA_Table[show_buffer[1]];
	P2=CA_Table[show_buffer[2]];

}
void main()
{
	//初始化显示端口
	P0=0xFF;
	P1=0xFF;
	P2=0xFF;
	IE=0x81;//允许INT0中断
	IT0=1;//下降沿触发
	while(1)
	{
		if(clear_key==0)//清零
			count=0;
		refresh_show();//持续则刷新显示
	}
}

//INT0中断函数
void ex_int0() interrupt 0
{
	EA=0;//禁止中断
	delay_ms(10);//消抖
	count++;//计数值递增
	EA=1;//开中断
}
