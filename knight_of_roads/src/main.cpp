#include <Arduino.h>

#define PIN 2+
#define RIGHT A0
#define LEFT A1

long long t = 0;
int R, L;
short int v = 1;
int now = 0;

void setup() {
  for(int i = 0; i < 10; i++)
    pinMode(PIN i, OUTPUT);
  pinMode(RIGHT, INPUT);
  pinMode(LEFT, INPUT);
}

void loop() {
  R = analogRead(RIGHT);
  L = analogRead(LEFT);
  if(millis() - t >= 50)
  {

  }
}