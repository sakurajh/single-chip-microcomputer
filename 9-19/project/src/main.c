//ʵ��32����ָ��������Ϊ�����Ĳ�����ʾ����ַ���

#include<reg51.h>    //����51��Ƭ���Ĵ��������ͷ�ļ�


unsigned char code str1[]="TemperatureistestedbyDS18B20";//C�����У��ַ���

//����Ϊ�ַ�������������

unsigned char code str2[]="Nowtemperatureis:";     //���ԣ��ַ��������־���

//�ַ������׵�ַ

unsigned char code str3[]="TheSystermisdesignedbyZhangSan";

unsigned char code str4[]="Thedateis2008-9-30";

unsigned char *p[]={str1,str2,str3,str4};//����p[4]Ϊָ��4���ַ������ַ���ָ������

/**************************************************************

�������ܣ���ʱԼ150ms

**************************************************************/

void delay(void)

{

unsigned char m,n;

for(m=0;m<200;m++)

for(n=0;n<250;n++)

;

}

/**************************************************************

�������ܣ���ˮ����P0��8λLED

**************************************************************/

void led_display(unsignedchar*x [])   //�βα���Ϊָ������

{

unsigned char i,j;

for(i=0;i<4;i++)//��4���ַ���Ҫ��ʾ

{

j=0;  //ָ������ַ����ĵ�0��Ԫ��

while(*(x[i]+j)!='\0')//ֻҪ��i���ַ����ĵ�j��Ԫ�ز��ǽ�����־
{

P0=*(x[i]+j);//ȡ�ø�Ԫ��ֵ�͵�P0����ʾ

delay();  //������ʱ����

j++;   //ָ����һ��Ԫ��

}

}

}


/**************************************************************

�������ܣ�������

**************************************************************/

void main(void)

{

unsigned char i;

while(1)

{

for(i=0;i<4;i++)

led_display(p);//��ָ����������ʵ�ʲ�������

}

}