#include<reg52.h> 
#define uchar unsigned char 	//�궨�壬Ϊ������
#define uint unsigned int
#define DIGI P0 				//�궨�壬��P0�ڶ���Ϊ����ܶ�ѡ�ӿ�
#define SELECT P2 				//�궨�壬��P2����Ϊ�����ѡ���

uint number=0;

uchar digivalue[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7f,0x6f};
//uchar digivalue[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07};
//��ʾ���������飬����Ϊ0��1��..��7
uchar select[]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80}; //ѡ����������飬����ѡ��1��2��..��8

void delay() //�ӳٺ������������������ļ��ʱ��
{ 
	uchar ii=200; //�������������˸���������Ｔ��
	while(ii--);
}

void timer0Init(){
	TMOD=0x01;
	TH0=0xDB;
	TL0=0xFF;
	EA=1;
	ET0=1;
	TR0=1;
}

void display(){
	uchar i=0;
	while(1)       //00310209
	{ 
		for(i=0;i<2;i++) 		//8�������������ʾ
		{
			switch(i)
			{
				case 0:SELECT=select[i]; DIGI=digivalue[number%10];break;
				case 1:SELECT=select[i]; DIGI=digivalue[number/10];break;
				
				
			}
				//ѡ���i�������
			//DIGI=0x90;
			 	//��ʾi
			delay();
		} 
	}
}

main() //������
{
	
	timer0Init();
	display();
}

void time0() interrupt 1
{
	if(number>99){
		number=0;
	}
	number++;
}
