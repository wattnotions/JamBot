/*
 * 
 * RoboJAM! 
 * 
 * Set Name of HC-06 Bluetooth Module
 *
 * 
 */


#include <SoftwareSerial.h>

SoftwareSerial btSerial(A3,A2); // RX, TX


#define ROBOT_NAME "TERMINATOR"


void setup() {
  // put your setup code here, to run once:

  btSerial.begin(9600);

  btSerial.print("AT+NAME");
  btSerial.print(ROBOT_NAME);
  btSerial.print("\r\n");
  

}

void loop() {
  // put your main code here, to run repeatedly:

}
