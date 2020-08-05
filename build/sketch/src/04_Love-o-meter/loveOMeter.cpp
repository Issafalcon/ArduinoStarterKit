#include <Arduino.h>
#include "./loveOMeter.h"

const int sensorPin = A0;
const float baselineTemp = 26.0;

void initialiseMeter() 
{
    Serial.begin(9600); // Open a serial port

    for (int pinNumber = 2; pinNumber < 5; pinNumber++)
    {
        pinMode(pinNumber, OUTPUT);
        digitalWrite(pinNumber, LOW);
    }    
}

void performLoop()
{
    auto sensorVal = analogRead(sensorPin);
    // Convert ADC reading to voltage
    auto voltage = (sensorVal/1024.0) * 5.0;
    auto temp = (voltage - 0.5) * 100;

    Serial.print("Sensor value: ");
    Serial.print(sensorVal);
    Serial.print(", Volts: ");
    Serial.print(voltage);
    Serial.print(", Degrees C:");
    Serial.println(temp);

    setLamps(temp);
}

void setLamps(double temp)
{
    if (temp < baselineTemp+1.0)
    {
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
    }
    else if (temp  >= baselineTemp+1.0 && temp < baselineTemp+2.0)
    {
        digitalWrite(2, HIGH);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
    }
    else if (temp >= baselineTemp+2.0 && temp < baselineTemp+3.0)
    {
        digitalWrite(2, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(4, LOW);
    } 
    else if (temp >= baselineTemp+3.0)
    {
        digitalWrite(2, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(4, HIGH);
    }
    delay(1);
}