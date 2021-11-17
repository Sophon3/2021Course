/***************************************************************************
ʵ�����ƣ� ����ADת��ʵ��

ʵ��ģ��:  51��Ƭ�����İ塢LEDʾ��������A/Dת����

ʵ����ߣ�  51��Ƭ�����İ�------����A/Dת����
					 P0   ---------  J36
					 P3.0 --------- START
					 P3.1 ---------	EOC  
					 P3.2 --------- OE 
					 P3.3 --------- ALE
					 
			51��Ƭ�����İ�------LEDʾ��
					 P1  ---------  J4	
						
����������	ת�����ֱ���Զ�������ʽ��LED����ʾ���ɵ��ڵ�λ���ı������ģ����

����ʱ�䣺  2017.10.17

p1   digi
p3   select
p0    d1-d7
p2     4
***************************************************************************/

#include <reg52.H>

#define DIGI P1				//�궨�壬��1�ڶ���Ϊ����ܶ�ѡ�ӿ�
#define SELECT P3 				//�궨�壬��P2����Ϊ�����ѡ���


sbit START = P2^0;
sbit EOC = P2^1;
sbit OE  = P2^2;
sbit CLK = P2^3;
unsigned char getdata;
unsigned char i=0;

unsigned char m=0;
unsigned char digivalue[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7f,0x6f};
//uchar digivalue[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07};
//��ʾ���������飬����Ϊ0��1��..��7
unsigned char select[]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80}; //ѡ����������飬����ѡ��1��2��..��8
unsigned char xianshi;

/************************************************/
//��ʱ����ʼ��
void init()
{
        TMOD= 0x03;// ��ʱ��0������ʽ3
        TH0 = 0xff;// ��ʱ��0����ֵ
        TL0 = 0x00;
        TR0 = 1;
        ET0 = 1;
        EA  = 1;
}

/***********************************************/
//�����ʱ����ADC0809��ʱ��
void clk() interrupt 1
{ 
	
        CLK=(~CLK);
		
	
}


/************************************************/
//ADת������
unsigned char ADC()
    {
     char value;
		 START=0; 
		 START=1;      //��ʼת������
		 START=0;
		 while(EOC==0);//�ȴ�ת������
		 OE=1;
		 value=P0;
		 OE=0;
         return value;
     }


void delay() //�ӳٺ������������������ļ��ʱ��
{ 
	int ii=500; //�������������˸���������Ｔ��
	while(ii--);
}
		 
		 
		 
/************************************************/
void main()
{
    init();
    START = 1;       // ST�˲���������
    START = 0;
    while(1)
	{
		

			xianshi=~ADC();//���ת���õ�������
			xianshi=((xianshi+0.5)/68)*10;
		for(m=0;m<18;m++){
			for(i=0;i<2;i++) 		//8�������������ʾ
			{
				switch(i)
				{
					case 0:SELECT=select[i]; DIGI=digivalue[xianshi%10];delay();break;
					case 1:SELECT=select[i]; DIGI=digivalue[(xianshi%100)/10];delay();break;
				 
				}
				delay();
			}
		}
	}
}
