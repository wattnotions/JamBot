//
// RoboSlam example: Print IR sensor analog value
//

int colour;

void setup()
{ 
  Serial.begin(9600);
 
}

void loop()
{
  // Read the voltage on pin A0 (the colour sensor voltage)
  
    colour = analogRead(A0);
    Serial.println(colour);
    delay(10);
  
}


