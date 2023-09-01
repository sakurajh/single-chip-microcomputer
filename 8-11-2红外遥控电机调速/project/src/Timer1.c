#include<REG51.H>



void Timer1_Init()
{
//    TMOD=0x01;  //0000 0001
	TMOD &= 0x0F;		//设置定时器模式
	TMOD |= 0x10;		//设置定时器模式
	TL1 = 0x9C;		//设置定时初值
	TH1 = 0xFF;		//设置定时初值
	TF1 = 0;		//清除TF0标志
	TR1 = 1;		//定时器0开始计时
    ET1=1;
    EA=1;
    PT1=0;
}
/*定时器中断函数模版
void Timer1_Routine() interrupt 3
{   
    static unsigned int T1Count;
	TL1 = 0xA4;		//设置定时初值
	TH1 = 0xFF;		//设置定时初值
    T1Count++;
    if(T1Count>=1000)
    {
         T1Count=0;
         P2_0=~P2_0;
    }
   
}


*/