//ʵ��24����P0����ʾָ��������

#include<reg51.h>

void main(void)

{

unsigned char*p1,*p2;//�����޷����ַ���ָ�����p1,p2

unsigned char i,j;//�����޷����ַ�������

i=25;//��i����ֵ25

j=15;

P1=&i;//ʹָ�����ָ��i����ָ���ʼ��

P2=&j;//ʹָ�����ָ��j����ָ���ʼ��
 
P0=*p1+*p2;//*p1+*p2�൱��i+j,����P0=25+15=40=0x28//��P0=00101000B�����P0.3��P0.5����LEDϨ��
//�������

while(1);             //����ѭ������ֹ�����ܷɡ�
}