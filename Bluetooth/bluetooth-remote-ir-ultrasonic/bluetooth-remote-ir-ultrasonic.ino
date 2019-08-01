#include <SoftwareSerial.h>

SoftwareSerial mySerial(4,5); // RX, TX

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
  
  mySerial.begin(115200);
  Serial.begin(115200);

  stop();


}


char cmd;
void loop() {
  
  if (mySerial.available()) {
      cmd =  mySerial.read();
      if (cmd == 'S') { stop(); }
      if (cmd == 'R') { turn_right(); }
      if (cmd == 'L') { turn_left(); }
      if (cmd == 'F') { forward(); }
      if (cmd == 'B') { reverse(); }
      if (cmd == 'X') { ir_control(); }
      if (cmd == 'V') { ultrasonic_control(); }
      
      Serial.println(cmd);
    }
  
  
}


void forward(){

  digitalWrite(2, HIGH); // Left motor forward
  digitalWrite(3, LOW);
  digitalWrite(A4, HIGH); // Right motor forward
  digitalWrite(A5, LOW);
}

void turn_left(){
  
  digitalWrite(2, LOW); // Left motor reverse
  digitalWrite(3, HIGH);
  digitalWrite(A4, HIGH);  // Right motor forward
  digitalWrite(A5, LOW);
  
}

void turn_right(){
  
  digitalWrite(2, HIGH); // Left motor forward
  digitalWrite(3, LOW);
  digitalWrite(A4, LOW);  // Right motor reverse
  digitalWrite(A5, HIGH);
  
}

void reverse(){
  
  digitalWrite(2, LOW); // Left motor reverse
  digitalWrite(3, HIGH);
  digitalWrite(A4, LOW);  // Right motor reverse
  digitalWrite(A5, HIGH);
}

void stop(){
  digitalWrite(2, LOW); // Left motor stop
  digitalWrite(3, LOW);
  digitalWrite(A4, LOW);  // Right motor stop
  digitalWrite(A5, LOW);
}

void ir_control(){

  while (mySerial.available() == 0) {
  
    // Read the voltage on pin A0 (the colour sensor voltage)
    
      colour = analogRead(A0);
      Serial.println(colour);
    
    // Choose motor action based on colour reading
    if (colour > 100)
    {
      // black detected
      digitalWrite(13, LOW);  // LED off
  
      //Full steam ahead!!!
      delay(100);
      forward();
    }
    else
    {
      // white detected
      digitalWrite(13, HIGH); // LED on
  
      //go backwards!!
      reverse();
      delay(500);
  
      //do a turn!!
      turn_right();
      delay(150);
    }
  }

  stop();
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

void ultrasonic_control() {
  while (mySerial.available() == 0) {
  
    if (get_distance() > 20){
      set_speed(140);
      forward();
    }
    else {
      set_speed(140);
      while (get_distance() < 20) {
        reverse();
        delay(500);
        turn_right();
        delay(150);
      }
    }
  }
  stop();
}
