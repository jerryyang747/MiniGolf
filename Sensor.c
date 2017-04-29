#include "tm4c123gh6pm.h"
#include <stdint.h>
#include "ST7735.h"
#include "Sensor.h"

void Sensor_Init(){
	//Initialize port and periodic timer interrrupt
}
int getDistance(){ 
	int distance = 0;
//	int time = 0;
	//Send signal on TRIG
	//Measure time of echo using timer
	//convert to distance
	return distance;
}

void screenSaver(){
	
	// Store current screen state
	
	int dist = getDistance();
	while(dist >30){
		ST7735_FillScreen(0);
		ST7735_OutString(" SCREEN SAVER MODE ");
	}
	
	// Restore current screen state
	
}
