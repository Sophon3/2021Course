/***************************************************************************
ʵ�����ƣ� �ⲿ�ж�ʵ��

ʵ��ģ��:  51��Ƭ�����İ塢����ܡ����뿪�ء��ᴥ������

ʵ����ߣ� 51��Ƭ�����İ�------����ܡ����뿪�ء��ᴥ������

						P1---------J4	
						
						P3.2---------K1
						


����ʱ�䣺2017.10.17
***************************************************************************/


#include<reg52.h>	//��ӿ��ļ�
#include<stdio.h>	
#define uint unsigned int
uint a = 0xFF;

void mDelay(uint Delay)	   //��ʱ
{	
	uint i;
	for(;Delay > 0;Delay--)
	for(i = 0;i < 110;i++);
}

void main(void)
{	
	unsigned char a,i;
	EA=1;
  EX0=1	;//�����ⲿ�ж�0
	IT0 = 1;		//�ⲿ�ж�0�����崥����ʽ���½��ش�����Ч
	EX1=1;
	IT1=1;
	PX0=0;
	  PX1=1;	
	
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



