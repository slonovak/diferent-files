#include <Arduino.h>

#define latchPin 12
#define clockPin 11
#define dataPin 13

byte num_array[10] = {  0b11111101,    // 0
                        0b01100001,    // 1
                        0b11011011,    // 2
                        0b11110010,    // 3
                        0b01100110,    // 4
                        0b10110110,    // 5
                        0b10111110,    // 6
                        0b11100000,    // 7
                        0b11111110,    // 8
                        0b11110110};   // 9

int num = 0;

void setup()
{
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop()
{
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, num_array[num]);
  digitalWrite(latchPin, HIGH);
  num++;
  if(num == 10)
    num = 0;
  delay(1000);
}
/*
int latchPin = 12;
int clockPin = 11;
int dataPin = 13;
byte leds = 0;
int currentLED = 0;

void setup()
{
    pinMode(latchPin, OUTPUT);
    pinMode(dataPin, OUTPUT);
    pinMode(clockPin, OUTPUT);

    leds = 0;
}

void loop()
{
    leds = 0;

    if (currentLED == 7)
    {
        currentLED = 0;
    }
    else
    {
        currentLED++;
    }

    bitSet(leds, currentLED);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, leds);
    digitalWrite(latchPin, HIGH);

    delay(250);
}*/