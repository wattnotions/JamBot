/*
 * RoboJAM!
 * Control the robot using the distance sensor
 * Makes the robot drive forward until it detects an object under 20cm in front of it
 * THen turns to the right until there is a clear path
 * Then goes forward again
 */
int pwmPin = 10;
int trigPin = 6;    // Trigger
int echoPin = 7;    // Echo
long duration;
int cm ;
 
void setup() {
  //Serial Port begin
  Serial.begin (9600);
  
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  //define PWM output pin
   pinMode(pwmPin, OUTPUT);
   set_speed(100);

}
 
void loop() {
  
  
  if (get_distance() > 20)
  {
    set_speed(140);
    forward();
  }
  
  else
  {
    set_speed(140);
    while (get_distance() < 20) 
    {
      turn_right();
    }
  }
  
  
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

