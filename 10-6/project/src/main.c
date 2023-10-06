/*
	名称:INT0和INT1中断计数
	说明:按下计数键K1计数值显示在右边数码管上,
		按下计数键K2计数值显示在左边数码管上,
		按下清零键K3,K4数码管清零

*/
#include<reg51.h>
#include<intrins.h>
#define INT8U unsigned char
#define INT16U unsigned int 

sbit K3=P3^4;//清零
sbit K4=P3^5;
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

code INT8U scan_bits[]=
{
	0x20,0x10,
	0x08,0x04,
	0x02,0x01
};
//两组计数的显示缓冲,前3为一组,后3一组
INT8U show_buffer[]=
{
	0,0,0,
	0,0,0
};
INT16U count_a=0;
INT16U count_b=0;

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
	INT8U i;
	//分解count_a
	show_buffer[5]=count_a/100;
	show_buffer[4]=count_a%100/10;
	show_buffer[3]=count_a%10;

	if(show_buffer[5]==0)//高位为0时不显示
	{
		show_buffer[5]=10;
		//高位为0时,第二位为0,也不显示
		if(show_buffer[4]==0)
			show_buffer[4]=10;
	}

	//分解count_b
	show_buffer[2]=count_b/100;
	show_buffer[1]=count_b%100/10;
	show_buffer[0]=count_b%10;

	if(show_buffer[2]==0)//高位为0时不显示
	{
		show_buffer[2]=10;
		//高位为0时,第二位为0,也不显示
		if(show_buffer[1]==0)
			show_buffer[1]=10;
	}


	for(i=0;i<6;i++)
	{
		P0=0xFF;//暂时关闭段码
		P2=scan_bits[i];//位码
		P0=CA_Table[show_buffer[i]];//段码
		delay_ms(1);
	}

}
void main()
{
	IT0=1;//下降沿触发
	IT1=1;
	PX0=1;//设置优先级
	IE=0x85;//允许INT0,INT1中断

	while(1)
	{
		if(!K3)//清零
			count_a=0;
		if(!K4)//清零
			count_b=0;
		refresh_show();//持续则刷新显示
	}
}

//INT0中断函数
void ex_int0() interrupt 0
{
	EA=0;//禁止中断
	delay_ms(10);//消抖
	count_a++;//计数值递增
	EA=1;//开中断
}
//INT1中断函数
void ex_int1() interrupt 2
{
	EA=0;//禁止中断
	delay_ms(10);//消抖
	count_b++;//计数值递增
	EA=1;//开中断
}
