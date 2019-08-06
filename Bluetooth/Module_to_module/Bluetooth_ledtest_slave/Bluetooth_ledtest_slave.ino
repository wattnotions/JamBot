#include <SoftwareSerial.h>
#include <robojam.h>

SoftwareSerial btSerial(BLUETOOTH_RX, BLUETOOTH_TX); // RX, TX



void setup() {
   
  // Digital outputs for built-in LED
  pinMode(GREEN_LED, OUTPUT);

  Serial.begin(9600);
  btSerial.begin(9600);

}


char cmd;
void loop() {
  
  if (btSerial.available()) {
      cmd =  btSerial.read();
      if (cmd == 'a') { digitalWrite(GREEN_LED, HIGH); }
      if (cmd == 'd') { digitalWrite(GREEN_LED, LOW ); }
     
      Serial.println(cmd);
    }

}
