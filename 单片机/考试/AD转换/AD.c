

#include <reg52.H>
#define uchar unsigned char 	//宏定义，为方便编程
#define uint unsigned int
uchar showdata[2];
#define DIGI P0 				//宏定义，将P0口定义为数码管段选接口   j6
#define SELECT P3 				//宏定义，将P2定义为数码管选择口  j5

uchar digivalue[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71};
uchar select[]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80}; 
	  uchar a;
    uchar u;

	
void delay() //延迟函数，决定数码管跳变的间隔时间
{ 
	uchar ii=200; //若发现数码管闪烁，
	while(ii--);
}


sbit START = P2^0;
sbit EOC = P2^1;
sbit OE  = P2^2;
sbit CLK = P2^3;

void time1_init()
{
	TMOD|=0x01;
	TH1=0xfc;
	TL1=0x18;
	ET1=1;
	EA=1;
	TR1=1;
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
		 value=P1;
		 OE=0;
     return value;
     }

/***********************************************/
//软件延时产生ADC0809的时钟
void clk() interrupt 1
{ 

  CLK=(~CLK);

}
void time1() interrupt 3
{
	uint i;
	TH1=0xfc;
	TL1=0x18;
	i++;
	if(i==10)
	{
		i=0;
	 
	}

	
}



/************************************************/
void display(uchar num)
{
 uint i;
 
  showdata[0] = digivalue[num%10];
  showdata[1] = digivalue[num/10]|0x80;
  for(i=0;i<2;i++)
	  {
				switch(i)
				{
					case 0:SELECT=select[i];DIGI=0x90;DIGI=showdata[i]; break;
					case 1:SELECT=select[i];DIGI=0x90;DIGI=showdata[i]; break;
				}
       delay();
			}
				/*SELECT=select[i]; 	//选择第i个数码管亮
					DIGI=0x90;
				DIGI=showdata[i]; 	//显示i	*/		

}
/**************************************************/
void main()
{   
uint j;
    init();

		START = 1;       // ST端产生正脉冲
    START = 0;
	 
   	
  while(1)
	{
		
		 a = ADC();
for(j=0;j<100;j++)
		{
     u=((a+0.5)/68)*10;
		display(u);
		}
	
	}
}
