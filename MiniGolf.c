#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "ST7735.h"
#include "Random.h"
#include "TExaS.h"
#include "ADC.h"
#include "Sound.h"
#include "Sensor.h"
#include "EdgeInterrupt.h"
#include "Physics.h"
//#include "MiniGolf.h"
void PortFInit(void);
void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts
void Delay100ms(uint32_t count); // time delay in 0.1 seconds


// *************************** Images ***************************
// enemy ship that starts at the top of the screen (arms/mouth closed)
// width=16 x height=10

// *************************** Capture image dimensions out of BMP**********
int displayStart(void);
void displayHelp(void);
int getBallWidth(void); int getBallHeight(void); int getBallX(void); int getBallY(void);
void setBallWidth(int set); void setBallHeight(int set); void setBallX(int set); void setBallY(int set);
int state=0;
struct Object {int xPos; int yPos; uint16_t width; uint16_t height;};

typedef struct Object Ball;
typedef const struct Object Tree;
typedef const struct Object Player;
typedef const struct Object Hole;
Ball ball1; 
	
int main(void){
	// setting the original location of the ball should be done with Physics.c file to avoid redudancy (calibration)
	DisableInterrupts();
  TExaS_Init();  // set system clock to 80 MHz
		ADC_Init();
  Random_Init(1);
  Output_Init();

	Sound_Init();
	Buttons_Init();
	Sensor_Init();
	PortFInit();
	EnableInterrupts();
	GPIO_PORTF_DATA_R ^=0x02; //toggle heartbeat
	
	displayHelp();
	
	/*
	switch(displayStart()){
		case 0: startGame();break;
		case 1: selectLevel();break;
		case 2: displayHelp(); break;//Start Screen
	}
	if(help ==1) displayStart();*/
	
	
	//ST7735_DrawBitmap(ball1.xPos, ball1.yPos, ball1.image, ball1.width, ball1.height);
	//ST7735_DrawBitmap(64, 149, ball[], Ball.width,Ball.height);
	GPIO_PORTF_DATA_R ^=0x02; // toggle heartbeat
  
}

int startArray[3] = {8,10,12};
int displayStart(){
	ST7735_SetCursor(4,2);
	ST7735_OutString(" HOLE IN FUN ");
	ST7735_SetCursor(4,3);
	ST7735_OutString(" MINIGOLF!!! ");
	ST7735_SetCursor(4,8);
	ST7735_OutString(" START GAME ");
	ST7735_SetCursor(4,10);
	ST7735_OutString(" LEVEL SELECT ");
	ST7735_SetCursor(4,12);
	ST7735_OutString(" HELP ");
	int index = 0;
	while(1){
		if(PD0){ flag = 0; return index;}
		ST7735_SetCursor(3,startArray[index]);
		ST7735_OutChar(0x3E);
		Delay100ms(100);
		ST7735_SetCursor(3,startArray[index]);
		ST7735_OutChar(0x20);
		Delay100ms(100);
		if(PD1) {flag = 0; index--;} // change index based on button press
		if(PD2) {flag = 0; index++;}
		if(index==-1){index=2;} // circular array
		if(index==3){index=0;}
	}
}

void displayHelp(){
	ST7735_SetCursor(0,0);
	ST7735_OutString("HELP");
	ST7735_SetCursor(0,2);
	ST7735_OutString(" Left button- Swing");
	ST7735_SetCursor(0,4);
	ST7735_OutString(" Slide pot- Power");
	ST7735_SetCursor(0,6);
	ST7735_OutString(" Knob pot- Direction");
	ST7735_SetCursor(0,8);
	ST7735_OutString(" Top button- Options");
	ST7735_SetCursor(0,10);
	ST7735_OutString(" Bottom button- Exit");
	
	ST7735_SetCursor(0,13);
	ST7735_OutString(" Press any button to\n go back.");
	
	while(!(PD0||PD1|PD2)){}
}

// You can use this timer only if you learn how it works

void Delay100ms(uint32_t count){uint32_t volatile time;
  while(count>0){
    time = 70000;  // 0.1sec at 80 MHz
    while(time){
	  	time--;
    }
    count--;
  }
}
int getBallWidth(void)
{
return ball1.width; 
}
int getBallHeight(void){return ball1.height;}
int getBallX(void){return ball1.xPos;}
int getBallY(void){return ball1.yPos;}
void setBallWidth(int set){ball1.width = set;}
void setBallHeight(int set){ball1.height=set;}
void setBallX(int set){ball1.xPos=set;}
void setBallY(int set){ball1.yPos=set;}
void PortFInit(void)
{
	volatile unsigned int delay=0;
	SYSCTL_RCGCGPIO_R|=0x21;
	delay++;
	delay++;
	delay++;
	delay++;
	GPIO_PORTF_DIR_R |=0x02; //PF2
	GPIO_PORTF_AFSEL_R &=0x0;
	GPIO_PORTF_DEN_R |=0x02;
}