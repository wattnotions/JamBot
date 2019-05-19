/*
 * RoboJAM! Motor Control Functions
 * 
 * The various combinations of pin states have been put into handy
 * functions for you to use in your programs
 */


int pwm;

void setup() {
  // Digital output for PWM
  pinMode(pwm, OUTPUT);
  analogWrite(pwm, 140);
  
  // Digital outputs for left motor
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);

  // Digital outputs for right motor
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);

}

void loop() {
  
  forward();
  delay(1000);
  reverse();
  delay(1000);
  turn_left();
  delay(1000);
  turn_right();
  delay(1000);
  

}

void forward(){

  digitalWrite(2, HIGH); // Left motor forward
  digitalWrite(3, LOW);
  digitalWrite(A4, HIGH); // Right motor forward
  digitalWrite(A5, LOW);
}

void turn_left(){
  
  digitalWrite(2, HIGH); // Left motor forward
  digitalWrite(3, LOW);
  digitalWrite(A4, LOW);  // Right motor reverse
  digitalWrite(A5, HIGH);
  
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

