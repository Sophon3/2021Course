/*
************************************************
                 数码管
************************************************
*/

#include<reg52.h>

#define uchar unsigned char  //宏定义 
#define uint unsigned int
	
// 共阳极数码管1-f{0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e};
// 共阴极数码管1-f{0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
uchar value[] = {0x06,0x6f,0x3f,0x3f,0x4f,0x06,0x3f,0x5b,0x5b,0x4f};//学号1900310223
uchar select[] = {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};//位选

void delay(uchar t) //延时函数
{
	while(t--)
	{
		
	}
}

void display1() //第一种展示方法，显示学号后8位
{
	uchar i;
	for(i=0;i<8;i++)//循环显示8个数字，速度够快时，让人眼错以为同时显示8个数字
	{
		P2 = select[i]; //位选
		P0 = value[i+2]; //段选
		delay(100); 
		P0 = 0x00;  //消影
	}
}

void display2()  //第二种展示方法，循环显示10位学号
{
	uchar i,j,d;
	d = 0;
	while(1)
	{
		for(j=0;j<100;j++) // 第一个循环，显示第一“帧” 
		{
			for(i=0;i<8;i++) //与上方相同
			{
				P2 = select[i];
				P0 = value[i+d]; //移动相应的位置的段选
				delay(100);
				P0 = 0x00;
			}
		}
		d++;		
		if(d==2)// 判断是否恢复初始状态
		{
			d=0;
		}
  }
}
void mian()
{
	while(1)
	{
		display1();//第一种显示方式
		display2();//第二种显示方式
	}
}