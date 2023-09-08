#include <reg52.h>
#include <intrins.h>
unsigned char i;
unsigned char b;
void delay(unsigned char n)
{
	unsigned char l;
	for(l = 0;l < n;l++);
}

void delays()
{
	unsigned char j;
	for(j = 0; j < 20; j++)
	{
		TH1 = (65536 - 50000)/256;
		TL1 = (65536 - 50000)%256;
		TR1 = 1;
		while(!TF1);
		TF1 = 0;
	}
}

void LED()
{
	unsigned char num[] = {0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80};
	unsigned char j;
	for(j = 0; j< 100; j++)
	{
		P2 = 0xfe;
		for(i = 0; i < 4; i++)
		{			
			P0 = num[i];			
			delay(200);
			P2 = _crol_(P2,1);
		}
	}
	for(j = 0; j< 100; j++)
	{
		P2 = 0xfe;
		for(i = 4; i < 8; i++)
		{			
			P0 = num[i];			
			delay(200);
			P2 = _crol_(P2,1);
		}
	}	
}

void LEDI()
{
	unsigned char code num[4][4] = {{0xa4,0xb0,0x99,0xf9},{0xb0,0x99,0xf9,0xa4},{0x99,0xf9,0xa4,0xb0},{0xf9,0xa4,0xb0,0x99}};
	unsigned char j, k, l;
	for(j = 0; j < 4; j++)
	{
		for(l = 0;l < 100;l++)
		{
			P2 = 0xfe;
			for(k = 0; k < 4;k++)
			{				
				P0 = num[j][k];
				delay(200);
				P2 = _crol_(P2,1);
			}
		}
	}	
}

void LEDT()
{
	unsigned char code num[4][4] = {{0x82,0xf8,0x80,0x92},{0xf8,0x80,0x92,0x82},{0x80,0x92,0x82,0xf8},{0x92,0x82,0xf8,0x80}};
	unsigned char j, k, l;
	for(j = 0; j < 4; j++)
	{
		for(l = 0;l < 100;l++)
		{
			P2 = 0xfe;
			for(k = 0; k < 4;k++)
			{				
				P0 = num[j][k];
				delay(200);
				P2 = _crol_(P2,1);
			}
		}
	}
}

void int_0() interrupt 0
{
		if(b != 0)
		b = 0;
		else if(i < 4 && b == 0)
		{
			b = 1;
		}
		else if(i >= 4 && b == 0)
		{
			b = 2;
		}	
}


void main()
{
	TMOD = 0x10;	
	EA =1;
	EX0 = 1;
	IT0 = 1;
	while(1)
	{
		if( b == 0)
		{
			LED();
		}
		else if(b == 1)
			LEDI();
		else
			LEDT();
	}
}
