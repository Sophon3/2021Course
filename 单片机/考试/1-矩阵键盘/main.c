
/***************************************************************************
实验名称： 矩阵键盘读取实验

***************************************************************************/

#include <reg52.h>               

unsigned char  temp;
unsigned char  key=0;         //键顺序码

sbit  LCM_RS = P2^0; 		  //定义引脚
sbit  LCM_RW = P2^1;
sbit  LCM_E  = P2^2;

#define LCM_Data P0
#define Busy 0x80 //用于检测LCM状态字中的Busy标识
unsigned char Code[]={'1','2','3','10','4','5','6','11','7','8','9','12','14','0','15','13'};

/**********************************************************/
//5ms延时
void Delay5Ms(void)
{
    unsigned int TempCyc = 5552;
    while(TempCyc--);
}

/**********************************************************/
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
    unsigned char m;
    P0=0xFF;                    //置P0口
    P2=0xFF;                    //置P2口  

    while(1)
    { 
       keydown();
		   P0 = key;	//key就是矩阵键盘读出来的值，二进制
    }
  }   

/************************************************************/  