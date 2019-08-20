/*
 * RoboJAM! Remote Control LED Example *
 */

#include <SoftwareSerial.h>
#include <robojam.h>

SoftwareSerial btSerial(BLUETOOTH_RX, BLUETOOTH_TX); // RX, TX

void setup() {

  Serial.begin(9600);     //enable Arduino serial link to computer
  btSerial.begin(9600);   //enable software serial connected to hc-06
  
  pinMode(GREEN_LED, OUTPUT);    //set LED pin as output

}



char msg;

void loop() 
{
  
	if (btSerial.available())      //if serial data has been received
	{
		msg =  btSerial.read();    //read the character into the msg variable
		
		if (msg == 'a') 
		{  
			digitalWrite(GREEN_LED, HIGH);
			btSerial.println("LED ON!"); //send message back to phone via hc-06
		}
		else if (msg == 'd')
		{
			digitalWrite(GREEN_LED, LOW);
			btSerial.println("LED OFF!"); //send message back to phone via hc-06
		}
      
		Serial.println(msg);       //print the received character to the serial monitor
	}
  
  
}



