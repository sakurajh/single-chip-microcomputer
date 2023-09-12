#include<reg51.h>
unsigned char code table[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
char led_mod[] = {0x38,0x5b};
sbit P3_0=P3^0;
sbit P3_1=P3^1;
void delay(unsigned char time){
	unsigned char tmp = 125;
	for(;time>0;time--)
		for(;tmp>0;tmp--);
}
void main(){
	P3 = 0x00;
	while(1){
		P3_0 = 1;
		P3_1 = 0;
		P2 = led_mod[0];
		delay(30);
		P3_1 = 1;
		P3_0 = 0;
		P2 = led_mod[1];
		delay(30);
	}

}
