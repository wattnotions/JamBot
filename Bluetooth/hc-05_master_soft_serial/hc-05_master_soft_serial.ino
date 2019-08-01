#include <SoftwareSerial.h>

SoftwareSerial btSerial(A3,A2); // RX, TX

char cmd;

void setup() {
  Serial.begin(9600);
  btSerial.begin(9600);

}

void loop() {
  if (btSerial.available()) {
      cmd =  btSerial.read();
      Serial.print(cmd);

  }

}
