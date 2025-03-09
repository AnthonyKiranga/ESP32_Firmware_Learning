#include <Arduino.h>

#define D1 2
/* International Morse Code
H ....
E .
L .-..
O ---

W .--
R .-.
D -..
*/


void dot(bool isLast = false)
{
  digitalWrite(D1, HIGH);
  delay(250);
  digitalWrite(D1, LOW);
  delay(isLast ? 750 : 250);
}

void dash(bool isLast = false) 
{
  digitalWrite(D1, HIGH);
  delay(600);
  digitalWrite(D1, LOW);
  delay(isLast ? 750 : 250);
}

void H()
{
  dot();
  dot();
  dot();
  dot(true);
}

void e() 
{
  dot(true);
}

void l() 
{
  dot();
  dash();
  dot();
  dot(true);
}

void o() 
{
  dash();
  dash();  
  dash(true);
}

void w() 
{
  dot();
  dash();
  dash(true);
}
void r()
 {
  dot();
  dash();
  dot(true);
}

void d()
 { 
  dash();
  dot();
  dot(true);
}

void setup() {
  Serial.begin(115200);
  pinMode(D1, OUTPUT);
}

void loop()
{
  H();
  e();
  l();
  l();
  o();
  delay(1000);
  w();
  o();
  r();
  l();
  d();
  Serial.println("Hello world");
  delay(2000);
}

