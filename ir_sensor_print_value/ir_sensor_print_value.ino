//
// RoboSlam example: Print IR sensor analog value
//


// The setup routine runs once when the power is switched on.
int colour;

void setup()
{ 
  Serial.begin(9600);
 
}

// The loop routine runs over and over until the power is switched off.
void loop()
{
  // Read the voltage on pin A0 (the colour sensor voltage)
  
    colour = analogRead(A0);
    Serial.println(colour);
  
}


