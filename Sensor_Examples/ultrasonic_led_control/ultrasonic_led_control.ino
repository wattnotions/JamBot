/*
 * RoboJAM!
 * Ultrasonic distance sensor function example
 * prints the measured distance in centimeters over the serial port
 */
 
#include <robojam.h>

long distance;
unsigned long previousMillis;
int interval;
bool ledState = 0;
 
void setup() {
  
  //Serial Port begin
  Serial.begin (9600);
  
  //Define inputs and outputs
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  
}

 
void loop() {

	distance = get_distance();
  interval = (distance*5);
  
	unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = 1;
      digitalWrite(GREEN_LED, HIGH);
      digitalWrite(RED_LED  , LOW);
    } else {
      ledState = 0;
      digitalWrite(GREEN_LED, LOW);
      digitalWrite(RED_LED  , HIGH);
    }

   
  }
}


