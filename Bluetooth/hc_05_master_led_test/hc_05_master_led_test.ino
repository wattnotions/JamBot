/* RoboJAM Master Sample Code
 *  Sends "a" and "d" in a loop
 *  
 */

#include <SoftwareSerial.h>

SoftwareSerial btSerial(A4, A5); // RX, TX


void setup() {
   
  // Digital outputs for built-in LED
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(9600);
  btSerial.begin(9600);

}



void loop() 
{

  btSerial.print("a");
  digitalWrite(LED_BUILTIN,HIGH);
  delay(1000);
  
  btSerial.print("d");
  digitalWrite(LED_BUILTIN,LOW);
  delay(1000);

}
