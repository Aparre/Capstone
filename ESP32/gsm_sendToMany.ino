//use arduino uno and GSM SIM900A
#include <SoftwareSerial.h>

SoftwareSerial sim900(7, 8); // RX, TX

// List of phone numbers
String recipients[] = {
  "+639998332435",
  "+639454582962",
  "+639663318560",
  "+639614704497"
};
int totalRecipients = sizeof(recipients) / sizeof(recipients[0]);

void setup() {
  sim900.begin(9600);
  Serial.begin(9600);

  delay(1000);
  Serial.println("Starting SIM900...");

  // Set SMS text mode once
  sim900.println("AT+CMGF=1");
  delay(1000);

  // Send message to all recipients
  for (int i = 0; i < totalRecipients; i++) {
    Serial.print("Sending SMS to ");
    Serial.println(recipients[i]);

    sim900.print("AT+CMGS=\"");
    sim900.print(recipients[i]);
    sim900.println("\"");
    delay(1000);

    sim900.println("Hello! This is a drill, We are testing our thesis"); // Message body
    delay(1000);

    sim900.write(26); // CTRL+Z to send
    delay(5000);      // Wait a few seconds between messages
  }

  Serial.println("All SMS sent!");
}

void loop() {
  // nothing
}

code to send to many
