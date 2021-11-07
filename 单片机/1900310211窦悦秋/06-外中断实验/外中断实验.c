/***************************************************************************
实验名称： 外部中断实验

实验模块:  51单片机核心板、发光管、拨码开关、轻触开关区

实验接线： 51单片机核心板------发光管、拨码开关、轻触开关区

						P1---------J4	
						
						P3.2---------K1
						


更新时间：2017.10.17
***************************************************************************/


#include<reg52.h>	//添加库文件
#include<stdio.h>	
#define uint unsigned int
uint a = 0xFF;

void mDelay(uint Delay)	   //延时
{	
	uint i;
	for(;Delay > 0;Delay--)
	for(i = 0;i < 110;i++);
}

void main(void)
{	
	unsigned char a,i;
	EA=1;
  EX0=1	;//启动外部中断0
	IT0 = 1;		//外部中断0，脉冲触发方式，下降沿触发有效
	EX1=1;
	IT1=1;
	PX0=0;
	  PX1=1;	
	
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
void INIT_0(void) interrupt 0
{
	
	unsigned char c;
	for(c=0;c<3;c++)
	{
		P1 = 0x00;          
		mDelay(500);
		P1 = ~P1;          
		mDelay(500);
	}
	
}


void INIT_1(void) interrupt 2
{
	
	unsigned char c;
	for(c=0;c<3;c++)
	{
		P1 = 0xf0;          
		mDelay(500);
		P1 = ~P1;          
		mDelay(500);
	}
	
}



