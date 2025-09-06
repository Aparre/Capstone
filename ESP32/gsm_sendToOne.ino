#include <SoftwareSerial.h>

SoftwareSerial sim900(7, 8); // RX, TX

void setup() {
  sim900.begin(9600);
  Serial.begin(9600);

  delay(1000);
  Serial.println("Starting SIM900...");

  sim900.println("AT"); // Check communication
  delay(1000);
  
  sim900.println("AT+CMGF=1"); // Set SMS text mode
  delay(1000);

  sim900.println("AT+CMGS=\"+639998332435\""); // Set recipient
  delay(1000);

  sim900.println("Hello! ANDENGGGGGGGGG"); // SMS content
  delay(1000);

  sim900.write(26); // CTRL+Z to send
  delay(1000);

  Serial.println("SMS Sent!");
}

void loop() {
}

code to send to one
