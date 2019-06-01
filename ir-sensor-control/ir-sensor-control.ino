//
// RoboSlam example: Colour sensor control
//



// Declare an integer variable to store the colour readings
int colour;
int pwm;

// The setup routine runs once when the power is switched on.
void setup()
{
  // Digital output for PWM
  pinMode(pwm, OUTPUT);
  analogWrite(pwm, 140);
  
  // Digital outputs for left motor
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);

  // Digital outputs for right motor
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
  
  Serial.begin(9600);
 
}

// The loop routine runs over and over until the power is switched off.
void loop()
{
  // Read the voltage on pin A0 (the colour sensor voltage)
  
    colour = analogRead(A0);
    Serial.println(colour);
  
  // Choose motor action based on colour reading
  if (colour)
  {
    // black detected
    digitalWrite(13, LOW);  // LED off

    //Full steam ahead!!!
    delay(100);
    forward();
  }
  else
  {
    // white detected
    digitalWrite(13, HIGH); // LED on

    //go backwards!!
    reverse();
    delay(500);

    //do a turn!!
    turn_right();
    delay(150);
  }
}


void forward(){

  digitalWrite(2, HIGH); // Left motor forward
  digitalWrite(3, LOW);
  digitalWrite(A4, HIGH); // Right motor forward
  digitalWrite(A5, LOW);
}

void turn_left(){
  
  digitalWrite(2, LOW); // Left motor reverse
  digitalWrite(3, HIGH);
  digitalWrite(A4, HIGH);  // Right motor forward
  digitalWrite(A5, LOW);
  
}

void turn_right(){
  
  digitalWrite(2, HIGH); // Left motor forward
  digitalWrite(3, LOW);
  digitalWrite(A4, LOW);  // Right motor reverse
  digitalWrite(A5, HIGH);
  
}

void reverse(){
  
  digitalWrite(2, LOW); // Left motor reverse
  digitalWrite(3, HIGH);
  digitalWrite(A4, LOW);  // Right motor reverse
  digitalWrite(A5, HIGH);
}

void stop(){
  digitalWrite(2, LOW); // Left motor stop
  digitalWrite(3, LOW);
  digitalWrite(A4, LOW);  // Right motor stop
  digitalWrite(A5, LOW);
}
