#include<intrins.h>
#include<reg52.h>
#define uchar unsigned char	
#define uint unsigned int


void mDelay(uint Delay)	   //��ʱ
{	uint i;
	for(;Delay > 0;Delay--)
		for(i = 0;i < 110;i++);
}

void main(void)
{
	unsigned char a,i;
	while(1)
	{
		
		for(i = 0;i < 8;i++)        //��ˮ��һ��8ֻ��ʵ��1��8ֻ��ˮ�Ƶ�ѭ��
		{
			P1 = ~(0x01<<i);     
			mDelay(500);       
		}
		for(i = 0;i < 8;i++)        //��ˮ��һ��8ֻ��ʵ��1��8ֻ��ˮ�Ƶ�ѭ��
		{
			P1 = ~(0x80>>i);     
			mDelay(500);       
		}
	}
}