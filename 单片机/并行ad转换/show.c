#include <STC89C5xRC.H>
#define DIGI P0 				//宏定义，将P0口定义为数码管段选接口
#define SELECT P2 				//宏定义，将P2定义为数码管选择口

unsigned char NUM[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7f,0x6f};
unsigned char WEIZ[]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};

void show(unsigned char location,num)
{
   switch(num){
	   case 0:
			 DIGI=NUM[0];break;
		 case 1:
			 DIGI=NUM[1];break; 
		 case 2:
			 DIGI=NUM[2];break;
		 case 3:
			 DIGI=NUM[3];break;
		 case 4:
			 DIGI=NUM[4];break;
		 case 5:
			 DIGI=NUM[5];break;
		 case 6:
			 DIGI=NUM[6];break;
		 case 7:
			 DIGI=NUM[7];break;	
		 case 8:
			 DIGI=NUM[8];break;	
		 case 9:
			 DIGI=NUM[9];break;			 
	 }
	 switch(location){
		  case 1:
			  SELECT=WEIZ[0];break;
			case 2:
				SELECT=WEIZ[1];break;
			case 3:
				SELECT=WEIZ[2];break;
			case 4:
				SELECT=WEIZ[3];break;
			case 5:
				SELECT=WEIZ[4];break;
		  case 6:
				SELECT=WEIZ[5];break;
			case 7:
				SELECT=WEIZ[6];break;
		  case 8:
				SELECT=WEIZ[7];break;
	 }
		 
}