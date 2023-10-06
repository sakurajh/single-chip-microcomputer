/*
	����:INT0��INT1�жϼ���
	˵��:���¼�����K1����ֵ��ʾ���ұ��������,
		���¼�����K2����ֵ��ʾ������������,
		���������K3,K4���������

*/
#include<reg51.h>
#include<intrins.h>
#define INT8U unsigned char
#define INT16U unsigned int 

sbit K3=P3^4;//����
sbit K4=P3^5;
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

code INT8U scan_bits[]=
{
	0x20,0x10,
	0x08,0x04,
	0x02,0x01
};
//�����������ʾ����,ǰ3Ϊһ��,��3һ��
INT8U show_buffer[]=
{
	0,0,0,
	0,0,0
};
INT16U count_a=0;
INT16U count_b=0;

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
	INT8U i;
	//�ֽ�count_a
	show_buffer[5]=count_a/100;
	show_buffer[4]=count_a%100/10;
	show_buffer[3]=count_a%10;

	if(show_buffer[5]==0)//��λΪ0ʱ����ʾ
	{
		show_buffer[5]=10;
		//��λΪ0ʱ,�ڶ�λΪ0,Ҳ����ʾ
		if(show_buffer[4]==0)
			show_buffer[4]=10;
	}

	//�ֽ�count_b
	show_buffer[2]=count_b/100;
	show_buffer[1]=count_b%100/10;
	show_buffer[0]=count_b%10;

	if(show_buffer[2]==0)//��λΪ0ʱ����ʾ
	{
		show_buffer[2]=10;
		//��λΪ0ʱ,�ڶ�λΪ0,Ҳ����ʾ
		if(show_buffer[1]==0)
			show_buffer[1]=10;
	}


	for(i=0;i<6;i++)
	{
		P0=0xFF;//��ʱ�رն���
		P2=scan_bits[i];//λ��
		P0=CA_Table[show_buffer[i]];//����
		delay_ms(1);
	}

}
void main()
{
	IT0=1;//�½��ش���
	IT1=1;
	PX0=1;//�������ȼ�
	IE=0x85;//����INT0,INT1�ж�

	while(1)
	{
		if(!K3)//����
			count_a=0;
		if(!K4)//����
			count_b=0;
		refresh_show();//������ˢ����ʾ
	}
}

//INT0�жϺ���
void ex_int0() interrupt 0
{
	EA=0;//��ֹ�ж�
	delay_ms(10);//����
	count_a++;//����ֵ����
	EA=1;//���ж�
}
//INT1�жϺ���
void ex_int1() interrupt 2
{
	EA=0;//��ֹ�ж�
	delay_ms(10);//����
	count_b++;//����ֵ����
	EA=1;//���ж�
}
