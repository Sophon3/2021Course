/*************************************************************/
/********************* 24 ������̶�ȡʵ�� *******************/
/*************************************************************/
/************************* ���ߣ�XHCH ************************/
/*************************************************************/
/******************* �޸����ڣ�2012��2��3�� ******************/
/*************************************************************/
/***************************************************************************
ʵ�����ƣ� ������̶�ȡʵ��


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
#define DIGI P0 				//�궨�壬��P0�ڶ���Ϊ����ܶ�ѡ�ӿ�
#define SELECT P3 				//�궨�壬��P2����Ϊ�����ѡ���


#define Busy 0x80 //���ڼ��LCM״̬���е�Busy��ʶ

//unsigned char Code[]={'1','2','3','A','4','5','6','B','7','8','9','C','*','0','#','D'};
unsigned char Code[]={1,2,3,10,4,5,6,11,7,8,9,12,14,0,15,13};
// �����������1-f{0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
unsigned char select[]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80}; //ѡ����������飬����ѡ��1��2��..��8
unsigned char digivalue[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
//unsigned char digivalue[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7f,0x6f};

/**********************************************************/
//5ms��ʱ
void Delay5Ms(void)
{
    unsigned int TempCyc = 552;
    while(TempCyc--);
}
void delay() //�ӳٺ������������������ļ��ʱ��
{ 
	unsigned char ii=200; //�������������˸���������Ｔ��
	while(ii--);
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
    unsigned char i,m;
   // P0=0xFF;                    //��P0��
   // P2=0xFF;                    //��P2��  

    while(1)
    { 
       keydown();
			for(i=0;i<1;i++) 		//8�������������ʾ
		{
			delay();
			switch(i)
			{
				
				case 0:SELECT=select[i]; DIGI=digivalue[Code[key]];break;
				//case 1:SELECT=select[i]; DIGI=digivalue[Code[key]/10];break;
				//case 2:SELECT=select[i]; DIGI=digivalue[0];break;
				//case 2:SELECT=select[i]; DIGI=digivalue[number/100];break;
			}
				//ѡ���i�������
			 	//��ʾi
			//delay();
		} 
		delay();
		
		

    }
  }   
