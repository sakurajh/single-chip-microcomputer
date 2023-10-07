/*
	����:��ʱ�����Ƶ�ֻLED��˸
	˵��:TIMER0����LED��˸

*/
#include<reg51.h>
#define INT8U unsigned char
#define INT16U unsigned int 

INT16U count=0;
//������
void main()
{
	TMOD=0x00;//T0������ģʽ0(13λģʽ)

	//5ms��ʱ
	TH0=(8192-5000)>>5;//��ͬ��:TH0=(8192-5000)/32;
	TL0=(8192-5000)&0x1F;//��ͬ��:TH0=(8192-5000)%32;

	IE=0x82;//����T0�ж�
	TR0=1;//����T0
	while(1);
}

//T0�жϺ���
void led_flash() interrupt 1
{
	TH0=(8192-5000)>>5;
	TL0=(8192-5000)&0x1F;
	if(++count==50)//�ۼ��γ�5ms*50=250ms��ʱ����LED
	{
		P0=~P0;//P0�˿ڵ�LED������˸
		count=0;
	}
}

