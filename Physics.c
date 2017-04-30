#include <stdint.h>
#include "MiniGolf.h"
#include "ST7735.h"
#include "ADC.h"
//int a = -10;
//void Collide(struct Object obj1, struct Object obj2);
int getSpeed(void);
int getDir(void); 
int Convert(uint32_t input);
int ConvertDir(uint32_t input); 
void setBall(void);
const short run[181] = {-1,-1,-1,1,1, 1,1,1,1,1, 5,5,5,5,5, 3,3,3,3,3, 2,2,2,2,2, 2,2,2,2,2, 3,3,3,3,3, 4,4,4,4,4, 4,4,4,4,4, 1,1,1,1,1, 5,5,5,5,5, 2,2,2,2,2, 1,1,1,1,1, 5,5,5,5,5, 1,1,1,1,1, 2,2,2,2,2, 1,1,1,1,1, 
1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 2,2,2,2,2, 1,1,1,1,1,
	5,5,5,5,5, 1,1,1,1,1, -2,-2,-2,-2,-2, -5,-5,-5,-5,-5, -1,-1,-1,-1,-1, -4,-4,-4,-4,-4, -4,-4,-4,-4,-4, -3,-3,-3,-3,-3, -2,-2,-2,-2,-2, -2,-2,-2,-2,-2, 
-3,-3,-3,-3,-3, -5,-5,-5,-5,-5, -1,-1,-1,-1,-1, -1,-1,-1,-1,-1,-1}; 
const short rise[181] = {0,0,0,0,0, 0,0,0,0,0, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 2,2,2,2,2, 3,3,3,3,3, 3,3,3,3,3, 1,1,1,1,1, 6,6,6,6,6, 3,3,3,3,3, 2,2,2,2,2, 
12,12,12,12,12, 3,3,3,3,3, 9,9,9,9,9, 7,7,7,7,7, 10,10,10,10,10, 10,10,10,10, 7,7,7,7,7, 9,9,9,9,9,3,3,3,3,3,12,12,12,12,12, 
2,2,2,2,2,3,3,3,3,3,6,6,6,6,6,1,1,1,1,1,3,3,3,3,3, 3,3,3,3,3,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1, 0,0,0,0,0, 0,0,0,0,0,0};

//dir is value from 0 to 180
//speed is value from 0-10
void setBall(void)
{
	setBallX(64);
	setBallY(149);
	setBallWidth(8);
	setBallHeight(8);
	ST7735_DrawBitmap(getBallX(), getBallY(), ball,getBallWidth(),getBallHeight()); // set the ball to  the starting position. 
}
void MoveBall(void){
	//calculate final position
	
	//int speed = getSpeed();
	//int index = getDir();
	for(int i=0; i<181; i++){
	int index = i;
	int speed = 7;
	int Rise = rise[index]; 
	int Run = run[index]; 
	speed *= 2; //that is the factor t for now 
	int ballx =0; 
	int bally = 0; 
	for(int x = 0; x<speed; x++)
	{
		ST7735_FillRect(getBallX()+ballx, getBallY()+bally, getBallWidth(), getBallHeight(), 0x07E0);
		ballx -= Run;
		bally -= Rise;
		ST7735_DrawBitmap(getBallX()+ballx, getBallY()+bally, ball,getBallWidth(),getBallHeight());
		Delay100ms(1);
	}
	
}
	
}
//void WaterTrap(Ball ball, gameLevel lvl);
//void SandTrap(Ball ball, gameLevel lvl);
//void InHole(Ball ball, Hole hole);
int getSpeed(void)
{
	uint32_t data = Convert(ADC_In()); // get the data from the ADC

	return data; 
}
int getDir(void)
	{
		int data = (int)ConvertDir(ADC_In());
		return data; 
	}
void showSpeed(void){
		//int magnitude = getSpeed();
		int magnitude = 3;
		int xPos = getBallX() + magnitude + 17;
		int yPos = getBallY() - magnitude - 10;
		ST7735_FillRect(xPos, yPos, 2, 2, 0x0000);
		
	}
void showDir(void)
{
	//int magnitude = 3; //tester
	int xPos = getBallX() + 27;
	int yPos = getBallY() - 9;
	int poserx =0;int posery =0;
	int index = 0; // tester
	//ST7735_FillRect(xPos, yPos, 2,2,0x07E0);
	for(index =0; index<181; index++){
		ST7735_FillRect(xPos+poserx, yPos+posery, 2,2,0x07E0);
	poserx = (run[index]*2);
	posery = (2*rise[index]*-1);
		if(posery>0){
			poserx*=-1;
			poserx-=27;}
	ST7735_FillRect(xPos+poserx, yPos+posery, 2,2,0x000);}
	Delay100ms(1);
}

void displayLevel(){
	ST7735_DrawBitmap(0,160,lvl1,110,136);
	ST7735_DrawBitmap(15,150,ball,7,7);
	ST7735_DrawBitmap(30,80,tree,12,12);
	ST7735_DrawBitmap(70,50,Hole, 7,14);
}






int Convert(uint32_t input){ //Convert reading from ADC_In to distance along slide pot
  double slope = 11 * input/4095; 			//y = 0.0046806x+0.093609
	double intercept = 0;		//r = 0.992
	int result = (int) (slope + intercept);
	
	return result;}
int ConvertDir(uint32_t input)
{
	int slope = 181*input/4095;
	int intercept = 0; 
	int result  = slope +intercept;
return result; 	
}