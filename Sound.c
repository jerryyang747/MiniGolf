// Sound.c
// Runs on any computer
// Sound assets based off the original Space Invaders 
// Import these constants into your SpaceInvaders.c for sounds!
// Jonathan Valvano
// November 17, 2014
#include <stdint.h>
//#include "Sound.h"
#include "DAC.h"
#include "tm4c123gh6pm.h"

//PLACE ALL SOUND DATA IN HEADER FILES

void Sound_Init(void){
  NVIC_ST_CTRL_R &=0x0;
	NVIC_ST_RELOAD_R = 0;
	NVIC_ST_CURRENT_R = 0;
	NVIC_SYS_PRI3_R = (NVIC_SYS_PRI3_R&0x00FFFFFF)|0x40000000; //Set priority 2
	NVIC_ST_CTRL_R |= 0x7;//Start and arm
	DAC_Init();
};
int prevPeriod = 1;
void Sound_Play(const uint8_t *pt, uint32_t count){
// write this
	NVIC_ST_RELOAD_R = count-1;
	/*if(prevPeriod == period) {
		for(int i=0; i<100;i++){}
		amplitude+=1;}*/
  if(prevPeriod!=count) {//amplitude = 1;}
	prevPeriod = count;
	
		//delay
	//for(int i=0;i<10000;i++){}
}


int val=64;
void SysTick_Handler(void);{//Interrupt service routine
	if( val < 64){
	//	DAC_Out(Flute[val]);
		//DAC_Out(Flute[val]/amplitude);
		val++;
	}
}
};
void Sound_Collide(void){
// write this
};
void Sound_Hole(void){
	
}
void Sound_Water(void){
	
	
}
void Sound_Sand(void){
	
	
	
}
void SysTick_Handler(void){
	
	
}
