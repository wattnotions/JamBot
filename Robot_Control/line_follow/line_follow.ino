//
// RoboSlam example: Colour sensor control
//

#define LEFT_MOTOR_A  2
#define LEFT_MOTOR_B  3
#define RIGHT_MOTOR_A 4
#define RIGHT_MOTOR_B 5

// Declare an integer variable to store the colour readings
int colour;

// The setup routine runs once when the power is switched on.
void setup()
{
  // Digital output for LED
  pinMode(2, OUTPUT);

  // Digital outputs for left motor
  pinMode(LEFT_MOTOR_A, OUTPUT);
  pinMode(LEFT_MOTOR_B, OUTPUT);

  // Digital outputs for right motor
  pinMode(RIGHT_MOTOR_A, OUTPUT);
  pinMode(RIGHT_MOTOR_B, OUTPUT);
    
  // Open serial port to display colour readings on screen
  Serial.begin(9600);

  analogWrite(10, 140);
}

// The loop routine runs over and over until the power is switched off.
void loop()
{
  // Read the voltage on pin A0 (the colour sensor voltage)
  colour = analogRead(A0);

  // Print the colour value via the serial port
  Serial.println(colour);
  
  // Choose motor action based on colour reading
  if (colour > 100)
  {
    // black detected
    digitalWrite(2, LOW);  // LED off
    turn_right();
  }
  else
  {
    // white detected
    digitalWrite(2, HIGH); // LED on
    turn_left();
  }
}


 
void turn_left(){
  
  digitalWrite(LEFT_MOTOR_A, LOW); // Left motor reverse
  digitalWrite(LEFT_MOTOR_B, LOW);
  digitalWrite(RIGHT_MOTOR_A, HIGH);  // Right motor forward
  digitalWrite(RIGHT_MOTOR_B, LOW);
  
}
 
void turn_right(){
  
  digitalWrite(LEFT_MOTOR_A, HIGH); // Left motor forward
  digitalWrite(LEFT_MOTOR_B, LOW);
  digitalWrite(RIGHT_MOTOR_A, LOW);  // Right motor reverse
  digitalWrite(RIGHT_MOTOR_B, LOW);
  
}
 

