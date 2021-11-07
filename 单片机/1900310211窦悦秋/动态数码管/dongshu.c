#include<reg52.h> 
#define uchar unsigned char 	//宏定义，为方便编程
#define uint unsigned int
#define DIGI P0 				//宏定义，将P0口定义为数码管段选接口
#define SELECT P2 				//宏定义，将P2定义为数码管选择口

uchar digivalue[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7f,0x6f};
//uchar digivalue[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07};
//显示的数字数组，依次为0，1，..，7
uchar select[]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80}; //选择数码管数组，依次选择1，2，..，8

void delay() //延迟函数，决定数码管跳变的间隔时间
{ 
	uchar ii=200; //若发现数码管闪烁，调节这里即可
	while(ii--);
}

main() //主函数
{
	uchar i=0;
	while(1)       //00310209
	{ 
		for(i=0;i<8;i++) 		//8个数码管轮流显示
		{
			switch(i)
			{
				case 0:SELECT=select[i]; DIGI=digivalue[0];break;
				case 1:SELECT=select[i]; DIGI=digivalue[0];break;
				case 2:SELECT=select[i]; DIGI=digivalue[3];break;
				case 3:SELECT=select[i]; DIGI=digivalue[1];break;
				case 4:SELECT=select[i]; DIGI=digivalue[0];break;
				case 5:SELECT=select[i]; DIGI=digivalue[2];break;
				case 6:SELECT=select[i]; DIGI=digivalue[1];break;
				case 7:SELECT=select[i]; DIGI=digivalue[1];break;
			}
				//选择第i个数码管
			//DIGI=0x90;
			 	//显示i
			delay();
		} 
	}
}

