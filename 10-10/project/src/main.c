/*
	名称:TIMER0控制8*8点阵显示数字
	说明:点阵屏显示:0-9
		使用T0定时器溢出中断实现

*/
#include<reg51.h>
#include<intrins.h>
#define INT8U unsigned char
#define INT16U unsigned int 

//数字点阵

INT8U code DotMatrix[] =
{ 
	0x00,0x3E,0x41,0x41,0x41,0x3E,0x00,0x00,//0
	0x00,0x00,0x00,0x21,0x7F,0x01,0x00,0x00,//1
	0x00,0x27,0x45,0x45,0x45,0x39,0x00,0x00,//2
	0x00,0x22,0x49,0x49,0x49,0x36,0x00,0x00,//3
	0x00,0x0C,0x14,0x24,0x7F,0x04,0x00,0x00,//4
	0x00,0x72,0x51,0x51,0x51,0x4E,0x00,0x00,//5
	0x00,0x3E,0x49,0x49,0x49,0x26,0x00,0x00,//6
	0x00,0x40,0x40,0x40,0x4F,0x70,0x00,0x00,//7
	0x00,0x36,0x49,0x49,0x49,0x36,0x00,0x00,//8
	0x00,0x32,0x49,0x49,0x49,0x3E,0x00,0x00//9
};


//主程序
void main()
{
	TMOD=0x00;//T0工作于模式0(13位模式)

	//2ms定时
	TH0=(8192-2000)>>5;
	TL0=(8192-2000)&0x1F;
	TR0=1;//启动T0
	IE=0x82;//允许T0中断

	while(1);
}


//T0中断函数
void seg_show() interrupt 1
{
	static INT8U i=0;
	static INT8U num_idx=0;
	static INT8U t=0;
	TH0=(8192-2000)>>5;
	TL0=(8192-2000)&0x1F;
	P2=0xFF;//先暂时关闭段码
	P3=1<<i;//输出列码(列共阳)
	P2=~DotMatrix[num_idx*8+i];//输出行码
	if(++i==8)//每屏一个数字点阵由8个字节构成
		i=0;
	if(++t==200)//每个数字刷新显示一段时间
	{
		t=0x00;
		if(++num_idx==10)
			num_idx=0;//显示下一个数字
	}

}
