#include<REG51.H>
#include"Delay.h"
#include<INTRINS.H>


//�������˿�
sbit Buzzer=P2^5;

//������˽����ʱ����,��ʱ500us
void Buzzer_Delay500us()		//@11.0592MHz
{
	unsigned char i;

	_nop_();
	i = 227;
	while (--i);
}

//����������  ms ʱ��
void Buzzzer_Time(unsigned int ms)
{
    unsigned int i;
    for(i=0;i<ms*2;i++)
    {
        Buzzer=!Buzzer;
        Buzzer_Delay500us();
    }
}