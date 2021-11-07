#include<reg52.h> 
#define uint unsigned int 
#define uchar unsigned char 
#define DIGI P0 				//宏定义，将P0口定义为数码管段选接口
#define SELECT P2 			//宏定义，将P2定义为数码管选择口
sbit DAT = P1^1;		//定义管脚P1.1
sbit CLK = P1^0;		//定义管脚P1.0

uchar code tab[] = {0xfc,0x60,0xda,0xf2,0x66,0xb6,0xbe,0xe0,
					0xff,0xf6,0xee,0x3e,0x9c,0x7a,0x9e,0x8e};      //0-F在数码管上显示的16进制数

//uchar digivalue[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07};
//显示的数字数组，依次为0，1，..，7
uchar digivalue[]={0x3F,0x3F,0x4F,0x06,0x3F,0x5B,0x5B,0x6D};
									// 00310225
uchar select[]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80}; 

//延时
 void Delay(uint delay){	
	 uint i;
	 for(;delay > 0;delay--)
		 for(i = 0;i < 110;i++);
}

void sendbyte(uchar byte) 	   	//发送字节的程序
{     
	uchar num,c;  
	num = tab[byte];		   	//取段码
	for(c = 0; c < 8; c++) 		//发送8位段码
	{ 
		CLK = 0; 
		DAT = num&0x01; 		//发送最低位数据
		CLK = 1; 
		num>>=1; 				//数据右移一位
	       
	} 
} 

void delay() //延迟函数，决定数码管跳变的间隔时间
{ 
	uchar ii=200; //若发现数码管闪烁，调节这里即可
	while(ii--);
}

/*
main() 
{  
	unsigned char h; 
	while(1){ 
		for(h = 0; h < 16; h++){   	//依次把tab中16个数输入进去
			Delay(50);				//调用延时程序，延时50毫秒 
			sendbyte(h); 	  		//调用发送字节的程序
			Delay(500);			//调用延时程序，延时500毫秒 
		} 
		h = 0; 
	} 
     
} 
*/
main() //主函数
{
	uchar i=0;
	while(1)
	{ 
		for(i=0;i<8;i++) 		//8个数码管轮流显示
		{
			SELECT=select[i]; 	//选择第i个数码管
			DIGI=0x90;
			DIGI=digivalue[i]; 	//显示i
			delay();
		} 
	}
}

