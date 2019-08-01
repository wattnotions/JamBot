#include <SoftwareSerial.h>
#include <robojam.h>

SoftwareSerial btSerial(BLUETOOTH_RX,BLUETOOTH_TX); // RX, TX

char cmd;

void setup() {
   
   // Digital outputs for left motor
  pinMode(LEFT_MOTOR_A, OUTPUT);
  pinMode(LEFT_MOTOR_B, OUTPUT);

  // Digital outputs for right motor
  pinMode(RIGHT_MOTOR_A, OUTPUT);
  pinMode(RIGHT_MOTOR_B, OUTPUT);

  Serial.begin(9600);
  btSerial.begin(9600);

  stop();


}

void loop() {
  
  if (btSerial.available())
  {
      cmd =  btSerial.read();
      if (cmd == 'S') { stop(); }
      if (cmd == 'R') { turn_right(); }
      if (cmd == 'L') { turn_left(); }
      if (cmd == 'F') { forward(); }
      if (cmd == 'B') { reverse(); }
      
      Serial.println(cmd);  
   }
  
  
}



