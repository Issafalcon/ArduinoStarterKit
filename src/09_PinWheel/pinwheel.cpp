#include "pinwheel.h"

int pinwheelSwitchState = 0;

void initPinwheel()
{
    pinMode(motorPin, OUTPUT);
    pinMode(switchPin, INPUT);
}

void loopPinwheel()
{
    pinwheelSwitchState = digitalRead(switchPin);

    if (pinwheelSwitchState == HIGH)
    {
        digitalWrite(motorPin, HIGH);
    } 
    else
    {
        digitalWrite(motorPin, LOW);
    }
    
    
}