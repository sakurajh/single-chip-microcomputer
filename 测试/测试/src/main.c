#include <REG51.h>
#include "LCD1602.h"	//����LCD1602ͷ�ļ�
#include "MatrixKey.h"	//�����������ͷ�ļ�
 
unsigned char KeyNum;
 
void main()
{
LCD_Init();							//LCD��ʼ��
  LCD_ShowString(1,1,"MatrixKey:");	//LCD��ʾ�ַ���
	while(1)
	{
		KeyNum=MatrixKey();				//��ȡ������̼���
		if(KeyNum)						//����а�������
		{
			LCD_ShowNum(2,1,KeyNum,2);	//LCD��ʾ����
		}
	}
}