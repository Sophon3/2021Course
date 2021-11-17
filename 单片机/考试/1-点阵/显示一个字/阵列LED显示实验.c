
/*
***************************************
									LED点阵---循环显示唐
***************************************
*/

#include<reg52.h>

#define uint unsigned int
#define uchar unsigned char
	
uint code Tab[][32] = {
	{0x7f,0xfc,0xFF,0xFC,0x03,0x00,0xF3,0xFC,0x03,0xC0,0xF3,0xCC,0x03,0x00,0xF3,0xCC,
   0x03,0xC0,0xF3,0xFC,0x03,0xC0,0xC3,0xCF,0xC9,0xCF,0xC9,0xCF,0x0C,0xC0,0xCF,0xCF},/*"唐",0*/
};

uint  temp[32];

void delay(uint t)
{
	uchar i;
	for(;t>0;t++)
		for(i = 0;i<2;i++);
}

void main()
{
	uchar i,j,a,b,d;
	uint k;
	for(i=0;i<31;i++)
	{
		temp[i] = Tab[0][i];
	}
	while(1)
	{
		for(i=0;i<16;i++)//循环的次数
		{
			/*
			for(d = 0;d<14;d++)//给存储数组赋值，
			{
				int tax,tay;
				tax = temp[d];
				tay = temp[d+1];
				temp[2*d] = temp[2*d+2];
				temp[2*d+1] = temp[2*d+3];
				temp[30] = tax;
				temp[31] = tay;
			}*/
			for(k=0;k<2;k++)
			{
				P1 = 0; //设置初值
				P3 = 0;
				a = 1;
				b = 1;
				for(j =0;j<16;j++)//扫描点阵
				{
					P0 = temp[j*2];
					P2 = temp[j*2+1];
					if(j < 8)				//前八行设置哪一行显示
					{
						P1 = P1|a;			//当前显示的那一行置高
						delay(1);
						P1 = P1&0;
						a *= 2;
					}
					else					//后八行设置哪一行显示
					{
						P3 = P1|b;			//当前显示的那一行置高
						delay(1);
						P3 = P3&0;
						b *= 2;	
					}
				}
			}
		}
	}
}