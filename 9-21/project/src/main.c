//ʵ��15��"�����߼���·"ʵ��

#include<reg51.h>//������Ƭ���Ĵ�����ͷ�ļ�

sbit F=P1^4;//��Fλ����ΪP1.4

sbit X=P1^5;//��Xλ����ΪP1.5

sbit Y=P1^6;

sbit Z=P1^7;

void main(void)

{

while(1)

{
    F=((~X)&Y)|Z;//���߼�����������F
}


}

