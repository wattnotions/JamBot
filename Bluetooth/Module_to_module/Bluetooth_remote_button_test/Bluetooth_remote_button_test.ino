/* RoboJAM! Button Read Test
 *  This program prints the values of three buttons connected to pins A1, A2 and A3
 *  Open the serial monitor to look at the values
 */

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(A1, INPUT_PULLUP);
  pinMode(A2, INPUT_PULLUP);
  pinMode(A3, INPUT_PULLUP);
}

// the loop routine runs over and over again forever:
void loop() {
  // print out the state of the buttons:
  
  Serial.print(digitalRead(A1));
  Serial.print("   ");

  Serial.print(digitalRead(A2));
  Serial.print("   ");

  Serial.println(digitalRead(A3));

  
  delay(100);        // delay in between reads for stability
}
