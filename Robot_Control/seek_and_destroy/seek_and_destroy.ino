//
// RoboSlam example: Seek and Destroy
//

#include <robojam.h>

// Declare an integer variable to store the ir readings
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

  //set up pins for ultrasonic control
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  
  Serial.begin(9600);

 
 
}

// The loop routine runs over and over until the power is switched off.



void loop()
{
  // Read the voltage on pin A0 (the ir sensor voltage)
  
    ir_val = analogRead(IR_PIN);

    Serial.print("IRVAL = ");
    Serial.println(ir_val);

    Serial.print("sonar = ");
    Serial.println(get_distance());

    
    
  
  // Choose motor action based on colour reading
  if (ir_val > 100) //if we are on black
  {

    set_speed(1);
    if   (get_distance() > 30 ) 
    {
      turn_right();
    }
    else
    {
      set_speed(10);
      while (ir_val > 100)
      {
        ir_val = analogRead(A0);
        forward();
      }
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





