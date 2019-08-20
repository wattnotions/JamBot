#include <SoftwareSerial.h>
#include <robojam.h>

SoftwareSerial btSerial(BLUETOOTH_RX , BLUETOOTH_TX); // RX, TX

void setup() {

  Serial.begin(9600);
  btSerial.begin(9600);

}



char msg;

void loop() {
  
  if (btSerial.available())      //if serial data has been received
  {
      msg =  btSerial.read();    //read the character into the msg variable
      btSerial.println("Received Character!"); //send received notification back to phone via HC-06
      
      Serial.println(msg);       //print the received character to the serial monitor
  }
  
  
}



