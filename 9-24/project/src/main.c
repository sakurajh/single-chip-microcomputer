//ʵ��18����swtich���Ŀ���P0��8λLED�ĵ���״̬

#include<reg51.h>   //������Ƭ���Ĵ�����ͷ�ļ�

sbit S1=P1^4;      //��S1λ����ΪP1.4

/*****************************

�������ܣ���ʱһ��ʱ��

*****************************/

void delay(void)

{

unsigned int n;

for(n=0;n<10000;n++)

;

}

/*****************************

�������ܣ�������

*****************************/

void main(void)

{

unsigned char i;

i=0;//��i��ʼ��Ϊ0

while(1)

{

if(S1==0)//���S1������

delay();//��ʱһ��ʱ��

if(S1==0)//����ٴμ�⵽S1������

i++;    //i����1

if(i==9)  //���i=9�����½�����Ϊ1

i=1;

switch(i)//ʹ�ö��֧ѡ�����

{

case1:P0=0xfe;   //��һ��LED��

break;

case2:P0=0xfd;   //�ڶ���LED��

break;

case3:P0=0xfb;    //������LED��

break;

case4:P0=0xf7;    //���ĸ�LED��

break;

case5:P0=0xef;    //�����LED��

break;

case6:P0=0xdf;    //������LED��

break;

case7:P0=0xbf;    //���߸�LED��

break;

case8:P0=0x7f;    //�ڰ˸�LED��

break;

default:   //ȱʡֵ���ر�����LED

P0=0xff;

}

}