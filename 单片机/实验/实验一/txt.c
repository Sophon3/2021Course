#include<reg52.h>

void delay(int t)
{
	int y;
	for(；t>0;x--)
		for(y=0;y<200;y++);
}

void mian()
{
	while(1)
	{
		int i;
		P0 = 0x01;
		//delay(100);
		/*for(i=0;i<8;i++)
		{
			P0 = P0<<1;
			delay(100);
		}*/
	}
}



#include<reg52.h>


void mDelay(int Delay)	   //延时
{	int i;
	for(;Delay > 0;Delay--)
		for(i = 0;i < 110;i++);
}

void main(void)
{
	int i;
	while(1)
	{
		P0 = 0xfe;
		for(i = 0;i < 8;i++)        //流水灯一共8只，实现1到8只流水灯的循环
		{
			//P0 = _crol_(a,1);     	//实现输出
			P0 = (P0<<1)+1;
			mDelay(100);            //100ms的延迟
		}
	}
}

