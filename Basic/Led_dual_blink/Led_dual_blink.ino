/*
 * RoboJAM LED Blink Example
 * Alternates between blinking both LEDs
 * 
 */


void setup() {
  
pinMode(11, OUTPUT);
pinMode(12, OUTPUT);
}

void loop() {
 
  digitalWrite(11, HIGH);
  digitalWrite(12, LOW);
  delay(100);

  digitalWrite(11, LOW);
  digitalWrite(12, HIGH);
  delay(100);

}
