#include <Arduino.h>
#include "Keypad.h"

#define R A0
#define G A1
#define B A2
#define tonePin 10

const String pass = "1234567890";
const byte ROWS = 4; 
const byte COLS = 3; 
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {2, 3, 4, 5}; 
byte colPins[COLS] = {6, 7, 8}; 

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

long long t = 0;
char stat = 0, now = 0;

void setup(){
  Serial.begin(9600);
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
  analogWrite(B, 1024);
}
void loop(){
  char key = keypad.getKey();
  switch(stat){
    case 0:
      if(key != NO_KEY)
      {
        if(key == pass[now])
        {
          stat = 1;
          now++;
          analogWrite(R, 1024);
          analogWrite(G, 1024);
          analogWrite(B, 0);
        }
        else
        {
          stat = 3;
          now = 0;
          analogWrite(R, 1024);
          analogWrite(G, 0);
          analogWrite(B, 0);
          t = millis();
          tone(tonePin, 100, 100);
        }
      }
      break;

      case 1:
        if(key != NO_KEY)
        {
          if(key == pass[now])
          {
            now++;
            if(now == pass.length())
            {
              stat = 2;
              now = 0;
              analogWrite(R, 0);
              analogWrite(G, 1024);
              analogWrite(B, 0);
              t = millis();
              tone(tonePin, 500, 900);
            }
          }
          else
          {
            stat = 3;
            now = 0;
            analogWrite(R, 1024);
            analogWrite(G, 0);
            analogWrite(B, 0);
            t = millis();
            tone(tonePin, 100, 100);
          }
        }
        break;
      
      case 2:
        if(millis() - t >= 1000)
        {
          stat = 0;
          now = 0;
          analogWrite(R, 0);
          analogWrite(G, 0);
          analogWrite(B, 1024);
        }
        break;

      case 3:
        if(millis() - t >= 1000)
        {
          stat = 0;
          now = 0;
          analogWrite(R, 0);
          analogWrite(G, 0);
          analogWrite(B, 1024);
        }
        break;
  }
}