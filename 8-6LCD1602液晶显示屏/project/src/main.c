#include<REG51.H>
#include"LCD1602.h"

void main()
{
 	LCD_Init();						//LCD��ʼ��
	LCD_ShowChar(1,1,'A');			//��1��1����ʾ�ַ�A
	LCD_ShowString(1,3,"Hello");	//��1��3����ʾ�ַ���Hello
	LCD_ShowNum(1,9,66,2);			//��1��9����ʾ����66������Ϊ2
	LCD_ShowSignedNum(1,12,-66,2);	//��1��12����ʾ�з�������-88������Ϊ2
	LCD_ShowHexNum(2,1,0xA5,2);		//��2��1����ʾʮ����������0xA5������Ϊ2
	LCD_ShowBinNum(2,4,0xA5,8);		//��2��4����ʾ����������0xA5������Ϊ8
	LCD_ShowChar(2,13,0xDF);		//��2��13����ʾ����Ϊ0xDF���ַ�
	LCD_ShowChar(2,14,'C');			//��2��14����ʾ�ַ�C
    while(1)
    {

    }
}

