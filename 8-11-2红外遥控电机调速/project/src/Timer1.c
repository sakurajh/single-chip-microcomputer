#include<REG51.H>



void Timer1_Init()
{
//    TMOD=0x01;  //0000 0001
	TMOD &= 0x0F;		//���ö�ʱ��ģʽ
	TMOD |= 0x10;		//���ö�ʱ��ģʽ
	TL1 = 0x9C;		//���ö�ʱ��ֵ
	TH1 = 0xFF;		//���ö�ʱ��ֵ
	TF1 = 0;		//���TF0��־
	TR1 = 1;		//��ʱ��0��ʼ��ʱ
    ET1=1;
    EA=1;
    PT1=0;
}
/*��ʱ���жϺ���ģ��
void Timer1_Routine() interrupt 3
{   
    static unsigned int T1Count;
	TL1 = 0xA4;		//���ö�ʱ��ֵ
	TH1 = 0xFF;		//���ö�ʱ��ֵ
    T1Count++;
    if(T1Count>=1000)
    {
         T1Count=0;
         P2_0=~P2_0;
    }
   
}


*/