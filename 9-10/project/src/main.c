#include<reg51.h>
unsigned char code led[] = {0x01,0x02,0x04,0x08};
void delay(unsigned char time){
	unsigned char tmp = 125;
	for(;time>0;time--)
		for(;tmp>0;tmp--);
}
void main(){
	
	bit run=0,flag=0;
	unsigned char i = 0;
	P2 = 0X00;
	while(1){
		switch(~P0&0x0f){
			case 0x01:run=1;break;
			case 0x02:run=0;flag=0;break;
			case 0x04:flag=0;break;
			case 0x08:flag=1;break;
		}
		if(run){
			if(!flag){
				for(i=0;i<4;i++){
					P2 = led[i];
					delay(500);
				}
			}
			else{
				for(i=3;i>=0;i--){
					P2 = led[i];
					delay(500);
				}
			}
		}
		else P2 = 0X00;
	}
}
