#include <SoftwareSerial.h>

SoftwareSerial btSerial(A3,A2); // RX, TX

int pwm;

void setup() {
   
  // Digital outputs for built-in LED
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(9600);
  btSerial.begin(9600);

}


char cmd;
void loop() {
  
  if (btSerial.available()) {
      cmd =  btSerial.read();
      if (cmd == 'a') { digitalWrite(LED_BUILTIN, HIGH); }
      if (cmd == 'd') { digitalWrite(LED_BUILTIN, LOW ); }
     
      Serial.println(cmd);
    }

}
