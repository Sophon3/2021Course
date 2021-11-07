#include <reg52.h>               

unsigned char  dis_buf;       //显示缓存
unsigned char  temp;
unsigned char  key=0;         //键顺序码

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
		 P0 = key;
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
    while(1)
    { 
       keydown();
    }
  }   

/************************************************************/  