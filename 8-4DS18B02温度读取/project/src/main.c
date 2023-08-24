#include<REG51.H>
#include"Delay.h"
#include"LCD1602.h"
#include"DS18B20.h"

float T;

void main()
{
    DS18B20_Convert();
    Delay(1000);
    LCD_Init();
    LCD_ShowString(1,1,"Temperature:");
    while(1)
    {
        DS18B20_Convert();
        T=DS18B20_ReadT();
        if(T<0)
        {
            LCD_ShowChar(2,1,'-');
            T=-T;
        }
        else
        {
            LCD_ShowChar(2,1,'+');
        }
        LCD_ShowNum(2,2,T,3);
        LCD_ShowChar(2,5,'.');
        LCD_ShowNum(2,6,(unsigned long)(T*10000)%10000,4);
    }
}