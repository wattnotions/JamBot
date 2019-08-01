#include <SoftwareSerial.h>

SoftwareSerial btSerial(A3,A2); // RX, TX

#define LEFT_MOTOR_A  2
#define LEFT_MOTOR_B  3
#define RIGHT_MOTOR_A 4
#define RIGHT_MOTOR_B 5


int pwm = 10;



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

  //make built-in LED an output and turn it on
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);

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


void forward(){
 
  digitalWrite(LEFT_MOTOR_A, HIGH); // Left motor forward
  digitalWrite(LEFT_MOTOR_B, LOW);
  digitalWrite(RIGHT_MOTOR_A, HIGH); // Right motor forward
  digitalWrite(RIGHT_MOTOR_B, LOW);
}
 
void turn_left(){
  
  digitalWrite(LEFT_MOTOR_A, LOW); // Left motor reverse
  digitalWrite(LEFT_MOTOR_B, HIGH);
  digitalWrite(RIGHT_MOTOR_A, HIGH);  // Right motor forward
  digitalWrite(RIGHT_MOTOR_B, LOW);
  
}
 
void turn_right(){
  
  digitalWrite(LEFT_MOTOR_A, HIGH); // Left motor forward
  digitalWrite(LEFT_MOTOR_B, LOW);
  digitalWrite(RIGHT_MOTOR_A, LOW);  // Right motor reverse
  digitalWrite(RIGHT_MOTOR_B, HIGH);
  
}
 
void reverse(){
  
  digitalWrite(LEFT_MOTOR_A, LOW); // Left motor reverse
  digitalWrite(LEFT_MOTOR_B, HIGH);
  digitalWrite(RIGHT_MOTOR_A, LOW);  // Right motor reverse
  digitalWrite(RIGHT_MOTOR_B, HIGH);
}
 
void stop(){
  digitalWrite(LEFT_MOTOR_A, LOW); // Left motor stop
  digitalWrite(LEFT_MOTOR_B, LOW);
  digitalWrite(RIGHT_MOTOR_A, LOW);  // Right motor stop
  digitalWrite(RIGHT_MOTOR_B, LOW);
}
 
