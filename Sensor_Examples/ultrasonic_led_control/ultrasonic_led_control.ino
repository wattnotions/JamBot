/*
 * RoboJAM!
 * Ultrasonic distance sensor function example
 * prints the measured distance in centimeters over the serial port
 */
 
#include <robojam.h>

long distance;
 
void setup() {
  
  //Serial Port begin
  Serial.begin (9600);
  
  //Define inputs and outputs
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  
}

 
void loop() {

	distance = get_distance();
  
	if (distance != 100)
  {
	  analogWrite(LED_PIN, distance*2.5);
  }

  Serial.println(distance);
  delay(50);
}


