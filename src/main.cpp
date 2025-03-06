#include <Arduino.h>
#include <WiFiMulti.h>

#define WIFI_SSID "mywifi"
#define WIFI_PASSWORD "1234567890"

WiFiMulti wifiMulti;

void setup()
{
  Serial.begin(921600);
  pinMode(LED_BUILTIN, OUTPUT);

  wifiMulti.addAP(WIFI_SSID, WIFI_PASSWORD);

  while (wifiMulti.run() != WL_CONNECTED)
  {
    delay(100);
  }

  Serial.println("Connected");
}

void loop()
{
  digitalWrite(LED_BUILTIN, WiFi.status() == WL_CONNECTED);
}