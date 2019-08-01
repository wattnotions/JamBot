/*
 * RoboJAM!
 * Converts your robot into a remote control!
 * Wave your hand in front of the ultrasonic sensor to send the letter "a" 
 * When your hand is removed it send the letter "d"
 */

 #include <SoftwareSerial.h>

SoftwareSerial btSerial(A4,A5); // RX, TX
 
int trigPin = 6;    // Trigger
int echoPin = 7;    // Echo
int ledPin = LED_BUILTIN;
long duration, cm, distance;
 
void setup() {
  //Serial Port begin
  Serial.begin (9600);
  btSerial.begin(9600);

  
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(ledPin, OUTPUT);

  
}
 
void loop() {

  distance = get_distance() ;
  
  if (distance < 30 && distance != 100)         //hand detected
  {
    digitalWrite(ledPin, HIGH);
    btSerial.print("a");
    while (get_distance() < 30) {}  //wait until hand is removed
    btSerial.print("d");
    
  }
  else
  {
    digitalWrite(ledPin, LOW);
  }

  
}

int get_distance() {
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
 
  // Convert the time into a distance
  cm = (duration/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
  
  if (cm < 100)
  {
  return cm;
  }
  else
  {
    return 100;
  }
  
}

