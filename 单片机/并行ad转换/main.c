#include <STC89C5xRC.H>
#include "SHOW.H"

sbit START = P2^0;
sbit EOC = P2^1;
sbit OE  = P2^2;
sbit CLK = P2^3;
unsigned char getdata;
unsigned char m_1;
unsigned char m_2;
unsigned char tmp;
unsigned char sum;
unsigned char m_3;

void delay() //延迟函数，决定数码管跳变的间隔时间
{ 
	unsigned char ii=200; //若发现数码管闪烁，调节这里即可
	while(ii--);
}

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


/************************************************/
void main()
{
    init();
    START = 1;       // ST端产生正脉冲
    START = 0;
    while(1)
	{
		tmp=ADC();//输出转换得到的数据
		m_2=sum/10;
		m_1=sum%10;
		show(6,m_2);delay();
		show(5,m_1);delay();
	}
}

