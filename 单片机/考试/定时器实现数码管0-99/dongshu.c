/***************************************************************************
ʵ�����ƣ� ����ܶ�̬ɨ��ʵ��

ʵ��ģ��:  51��Ƭ�����İ塢��̬ɨ���������

ʵ����ߣ�  51��Ƭ�����İ�------��̬ɨ���������
					P0----------------J6
					P2----------------J5
						
����������	8λ����ܴ�������������ʾ��0~7��

����ʱ�䣺2017.10.17
***************************************************************************/

#include<reg52.h> 
#define uchar unsigned char 	//�궨�壬Ϊ������
#define uint unsigned int
#define DIGI P0 				//�궨�壬��P0�ڶ���Ϊ����ܶ�ѡ�ӿ�
#define SELECT P2 				//�궨�壬��P2����Ϊ�����ѡ���

uint number=0;
uint cn=0;
uchar digivalue[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7f,0x6f};
// �����������1-f{0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
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
	TH0=(65536-45872)/256;
	TL0=(65536-45872)%256;
	EA=1;
	ET0=1;
	TR0=1;
}

void display(){
	uchar i=0;
	while(1)       //00310209
	{ 
		for(i=0;i<3;i++) 		//8�������������ʾ
		{
			switch(i)
			{
				case 0:SELECT=select[i]; DIGI=digivalue[number%10];break;
				case 1:SELECT=select[i]; DIGI=digivalue[number/10%10];break;
				case 2:SELECT=select[i]; DIGI=digivalue[number/100];break;
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
		if(number>999){
			number=0;
		}
		if(cn==20){
		number++;
		cn=0;
		}
		cn++;
}
