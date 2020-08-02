#include <Arduino.h>

static const int greenLEDPin = 9;
static const int redLEDPin = 11;
static const int blueLEDPin = 10;

static const int redSensorPin = A0;
static const int greenSensorPin = A1;
static const int blueSensorPin = A2;

void setupColours();
void loopColours();