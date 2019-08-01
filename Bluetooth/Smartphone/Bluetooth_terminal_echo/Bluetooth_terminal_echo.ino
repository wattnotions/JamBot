#include <SoftwareSerial.h>

SoftwareSerial mySerial(A3,A2); // RX, TX

void setup() {

  Serial.begin(9600);
  mySerial.begin(9600);

}



char msg;

void loop() {
  
  if (mySerial.available())      //if serial data has been received
  {
      msg =  mySerial.read();    //read the character into the msg variable
      mySerial.println("Received Character!"); //send received notification back to phone via HC-06
      
      Serial.println(msg);       //print the received character to the serial monitor
  }
  
  
}



