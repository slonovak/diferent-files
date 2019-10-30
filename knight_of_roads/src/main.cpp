#include <Arduino.h>

#define PIN 2+
#define RIGHT A0
#define LEFT A1

long long t = 0;
short int R, L, now = 0, past = 0, v = 1;
char f = 0;

void setup() {
  for(int i = 0; i < 10; i++)
    pinMode(PIN i, OUTPUT);
  pinMode(RIGHT, INPUT);
  pinMode(LEFT, INPUT);
}

void loop() {
  R = analogRead(RIGHT) / 102.4;
  L = analogRead(LEFT) / 102.4;
  if(R > L)
  {
    short int tmp = R;
    R = L;
    L = tmp;
  }
  if(now < R)
  {
    f = 1;
    v = 1;
  }
  else if (now > L)
  {
    f = 2;
    v = -1;
  }
  
  if(millis() - t >= 50)
  {
    switch (f)
    {
    case 1:
      break;
    
    case 2:
      break;

    default:
      break;
    }
  }
}