#include <SoftwareSerial.h>

SoftwareSerial mySerial(A3,A2); // RX, TX

int pwmPin = 10;
int trigPin = 6;    // Trigger
int echoPin = 7;    // Echo
long duration;
int cm ;
int colour;

void setup() {
   
  // Digital outputs for left motor
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);

  // Digital outputs for right motor
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);

  //set up pins for ultrasonic control
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  //define PWM output pin
   pinMode(pwmPin, OUTPUT);
   set_speed(150);
  
  mySerial.begin(9600);
  Serial.begin(115200);

  stop();


}


char cmd;
int ir_val;
void loop() {

  ir_val = analogRead(A0);
  
  if (mySerial.available()) {
      cmd =  mySerial.read();
      if (cmd == 'S') { stop(); }
      if (cmd == 'R') { turn_right(100); }
      if (cmd == 'L') { turn_left(100); }
      if (cmd == 'F') { forward(150); }
      if (cmd == 'B') { reverse(150); }
     
      
      Serial.println(cmd);
      
    }

  mySerial.print(ir_val);
  mySerial.print("    ");
  mySerial.println (get_distance());
  delay(100);
  
  
}


void forward(int delay_ms){

  digitalWrite(2, HIGH); // Left motor forward
  digitalWrite(3, LOW);
  digitalWrite(A4, HIGH); // Right motor forward
  digitalWrite(A5, LOW);
  delay(delay_ms);
  stop();
}

void turn_left(int delay_ms){
  
  digitalWrite(2, LOW); // Left motor reverse
  digitalWrite(3, HIGH);
  digitalWrite(A4, HIGH);  // Right motor forward
  digitalWrite(A5, LOW);
  delay(delay_ms);
  stop();
  
}

void turn_right(int delay_ms){
  
  digitalWrite(2, HIGH); // Left motor forward
  digitalWrite(3, LOW);
  digitalWrite(A4, LOW);  // Right motor reverse
  digitalWrite(A5, HIGH);

  delay(delay_ms);

  stop();
  
}

void reverse(int delay_ms){
  
  digitalWrite(2, LOW); // Left motor reverse
  digitalWrite(3, HIGH);
  digitalWrite(A4, LOW);  // Right motor reverse
  digitalWrite(A5, HIGH);
  delay(delay_ms);
  stop();
}

void stop(){
  digitalWrite(2, LOW); // Left motor stop
  digitalWrite(3, LOW);
  digitalWrite(A4, LOW);  // Right motor stop
  digitalWrite(A5, LOW);
}



int get_distance(){
  
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
 
  // Convert the time into a distance
  cm = (duration/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343

  return cm ;
}

void set_speed(char pwm){

  analogWrite(pwmPin, pwm);
}


