#include<reg52.h> 
#define uchar unsigned char 	//�궨�壬Ϊ������
#define uint unsigned int
#define DIGI P0 				//�궨�壬��P0�ڶ���Ϊ����ܶ�ѡ�ӿ�
#define SELECT P2 				//�궨�壬��P2����Ϊ�����ѡ���

uchar digivalue[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7f,0x6f};
//uchar digivalue[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07};
//��ʾ���������飬����Ϊ0��1��..��7
uchar select[]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80}; //ѡ����������飬����ѡ��1��2��..��8

void delay() //�ӳٺ������������������ļ��ʱ��
{ 
	uchar ii=200; //�������������˸���������Ｔ��
	while(ii--);
}

main() //������
{
	uchar i=0;
	while(1)       //00310209
	{ 
		for(i=0;i<8;i++) 		//8�������������ʾ
		{
			switch(i)
			{
				case 0:SELECT=select[i]; DIGI=digivalue[0];break;
				case 1:SELECT=select[i]; DIGI=digivalue[0];break;
				case 2:SELECT=select[i]; DIGI=digivalue[3];break;
				case 3:SELECT=select[i]; DIGI=digivalue[1];break;
				case 4:SELECT=select[i]; DIGI=digivalue[0];break;
				case 5:SELECT=select[i]; DIGI=digivalue[2];break;
				case 6:SELECT=select[i]; DIGI=digivalue[1];break;
				case 7:SELECT=select[i]; DIGI=digivalue[1];break;
			}
				//ѡ���i�������
			//DIGI=0x90;
			 	//��ʾi
			delay();
		} 
	}
}

