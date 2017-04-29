//Physics Engine
#include <stdint.h>
//#include "MiniGolf.h"
#include "ST7735.h"
int a = -10;
void Collide(struct Object obj1, struct Object obj2);
int run[181];
int rise[181] = {0,0,0,0,0, 12,12,12,12,12, 20,20,20,20,20, 30,30,30,30,30, 41,41,41,41,41, 51,51,51,51,51, 63,63,63,63,63, 75,75,75,75,75, 90,90,90,90,90, 100,100,100,100,100, 129,129,129,129,129, 150,150,150,150,150, 189,189,189,189,189, 235,235,235,235,235, 285,285,285,285,285, 450,450,450,450,450, 712,712,712,712,712, 5729,5729,5729,5729,5729, 
								-5729,-5729,-5729,-5729,-5729, -712,-712,-712,-712,-712, -450,-450,-450,-450,-450, -285,-285,-285,-285,-285, -235,-235,-235,-235,-235, -189,-189,-189,-189,-189, -150,-150,-150,-150,-150, -129,-129,-129,-129,-129, -100,-100,-100,-100,-100, -90,-90,-90,-90,-90, -75,-75,-75,-75,-75, -63,-63,-63,-63,-63, -51,-51,-51,-51,-51, -41,-41,-41,-41,-41, 
								-30,-30,-30,-30,-30, -20,-20,-20,-20,-20, -12,-12,-12,-12,-12, 0,0,0,0,0 };
void ArrayInit(void)
{
	volatile int x = 0; 
	for(x =0; x<=180; x++)
	{
		run[x] = 100; 
	}
	
}
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
int getSpeed(void)
{
	uint32_t data = Convert(ADC_In()); // get the data from the ADC
	return data; 
}
int getDir(void)
	{
		uint32_t data = ADC_In();
		
	}
int Convert(uint32_t input){ //Convert reading from ADC_In to distance along slide pot
  double slope = 11 * input/4095; 			//y = 0.0046806x+0.093609
	double intercept = 0;		//r = 0.992
	int result = (int) (slope + intercept);
	
	return result;}