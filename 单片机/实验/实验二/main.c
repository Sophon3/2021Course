/*
************************************************
                 �����
************************************************
*/

#include<reg52.h>

#define uchar unsigned char  //�궨�� 
#define uint unsigned int
	
// �����������1-f{0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e};
// �����������1-f{0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
uchar value[] = {0x06,0x6f,0x3f,0x3f,0x4f,0x06,0x3f,0x5b,0x5b,0x4f};//ѧ��1900310223
uchar select[] = {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};//λѡ

void delay(uchar t) //��ʱ����
{
	while(t--)
	{
		
	}
}

void display1() //��һ��չʾ��������ʾѧ�ź�8λ
{
	uchar i;
	for(i=0;i<8;i++)//ѭ����ʾ8�����֣��ٶȹ���ʱ�������۴���Ϊͬʱ��ʾ8������
	{
		P2 = select[i]; //λѡ
		P0 = value[i+2]; //��ѡ
		delay(100); 
		P0 = 0x00;  //��Ӱ
	}
}

void display2()  //�ڶ���չʾ������ѭ����ʾ10λѧ��
{
	uchar i,j,d;
	d = 0;
	while(1)
	{
		for(j=0;j<100;j++) // ��һ��ѭ������ʾ��һ��֡�� 
		{
			for(i=0;i<8;i++) //���Ϸ���ͬ
			{
				P2 = select[i];
				P0 = value[i+d]; //�ƶ���Ӧ��λ�õĶ�ѡ
				delay(100);
				P0 = 0x00;
			}
		}
		d++;		
		if(d==2)// �ж��Ƿ�ָ���ʼ״̬
		{
			d=0;
		}
  }
}
void mian()
{
	while(1)
	{
		display1();//��һ����ʾ��ʽ
		display2();//�ڶ�����ʾ��ʽ
	}
}