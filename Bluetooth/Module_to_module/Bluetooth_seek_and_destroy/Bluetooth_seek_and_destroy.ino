/*
 * RoboSlam example: Seek and Destroy Bluetooth Remote Control
 * Intented for used on Slave device
 * Robot will spin around until it receives the character "a" over serial.
 * It will then charge forwards until it hits the white line. It will then reverse and start spinning again
 * 
 */


#include <SoftwareSerial.h>
SoftwareSerial btSerial(A3,A2); // RX, TX


// Declare an integer variable to store the colour readings
int colour;
int pwm=10;
int trigPin = 6;    // Trigger
int echoPin = 7;    // Echo

long duration, cm ;

// The setup routine runs once when the power is switched on.
void setup()
{
  // Digital output for PWM motor speed control
  pinMode(pwm, OUTPUT);
  analogWrite(pwm, 255);
  
  // Digital outputs for left motor
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);

  // Digital outputs for right motor
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);

  //set up pins for ultrasonic control
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  Serial.begin(9600);
  btSerial.begin(9600);


 
 
}

// The loop routine runs over and over until the power is switched off.

int ir_val;
char msg;

void loop()
{
  // Read the voltage on pin A0 (the ir sensor voltage)
  
    ir_val = analogRead(A0);
  
  // Choose motor action based on colour reading
  if (ir_val > 100) //if we are on black
  {
    if (btSerial.available())      //if serial data has been received
    {
         msg =  btSerial.read();    //read the character into the msg variable
    }
    
    if   (msg == "a")              //charge!
    {
      set_speed(255);
      while (ir_val > 100)
      {
        ir_val = analogRead(A0);
        forward();
      }
    }
    
    else                          //no msg received, spin and wait
    {
      set_speed(100);
      turn_right();
    }
    
    
    
    
    
  }
  else             //if we are on white
  {

    //go backwards!!
    reverse();
    delay(500);

    //do a turn!!
    turn_right();
    delay(150);
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
  duration = pulseIn(echoPin, HIGH);
 
  // Convert the time into a distance
  cm = (duration/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
  return cm ;
}

void set_speed(char speed)
{
  analogWrite(pwm, speed);
}


