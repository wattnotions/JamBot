//
// RoboSlam example: Colour sensor control
//

#include <robojam.h>

// Declare an integer variable to store the colour readings
int ir_val;

// The setup routine runs once when the power is switched on.
void setup()
{
  // Digital output for LED
  pinMode(GREEN_LED, OUTPUT);

  // Digital outputs for left motor
  pinMode(LEFT_MOTOR_A, OUTPUT);
  pinMode(LEFT_MOTOR_B, OUTPUT);

  // Digital outputs for right motor
  pinMode(RIGHT_MOTOR_A, OUTPUT);
  pinMode(RIGHT_MOTOR_B, OUTPUT);
    
  // Open serial port to display colour readings on screen
  Serial.begin(9600);

  set_speed(1);
}

// The loop routine runs over and over until the power is switched off.
void loop()
{
  // Read the voltage on pin A0 (the colour sensor voltage)
  ir_val = analogRead(IR_PIN);

  // Print the colour value via the serial port
  Serial.println(ir_val);
  
  // Choose motor action based on colour reading
  if (ir_val > 100)
  {
    // black detected
    digitalWrite(2, LOW);  // LED off
    shuffle_left();
  }
  else
  {
    // white detected
    digitalWrite(2, HIGH); // LED on
    shuffle_right();
  }
}


 


