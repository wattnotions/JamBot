/*
 * RoboJAM!
 * Ultrasonic distance sensor example
 * prints the measured distance in centimeters over the serial port
 */
 
 #include <robojam.h>
 
void setup() {
  
  //Serial Port begin
  Serial.begin (9600);
  
  //Define inputs and outputs
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}
 
void loop() {

  static long distance;

  distance = get_distance();
  
  if (distance<100){
    Serial.println(distance);
  }

  delay(50);
}

