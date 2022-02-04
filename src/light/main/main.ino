#include "light.h"

// Const
const int PLOT_NUM = 1;
const int GPIO_IN = 4;
const bool ON = true; 
const bool OFF = false; 
const int HOURS = 60; 
const int RESTART_TICKS = 3; 

Light light(PLOT_NUM, GPIO_IN);
 
void setup()
{
 Serial.begin(9600);
 pinMode(GPIO_IN, OUTPUT);
}

// Recive time in minutes and matein the current status of 
// the light 
void mantein_status(float time){
  
  while(light.get_time() < time){
    // Debug messages
    Serial.print( "STATUS : ");
    Serial.println(light.get_status());
    Serial.print( "TIME: ");
    Serial.println(light.get_time());
      }
  }

// Reset the light(initial) 
void restart(){
  for (int i = 0; i < RESTART_TICKS; i++){
    light.set_status(ON); 
    delay(1000);
    light.set_status(OFF); 
    delay(1000);
  }
 }

void loop()
{

  int on_time = 12 * HOURS;
  int off_time = 12 * HOURS;

  restart(); 
  
  Serial.println("ON/ START/ 12 hours");
  light.set_status(ON); 
  mantein_status(on_time); 

  Serial.println("OFF/ START/ 12 hours");
  light.set_status(OFF); 
  mantein_status(off_time); 
}