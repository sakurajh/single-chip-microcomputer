/*
	����:TIMER0,TIMER1,INT0�жϿ��Ʊ���������ת��
	˵��:��ʱ�����Ʊ�������ת��ʾ,������������

*/

#include<reg52.h>
#include<intrins.h>
#define INT8U unsigned char
#define INT16U unsigned int 

sbit SPK=P3^7;
INT8U FRQ=0x00;

//��ʱ
void delay_ms(INT16U x)
{
	INT8U t;
	while(x--)
	{
		for(t=0;t<120;t++);
	}
}

//������
void main()
{
	P2=0x00;//�ر�����LED
	TMOD=0x11;//������ʱ����������ģʽ1
	TH0=0xFE;//��ʱ����ֵΪ0xFE00
	TL0=0x00;
	IT0=1;//�½��ش���INT0�ж�
	IE=0x8B;//����0,1,3���ж�(INT0,T0,T1)
	IP=0x01;//INT0��Ϊ�����ȼ�
	TR0=0;//��ʱ����ͣ��INT0�жϿ���,��ʼΪ�ر�
	TR1=0;
	while(1)//ѭ�������е���Ƶ��,������ٴε���
	{
		FRQ++;
		delay_ms(1);
	}
}

//INT0�ж�
void ex0_int() interrupt 0
{
	TR0=!TR0;//������ֹͣ������ʱ��,�ֱ���Ʊ�������LED��ת
	TR1=!TR1;
	if(P2==0x00)
		P2=0xE0;//������������ת(0xE0��1110 0000)
	else
		P2=0x00;//�ر�����LED	
}

//TIMER0�ж�
void Timer0() interrupt 1
{
	TH0=0xFE;
	TL0=FRQ;
	SPK=~SPK;
}

//TIEMR1�ж�
void Timer1() interrupt 3
{
	TH1=-45000>>8;
	TL1=-45000&0x1F;
	P2=_crol_(P2,1);
}
