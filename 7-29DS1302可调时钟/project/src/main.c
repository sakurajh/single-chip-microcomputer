#include<REG51.H>
#include"LCD1602.h"
#include"DS1302.h"
#include"Delay.h"
#include"Key.h"
#include"Timer0.h"

sbit P2_0=P2^0;

unsigned char KeyNum,MODE,TimeSetSelect,TimeSetFlashFlag;


void TimerShow(void)
{
        DS1302_ReadTime();//��ȡʱ��
        LCD_ShowNum(1,1,DS1302_Time[0],2);//��ʾ��
        LCD_ShowNum(1,4,DS1302_Time[1],2);//��ʾ��
        LCD_ShowNum(1,7,DS1302_Time[2],2);//��ʾ��
        LCD_ShowNum(2,1,DS1302_Time[3],2);//��ʾʱ
        LCD_ShowNum(2,4,DS1302_Time[4],2);//��ʾ��
        LCD_ShowNum(2,7,DS1302_Time[5],2);//��ʾ��
        
}
void TimerSet(void)
{
    if(KeyNum==2)//����2����
	{
		TimeSetSelect++;//����ѡ��λ��1
		TimeSetSelect%=6;//Խ������
	}
	if(KeyNum==3)//����3����
	{
		DS1302_Time[TimeSetSelect]++;//ʱ������λ��ֵ��1
		if(DS1302_Time[0]>99){DS1302_Time[0]=0;}//��Խ���ж�
		if(DS1302_Time[1]>12){DS1302_Time[1]=1;}//��Խ���ж�
		if( DS1302_Time[1]==1 || DS1302_Time[1]==3 || DS1302_Time[1]==5 || DS1302_Time[1]==7 || 
			DS1302_Time[1]==8 || DS1302_Time[1]==10 || DS1302_Time[1]==12)//��Խ���ж�
		{
			if(DS1302_Time[2]>31){DS1302_Time[2]=1;}//����
		}
		else if(DS1302_Time[1]==4 || DS1302_Time[1]==6 || DS1302_Time[1]==9 || DS1302_Time[1]==11)
		{
			if(DS1302_Time[2]>30){DS1302_Time[2]=1;}//С��
		}
		else if(DS1302_Time[1]==2)
		{
			if(DS1302_Time[0]%4==0)
			{
				if(DS1302_Time[2]>29){DS1302_Time[2]=1;}//����2��
			}
			else
			{
				if(DS1302_Time[2]>28){DS1302_Time[2]=1;}//ƽ��2��
			}
		}
		if(DS1302_Time[3]>23){DS1302_Time[3]=0;}//ʱԽ���ж�
		if(DS1302_Time[4]>59){DS1302_Time[4]=0;}//��Խ���ж�
		if(DS1302_Time[5]>59){DS1302_Time[5]=0;}//��Խ���ж�
	}
	if(KeyNum==4)//����3����
	{
		DS1302_Time[TimeSetSelect]--;//ʱ������λ��ֵ��1
		if(DS1302_Time[0]<0){DS1302_Time[0]=99;}//��Խ���ж�
		if(DS1302_Time[1]<1){DS1302_Time[1]=12;}//��Խ���ж�
		if( DS1302_Time[1]==1 || DS1302_Time[1]==3 || DS1302_Time[1]==5 || DS1302_Time[1]==7 || 
			DS1302_Time[1]==8 || DS1302_Time[1]==10 || DS1302_Time[1]==12)//��Խ���ж�
		{
			if(DS1302_Time[2]<1){DS1302_Time[2]=31;}//����
			if(DS1302_Time[2]>31){DS1302_Time[2]=1;}
		}
		else if(DS1302_Time[1]==4 || DS1302_Time[1]==6 || DS1302_Time[1]==9 || DS1302_Time[1]==11)
		{
			if(DS1302_Time[2]<1){DS1302_Time[2]=30;}//С��
			if(DS1302_Time[2]>30){DS1302_Time[2]=1;}
		}
		else if(DS1302_Time[1]==2)
		{
			if(DS1302_Time[0]%4==0)
			{
				if(DS1302_Time[2]<1){DS1302_Time[2]=29;}//����2��
				if(DS1302_Time[2]>29){DS1302_Time[2]=1;}
			}
			else
			{
				if(DS1302_Time[2]<1){DS1302_Time[2]=28;}//ƽ��2��
				if(DS1302_Time[2]>28){DS1302_Time[2]=1;}
			}
		}
		if(DS1302_Time[3]<0){DS1302_Time[3]=23;}//ʱԽ���ж�
		if(DS1302_Time[4]<0){DS1302_Time[4]=59;}//��Խ���ж�
		if(DS1302_Time[5]<0){DS1302_Time[5]=59;}//��Խ���ж�
	}
	//������ʾ������TimeSetSelect��TimeSetFlashFlag�жϿ������˸����
	if(TimeSetSelect==0 && TimeSetFlashFlag==1){LCD_ShowString(1,1,"  ");}
	else {LCD_ShowNum(1,1,DS1302_Time[0],2);}
	if(TimeSetSelect==1 && TimeSetFlashFlag==1){LCD_ShowString(1,4,"  ");}
	else {LCD_ShowNum(1,4,DS1302_Time[1],2);}
	if(TimeSetSelect==2 && TimeSetFlashFlag==1){LCD_ShowString(1,7,"  ");}
	else {LCD_ShowNum(1,7,DS1302_Time[2],2);}
	if(TimeSetSelect==3 && TimeSetFlashFlag==1){LCD_ShowString(2,1,"  ");}
	else {LCD_ShowNum(2,1,DS1302_Time[3],2);}
	if(TimeSetSelect==4 && TimeSetFlashFlag==1){LCD_ShowString(2,4,"  ");}
	else {LCD_ShowNum(2,4,DS1302_Time[4],2);}
	if(TimeSetSelect==5 && TimeSetFlashFlag==1){LCD_ShowString(2,7,"  ");}
	else {LCD_ShowNum(2,7,DS1302_Time[5],2);}

}

void main()
{
    LCD_Init();
    DS1302_Init();

    LCD_ShowString(1,1,"  -  -  ");//��̬�ַ���ʼ����ʾ
    LCD_ShowString(2,1,"  :  :  ");

    DS1302_SetTime();//����ʱ��

    while(1)
    {
        KeyNum=Key();
        if(KeyNum==1)
        {
            if(MODE==0){MODE=1;TimeSetSelect=0;}
            else if(MODE==1){MODE=0;DS1302_ReadTime();}

        }
        switch(MODE)
        {
            case 0:TimerShow();break;
            case 1:TimerSet();break;
        }
    }
}
void Timer0_Routine() interrupt 1
{   
    static unsigned int T0Count;
	TL0 = 0x66;		//���ö�ʱ��ֵ
	TH0 = 0xFC;		//���ö�ʱ��ֵ
    T0Count++;
    if(T0Count>=500)
    {
         T0Count=0;
         P2_0=~P2_0;
         TimeSetFlashFlag=!TimeSetFlashFlag;
    }
   
}