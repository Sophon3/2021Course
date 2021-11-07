#include<reg51.h>
#include<stdio.h>
#define uchar unsigned char 
void delay();
unsigned int i=0;
uchar digivalue[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7f,0x6f};
//显示的数字数组，依次为0，1，..，7
uchar select[]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80}; //选择数码管数组，依次选择1，2，..，8
void timer0Init(){
	TMOD=0x01;
	TH0=0xDB;
	TL0=0xFF;
	EA=1;
	ET0=1;
	TR0=1;
}
void delay(unsigned int i)
{
	unsigned int j;
	for(;i>0;i--)
	for(j=0;j<125;j++)
	{;}
}

void timer0() interrupt 1
{
  	i++;
	if(i>99)
	{
		i=0;
	}

	
}
void main()
{
    timer0lnit();
    while(1)
	{
                               P2=0x01;
	               P0=digivalue[i/10];
		delay(10);
		P2=0x02;
		P0=digivalue[i%10];
		delay(10);
	}
}


