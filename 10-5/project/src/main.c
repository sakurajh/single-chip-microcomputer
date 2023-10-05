/*
	����:INT0�жϼ���
	˵��:���¼�����K1�����ж�,�жϳ����ۼӼ���
		����ֵ��ʾ�������������,���������K2���������

*/
#include<reg51.h>
#include<intrins.h>
#define INT8U unsigned char
#define INT16U unsigned int 

//������0-9������ܶ����
code INT8U CA_Table[]=
{
	0xC0,0xF9,
	0xA4,0xB0,
	0x99,0x92,
	0x82,0xF8,
	0x80,0x90,
	0xFF//����
};
//������ֵ�ֽ��ĸ�λ
INT8U show_buffer[]={0,0,0};
INT16U count=0;
sbit clear_key=P3^6;
//��ʱ
void delay_ms(INT16U x)
{
	INT8U t;
	while(x--)
	{
		for(t=0;t<120;t++);
	}
}
//�������ʾ����ֵ
void refresh_show()
{
	//��ȡ������λ
	show_buffer[0]=count/100;
	show_buffer[1]=count%100/10;
	show_buffer[2]=count%10;

	if(show_buffer[0]==0)//��λΪ0ʱ����ʾ
	{
		show_buffer[0]=10;
		//��λΪ0ʱ,�ڶ�λΪ0,Ҳ����ʾ
		if(show_buffer[1]==0)
			show_buffer[1]=10;
	}
	P0=CA_Table[show_buffer[0]];
	P1=CA_Table[show_buffer[1]];
	P2=CA_Table[show_buffer[2]];

}
void main()
{
	//��ʼ����ʾ�˿�
	P0=0xFF;
	P1=0xFF;
	P2=0xFF;
	IE=0x81;//����INT0�ж�
	IT0=1;//�½��ش���
	while(1)
	{
		if(clear_key==0)//����
			count=0;
		refresh_show();//������ˢ����ʾ
	}
}

//INT0�жϺ���
void ex_int0() interrupt 0
{
	EA=0;//��ֹ�ж�
	delay_ms(10);//����
	count++;//����ֵ����
	EA=1;//���ж�
}
