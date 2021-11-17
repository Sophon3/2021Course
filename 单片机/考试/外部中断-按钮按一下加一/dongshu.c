#include<reg52.h> 
#define uchar unsigned char 	//宏定义，为方便编程
#define uint unsigned int
#define DIGI P0 				//宏定义，将P0口定义为数码管段选接口
#define SELECT P2 				//宏定义，将P2定义为数码管选择口

uint num22 = 0;
uint number=0;
uint cn=0;
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
	TH0=(65536-45872)/256;
	TL0=(65536-45872)%256;
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
	
IE=10000101;    //p169            
IT0=1;            
IT1=1;            
PX0=0;  //外部中断0为低优先级            
PX1=1;  //外部中断1为高优先级            //高优先级打断低优先级  
	//timer0Init();
	display();
}

void INIT_0(void) interrupt 0       //?D??0     p3.2    高闪低灭,高灭低闪
{    
  number++;
}

/*
void time0() interrupt 1
{
		if(number>99){
			number=0;
		}
		if(cn==20){
		number++;
		cn=0;
		}
		cn++;
}
*/