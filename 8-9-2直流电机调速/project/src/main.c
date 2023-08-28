#include<REG51.H>
#include"Delay.h"
#include"Key.h"
#include"Nixie.h"
#include"Timer0.h"


sbit Motor=P1^0;
unsigned char Counter,Compare;
unsigned char KeyNum,Speed=0;


void main()
{
    Timer0_Init();
    while(1)
    {
        KeyNum=Key_GetState();
        if(KeyNum==1)
        {
            Speed++;
            Speed%=4;
            if(Speed==0){Compare=0;}
            if(Speed==1){Compare=25;}
            if(Speed==2){Compare=75;}
            if(Speed==3){Compare=200;}
        }
        Nixie_Scan(1,Speed);
    }
}

void Timer0_Routine() interrupt 1
{   
	TL0=0x9C;		//设置定时初值
	TH0=0xFF;		//设置定时初值
    Counter++;
    Counter%=100;   //Counter大于100,归零
    if(Counter<Compare)
    {
        Motor=1;
    }
    else
    {
        Motor=0;
    } 
}