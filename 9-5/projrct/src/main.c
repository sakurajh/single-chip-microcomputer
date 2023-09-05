#include <reg52.h>                  //头文件
unsigned char count=0;				//变量miao的计数器
unsigned char miao=0;				//表示秒			
unsigned char m=0;

//延时函数
void delay(unsigned int i)
{
 unsigned int k;
 for(k=0;k<i;k++);
}
//外部中断函数
void pause() interrupt 0
{
	if(m == 0)//判断是否第一次按下开关
	{
		TR1 = 0; 		 //计时器关闭
		m = 1;			//m初始化
	}
	else if(m == 1)    //判断是否第二次按下开关
	{
		TR1 = 1;		//计时器开启
		m = 0;
	}

}
//1秒定时器
void timer_1() interrupt 3
{	
	TH1=(65536-50000)/256;
	TL1=(65536-50000)%256;
	count++;
	if(count==20) //count加到20，表示过了1秒，miao就增加一
	{
		count=0;
		miao++;
		if(miao == 20)   //当秒加到20时，表示已完成一个周期，然后miao重新开始计数
			miao = 0;			
	}

}
//数码管显示函数
void disp(unsigned char i)
{
	//数码管的段选信号，分别表示0123456789
	unsigned char led[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
	
	P0=led[i%10];   //段选信号，第4个数码管依次0123456789
	P2=0xf7;    //位选信号  ，从左数第4个数码管
	delay(200);
	
	P0=led[0];   //段选信号，第3个数码管一直输出0
	P2=0xfb;    //位选信号  ，从左数第3个数码管
	delay(200);
	
	P2=0xfd;    //位选信号  ，从左数第2个数码管
	P0=led[i/10];  //段选信号，第2个数码管初始为0，过十秒后为1，周而复始
	delay(200);
	
	P2 = 0xfe;     //位选信号  ，从左数第1个数码管
	P0 = led[0]; //段选信号，第1个数码管一直输出0
	delay(200);
	//LED灯的亮灭，一秒亮一秒灭
  if(miao%2==0)  //当秒数为偶数时，LED灯亮
	  {
	  P1=0xfe;
	  }
	if(miao%2==1) //当秒数为奇数时，LED灯亮
	  {
	   P1=0xff;
	  }
}


void main()
{

	TMOD=0x10;   								//T1设置为工作方式一
	TH1=(65536-50000)/256;						//设置定时器初值
	TL1=(65536-50000)%256;
	ET1=1;    		//
	EA=1;			//开总中断允许位
	TR1=1;			//
	EX0=1;			//开外部中断0中断允许位
	IT0=1;			//开外部中断0为下降沿触发
	EX1=1;		//开外部中断1中断允许位
	IT1=1;			//开外部中断1为下降沿触发
	while(1)
	disp(miao);  //调用数码管显示函数

}

