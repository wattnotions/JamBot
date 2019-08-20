/*
 * RoboJAM!
 * Control the motor speed using ultrasonic distance value
 * The larget the distance value the faster the motors turn
 */

#include <robojam.h>

void setup() {

  // Digital outputs for left motor
  pinMode(LEFT_MOTOR_A, OUTPUT);
  pinMode(LEFT_MOTOR_B, OUTPUT);

  // Digital outputs for right motor
  pinMode(RIGHT_MOTOR_A, OUTPUT);
  pinMode(RIGHT_MOTOR_B, OUTPUT);
  
  //Define inputs and outputs
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  forward();

}
 
void loop() 
{

  static long distance;
  
  distance = get_distance();

  if (distance < 50){
    set_speed(distance/5);
  }
  else {
    set_speed(10);
  }
  
  
  
}




