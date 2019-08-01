/*
 * RoboJAM!
 * Ultrasonic distance sensor function example
 * prints the measured distance in centimeters over the serial port
 */
 
int trigPin = 6;    // Trigger
int echoPin = 7;    // Echo
int ledPin = 11;
long duration, cm, distance;
 
void setup() {
  //Serial Port begin
  Serial.begin (9600);
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(ledPin, OUTPUT);
}
 
void loop() {
	
	distance = get_distance();
	if (distance != 100)
  {
	  analogWrite(ledPin, distance*2.5);
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
