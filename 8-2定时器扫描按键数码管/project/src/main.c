#include<REG51.H>
#include"Key.h"
#include"Delay.h"
#include"Timer0.h"
#include"Nixie.h"
#include"AT24C02.h"

sbit P2_0=P2^0;

unsigned char KeyNum;
unsigned char Min,Sec,MinSec;
unsigned char RunFlag;

void main()
{
    Timer0_Init();
    while(1)
    {
        KeyNum=Key();
        if(KeyNum==1) 	//K1��������
        {
            RunFlag=!RunFlag; 	//������־λ��ת
        }
        if(KeyNum==2)  //K2��������
        {
            Min=0;   //������0
            Sec=0;
            MinSec=0;
        }
        if(KeyNum==3)  //K3��������
        {
           AT24C02_WriteByte(0,Min);  //������д��AT24C02
           Delay(5);
           AT24C02_WriteByte(1,Sec);
           Delay(5);
           AT24C02_WriteByte(2,MinSec);
           Delay(5);
        }
        if(KeyNum==4) //K4��������
        {
            Min=AT24C02_ReadByte(0); //����AT24C02����
            Sec=AT24C02_ReadByte(1);
            MinSec=AT24C02_ReadByte(2);
        }

        Nixie_SetBuf(1,Min/10);  //������ʾ���棬��ʾ����
        Nixie_SetBuf(2,Min%10);
        Nixie_SetBuf(3,11);
        Nixie_SetBuf(4,Sec/10);
        Nixie_SetBuf(5,Sec%10);
        Nixie_SetBuf(6,11);
        Nixie_SetBuf(7,MinSec/10);
        Nixie_SetBuf(8,MinSec%10);
    }
}


/**
  * @brief  ����������������ж��е���
  * @param  ��
  * @retval ��
  */
void Sec_Loop(void)
{
    if(RunFlag)
    {
        MinSec++;
        if(MinSec>=100)
        {
            MinSec=0;
            Sec++;
            if(Sec>=60)
            {
                Sec=0;
                Min++;
                if(Min>=60)
                {
                Min=0;
                }
        }

        
        }
    }
    
}

void Timer0_Routine() interrupt 1
{   
    static unsigned int T0Count1,T0Count2,T0Count3;
	TL0 = 0x66;		//���ö�ʱ��ֵ
	TH0 = 0xFC;		//���ö�ʱ��ֵ
    T0Count1++;
    if(T0Count1>=20)
    {
         T0Count1=0;
         Key_Loop();  //20ms����һ�ΰ�����������
    }
    T0Count2++;
    if(T0Count2>=2)
    {
         T0Count2=0;
         Nixie_Loop();  //2ms����һ���������������
    }
   T0Count3++;
   if(T0Count3>=10)
   {
    T0Count3=0;
    Sec_Loop();  //10ms����һ���������������
   }
}
