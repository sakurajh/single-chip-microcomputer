#include<REG51.H>
#include"LCD1602.h"
#include"Delay.h"
#include"IR.h"

unsigned char Num;
unsigned char Address;
unsigned char Command;

void main()
{
	LCD_Init();
	LCD_ShowString(1,1,"ADDR  CMD  NUM");
	LCD_ShowString(2,1,"00    00   000");
	
	IR_Init();
	
	while(1)
	{
		if(IR_GetDataFlag() || IR_GetRepeatFlag())	//����յ�����֡�����յ�����֡
		{
			Address=IR_GetAddress();		//��ȡң������ַ��
			Command=IR_GetCommand();		//��ȡң����������
			
			LCD_ShowHexNum(2,1,Address,2);	//��ʾң������ַ��
			LCD_ShowHexNum(2,7,Command,2);	//��ʾң����������
			
			if(Command==IR_VOL_MINUS)		//���ң����VOL-��������
			{
				Num--;						//Num�Լ�
			}
			if(Command==IR_VOL_ADD)			//���ң����VOL+��������
			{
				Num++;						//Num����
			}
			
			LCD_ShowNum(2,12,Num,3);		//��ʾNum
		}
	}
}


