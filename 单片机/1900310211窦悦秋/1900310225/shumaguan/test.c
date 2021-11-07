#include<reg52.h> 
#define uint unsigned int 
#define uchar unsigned char 
#define DIGI P0 				//�궨�壬��P0�ڶ���Ϊ����ܶ�ѡ�ӿ�
#define SELECT P2 			//�궨�壬��P2����Ϊ�����ѡ���
sbit DAT = P1^1;		//����ܽ�P1.1
sbit CLK = P1^0;		//����ܽ�P1.0

uchar code tab[] = {0xfc,0x60,0xda,0xf2,0x66,0xb6,0xbe,0xe0,
					0xff,0xf6,0xee,0x3e,0x9c,0x7a,0x9e,0x8e};      //0-F�����������ʾ��16������

//uchar digivalue[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07};
//��ʾ���������飬����Ϊ0��1��..��7
uchar digivalue[]={0x3F,0x3F,0x4F,0x06,0x3F,0x5B,0x5B,0x6D};
									// 00310225
uchar select[]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80}; 

//��ʱ
 void Delay(uint delay){	
	 uint i;
	 for(;delay > 0;delay--)
		 for(i = 0;i < 110;i++);
}

void sendbyte(uchar byte) 	   	//�����ֽڵĳ���
{     
	uchar num,c;  
	num = tab[byte];		   	//ȡ����
	for(c = 0; c < 8; c++) 		//����8λ����
	{ 
		CLK = 0; 
		DAT = num&0x01; 		//�������λ����
		CLK = 1; 
		num>>=1; 				//��������һλ
	       
	} 
} 

void delay() //�ӳٺ������������������ļ��ʱ��
{ 
	uchar ii=200; //�������������˸���������Ｔ��
	while(ii--);
}

/*
main() 
{  
	unsigned char h; 
	while(1){ 
		for(h = 0; h < 16; h++){   	//���ΰ�tab��16���������ȥ
			Delay(50);				//������ʱ������ʱ50���� 
			sendbyte(h); 	  		//���÷����ֽڵĳ���
			Delay(500);			//������ʱ������ʱ500���� 
		} 
		h = 0; 
	} 
     
} 
*/
main() //������
{
	uchar i=0;
	while(1)
	{ 
		for(i=0;i<8;i++) 		//8�������������ʾ
		{
			SELECT=select[i]; 	//ѡ���i�������
			DIGI=0x90;
			DIGI=digivalue[i]; 	//��ʾi
			delay();
		} 
	}
}

