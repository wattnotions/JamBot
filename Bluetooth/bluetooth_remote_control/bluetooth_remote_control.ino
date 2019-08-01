#include <SoftwareSerial.h>

SoftwareSerial mySerial(A3,A2); // RX, TX

void setup() {
   
  // Digital outputs for left motor
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);

  // Digital outputs for right motor
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);

  Serial.begin(9600);
  mySerial.begin(9600);

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
