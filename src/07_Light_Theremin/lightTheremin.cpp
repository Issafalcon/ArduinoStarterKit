#include "./lightTheremin.h"

int sensorValue {};
int sensorLow {1023};
int sensorHigh {0};

void initializeTheremin() 
{
   pinMode(ledPin, OUTPUT);
   digitalWrite(ledPin, HIGH);

   while (millis() < 5000) // Millis reports how long Arduino has been running since last powered on / reset
   {
       sensorValue = analogRead(A0);
       if (sensorValue > sensorHigh)
       {
           sensorHigh = sensorValue;
       }
       if (sensorValue < sensorLow)
       {
           sensorLow = sensorValue;
       }
       
       digitalWrite(ledPin, LOW);
       Serial.begin(115200);
   }
}

void performThereminLoop() 
{
    sensorValue = analogRead(A0);
    int pitch = map(sensorValue, sensorLow, sensorHigh, 100, 4000);

    Serial.print("Sensor Low: ");
    Serial.print(sensorLow);
    Serial.print("\t Sensor High: ");
    Serial.println(sensorHigh);
    Serial.print("Sensor Value: ");
    Serial.println(sensorValue);

    tone(8, pitch, 20);
    delay(10);
}
