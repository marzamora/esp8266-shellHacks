#include "ESP8266WiFi.h"
/* HC-SR501 Motion Detector */
#define ledPin D7 // Red LED
#define pirPin D1 // Input for HC-SR501

int pirValue; // variable to store read PIR Value

void setup() 
{
  pinMode(ledPin, OUTPUT);
  pinMode(pirPin, INPUT);
  digitalWrite(ledPin, LOW);
}

void loop() 
{
  pirValue = digitalRead(pirPin);
  digitalWrite(ledPin, pirValue);
}
