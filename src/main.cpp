#include <Arduino.h>
#include <WiFi.h>

#define WIFI_SSID "mywifi"
#define WIFI_PASSWORD "1234567890"

void setup()
{
  Serial.begin(921600);
  pinMode(LED_BUILTIN, OUTPUT);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  Serial.println("Starting");
}

bool isConnected = false;

void loop()
{
    if(WiFi.status() == WL_CONNECTED && !isConnected)    
    {
        Serial.println("connected");
        digitalWrite(LED_BUILTIN, HIGH);
        isConnected = true;
    }
    if (WiFi.status() != WL_CONNECTED)
    {
      Serial.println(".");
      digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
      delay(1000);
      isConnected = false;      
    }
}