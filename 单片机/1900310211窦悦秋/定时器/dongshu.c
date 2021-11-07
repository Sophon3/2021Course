#include<reg52.h> 
#define uchar unsigned char 	//宏定义，为方便编程
#define uint unsigned int
#define DIGI P0 				//宏定义，将P0口定义为数码管段选接口
#define SELECT P2 				//宏定义，将P2定义为数码管选择口

uint number=0;

uchar digivalue[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7f,0x6f};
//uchar digivalue[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07};
//显示的数字数组，依次为0，1，..，7
uchar select[]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80}; //选择数码管数组，依次选择1，2，..，8

void delay() //延迟函数，决定数码管跳变的间隔时间
{ 
	uchar ii=200; //若发现数码管闪烁，调节这里即可
	while(ii--);
}

void timer0Init(){
	TMOD=0x01;
	TH0=0xDB;
	TL0=0xFF;
	EA=1;
	ET0=1;
	TR0=1;
}

void display(){
	uchar i=0;
	while(1)       //00310209
	{ 
		for(i=0;i<2;i++) 		//8个数码管轮流显示
		{
			switch(i)
			{
				case 0:SELECT=select[i]; DIGI=digivalue[number%10];break;
				case 1:SELECT=select[i]; DIGI=digivalue[number/10];break;
				
				
			}
				//选择第i个数码管
			//DIGI=0x90;
			 	//显示i
			delay();
		} 
	}
}

main() //主函数
{
	
	timer0Init();
	display();
}

void time0() interrupt 1
{
	if(number>99){
		number=0;
	}
	number++;
}
