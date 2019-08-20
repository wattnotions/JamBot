/*
 * RoboJAM!
 * Send certain characters depending on which buttons you press
 */

 #include <SoftwareSerial.h>
 #include <robojam.h>

SoftwareSerial btSerial(BLUETOOTH_RX, BLUETOOTH_TX); // RX, TX

long distance;
 
void setup() {
  
  //Serial Ports begin
  Serial.begin (9600);
  btSerial.begin(9600);
  
  //Define inputs and outputs
  pinMode(FORWARD_BUTTON, INPUT_PULLUP);
  pinMode(LEFT_BUTTON   , INPUT_PULLUP);
  pinMode(RIGHT_BUTTON  , INPUT_PULLUP);

}
 
void loop() {


  if (digitalRead(FORWARD_BUTTON) == 1) 
  {
    btSerial.print("f");
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(RED_LED  , HIGH);
  }
  
  else if (digitalRead(RIGHT_BUTTON) == 1) 
  {
    btSerial.print("r");
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(RED_LED  , LOW);
  }
  
  else if(digitalRead(LEFT_BUTTON) == 1) 
  {
    btSerial.print("l");
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RED_LED  , HIGH);
  }

  else
  {
    btSerial.print("s");
  }

  delay(50); //delay for stability

  
}



