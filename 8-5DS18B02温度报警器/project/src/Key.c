#include <REG51.H>
#include "Delay.h"

sbit P3_1=P3^1;
sbit P3_2=P3^2;
sbit P3_3=P3^3;
sbit P3_4=P3^4;
sbit P3_0=P3^0;


unsigned char Key_KeyNumber;

/**
  * @brief  ��ȡ��������
  * @param  ��
  * @retval ���°����ļ��룬��Χ��0,1~4,0��ʾ�ް�������
  */
unsigned char Key(void)
{
    unsigned char Temp=0;
    Temp=Key_KeyNumber;
    Key_KeyNumber=0;
    return Temp;
}


//��ȡ������������
/**
  * @brief  ��ȡ��ǰ������״̬�������������ּ��
  * @param  ��
  * @retval ���°����ļ��룬��Χ��0,1~4,0��ʾ�ް�������
  */
unsigned char Key_GetState()

{
    unsigned char KeyNumer=0;

    if(P3_1==0){KeyNumer=1;}
    if(P3_0==0){KeyNumer=2;}
    if(P3_2==0){KeyNumer=3;}
    if(P3_3==0){KeyNumer=4;}

    return KeyNumer;
}

/**
  * @brief  �����������������ж��е���
  * @param  ��
  * @retval ��
  */
void Key_Loop(void)
{
    static unsigned char NowState,LastState;
    LastState=NowState;  //����״̬����
    NowState=Key_GetState(); 	//��ȡ��ǰ����״̬
    //����ϸ�ʱ��㰴�����£����ʱ���δ���£���������˲�䣬�Դ˱������������ּ��
    if(LastState==1&&NowState==0)
    {
        Key_KeyNumber=1;
    }
    if(LastState==2&&NowState==0)
    {
        Key_KeyNumber=2;
    }
    if(LastState==3&&NowState==0)
    {
        Key_KeyNumber=3;
    }
    if(LastState==4&&NowState==0)
    {
        Key_KeyNumber=4;
    }
}