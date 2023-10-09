/*
	名称:TIMER0控制数码管动态显示
	说明:数码管显示:年月日时分秒
		使用定时器实现

*/
#include<reg51.h>
#include<intrins.h>
#define INT8U unsigned char
#define INT16U unsigned int 
#define METHOD1 1
//共阳极0-9的数码管段码表
code INT8U CA_Table[]=
{
	0xC0,0xF9,
	0xA4,0xB0,
	0x99,0x92,
	0x82,0xF8,
	0x80,0x90,
	0xBF//'-'的段码,索引为10
};
//待显示数据
code INT8U show_date[][8]=
{
	{2,2,10,0,2,10,1,4},
	{2,3,10,5,9,10,5,9}
};
INT8U i=0;
INT8U j=0;
INT16U t=0;

#if METHOD1
//主程序:使用方法1,使用定时器中断控制数码管刷新显示
void main()
{
	TMOD=0x01;//T0工作于模式1(16位模式)

	//4ms定时
	TH0=(65536-5000)>>8;
	TL0=(65536-5000)&0xFF;

	IE=0x82;//允许T0中断
	TR0=1;//启动T0
	while(1);
}
#else 
//方法2:不使用定时器中断控制,不需要中断函数
void main()
{
	TMOD=0x01;//T0工作于模式1(16位模式)

	//4ms定时
	TH0=(65536-5000)>>8;
	TL0=(65536-5000)&0xFF;

	IE=0x82;//允许T0中断
	TR0=1;//启动T0
	while(1)
	{
		if(TF0)
		{
			TF0=0;
			TH0=(65536-5000)>>8;
			TL0=(65536-5000)&0xFF;
			P0=0xFF;//先暂时关闭段码
			P2=~(1<<j);//输出位码
			P0=CA_Table[show_date[i][j]];//输出段码
			j=(j+1)%8;//数组第i行的下一数字索引
			if(++t!=350)//每组的8个字符位保持刷新一段时间
				continue;
			t=0;
			//刷新若干遍后切换
			i=(i+1)%2;//数组行i=0时,显示年月日,i=1时显示时分秒
		}
	}
}
#endif 

//T0中断函数
void seg_show() interrupt 1
{
	TH0=(65536-5000)>>8;
	TL0=(65536-5000)&0xFF;
	P0=0xFF;//先暂时关闭段码
	P2=~(1<<j);//输出位码
	P0=CA_Table[show_date[i][j]];//输出段码
	j=(j+1)%8;//数组第i行的下一数字索引
	if(++t!=350)//每组的8个字符位保持刷新一段时间
		return;
	t=0;
	//刷新若干遍后切换
	i=(i+1)%2;//数组行i=0时,显示年月日,i=1时显示时分秒

}
