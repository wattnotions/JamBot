//
// RoboJAM! example: Turn LED on or off depending on IR value
//

#include <robojam.h>

int ir_val;
 
void setup()
{ 
  Serial.begin(9600);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

}
 
void loop()
{
  // Read the voltage on pin A0 and send it via serial
  
    ir_val = analogRead(IR_PIN);
    Serial.println(ir_val);
    


  if (ir_val > 100)
  {
      digitalWrite(GREEN_LED, HIGH);
      digitalWrite(RED_LED, LOW);
  }
  else
  {
      digitalWrite(GREEN_LED, LOW);
      digitalWrite(RED_LED, HIGH);
  }


  delay(50);
    
}
