#include <REG51.H>

void UART_Init()
{
    SCON=0X50;
    PCON=0;
	TMOD &= 0x0F;		//���ö�ʱ��ģʽ
	TMOD |= 0x20;		//���ö�ʱ��ģʽ
    TL1 = 0xFA;		//�趨��ʱ��ֵ
	TH1 = 0xFA;		//�趨��ʱ����װֵ
    ET1=0;
    TR1 = 1;
    EA=1;
    ES=1;
}

void UART_SendByte(unsigned char Byte)
{
    SBUF=Byte;
    while(TI==0);
    TI=0;
}

//�����жϺ���ģ��
// void UART_Routine() interrupt 4
// {
//    if(RI==1)
//    {
//      P2=~SBUF;
//      UART_SendByte(SBUF);
//      RI=0;
//    }
// }