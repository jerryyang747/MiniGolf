//Physics Engine
#include <stdint.h>
#include "MiniGolf.h"
#include "ST7735.h"
int a = -10;
void Collide(struct Object obj1, struct Object obj2);
void MoveBall(Ball ball, int speed, int dir){
	ST7735_FillRect(ball.xPos,ball.yPos, ball.width, ball.height, 0x07E0);
	
	
}
void WaterTrap(Ball ball, gameLevel lvl);
void SandTrap(Ball ball, gameLevel lvl);
void InHole(Ball ball, Hole hole);
