
/***************************************************************************
ʵ�����ƣ� ������̶�ȡʵ��

***************************************************************************/

#include <reg52.h>               

unsigned char  temp;
unsigned char  key=0;         //��˳����

sbit  LCM_RS = P2^0; 		  //��������
sbit  LCM_RW = P2^1;
sbit  LCM_E  = P2^2;

#define LCM_Data P0
#define Busy 0x80 //���ڼ��LCM״̬���е�Busy��ʶ
unsigned char Code[]={'1','2','3','10','4','5','6','11','7','8','9','12','14','0','15','13'};

/**********************************************************/
//5ms��ʱ
void Delay5Ms(void)
{
    unsigned int TempCyc = 5552;
    while(TempCyc--);
}

/**********************************************************/
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
    unsigned char m;
    P0=0xFF;                    //��P0��
    P2=0xFF;                    //��P2��  

    while(1)
    { 
       keydown();
		   P0 = key;	//key���Ǿ�����̶�������ֵ��������
    }
  }   

/************************************************************/  