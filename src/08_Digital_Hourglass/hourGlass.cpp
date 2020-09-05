#include "./hourGlass.h"

unsigned long previousTime = 0;
int tiltSwitchState = 0;
int prevSwitchState = 0;
int led = 2;
long interval = 6000;

void initializeHourglass()
{
    for (int x = 2; x < switchPin; x++)
    {
        pinMode(x, OUTPUT);
    }
    
    pinMode(switchPin, INPUT);
}

void performHourGlassLoop()
{
    unsigned long currentTime = millis();

    if (currentTime - previousTime > interval)
    {
        previousTime = currentTime;
        digitalWrite(led, HIGH);
        led++;
    }

    if (led == 7)
    {
        /* code */
    }

    tiltSwitchState = digitalRead(switchPin);

    if (tiltSwitchState != prevSwitchState)
    {
        for (int i = 2; i < switchPin; i++)
        {
            digitalWrite(i, LOW);
        }
        led = 2;
        previousTime = currentTime;
    }
    
    prevSwitchState = tiltSwitchState;
}
