//Physics Engine
#include <stdint.h>
#include "MiniGolf.h"
#include "ST7735.h"
#include "ADC.h"
int a = -10;
void Collide(struct Object obj1, struct Object obj2);
int getSpeed(void);
int getDir(void); 
int Convert(uint32_t input);
int ConvertDir(uint32_t input); 
int run[181] = {1,1,1,1,1, 1,1,1,1,1, 5,5,5,5,5, 3,3,3,3,3, 2,2,2,2,2, 2,2,2,2,2, 3,3,3,3,3, 4,4,4,4,4, 4,4,4,4,4, 1,1,1,1,1, 5,5,5,5,5, 2,2,2,2,2, 1,1,1,1,1, 5,5,5,5,5, 1,1,1,1,1, 2,2,2,2,2, 1,1,1,1,1, 
1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 2,2,2,2,2, 1,1,1,1,1, 5,5,5,5,5, 1,1,1,1,1, 2,2,2,2,2, 5,5,5,5,5, 1,1,1,1,1, 4,4,4,4,4, 4,4,4,4,4, 3,3,3,3,3, 2,2,2,2,2, 2,2,2,2,2, 
3,3,3,3,3, 5,5,5,5,5, -1,-1,-1,-1,-1, -1,-1,-1,-1,-1,-1}; 
int rise[181] = {0,0,0,0,0, 0,0,0,0,0, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 2,2,2,2,2, 3,3,3,3,3, 3,3,3,3,3, 1,1,1,1,1, 6,6,6,6,6, 3,3,3,3,3, 2,2,2,2,2, 
12,12,12,12,12, 3,3,3,3,3, 9,9,9,9,9, 7,7,7,7,7, 10,10,10,10,10, -10,-10,-10,-10, -7,-7,-7,-7,-7, -9,-9,-9,-9,-9, -3,-3,-3,-3,-3, -12,-12,-12,-12,-12, 
-2,-2,-2,-2,-2, -3,-3,-3,-3,-3, -6,-6,-6,-6,-6, -1,-1,-1,-1,-1, -3,-3,-3,-3,-3, -3,-3,-3,-3,-3, -2,-2,-2,-2,-2, -1,-1,-1,-1,-1, -1,-1,-1,-1,-1, -1,-1,-1,-1,-1,
-1,-1,-1,-1,-1, 0,0,0,0,0, 0,0,0,0,0,0};

//dir is value from 0 to 180
//speed is value from 0-10
void MoveBall(Ball ball ){
	//calculate final position
	static int xFinal  = 0;
	static int yFinal = 0;
	int speed = getSpeed();
	int index = getDir();
	int Rise = rise[index]; 
	int Run = run[index]; 
	if(Rise<0) 
	{Run *=-1; Rise*=-1;}
	speed *= 15; //that is the factor t for now
	volatile int x = 0; 
	int ballx =0; 
	int bally = 0; 
	for(x = 0; x<speed; x++)
	{
		ST7735_FillRect(ball.xPos+ballx, ball.yPos+bally, ball.width, ball.height, 0x07E0);
		ballx += Run;
		bally += Rise;
		ST7735_DrawBitmap(ball.xPos+ballx, ball.yPos+bally, ball.image,ball.width,ball.height);
	}
	
	
	//calculate trajectory - lines of slope 0 to infinity (rise over run)
	//while(v !=0){
		//for(int y=0;y<
	
	
}
void WaterTrap(Ball ball, gameLevel lvl);
void SandTrap(Ball ball, gameLevel lvl);
void InHole(Ball ball, Hole hole);
int getSpeed(void)
{
	uint32_t data = Convert(ADC_In()); // get the data from the ADC
	data = 5;//tester 
	return data; 
}
int getDir(void)
	{
		int data = (int)ConvertDir(ADC_In());
		data = 19; //tester
		return data; 
		
		
		
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