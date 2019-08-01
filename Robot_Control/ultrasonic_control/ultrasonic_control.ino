/*
 * RoboJAM!
 * Control the robot using the distance sensor
 * Makes the robot drive forward until it detects an object under 20cm in front of it
 * THen turns to the right until there is a clear path
 * Then goes forward again
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
  

}
 
void loop() 
{
  
  
  if (get_distance() > 20)
  {
    set_speed(10);
    forward();
  }
  
  else
  {
    set_speed(10);
    while (get_distance() < 20) 
    {
      turn_right();
    }
  }
  
  
}




