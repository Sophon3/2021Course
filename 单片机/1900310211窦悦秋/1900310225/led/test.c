#include<intrins.h>
#include<reg52.h>
#define uchar unsigned char	
#define uint unsigned int
	
void Delay(uint delay){
	uint i;
	for(;delay > 0;delay--)
		for(i = 0;i < 110;i++);
}
// ��ˮ��������
void led1(){
	unsigned char a,i;
		//a = 0xfe;
		P0 =0xfe;
		for(i = 0;i < 8;i++)        //��ˮ��һ��8ֻ��ʵ��1��8ֻ��ˮ�Ƶ�ѭ��
		{

			P0 = _crol_(a,1);     	//ʵ�����
			a = P0;
		
			Delay(100);            //100ms���ӳ�
	}	
}
//��ˮ���ҵ���
void led2(){
	unsigned char a,i;
		a = 0xef;
		for(i = 0;i < 8;i++)        //��ˮ��һ��8ֻ��ʵ��1��8ֻ��ˮ�Ƶ�ѭ��
		{
			P0 = _cror_(a,1);     	//ʵ�����
			a = P0;
			Delay(100);            //100ms���ӳ�
		}
}
void main(void){
	while(1)
	{
		led1();
	}
}