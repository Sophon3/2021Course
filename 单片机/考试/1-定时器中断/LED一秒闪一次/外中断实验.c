/***************************************************************************
实验名称： 外部中断实验

实验模块:  51单片机核心板、发光管、拨码开关、轻触开关区

实验接线： 51单片机核心板------发光管、拨码开关、轻触开关区

						P1---------J4	
						
						P3.2---------K1
						
现象描述：按动一下K1，LED按照二进制加的方式熄灭

更新时间：2017.10.17
***************************************************************************/

#include<reg52.h>	//添加库文件
#include<stdio.h>	
#define uint unsigned int
#define uchar unsigned char
uint flag = 0;

void Timer0()//使用定时计数器所做的处理函数，用做定时器
{
	TMOD=0x01;//定时器0，方式1
	TH0=0xFC;//定时1ms的初值
	TL0=0x18;//定时1ms的初值
	ET0=1;//打开定时计数器0使能控制位
	EA=1;//打开总中断
	TR0=1;//打开定时计数器0的启动控制位	
}

void main(void) 
{      
	Timer0();//调用函数
	while(1)
	{
	}		
}
void ledxs()interrupt 1//中断执行内容函数,用定时器0编号为1
{
	static unsigned int i=0;
	TH0=0xFC;//方式1不是自动重装，需要重新装载初值
	TL0=0x18;	
	i++;
	if(i==1000)//让LED灯过1s闪烁
	{
		P0 = 0x00;
	}	
	else if(i==2000)
	{
		P0 = 0xff;
		i=0;
	}
	
}