
//Motor Control Pins
#define LEFT_MOTOR_A  2
#define LEFT_MOTOR_B  3
#define RIGHT_MOTOR_A 4
#define RIGHT_MOTOR_B 5

//Ultrasonic Sensor Pins
#define TRIG_PIN 6
#define ECHO_PIN 7

//Infrared Sensor Pin
#define IR_PIN A0

//PWM Pin
#define PWM_PIN 10

//LED PINs
#define GREEN_LED 11
#define RED_LED   12

//Bluetooth Serial Pins
#define BLUETOOTH_RX A3
#define BLUETOOTH_TX A2



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

void shuffle_left(){
  
  digitalWrite(LEFT_MOTOR_A, LOW); // Left motor reverse
  digitalWrite(LEFT_MOTOR_B, LOW);
  digitalWrite(RIGHT_MOTOR_A, HIGH);  // Right motor forward
  digitalWrite(RIGHT_MOTOR_B, LOW);
  
}
 
void shuffle_right(){
  
  digitalWrite(LEFT_MOTOR_A, HIGH); // Left motor forward
  digitalWrite(LEFT_MOTOR_B, LOW);
  digitalWrite(RIGHT_MOTOR_A, LOW);  // Right motor reverse
  digitalWrite(RIGHT_MOTOR_B, LOW);
  
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

int get_distance()
{

  static long duration, cm;
  
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(5);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  duration = pulseIn(ECHO_PIN, HIGH);
 
  // Convert the time into a distance
  cm = (duration/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
  
  if (cm < 100)
  {
	  return cm;
  }
  else
  {
	  return 100;
  }
}

void set_speed(char scaled_speed)     // takes a value from 1-10 with 1 being lowest and 10 highest speed
{
  static char speed;
  speed = 100+(scaled_speed*15);
  analogWrite(PWM_PIN, speed);
}
