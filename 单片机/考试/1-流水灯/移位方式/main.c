/***************************************************************************
ʵ�����ƣ� ��ˮ��ʵ��  ��λ����ʵ��
***************************************************************************/

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
	unsigned char i;
	while(1)
	{
		P0 = 0xfe;
		for(i = 0;i < 8;i++)        //��ˮ��һ��8ֻ��ʵ��1��8ֻ��ˮ�Ƶ�ѭ��
		{
			P0 = P0<<1+1;     	//ʵ�����
			mDelay(100);            //100ms���ӳ�
		}
	}
}
