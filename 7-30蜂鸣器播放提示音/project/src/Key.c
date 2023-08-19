#include <REG51.H>
#include "Delay.h"

sbit P3_1=P3^1;
sbit P3_2=P3^2;
sbit P3_3=P3^3;
sbit P3_4=P3^4;
sbit P3_0=P3^0;

//获取独立按键键码
unsigned char Key()

{
    unsigned char KeyNumer=0;
    if(P3_1==0)
    {
        Delay(20);while(P3_1==0);Delay(20);KeyNumer=1;
    }
    if(P3_0==0)
    {
        Delay(20);while(P3_0==0);Delay(20);KeyNumer=2;
    }
    if(P3_2==0)
    {
        Delay(20);while(P3_2==0);Delay(20);KeyNumer=3;
    }
    if(P3_3==0)
    {
        Delay(20);while(P3_3==0);Delay(20);KeyNumer=4;
    }
    return KeyNumer;
}