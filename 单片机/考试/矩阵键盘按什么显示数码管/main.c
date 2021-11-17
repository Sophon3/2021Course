/*************************************************************/
/********************* 24 矩阵键盘读取实验 *******************/
/*************************************************************/
/************************* 作者：XHCH ************************/
/*************************************************************/
/******************* 修改日期：2012年2月3日 ******************/
/*************************************************************/
/***************************************************************************
实验名称： 矩阵键盘读取实验


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
#define DIGI P0 				//宏定义，将P0口定义为数码管段选接口
#define SELECT P3 				//宏定义，将P2定义为数码管选择口


#define Busy 0x80 //用于检测LCM状态字中的Busy标识

//unsigned char Code[]={'1','2','3','A','4','5','6','B','7','8','9','C','*','0','#','D'};
unsigned char Code[]={1,2,3,10,4,5,6,11,7,8,9,12,14,0,15,13};
// 共阴极数码管1-f{0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
unsigned char select[]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80}; //选择数码管数组，依次选择1，2，..，8
unsigned char digivalue[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7f,0x6f};
//unsigned char digivalue[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7f,0x6f};

/**********************************************************/
//5ms延时
void Delay5Ms(void)
{
    unsigned int TempCyc = 552;
    while(TempCyc--);
}
void delay() //延迟函数，决定数码管跳变的间隔时间
{ 
	unsigned char ii=200; //若发现数码管闪烁，调节这里即可
	while(ii--);
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
    unsigned char i,m;
   // P0=0xFF;                    //置P0口
   // P2=0xFF;                    //置P2口  

    while(1)
    { 
       keydown();
			for(i=0;i<2;i++) 		//8个数码管轮流显示
		{
			delay();
			switch(i)
			{
				
				case 0:SELECT=select[i]; DIGI=digivalue[Code[key]%10];break;
				case 1:SELECT=select[i]; DIGI=digivalue[Code[key]/10];break;
				//case 2:SELECT=select[i]; DIGI=digivalue[0];break;
				//case 2:SELECT=select[i]; DIGI=digivalue[number/100];break;
			}
				//选择第i个数码管
			 	//显示i
			//delay();
		} 
		delay();
		
		

    }
  }   
