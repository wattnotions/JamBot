/*
 * RoboJAM!
 * Converts your robot into a remote control!
 * Wave your hand in front of the ultrasonic sensor to send the letter "a" 
 * When your hand is removed it send the letter "d"
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
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(GREEN_LED, OUTPUT);

}
 
void loop() {

  distance = get_distance() ;
  
  if (distance < 30)         //hand detected
  {
    digitalWrite(GREEN_LED, HIGH);
    btSerial.print("a");
    while (get_distance() < 30) {}  //wait until hand is removed
    btSerial.print("d");
    
  }
  else
  {
    digitalWrite(GREEN_LED, LOW);
  }

  
}



