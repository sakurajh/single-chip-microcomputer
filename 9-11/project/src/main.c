#include<reg51.h>
unsigned char code table[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
sbit P3_7 = P3^7;
void delay(unsigned char time){
	unsigned char tmp = 125;
	for(;time>0;time--)
		for(;tmp>0;tmp--);
}
void main(){
	unsigned char count = 0;
	P2 = table[count%10];
	P0 = table[count/10];
	while(1){
	if(P3_7==0){
		delay(10);
		if(P3_7==0){
			count++;
			if(count==100) count=0;
			P2 = table[count%10];
			P0 = table[count/10];
			while(P3_7==0);
		}
	}
	}
}
