/***************************************************************************
实验名称： 流水灯实验  移位函数实现
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

void main(void)
{
	unsigned char i;
	while(1)
	{
		P0 = 0xfe;
		for(i = 0;i < 8;i++)        //流水灯一共8只，实现1到8只流水灯的循环
		{
			P0 = P0<<1+1;     	//实现输出
			mDelay(100);            //100ms的延迟
		}
	}
}
