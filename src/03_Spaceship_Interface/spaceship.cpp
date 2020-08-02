#include <Arduino.h>
#include "spaceship.h"

int switchState = 0;

enum class LEDPin : unsigned char {
  Green = 3,
  Red1,
  Red2
};

void InitialiseShip() 
{
    pinMode((uint8_t)LEDPin::Green, OUTPUT); 
    pinMode((uint8_t)LEDPin::Red1, OUTPUT);
    pinMode((uint8_t)LEDPin::Red2, OUTPUT);
    pinMode(2, INPUT);
    return;
}

void LoopInterface() 
{
  switchState = digitalRead(2);
  // Button is not pressed
  if(switchState == LOW) 
  {
    digitalWrite((uint8_t)LEDPin::Green, HIGH);
    digitalWrite((uint8_t)LEDPin::Red1, LOW);
    digitalWrite((uint8_t)LEDPin::Red2, LOW);
  }
  else 
  {
    digitalWrite((uint8_t)LEDPin::Green, LOW);
    digitalWrite((uint8_t)LEDPin::Red1, LOW);
    digitalWrite((uint8_t)LEDPin::Red2, HIGH);
    
    delay(250); // Wait 1/4 second
    
    // toggle LEDs
    digitalWrite((uint8_t)LEDPin::Red1, HIGH);
    digitalWrite((uint8_t)LEDPin::Red2, LOW);
    
    delay(100); // Wait 1/4 second
  }
}