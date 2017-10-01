/**************************************************************
 * IoT Motion Detector with Blynk
 * Blynk library is licensed under MIT license
 * This example code is in public domain.
 * 
 * Developed by Marcelo Rovai - 30 November 2016
 **************************************************************/
#include <ESP8266WiFi.h>

#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <BlynkSimpleEsp8266.h>
char auth[] = "449c8d5bb27e4e7f8ada6a48973a11da";

/* WiFi credentials */
char ssid[] = "test";
char pass[] = "dalepipo";

/* HC-SR501 Motion Detector */
#define ledPin 13 // GPIO13
#define pirPin 5 // Input for PIR GPIO5
int pirValue; // Place to store read PIR Value

void setup()
{
  Serial.begin(115200);
  delay(10);
  Blynk.begin(auth, ssid, pass);
  pinMode(ledPin, OUTPUT);
  pinMode(pirPin, INPUT);
  digitalWrite(ledPin, LOW);
}

void loop()
{
  getPirValue();
  Blynk.run();
}

/***************************************************
 * Get PIR data
 **************************************************/
void getPirValue(void)
{
  pirValue = digitalRead(pirPin);
  if (pirValue) 
  { 
    Serial.println("==> Motion detected");
    Blynk.notify("T==> Motion detected");  
  }
  digitalWrite(ledPin, pirValue);
}
