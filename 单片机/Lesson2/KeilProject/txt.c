#include <reg52.h>
#define uint unsigned int

sbit P11 = P1^1;
sbit P12 = P1^2;
sbit P00 = P0^0;
sbit P20 = P2^0;

int ge[] = { 0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x18};//带小数点0-9
int shi[] = {0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x98};//不带小数点0-9

void delay(uint ms)
{
	uint i,j;
	for(i=0;i<ms;i++)
	{
		for(j=0;j<500;j++)
		{
			
		}
	}
		
	
}
void main()
{
	int i,j;
	while(1)
	{
		P2 =ge[0];
		P0 = shi[0];
		delay(200);
	
		for(i=0;i<=9;i++)
		{
			P0 = shi[i];
			delay(50);
			for(j=0;j<=9;j++)
			{
				P2 = ge[j];
				delay(50);
			}
			
		}
		
		
	}
}