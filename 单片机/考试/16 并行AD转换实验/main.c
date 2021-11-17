/***************************************************************************
实验名称： 并行AD转换实验

实验模块:  51单片机核心板、LED示区、并行A/D转换区

实验接线：  51单片机核心板------并行A/D转换区
					 P0   ---------  J36
					 P3.0 --------- START
					 P3.1 ---------	EOC  
					 P3.2 --------- OE 
					 P3.3 --------- ALE
					 
			51单片机核心板------LED示区
					 P1  ---------  J4	
						
现象描述：	转换结果直接以二进制形式在LED上显示。可调节电位器改变输入的模拟量

更新时间：  2017.10.17

p1   digi
p3   select
p0    d1-d7
p2     4
***************************************************************************/

#include <reg52.H>

#define DIGI P1				//宏定义，将1口定义为数码管段选接口
#define SELECT P3 				//宏定义，将P2定义为数码管选择口


sbit START = P2^0;
sbit EOC = P2^1;
sbit OE  = P2^2;
sbit CLK = P2^3;
unsigned char getdata;
unsigned char i=0;

unsigned char m=0;
unsigned char digivalue[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7f,0x6f};
//uchar digivalue[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07};
//显示的数字数组，依次为0，1，..，7
unsigned char select[]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80}; //选择数码管数组，依次选择1，2，..，8
unsigned char xianshi;

/************************************************/
//定时器初始化
void init()
{
        TMOD= 0x03;// 定时器0工作方式3
        TH0 = 0xff;// 定时器0赋初值
        TL0 = 0x00;
        TR0 = 1;
        ET0 = 1;
        EA  = 1;
}

/***********************************************/
//软件延时产生ADC0809的时钟
void clk() interrupt 1
{ 
	
        CLK=(~CLK);
		
	
}


/************************************************/
//AD转换函数
unsigned char ADC()
    {
     char value;
		 START=0; 
		 START=1;      //开始转换命令
		 START=0;
		 while(EOC==0);//等待转换结束
		 OE=1;
		 value=P0;
		 OE=0;
         return value;
     }


void delay() //延迟函数，决定数码管跳变的间隔时间
{ 
	int ii=500; //若发现数码管闪烁，调节这里即可
	while(ii--);
}
		 
		 
		 
/************************************************/
void main()
{
    init();
    START = 1;       // ST端产生正脉冲
    START = 0;
    while(1)
	{
		

			xianshi=~ADC();//输出转换得到的数据
			xianshi=((xianshi+0.5)/68)*10;
		for(m=0;m<18;m++){
			for(i=0;i<2;i++) 		//8个数码管轮流显示
			{
				switch(i)
				{
					case 0:SELECT=select[i]; DIGI=digivalue[xianshi%10];delay();break;
					case 1:SELECT=select[i]; DIGI=digivalue[(xianshi%100)/10];delay();break;
				 
				}
				delay();
			}
		}
	}
}
