#include <REG51.H>
#include"Key.h"
#include"Delay.h"
#include"LCD1602.h"
#include"I2C.h"
#include"AT24C02.h"

unsigned char KeyNum;
unsigned int NUm;

void main()
{
    LCD_Init();
    LCD_ShowNum(1,1,NUm,5);
    // AT24C02_WriteByte(0,123);
    // Delay(5);
    // AT24C02_WriteByte(1,145);
    // Delay(5);
   // Data=AT24C02_ReadByte(1);
    //LCD_ShowNum(2,1,Data,3);
    while(1)
    {
        KeyNum=Key();
        if(KeyNum==1)
        {
            NUm++;
            LCD_ShowNum(1,1,NUm,5);
        }
        if(KeyNum==2)
        {
            NUm--;
            LCD_ShowNum(1,1,NUm,5);
        }
        if(KeyNum==3)
        {
            AT24C02_WriteByte(0,NUm%256);
            Delay(5);
            AT24C02_WriteByte(1,NUm/256);
            Delay(5);
            LCD_ShowString(2,1,"RIGHT OK");
            Delay(1000);
            LCD_ShowString(2,1,"     ");
        }
        if(KeyNum==4)
        {
        NUm=AT24C02_ReadByte(0);
        NUm|=AT24C02_ReadByte(1)<<8;
        LCD_ShowNum(1,1,NUm,5);
        LCD_ShowString(2,1,"read OK");
        Delay(1000);
        LCD_ShowString(2,1,"     ");
        }
    }
}