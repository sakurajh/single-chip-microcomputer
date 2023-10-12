/*
	����:TIMER0���ƽ�ָͨʾ��
	˵��:�̵ƻƵƺ�Ƹ�������ѭ����˸

*/

#include<reg52.h>
#define INT8U unsigned char
#define INT16U unsigned int 

sbit RED_EW=P0^0;//��������
sbit YELLOW_EW=P0^1;
sbit GREEN_EW=P0^2;

sbit RED_SN=P0^3;//�ϱ�����
sbit YELLOW_SN=P0^4;
sbit GREEN_SN=P0^5;

//��ʱ����
INT8U Time_Count=0;
//��˸����
INT8U Flash_Count=0;
//����˸��ʽ
INT8U type=1;

//T0�ж�
void Timer0() interrupt 1
{
	TH0=-50000/256;
	TL0=-50000%256;
	switch(type)
	{
		case 1:
		{
			//���������̵���
			RED_EW=0;
			YELLOW_EW=0;
			GREEN_EW=1;
			//�ϱ���������
			RED_SN=1;
			YELLOW_SN=0;
			GREEN_SN=0;

			//5s
			if(++Time_Count!=100)
				return;
			Time_Count=0;
			type=2;//�л��仯��ʽ
			break;
		}
		case 2:
		{
			if(++Time_Count!=8)
				return;
			Time_Count=0;
			//�ر��̵�
			GREEN_EW=0;
			//��������Ƶ���˸
			YELLOW_EW=~YELLOW_EW;
			if(++Flash_Count!=10)
				return;
			Flash_Count=0;
			type=3;
			break;
		}
		case 3:
		{
			//������������
			RED_EW=1;
			YELLOW_EW=0;
			GREEN_EW=0;
			//�ϱ������̵���
			RED_SN=0;
			YELLOW_SN=0;
			GREEN_SN=1;

			if(++Time_Count!=100)
				return;
			Time_Count=0;
			type=4;
			break;
		}
		case 4:
		{
			if(++Time_Count!=8)
				return;
			Time_Count=0;
			//�ϱ�����Ƶ���˸
			YELLOW_SN=~YELLOW_SN;
			GREEN_SN=0;
			if(++Flash_Count!=10)
				return;
			Flash_Count=0;
			type=1;//ѭ��
		}
	}
}

//������
void main()
{
	TMOD=0x01;//��ʱ��0�����ڷ�ʽ1
	IE=0x82;//����ʱ��0�ж�
	TR0=1;//������ʱ��0
	while(1);
}
