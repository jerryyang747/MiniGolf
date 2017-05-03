#include <stdint.h>
#include "MiniGolf.h"
#include "ST7735.h"
#include "ADC.h"
#define Water 1
#define Sand 2
#define TreeA 3
#define TreeB 4
//int a = -10;
//void Collide(struct Object obj1, struct Object obj2);
int score = 0;
int level = 1;
int getSpeed(void);
int getDir(void); 
int Convert(uint32_t input);
int ConvertDir(uint32_t input); 
void setBall(void);
void showDir(void);
void showSpeed(void);
int BoundX; int BoundY; int BoundWidth; int BoundHeight;
const short run[360] = {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,1, 1, 1, 1, 1, 1, 1, 1, 1,0, 0, 0, 0, 0, 0,-1, -1, -1, -1, -1, -1, -1, -1, -1,-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,-3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3,-4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4,-5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5,-4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4,-3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3,-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,-1, -1, -1, -1, -1, -1, -1, -1, -1,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,1, 1, 1, 1, 1, 1, 1, 1, 1,2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5}; 
const short rise[360] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,-3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3,-4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4,-5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5,-4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4,-3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3,-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,0, 0, 0, 0, 0};
//dir is value from 0 to 180
//speed is value from 0-10
int Collide(int level);
void setBall(void)
{
	setBallX(64);
	setBallY(149);
	setBallWidth(8);
	setBallHeight(8);
	ST7735_DrawBitmap(getBallX(), getBallY(), ball,getBallWidth(),getBallHeight()); // set the ball to  the starting position. 
}
int MoveBall(int level){
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
		volatile int check = Collide(level);
		switch(check)
		{
			case 0: continue;
			case Water: ST7735_FillRect(getBallX()+ballx, getBallY()-bally, getBallWidth(), getBallHeight(), 0x07E0);;
					ST7735_DrawBitmap(getBallX()-ballx, getBallY()+bally, ball,getBallWidth(),getBallHeight());
					return Water; 
			case Sand: speed--; return Sand; 
			case 7: return 1; 
			case TreeA: index+=180;  //fix this for out of bounds
			case TreeB: index+=190;  //fix this for index out of bounds
			
		}
	}
	return 0;
}
int Collide(int level)
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
	switch (level)
	{
		case 1: if((getBallX()<= 100 || getBallX()>=200) || (getBallY()<=100 || getBallY()>=200)) return Water;
		case 2: if((getBallX()<= 100 || getBallX()>=200) || (getBallY()<=100 || getBallY()>=200)) return Water;
		
	}
		return 0;
}

void setBounds (int LevelNumber)
{
	switch (LevelNumber)
	{
		case 1: BoundX = 0; BoundY = 0; BoundWidth = 9; BoundHeight=10;
			//ST7735_drawRect(BoundX, BoundY, BoundWidth, BoundHeight);
	}
}
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
void showDir()
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
void displayData(int lvl);
void displayLevel( int level){
	ST7735_FillScreen(0);
	
	ST7735_DrawBitmap(0,160,game[level-1].image,110,136);
	ST7735_DrawBitmap(15,150,ball,7,7);
	ST7735_DrawBitmap(game[level-1].xTree1,game[level-1].yTree1,tree,12,12);
	ST7735_DrawBitmap(game[level-1].xTree2,game[level-1].yTree2,tree,12,12);
	ST7735_DrawBitmap(game[level-1].xHole,game[level-1].yHole,Hole, 7,14);

	displayData(level);
}

void displayData(int lvl){
	ST7735_SetCursor(0,0);
	ST7735_OutString("STROKES: ");
	ST7735_SetCursor(9,0);
	ST7735_OutChar(0x30+score); //max number of strokes is 9
	
	ST7735_SetCursor(14,0);
	ST7735_OutString("HOLE: ");
	LCD_OutDec(game[lvl-1].lvlNum);
	
	ST7735_SetCursor(0,1);
	ST7735_OutString("PAR: ");
	ST7735_SetCursor(5,1);
	ST7735_OutChar(0x30+game[lvl-1].par);
	
	ST7735_SetCursor(14,14);
	ST7735_OutString("OPTIONS");
	ST7735_SetCursor(17,15);
	ST7735_OutString("EXIT");
	
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
