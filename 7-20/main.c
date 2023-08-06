#include<REG51.H>
#include"Delay.h"
#include"LCD1602.h"
#include"MatixKey.h"

unsigned char KeyNum;
unsigned int  Password,count;


void main()
{
    LCD_Init();
    LCD_ShowString(1,1,"Password");
    while (1)
    {
       KeyNum=MatrixKey();
       if(KeyNum)
       {
        if(KeyNum <=10)//如果s1~s10按键按下,输入密码
        {
            if(count<4)
            {
            Password*=10;
            Password+=KeyNum%10;
            count++;
            }
            
        } 
        LCD_ShowNum(2,1,Password,4);
       }
       if(KeyNum==11)
       {
        if(Password==2345)
        {
            LCD_ShowString(1,14,"OK");
        }
        else{
            LCD_ShowString(1,14,"ERR");
        }
       }
    }
}