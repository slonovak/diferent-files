#include <Arduino.h>

#define PIN 2+
#define RIGHT A0
#define LEFT A1

long long t = 0;
int delta = 100;
short int R, L, now = 0, past = 0, v = 1;
char f = 0;

void setup() {
  for(int i = 0; i < 10; i++)
    pinMode(PIN i, OUTPUT);
  pinMode(RIGHT, INPUT);
  pinMode(LEFT, INPUT);

  R = analogRead(RIGHT) / 102.4;
  L = analogRead(LEFT) / 102.4;
  if(R > L)
  {
    v = -v;
  }
  now = R;
  past = R;
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
  
  if(millis() - t >= delta)
  {
    switch (f)
    {
    case 1:
      if(now == L)
      {
        f = 3;
        v = -v;
      }
      break;
    
    case 2:
    if(now == R)
      {
        f = 3;
        v = -v;
      }
      break;

    case 3:
    if(now == L || now == R)
      {
        v = -v;
      }
      break;

    default:
      f = 3;
      break;
    }
    digitalWrite(PIN past, LOW);
    digitalWrite(PIN now, HIGH);
    past = now;
    now += v;
    t = millis();
  }
}