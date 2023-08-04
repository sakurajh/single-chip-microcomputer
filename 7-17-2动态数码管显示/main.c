#include <REGX52.H>

unsigned char NixieTable[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

void Delay(unsigned int xms)		//@11.0592MHz
{
	unsigned char i, j;
	while(xms--)
	{
		i = 11;
	j = 190;
	do
	{
		while (--j);
	} while (--i);
	}

	
}

void Nixie(unsigned char Location,number)
{
	switch(Location)
	{
			case 1:P2_4=1;P2_3=1;P2_2=1;break;
			case 2:P2_4=1;P2_3=1;P2_2=0;break;
			case 3:P2_4=1;P2_3=0;P2_2=1;break;
			case 4:P2_4=1;P2_3=0;P2_2=0;break;
			case 5:P2_4=0;P2_3=1;P2_2=1;break;
			case 6:P2_4=0;P2_3=1;P2_2=0;break;
			case 7:P2_4=0;P2_3=0;P2_2=1;break;
			case 8:P2_4=0;P2_3=0;P2_2=0;break;
		
	}
		P0=NixieTable[number];
		Delay(1);
		P0=0x00;
}

void main()
{
	
	while(1)
	{
	Nixie(1,1);
	//Delay(200);
	Nixie(2,2);
	//Delay(200);
	Nixie(3,3);
	//Delay(200);
	
	}

		
}