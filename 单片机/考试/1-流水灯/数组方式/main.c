/***************************************************************************
实验名称： 流水灯实验 数组实现
***************************************************************************/

#include<intrins.h>
#include<reg52.h>
#define uchar unsigned char	
#define uint unsigned int

void mDelay(uint Delay)	   //延时
{	uint i;
	for(;Delay > 0;Delay--)
		for(i = 0;i < 110;i++);
}
uchar display[8] ={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f}; 
void main(void)
{
	unsigned char i;
	while(1)
	{
		for(i =0;i<8;i++)
		{
			P0 = display[i];
			mDelay(200);
		}
	}
}
