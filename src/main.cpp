#include <Arduino.h>

# define D5 5
# define D1 4

void setup()
{
    Serial.begin(115200);
    pinMode(D1, OUTPUT);
    pinMode(D5,INPUT_PULLUP);
}

void loop()
{
    int output = digitalRead(D5);

    if (output == HIGH)
    {
        Serial.println("High");
        digitalWrite(D1, HIGH);
  }
  else
  {
     Serial.println("Low");
      digitalWrite(D1, LOW);
  }
}

