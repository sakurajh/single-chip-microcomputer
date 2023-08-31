#include<REG51.H>



void Timer0_Init()
{
//    TMOD=0x01;  //0000 0001
	TMOD &= 0xF0;		//���ö�ʱ��ģʽ
	TMOD |= 0x01;		//���ö�ʱ��ģʽ
	TL0 = 0x9C;		//���ö�ʱ��ֵ
	TH0 = 0xFF;		//���ö�ʱ��ֵ
	TF0 = 0;		//���TF0��־
	TR0 = 0;		//��ʱ��0����ʼ��ʱ
}


void Timer0_SetCounter(unsigned int Value)
{
    TH0=Value/256;
    TL0=Value%256;
}

unsigned int Timer0_GetCounter(void)
{
    return (TH0<<8)|TL0;
}


void Timer0_Run(unsigned char Flag)
{
    TR0=Flag;
}