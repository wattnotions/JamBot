//
// RoboSlam example: IR sensor control
//


#include "robojam.h"

// Declare an integer variable to store the IR readings
int ir_val;


// The setup routine runs once when the power is switched on.
void setup()
{
  
  // Digital outputs for left motor
  pinMode(LEFT_MOTOR_A, OUTPUT);
  pinMode(LEFT_MOTOR_B, OUTPUT);

  // Digital outputs for right motor
  pinMode(RIGHT_MOTOR_A, OUTPUT);
  pinMode(RIGHT_MOTOR_B, OUTPUT);
  
  Serial.begin(9600);
 
}

// The loop routine runs over and over until the power is switched off.
void loop()
{
  // Read the voltage on pin A0 (the IR sensor voltage)
  
    ir_val = analogRead(IR_PIN);
    Serial.println(ir_val);
  
  // Choose motor action based on IR reading
  if (ir_val > 100)
  {
   
    //Full steam ahead!!!
    delay(100);
    forward();
  }
  else if (ir_val < 100 )
  {

    //go backwards!!
    reverse();
    delay(500);

    //do a turn!!
    turn_right();
    delay(150);
  }
}



