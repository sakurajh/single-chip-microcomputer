//ʵ��19����for�����Ʒ��������Ѵ���

#include<reg51.h>   //������Ƭ���Ĵ�����ͷ�ļ�

sbit sound=P3^7;   //��soundλ����ΪP3.7

/****************************************

�������ܣ���ʱ�γ�1600Hz��Ƶ

****************************************/

void delay1600(void)

{

unsigned char n;

for(n=0;n<100;n++)

;

}

/****************************************

�������ܣ���ʱ�γ�800Hz��Ƶ

****************************************/

void delay800(void)

{

unsigned char n;

for(n=0;n<200;n++)

;

}

/****************************************

�������ܣ�������

****************************************/

void main(void)

{

unsigned int i;

while(1)

{

for(i=0;i<830;i++)

{

sound=0;  //P3.7����͵�ƽ

delay1600();

sound=1;  //P3.7����ߵ�ƽ

delay1600();

}

for(i=0;i<200;i++)

{

sound=0;  //P3.7����͵�ƽ

delay800();

sound=1;  //P3.7����ߵ�ƽ

delay800();

}

}

}