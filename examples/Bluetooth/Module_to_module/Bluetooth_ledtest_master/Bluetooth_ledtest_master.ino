/* RoboJAM Master Sample Code
 *  Sends "a" and "d" in a loop
 *  
 */

#include <SoftwareSerial.h>
#include <robojam.h>

SoftwareSerial btSerial(BLUETOOTH_RX, BLUETOOTH_TX); // RX, TX


void setup() {
   
  // Digital outputs for built-in LED
  pinMode(GREEN_LED, OUTPUT);

  Serial.begin(9600);
  btSerial.begin(9600);

}



void loop() 
{

  btSerial.print("a");
  digitalWrite(GREEN_LED,HIGH);
  delay(1000);
  
  btSerial.print("d");
  digitalWrite(GREEN_LED,LOW);
  delay(1000);

}
