/*
 * RoboSlam example: Seek and Destroy Bluetooth Remote Control
 * Intented for used on Slave device
 * Robot will spin around until it receives the character "a" over serial.
 * It will then charge forwards until it hits the white line. It will then reverse and start spinning again
 * 
 */


#include <SoftwareSerial.h>
#include <robojam.h>

SoftwareSerial btSerial(BLUETOOTH_RX, BLUETOOTH_TX); // RX, TX


// The setup routine runs once when the power is switched on.
void setup()
{
  
  
  // Digital outputs for left motor
  pinMode(LEFT_MOTOR_A, OUTPUT);
  pinMode(LEFT_MOTOR_B, OUTPUT);

  // Digital outputs for right motor
  pinMode(RIGHT_MOTOR_A, OUTPUT);
  pinMode(RIGHT_MOTOR_B, OUTPUT);

  //set up pins for ultrasonic control
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  
  //Set up serial ports
  Serial.begin(9600);
  btSerial.begin(9600);


 
 
}

// The loop routine runs over and over until the power is switched off.

int ir_val;
char msg;

void loop()
{
  // Read the voltage from the IR sensor 
  
    ir_val = analogRead(IR_PIN);
  
  // Choose motor action based on IR value
  if (ir_val > 100) //if we are on black
  {
    if (btSerial.available())      //if serial data has been received
    {
         msg =  btSerial.read();    //read the character into the msg variable
    }
    
    if   (msg == "a")              //charge!
    {
      set_speed(10);
      while (ir_val > 100)
      {
        ir_val = analogRead(A0);
        forward();
      }
    }
    
    else                          //no msg received, spin and wait
    {
      set_speed(2);
      turn_right();
    }
    
    
    
    
    
  }
  
  else             //if we are on white
  {

    //go backwards!!
    reverse();
    delay(500);

    //do a turn!!
    turn_right();
    delay(150);
  }
  
}




