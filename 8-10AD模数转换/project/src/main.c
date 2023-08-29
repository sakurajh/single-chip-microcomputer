#include<REG51.H>
#include"Delay.h"
#include"LCD1602.h"
#include"XPT2046.h"

unsigned int ADValue=0;


void main()
{
    LCD_Init();
    LCD_ShowString(1,1,"ADJ  NTC  RG");
    while(1)
    {
        ADValue=XPT2046_ReadAD(XPT2406_XP_12);
        LCD_ShowNum(2,1,ADValue,3);
        ADValue=XPT2046_ReadAD(XPT2406_YP_12);
        LCD_ShowNum(2,6,ADValue,3);
        ADValue=XPT2046_ReadAD(XPT2406_VBAT_12);
        LCD_ShowNum(2,11,ADValue,3);
        Delay(10);
    }
}