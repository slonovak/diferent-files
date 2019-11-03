#include <Arduino.h>

int ColLed[5] = {2,3,4,5,6};        // Точки подключения катодов
int RowLed[5] = {7,8,9,10,11};       // Точки подключения анодов

int Rpin = 4;                           // Всего линий для катодов
int Cpin = 4; 

const bool img[5][5] = {{0, 1, 0, 1, 0}, {1, 1, 1, 1, 1}, {1, 0, 1, 0, 1}, {0, 1, 1, 1, 0}, {1, 0, 0, 0, 1}};

void setup()                
{
  for (int i = 0; i <= Rpin; i++) 
  {
    pinMode(RowLed[i], OUTPUT);
  }
  
  for (int j = 0; j <= Cpin; j++) 
  {
    pinMode(ColLed[j], OUTPUT);
  }
}

void alloff() 
{
  
  for (int i = 0; i <= Cpin; i++) 
  {
    digitalWrite(ColLed[i],LOW);
  }
  
  for (int j = 0; j <= Rpin; j++) 
  {
   digitalWrite(RowLed[j],HIGH);
  }

}  

void loop() 
{
	for(int i = 0; i<5; i++)
    {
      for(int j = 0; j<5;j++)
      {
        alloff();                             // сначала вызывается функция выключения, чтобы убедиться, что включен только этот светодиод.
 		digitalWrite(ColLed[j], img[i][j]);        // Анодный вывод конкретного светодиода в +5 В
  		digitalWrite(RowLed[i], !img[i][j]);
      }
    }
}