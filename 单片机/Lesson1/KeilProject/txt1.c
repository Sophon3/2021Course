#include <reg51.h>


/**************************
 共阴极流水灯
 -------------------Que
**************************/
void delay(int z)//延时函数
{
	int x,y;
	for(x = 0; x < z; x++)
		for(y = 0; y < 113; y++);
}
void main()
{
	while(1)
	{
		 int i;
	   P1 = 0x01;//初始状态
		 delay(100);
		for(i = 0;i<8;i++)
		{
			P1 = P1<<1;
			delay(100);
		}
	}
}