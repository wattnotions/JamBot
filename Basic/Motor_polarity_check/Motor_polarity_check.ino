/*
 * RoboJAM! Motor Polarity Check - Both Motors should turn forwards, if not, swap the purple wires!
 */

#include <robojam.h>

void setup() {
  
  
   // Digital outputs for left motor
  pinMode(LEFT_MOTOR_A, OUTPUT);
  pinMode(LEFT_MOTOR_B, OUTPUT);

  // Digital outputs for right motor
  pinMode(RIGHT_MOTOR_A, OUTPUT);
  pinMode(RIGHT_MOTOR_B, OUTPUT);


  forward();

}

void loop() {
  
  
}
