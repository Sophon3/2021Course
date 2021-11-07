
/***************************************************************************
实验名称： 矩阵键盘读取实验

实验模块:  51单片机核心板、矩阵键盘区、液晶显示区（1602）

实验接线：  51单片机核心板------矩阵键盘区
				P1.0~P1.3 --------- ROW1~ROW4
				P1.4~P1.7 --------- LINE1~LINE4				
					
			
						

更新时间：	2017.10.17
***************************************************************************/

#include <reg52.h>               

unsigned char  dis_buf;       //显示缓存
unsigned char  temp;
unsigned char  key=0;         //键顺序码

sbit  LCM_RS = P2^0; 		  //定义引脚
sbit  LCM_RW = P2^1;
sbit  LCM_E  = P2^2;

#define uchar unsigned char 	//宏定义，为方便编程
#define uint unsigned int
#define DIGI P0 				//宏定义，将P0口定义为数码管段选接口
#define SELECT P2 				//宏定义，将P2定义为数码管选择口




#define LCM_Data P0
#define Busy 0x80 //用于检测LCM状态字中的Busy标识

uchar digivalue[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7f,0x6f};
//uchar digivalue[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07};
//显示的数字数组，依次为0，1，..，7
uchar select[]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80}; //选择数码管数组，依次选择1，2，..，8





void Delay5Ms(void)
{
    unsigned int TempCyc = 5552;
    while(TempCyc--);
}


// 键扫描子程序
void  keyscan(void)
 { 
    P1=0xF0;                //行线为输入，列线为输出，并置列线输出全为0
	 temp=P1;               //读P1口       
    temp=temp&0xF0;
    temp=~((temp>>4)|0xF0);
    if(temp==1)
        key=0;
    else if(temp==2)
        key=1;
    else if(temp==4)
        key=2;
    else if(temp==8)
        key=3;
    P1=0x0F;                 //列线为输入，行线为输出，并置行线输出全为0  
	 temp=P1;                //读P1口 
    temp=temp&0x0F;
    temp=~(temp|0xF0);        
    if(temp==1)
        key=key+0;
    else if(temp==2)
        key=key+4;
    else if(temp==4)
        key=key+8;
    else if(temp==8)
        key=key+12;
    	
     dis_buf = key;	             //键值入显示缓存
     dis_buf = dis_buf&0x0f;

	 if(dis_buf>9)               //转换为ASCII码
      dis_buf = dis_buf+0x37;
    else
	   dis_buf = dis_buf+0x30;
 }

/*************************************************************/
//判断键是否按下
void  keydown(void)
 {  
  	P1=0xF0;
   Delay5Ms();
	if(P1!=0xF0)
	{
	  keyscan();
    }
 }

/*************************************************************/
// 主程序
main()
 {
       while(1){
				keydown();
		   	switch(key)
			  {
					case 0:SELECT= DIGI=digivalue[1];break;
					case 1:SELECT= DIGI=digivalue[3];break;
					case 2:SELECT= DIGI=digivalue[2];break;
					case 3:SELECT= DIGI=digivalue[3];break;
					case 4:SELECT= DIGI=digivalue[4];break;
					case 5:SELECT= DIGI=digivalue[6];break;
					case 6:SELECT= DIGI=digivalue[5];break;
					case 7:SELECT= DIGI=digivalue[8];break;
					case 8:SELECT= DIGI=digivalue[7];break;
					case 9:SELECT= DIGI=digivalue[9];break;
			  }
			 }
  }   

/************************************************************/  