#include<REG51.H>
#include"Delay.h"
#include"Key.h"
#include"Nixie.h"
#include"Timer0.h"


sbit DA=P2^1;
unsigned char Counter,Compare;
unsigned char i;


void main()
{
    Timer0_Init();
    while(1)
    {
        for ( i = 0; i < 100; i++)
        {
            Compare=i;
            Delay(10);
        }
        for ( i = 100; i >0; i--)
        {
            Compare=i;
            Delay(10);
        }
        
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
        DA=1;
    }
    else
    {
        DA=0;
    } 
}