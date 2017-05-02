//Physics Engine
#include <stdint.h>
#include "MiniGolf.h"
#include "ST7735.h"
#include "ADC.h"
#define Water 1
#define Sand 2
#define TreeA 3
#define TreeB 4
//#include <cmath.h>
//int a = -10;
//void Collide(struct Object obj1, struct Object obj2);
int getSpeed(void);
int getDir(void); 
int Convert(uint32_t input);
int ConvertDir(uint32_t input); 
void setBall(void);
void showDir(void);
void showSpeed(void);
int BoundX; int BoundY; int BoundWidth; int BoundHeight;
int Collide(void);
short run[360] = {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 
3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
1, 1, 1, 1, 1, 1, 1, 1, 1,
0, 0, 0, 0, 0, 0,
-1, -1, -1, -1, -1, -1, -1, -1, -1,
-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
-3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3,
-4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4,
-5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5,
-4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4,
-3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3,
-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
-1, -1, -1, -1, -1, -1, -1, -1, -1,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
1, 1, 1, 1, 1, 1, 1, 1, 1,
2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5}; 
short rise[360] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
-3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3,
-4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4,
-5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5,
-4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4,
-3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3,
-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
0, 0, 0, 0, 0};

//dir is value from 0 to 180
//speed is value from 0-10
void setBall(void)
{
	setBallX(64);
	setBallY(149);
	setBallWidth(35);
	setBallHeight(16);
	ST7735_DrawBitmap(getBallX(), getBallY(), ball,getBallWidth(),getBallHeight()); // set the ball to  the starting position. 
}
int MoveBall(void){
	// make sure to return 1 if the collide results with hole to increase the levelnumber!
	//int speed = getSpeed();
	//int index = getDir();
	int index = 19;// tester
	int speed = 7; // tester
	int Rise = rise[index]; 
	int Run = run[index]; 
	speed *= 1; //that is the factor t for now
	volatile int x = 0; 
	int ballx =0; 
	int bally = 0; 
	for(x = 0; x<speed; x++)
	{
		ST7735_FillRect(getBallX()+ballx, getBallY()-bally, getBallWidth(), getBallHeight(), 0x07E0);
		ballx += Run;
		bally += Rise;
		ST7735_DrawBitmap(getBallX()+ballx, getBallY()-bally, ball,getBallWidth(),getBallHeight());
		Delay100ms(1);
		volatile int check = Collide();
		switch(check)
		{
			case 0: continue;
			case Water: return Water; 
			case Sand: speed--; return Sand; 
			case 7: return 1; 
			case TreeA: index+=180;  //fix this for out of bounds
			case TreeB: index+=190;  //fix this for index out of bounds
			
		}
	}
	return 0;
}
int Collide()
{
	if((getBallX() >= 14 && getBallX() <=18)&& (getBallY()>=0 && getBallY()<= 5))// tester x and y for the hole since it is constant
			return 7;
	else if ((getBallX() >= getXPos(Water) && getBallX() <=getXPos(Water) + 15) && (getBallY()>=getYPos(Water) && getBallY()<= getYPos(Water) + 15)) // water
	{return Water;}
	else if ((getBallX() >= getXPos(Sand) && getBallX() <=getXPos(Sand) + 15) && (getBallY()>=getYPos(Sand) && getBallY()<= getYPos(Sand) + 15)) //sand
	{return Sand;}
	else if ((getBallX() >= getXPos(TreeA) && getBallX() <=getXPos(TreeA) + 15) && (getBallY()>=getYPos(TreeA) && getBallY()<= getYPos(TreeA) + 15)) // treeA
	{return TreeA;}	
		else if ((getBallX() >= getXPos(TreeB) && getBallX() <=getXPos(TreeB) + 15) && (getBallY()>=getYPos(TreeB) && getBallY()<= getYPos(TreeB) + 15)) //treeB
	{return TreeB;}
	
		return 0;
}
// need to have a setBound for the map in order to check in collide
void setBounds (int LevelNumber)
{
	switch (LevelNumber)
	{
		case 1: BoundX = 0; BoundY = 0; BoundWidth = 9; BoundHeight=10;
			//ST7735_drawRect(BoundX, BoundY, BoundWidth, BoundHeight);
	}
}
		
void showDir(void)
{
	int magnitude = 7; 
	if(magnitude==0){magnitude =1;}
	else if (magnitude >7){magnitude =7;}
	int xPos = getBallX()+13 ;
	int yPos = getBallY()-9;
	int poserx =0;int posery =0;
	int index = 19; // tester
	//ST7735_FillRect(xPos, yPos, 2,2,0x07E0);
	
	ST7735_FillRect(xPos+poserx, yPos-posery, 2,2,0x07E0);
	poserx = (run[index]) *magnitude;
	posery = (rise[index]) * magnitude;
	ST7735_FillRect(xPos+poserx, yPos-posery, 2,2,0x000);
	Delay100ms(1);
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
