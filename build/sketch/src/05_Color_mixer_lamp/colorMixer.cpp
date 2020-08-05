#include "./colorMixer.h"

int redValue = 0;
int greenValue = 0;
int blueValue = 0;

int redSensorValue = 0;
int greenSensorValue = 0;
int blueSensorValue = 0;

constexpr size_t pinCount = 3;
const int ledPins[pinCount] = { redLEDPin, greenLEDPin, blueLEDPin };

void setupColours()
{
    Serial.begin(9600);

    for (int i = 0; i < pinCount; i++)
    {
        pinMode(ledPins[i], OUTPUT);
    }
}

void loopColours()
{
    redSensorValue = analogRead(redSensorPin);
    delay(5);
    greenSensorValue = analogRead(greenSensorValue);
    delay(5);
    blueSensorValue = analogRead(blueSensorValue);

    Serial.print("Raw sensor values \t Red: ");
    Serial.print(redSensorValue);
    Serial.print("\t Green: ");
    Serial.print(greenSensorValue);
    Serial.print("\t Blue: ");
    Serial.println(blueSensorValue);

    redValue = redSensorValue/4;
    greenValue = greenSensorValue/4;
    blueValue = blueSensorValue/4;

    Serial.print("Mapped sensor values \t Red: ");
    Serial.print(redValue);
    Serial.print("\t Green: ");
    Serial.print(greenValue);
    Serial.print("\t Blue: ");
    Serial.println(blueValue);

    analogWrite(redLEDPin, redValue);
    analogWrite(greenLEDPin, greenValue);
    analogWrite(blueLEDPin, blueValue);
    Serial.end();
}