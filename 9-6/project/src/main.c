#include <reg52.h>
sbit Q1 = P2^0;
unsigned char num[]={0xff,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
unsigned char i;
void int_0() interrupt 0
{
	if(i<9)
		i++;
	else
		i=1;
	P0=num[i];
}
void delay()
{
	unsigned char j;
	for(j=0;j<20;j++)
	{
		TH1=(65536-50000)/256;
		TL1=(65536-50000)%256;
		TR1=1;
		while(!TF1);
		TF1=0;
	}
}
void LED()
{
	unsigned char k,w,n;
	w=0x01;
	for(k=0;k<8;k++)
	{
		P1 = ~w;
		for(n=0;n<i;n++)
		{
			delay();
		}
		w<<=1;
	}
}
void main()
{
	TMOD = 0x10;
	EX0 =1;
	IT0 =1;
	EA = 1;
	Q1 = 0;
	i=0;
	P0 = num[i];
	P1 = 0xff;
	while(1)
	{
		if(i!=0)
		LED();
	}
}
