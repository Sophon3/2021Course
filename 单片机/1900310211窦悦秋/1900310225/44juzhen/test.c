#include <reg52.h>               

unsigned char  dis_buf;       //��ʾ����
unsigned char  temp;
unsigned char  key=0;         //��˳����

void Delay5Ms(void)
{
    unsigned int TempCyc = 5552;
    while(TempCyc--);
}

// ��ɨ���ӳ���
void  keyscan(void)
 { 
    P1=0xF0;                //����Ϊ���룬����Ϊ����������������ȫΪ0
	 temp=P1;               //��P1��       
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
    P1=0x0F;                 //����Ϊ���룬����Ϊ����������������ȫΪ0  
	 temp=P1;                //��P1�� 
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
    	
     dis_buf = key;	             //��ֵ����ʾ����
     dis_buf = dis_buf&0x0f;
		 P0 = key;
	 if(dis_buf>9)               //ת��ΪASCII��
      dis_buf = dis_buf+0x37;
    else
	   dis_buf = dis_buf+0x30;
 }

/*************************************************************/
//�жϼ��Ƿ���
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
// ������
main()
 {     
    while(1)
    { 
       keydown();
    }
  }   

/************************************************************/  