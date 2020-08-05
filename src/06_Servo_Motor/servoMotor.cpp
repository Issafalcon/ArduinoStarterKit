#include <Servo.h>
#include "./servoMotor.h"

Servo myServo;
int potVal;
int angle;

void initializeServo() 
{
    myServo.attach(9);
    Serial.begin(115200);    
}

void performServoLoop() 
{
    potVal = analogRead(potPin);
    Serial.print("Pot Value: ");
    Serial.println(potVal);

    // Scale the value of the analogue input (from potentiometer) to the degree value
    // range that the servo motor can rotate to.
    angle = map(potVal, 0, 1023, 0, 179);
    Serial.print("Angle: ");
    Serial.println(angle);

    // Move the servo
    myServo.write(angle);
    delay(15); // Allow servo time to move to position before looping
}
