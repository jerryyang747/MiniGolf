//Physics Engine
#include <stdint.h>
#include "MiniGolf.h"
#include "ST7735.h"
int a = -10;
void Collide(struct Object obj1, struct Object obj2);

//dir is value from 0 to 180
//speed is value from 0-10
int run[180];
int rise[180];
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
