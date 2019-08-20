#include <SoftwareSerial.h>
#include <robojam.h>

SoftwareSerial btSerial(A3,A2); // RX, TX



void setup() {
   
  // Digital outputs for left motor
  pinMode(LEFT_MOTOR_A, OUTPUT);
  pinMode(LEFT_MOTOR_B, OUTPUT);

  // Digital outputs for right motor
  pinMode(RIGHT_MOTOR_A, OUTPUT);
  pinMode(RIGHT_MOTOR_B, OUTPUT);
  
  //Initialize Serial ports
  Serial.begin(9600);
  btSerial.begin(9600);

  //make external LED pin an output and turn it on
  pinMode(GREEN_LED, OUTPUT);
  digitalWrite(GREEN_LED, HIGH);

  //Stop motors from turning
  stop();

  


}


char cmd;
void loop() {
  
  if (btSerial.available())
  {
      cmd =  btSerial.read();
      if (cmd == 'f') 
      { 
        stop();
        delay(50);
        forward(); 

        digitalWrite(GREEN_LED, HIGH);
        digitalWrite(RED_LED  , HIGH);
      }
      
      else if (cmd == 'r') 
      { 
        stop();
        delay(50);
        turn_right(); 

        digitalWrite(GREEN_LED, HIGH);
        digitalWrite(RED_LED  , LOW);
      }

      else if (cmd == 'l') 
      { 
        stop();
        delay(50);
        turn_left(); 

        digitalWrite(GREEN_LED, LOW);
        digitalWrite(RED_LED  , HIGH);
      }
      
      else if (cmd == 's') 
      { 
        stop(); 
      }
      
      Serial.println(cmd);
  }

    delay(50); //delay for stability
  
  
}

 
