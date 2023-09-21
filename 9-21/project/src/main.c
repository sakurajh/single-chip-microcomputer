//实例15："万能逻辑电路"实验

#include<reg51.h>//包含单片机寄存器的头文件

sbit F=P1^4;//将F位定义为P1.4

sbit X=P1^5;//将X位定义为P1.5

sbit Y=P1^6;

sbit Z=P1^7;

void main(void)

{

while(1)

{
    F=((~X)&Y)|Z;//将逻辑运算结果赋给F
}


}

