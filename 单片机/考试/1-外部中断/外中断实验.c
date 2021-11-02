
#include<reg52.h>   
#include<stdio.h>   
#define uint unsigned int 
#define uchar unsigned char 
	uint a = 0xFF; 

void mDelay(uint Delay)   //?óê± 
{   uint i;    
  for(;Delay>0;Delay--)        
     for(i=0;i<110;i++);
} 

void main(void) 
{       
uchar display[9]={0xff,0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};    
uint i;    
//IE = 0x81;         
//IT0 = 1;       
while(1){            
IE=10000101;    //p169            
IT0=1;            
IT1=1;            
PX0=0;  //外部中断0为低优先级            
PX1=1;  //外部中断1为高优先级            //高优先级打断低优先级            
for (i=0; i <= 8; i++) {    //流水灯                
mDelay(500);                
P0=display[i];               
 //mDelay(500);           
 }           
 //i=0;    
} 
}
void INIT_0(void) interrupt 0       //?D??0     p3.2    高闪低灭,高灭低闪
{    
uchar i;
 for(i=0;i<3;i++){       
 mDelay(500);        
P0=0x0f;        
mDelay(500);        
P0=0xf0;    
}
}
 void INIT_1(void) interrupt 2       //?D??1     p3.3    全闪全灭
 {    
uchar i;    
for(i=0;i<3;i++){        
P0=0xff;        
mDelay(500);        
P0=0x00;        
mDelay(500);    
}
 }