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
		a = 0xfe;
		for(i = 0;i < 8;i++)        //流水灯一共8只，实现1到8只流水灯的循环
		{
			P0 = _crol_(a,1);     	//实现输出
			a = P0;
			mDelay(100);            //100ms的延迟
		}
	}
}