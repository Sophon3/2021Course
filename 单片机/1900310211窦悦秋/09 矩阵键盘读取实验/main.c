
/***************************************************************************
ʵ�����ƣ� ������̶�ȡʵ��

ʵ��ģ��:  51��Ƭ�����İ塢�����������Һ����ʾ����1602��

ʵ����ߣ�  51��Ƭ�����İ�------���������
				P1.0~P1.3 --------- ROW1~ROW4
				P1.4~P1.7 --------- LINE1~LINE4				
					
			
						

����ʱ�䣺	2017.10.17
***************************************************************************/

#include <reg52.h>               

unsigned char  dis_buf;       //��ʾ����
unsigned char  temp;
unsigned char  key=0;         //��˳����

sbit  LCM_RS = P2^0; 		  //��������
sbit  LCM_RW = P2^1;
sbit  LCM_E  = P2^2;

#define uchar unsigned char 	//�궨�壬Ϊ������
#define uint unsigned int
#define DIGI P0 				//�궨�壬��P0�ڶ���Ϊ����ܶ�ѡ�ӿ�
#define SELECT P2 				//�궨�壬��P2����Ϊ�����ѡ���




#define LCM_Data P0
#define Busy 0x80 //���ڼ��LCM״̬���е�Busy��ʶ

uchar digivalue[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7f,0x6f};
//uchar digivalue[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07};
//��ʾ���������飬����Ϊ0��1��..��7
uchar select[]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80}; //ѡ����������飬����ѡ��1��2��..��8





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