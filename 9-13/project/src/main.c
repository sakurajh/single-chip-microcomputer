
#include<reg51.h>
unsigned char code led_mod[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,	  //led��ʾ��
				  0x7f,0x6f,0x77,0x7c,0x58,0x5e,0x79,0x71};	  
unsigned char code key_buf[] = {0xee, 0xde, 0xbe, 0x7e,0xed, 0xdd, 0xbd, 0x7d,//��ֵ
				  0xeb, 0xdb, 0xbb, 0x7b,0xe7, 0xd7, 0xb7, 0x77};

char getKey(){
	char key_scan[] = {0xef,0xdf,0xbf,0x7f};
	char i=0,j=0;
	for(i=0;i<4;i++){
		P2 = key_scan[i];
		if((P2 & 0x0f)!=0x0f){
			for(j=0;j<16;j++){
				if(P2==key_buf[j])
					return j;
			}	 	
		}
		
	}
	return -1;
}

void main(){
	char key=0;
	P0=0X00;
	while(1){
	 	key=getKey();
		if(key!=-1){
			P0 = led_mod[key];
		}
	}
}