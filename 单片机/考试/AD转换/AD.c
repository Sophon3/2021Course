

#include <reg52.H>
#define uchar unsigned char 	//�궨�壬Ϊ������
#define uint unsigned int
uchar showdata[2];
#define DIGI P0 				//�궨�壬��P0�ڶ���Ϊ����ܶ�ѡ�ӿ�   j6
#define SELECT P3 				//�궨�壬��P2����Ϊ�����ѡ���  j5

uchar digivalue[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71};
uchar select[]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80}; 
	  uchar a;
    uchar u;

	
void delay() //�ӳٺ������������������ļ��ʱ��
{ 
	uchar ii=200; //�������������˸��
	while(ii--);
}


sbit START = P2^0;
sbit EOC = P2^1;
sbit OE  = P2^2;
sbit CLK = P2^3;

void time1_init()
{
	TMOD|=0x01;
	TH1=0xfc;
	TL1=0x18;
	ET1=1;
	EA=1;
	TR1=1;
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
		 value=P1;
		 OE=0;
     return value;
     }

/***********************************************/
//�����ʱ����ADC0809��ʱ��
void clk() interrupt 1
{ 

  CLK=(~CLK);

}
void time1() interrupt 3
{
	uint i;
	TH1=0xfc;
	TL1=0x18;
	i++;
	if(i==10)
	{
		i=0;
	 
	}

	
}



/************************************************/
void display(uchar num)
{
 uint i;
 
  showdata[0] = digivalue[num%10];
  showdata[1] = digivalue[num/10]|0x80;
  for(i=0;i<2;i++)
	  {
				switch(i)
				{
					case 0:SELECT=select[i];DIGI=0x90;DIGI=showdata[i]; break;
					case 1:SELECT=select[i];DIGI=0x90;DIGI=showdata[i]; break;
				}
       delay();
			}
				/*SELECT=select[i]; 	//ѡ���i���������
					DIGI=0x90;
				DIGI=showdata[i]; 	//��ʾi	*/		

}
/**************************************************/
void main()
{   
uint j;
    init();

		START = 1;       // ST�˲���������
    START = 0;
	 
   	
  while(1)
	{
		
		 a = ADC();
for(j=0;j<100;j++)
		{
     u=((a+0.5)/68)*10;
		display(u);
		}
	
	}
}
