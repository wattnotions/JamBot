//
// RoboSlam example: Print IR sensor analog value
//

#include <robojam.h>

int ir_val;

void setup()
{ 
  Serial.begin(9600);
}

void loop()
{
  // Read the voltage coming from the IR Sensor
  
    ir_val = analogRead(IR_PIN);
    Serial.println(ir_val);
    delay(10);
  
}


