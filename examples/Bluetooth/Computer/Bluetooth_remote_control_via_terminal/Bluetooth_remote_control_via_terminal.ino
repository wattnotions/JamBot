#include <SoftwareSerial.h>

SoftwareSerial btSerial(A3,A2); // RX, TX

int pwm;

void setup() {
   
  // Digital outputs for left motor
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);

  // Digital outputs for right motor
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);

  Serial.begin(9600);
  btSerial.begin(9600);

  stop();


}


char cmd;
void loop() {
  
  if (btSerial.available()) {
      cmd =  btSerial.read();
      if (cmd == 'S') { stop(); }
      if (cmd == 'd') { turn_right(150,100); }
      if (cmd == 'a') { turn_left(150,100); }
      if (cmd == 'w') { forward(500,100); }
      if (cmd == 's') { reverse(500,100); }
      
      Serial.println(cmd);
    }
  
  
}


void forward(int ms_delay, int speed){

	set_speed(speed);
	digitalWrite(2, HIGH); // Left motor forward
	digitalWrite(3, LOW);
 
	digitalWrite(A4, HIGH); // Right motor forward
	digitalWrite(A5, LOW);
	delay(ms_delay);
	stop();
}

void turn_left(int ms_delay, int speed){
  
	set_speed(speed);
	digitalWrite(2, LOW); // Left motor reverse
	digitalWrite(3, HIGH);
 
	digitalWrite(A4, HIGH);  // Right motor forward
	digitalWrite(A5, LOW);
	delay(ms_delay);
	stop();
  
}

void turn_right(int ms_delay, int speed){
  
	set_speed(speed);
	digitalWrite(2, HIGH); // Left motor forward
	digitalWrite(3, LOW);
 
	digitalWrite(A4, LOW);  // Right motor reverse
	digitalWrite(A5, HIGH);
	delay(ms_delay);
	stop();
  
}

void reverse(int ms_delay, int speed){
  
	set_speed(speed);
	digitalWrite(2, LOW); // left motor reverse
	digitalWrite(3, HIGH);
  
	digitalWrite(A4, LOW);  // Right motor reverse
	digitalWrite(A5, HIGH);
	delay(ms_delay);
	stop();
}

void stop(){
  digitalWrite(2, LOW); // Left motor stop
  digitalWrite(3, LOW);
  
  digitalWrite(A4, LOW);  // Right motor stop
  digitalWrite(A5, LOW);
}

void set_speed(char speed){
	
	static int scaled_speed;
	scaled_speed = 120 + (speed*13);
	analogWrite(pwm, scaled_speed);
	
}
