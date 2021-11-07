#include <STC89C5xRC.H>
#include "SHOW.H"

sbit START = P2^0;
sbit EOC = P2^1;
sbit OE  = P2^2;
sbit CLK = P2^3;
unsigned char getdata;
unsigned char m_1;
unsigned char m_2;
unsigned char tmp;
unsigned char sum;
unsigned char m_3;

void delay() //�ӳٺ������������������ļ��ʱ��
{ 
	unsigned char ii=200; //�������������˸���������Ｔ��
	while(ii--);
}

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


/************************************************/
void main()
{
    init();
    START = 1;       // ST�˲���������
    START = 0;
    while(1)
	{
		tmp=ADC();//���ת���õ�������
		m_2=sum/10;
		m_1=sum%10;
		show(6,m_2);delay();
		show(5,m_1);delay();
	}
}

