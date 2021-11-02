/***************************************************************************
实验名称： 数码管动态扫描实验

实验模块:  51单片机核心板、动态扫描数码管区

实验接线：  51单片机核心板------动态扫描数码管区
					P0----------------J6
					P2----------------J5
						
现象描述：	8位数码管从左向右依次显示“0~7”

更新时间：2017.10.17
***************************************************************************/


#include<reg52.h> 
#define uchar unsigned char 	//宏定义，为方便编程
#define uint unsigned int
#define DIGI P0 				//宏定义，将P0口定义为数码管段选接口
#define SELECT P2 				//宏定义，将P2定义为数码管选择口

uchar digivalue[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
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
	uint ge = 0;
	uint shi = 0;
	while(1)
	{ 
		for(i=0;i<2;i++) 		//2个数码管轮流显示
		{
			SELECT=select[i]; 	//选择第i个数码管
			DIGI=0x90;
			//DIGI=digivalue[i]; 	//显示i
			if(i==0)
			{
				DIGI=digivalue[ge]; 	//显示i
				ge++;
				if(ge==10)
				{
					ge = 0;
					shi++;
					if(shi == 10)
					{
						shi = 0;
					}
				}
			}
			else if(i==1)
			{
				DIGI=digivalue[shi]; 	//显示i
			}
			delay();
		} 
	}
}

