/*
 * 
 * RoboJAM! Remote Control LED Example
 *
 */


#include <SoftwareSerial.h>

SoftwareSerial btSerial(4,5); // RX, TX

void setup() {

  Serial.begin(9600);     //enable Arduino serial link to computer
  btSerial.begin(9600);   //enable software serial connected to hc-06
  
  pinMode(11, OUTPUT);    //set LED pin as output

}



char msg;

void loop() {
  
	if (btSerial.available())      //if serial data has been received
	{
		msg =  mySerial.read();    //read the character into the msg variable
		
		if (msg == 'a') 
		{  
			digitalWrite(11, HIGH);
			btSerial.println("LED ON!"); //send message back to phone via hc-06
		}
		else if (msg == 'd')
		{
			digitalWrite(11, LOW);
			btSerial.println("LED OFF!"); //send message back to phone via hc-06
		}
      
		Serial.println(msg);       //print the received character to the serial monitor
  }
  
  
}



