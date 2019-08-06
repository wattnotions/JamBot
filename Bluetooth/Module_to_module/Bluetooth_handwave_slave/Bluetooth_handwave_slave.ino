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
  
  if (btSerial.available()) {
      digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));   //toggle the LED each time a char is received
      cmd =  btSerial.read();
      if (cmd == 'a') { forward(); }
      if (cmd == 'd') { turn_right(); }
      
      Serial.println(cmd);
    }
  
  
}

 
