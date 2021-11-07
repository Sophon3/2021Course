#include<intrins.h>
#include<reg52.h>
#define uchar unsigned char	
#define uint unsigned int
	
void Delay(uint delay){
	uint i;
	for(;delay > 0;delay--)
		for(i = 0;i < 110;i++);
}
// 流水灯左向右
void led1(){
	unsigned char a,i;
		//a = 0xfe;
		P0 =0xfe;
		for(i = 0;i < 8;i++)        //流水灯一共8只，实现1到8只流水灯的循环
		{

			P0 = _crol_(a,1);     	//实现输出
			a = P0;
		
			Delay(100);            //100ms的延迟
	}	
}
//流水灯右到左
void led2(){
	unsigned char a,i;
		a = 0xef;
		for(i = 0;i < 8;i++)        //流水灯一共8只，实现1到8只流水灯的循环
		{
			P0 = _cror_(a,1);     	//实现输出
			a = P0;
			Delay(100);            //100ms的延迟
		}
}
void main(void){
	while(1)
	{
		led1();
	}
}