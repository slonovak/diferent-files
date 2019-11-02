#include <Arduino.h>

#define latchPin 9
#define clockPin 8
#define dataPin 10
#define LED 2
#define numOfRegisters 4

byte num_array[10] = {  0b11111100,    // 0
                        0b01100000,    // 1
                        0b11011010,    // 2
                        0b11110010,    // 3
                        0b01100110,    // 4
                        0b10110110,    // 5
                        0b10111110,    // 6
                        0b11100000,    // 7
                        0b11111110,    // 8
                        0b11110110 };  // 9

long long t = 0;
const byte init_hour = 8;
const byte init_min = 16;
const byte init_sec = 32;
byte sec = init_sec, min = init_min, hour = init_hour;
byte* registerState = new byte[numOfRegisters];
char f = 1;

void setup()
{
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(LED, OUTPUT);
  registerState[0] = num_array[min%10];
  registerState[1] = num_array[min/10];
  registerState[2] = num_array[hour%10];
  registerState[3] = num_array[hour/10];

  digitalWrite(latchPin, LOW);
    for (int i = 0; i < numOfRegisters; i++){
      byte *states = &registerState[i];
      shiftOut(dataPin, clockPin, LSBFIRST, *states);
    }
  digitalWrite(latchPin, HIGH);

}

void loop()
{
  if(millis()-t>=1000)
  {
    if(sec == 60)
    {
      sec = 0;
      min++;
      if(min == 60)
      {
        min = 0;
        hour++;
        if(hour == 24)
          {
            hour = 0;
          }
        registerState[2] = num_array[hour%10];
        registerState[3] = num_array[hour/10];
      }
      registerState[0] = num_array[min%10];
      registerState[1] = num_array[min/10];

      digitalWrite(latchPin, LOW);
      for (int i = 0; i < numOfRegisters; i++){
        byte *states = &registerState[i];
        shiftOut(dataPin, clockPin, LSBFIRST, *states);
      }
  	  digitalWrite(latchPin, HIGH);

    }
    digitalWrite(LED, f);
    f = !f;
    sec++;
    t = millis();
  }
}
