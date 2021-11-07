#include<intrins.h>
#include<reg52.h>
#define uchar unsigned char	
#define uint unsigned int


void mDelay(uint Delay)	   //延时
{	uint i;
	for(;Delay > 0;Delay--)
		for(i = 0;i < 110;i++);
}

void main(void)
{
	unsigned char a,i;
	while(1)
	{
		
		for(i = 0;i < 8;i++)        //流水灯一共8只，实现1到8只流水灯的循环
		{
			P1 = ~(0x01<<i);     
			mDelay(500);       
		}
		for(i = 0;i < 8;i++)        //流水灯一共8只，实现1到8只流水灯的循环
		{
			P1 = ~(0x80>>i);     
			mDelay(500);       
		}
	}
}