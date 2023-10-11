/*
	����:TIMER0�������������
	˵��:���°���ʱ,�������������˵�������

*/
#include<reg51.h>
#include<intrins.h>
#define INT8U unsigned char
#define INT16U unsigned int 

sbit key=P1^7;
sbit doorBell=P3^0;
INT16U p=0;

//��ʱ����
void delay_ms(INT16U x)
{
	INT8U t;
	while(x--);
	for(t=0;t<120;t++);
}
//������
void main()
{
	IE=0x82;//����T0�ж�
	TMOD=0x00;//T0������ģʽ0(13λģʽ)
	//��ʼ��ʱ700us
	TH0=(8192-1000)/32;
	TL0=(8192-1000)%32;
	while(1)
	{
		if(key==0)//����K1ʱ,������ʱ��
		{
			delay_ms(10);//����
			if(key==0)//�����ͷź�����T1
			{
				while(!key);
				TR0=1;
			}
		}
	}
	

	while(1);
}


//T0�жϺ���
void timer0() interrupt 1
{
	doorBell=~doorBell;
	p++;
	//����400��800,�������ϳ�
	//����
	if(p<400)
	{
		TH0=(8192-700)/32;
		TL0=(8192-700)%32;
	}
	else if(p<800)//����
	{
		TH0=(8192-1000)/32;
		TL0=(8192-1000)%32;
	}
	else//�ر�
	{
		TR0=0;
		p=0;
	}
}
