/*
 * RoboJAM! Motor Control Functions
 * 
 * The various combinations of pin states have been put into handy
 * functions for you to use in your programs
 */


int pwm = 10;

void setup() {
  // Digital output for PWM
  pinMode(pwm, OUTPUT);
  
  // Digital outputs for left motor
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);

  // Digital outputs for right motor
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);

}

void loop() {
  
	turn_right(2000, 10);  //turn right at half speed for 2 secs
	
  
}

void forward(int ms_delay, int speed){

	set_speed(speed);
	digitalWrite(2, HIGH); // Left motor forward
	digitalWrite(3, LOW);
	digitalWrite(A4, HIGH); // Right motor forward
	digitalWrite(A5, LOW);
	delay(ms_delay);
	stop();
}

void turn_left(int ms_delay, int speed){
  
	set_speed(speed);
	digitalWrite(2, HIGH); // Left motor forward
	digitalWrite(3, LOW);
	digitalWrite(A4, LOW);  // Right motor reverse
	digitalWrite(A5, HIGH);
	delay(ms_delay);
	stop();
  
}

void turn_right(int ms_delay, int speed){
  
	set_speed(speed);
	digitalWrite(2, HIGH); // Left motor forward
	digitalWrite(3, LOW);
	digitalWrite(A4, LOW);  // Right motor reverse
	digitalWrite(A5, HIGH);
	delay(ms_delay);
	stop();
  
}

void reverse(int ms_delay, int speed){
  
	set_speed(speed);
	digitalWrite(2, LOW); // Left motor reverse
	digitalWrite(3, HIGH);
	digitalWrite(A4, LOW);  // Right motor reverse
	digitalWrite(A5, HIGH);
	delay(ms_delay);
	stop();
}

void stop(){
  digitalWrite(2, LOW); // Left motor stop
  digitalWrite(3, LOW);
  digitalWrite(A4, LOW);  // Right motor stop
  digitalWrite(A5, LOW);
}

void set_speed(char speed){
	
	static int scaled_speed;
	scaled_speed = 120 + (speed*13);
	analogWrite(pwm, scaled_speed);
	
}

