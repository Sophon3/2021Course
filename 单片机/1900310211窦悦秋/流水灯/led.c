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
		a = 0xfe;
		for(i = 0;i < 8;i++)        //��ˮ��һ��8ֻ��ʵ��1��8ֻ��ˮ�Ƶ�ѭ��
		{
			P0 = _crol_(a,1);     	//ʵ�����
			a = P0;
			mDelay(100);            //100ms���ӳ�
		}
	}
}