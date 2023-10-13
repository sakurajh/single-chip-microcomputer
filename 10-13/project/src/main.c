/*
	����:TIMER1������������
	˵��:ʹ�ö�ʱ���жϿ�������һ������,K1���Ʋ���

*/

#include<reg52.h>
#include<intrins.h>
#define INT8U unsigned char
#define INT16U unsigned int 

INT8U i=0;//��������
sbit SPK=P2^0;//�������������
sbit K1=P3^6;//������������
//14��������TIMER1ģʽ0�µĶ�ʱ/�����Ĵ�����ֵ��
code INT8U hight_list[]=
{
	0,226,229,232,234,
	236,238,240,241,243,
	244,245,246,247,248
};
code INT8U lower_list[]=
{
	0,4,12,9,20,
	2,8,6,2,22,
	5,26,1,4,2
};

//��ʱ
void delay_ms(INT16U x)
{
	INT8U t;
	while(x--)
	{
		for(t=0;t<120;t++);
	}
}

//T1�ж�
void Timer1() interrupt 3
{
	SPK=!SPK;//��Ƶ�������
	TH1=hight_list[i];//���ص�i����������ʱ��ֵ
	TL1=lower_list[i];

}

//������
void main()
{
	IE=0x88;//T1�ж�
	TMOD=0x00;//ģʽ0
	while(1)
	{
		if(!K1)
		{
			delay_ms(10);//����
			if(!K1)
			{
				for(i=1;i<15;i++)//���14������
				{
					TR1=1;
					delay_ms(500);//����һ������
					TR1=0;
					delay_ms(50);//����ͣ��50ms
				}
			}
		}
	}
}
