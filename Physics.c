//Physics Engine
#include <stdint.h>
#include "MiniGolf.h"
#include "ST7735.h"
int a = -10;
void Collide(struct Object obj1, struct Object obj2);

//dir is value from 0 to 180
//speed is value from 0-10
void MoveBall(Ball ball, int speed, int dir){
	//calculate final position
	static int xFinal  = 0;
	static int yFinal = 0;
	
	ST7735_FillRect(ball.xPos,ball.yPos, ball.width, ball.height, 0x07E0);
	
	//calculate trajectory - lines of slope 0 to infinity (rise over run)
	//while(v !=0){
		//for(int y=0;y<
	ST7735_DrawBitmap(ball.xPos, ball.yPos, ball.image,ball.width,ball.height);
	
}
void WaterTrap(Ball ball, gameLevel lvl);
void SandTrap(Ball ball, gameLevel lvl);
void InHole(Ball ball, Hole hole);
int getSpeed(ADC_In())
{
	uint32_t data = Convert(ADC_In()); // get the data from the ADC
	return data; 
}
int getDir(ADC_In())
	{
		uint32_t data = ADC_In();
		
	}
uint32_t Convert(uint32_t input){ //Convert reading from ADC_In to distance along slide pot
  double slope = 11 * input/4095; 			//y = 0.0046806x+0.093609
	double intercept = 0;		//r = 0.992
	int result = (int) (slope + intercept);
	
	return result;