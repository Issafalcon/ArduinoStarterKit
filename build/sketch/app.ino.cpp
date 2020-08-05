#include <Arduino.h>
#line 1 "c:\\Users\\atfig\\Documents\\PlatformIO\\Projects\\Starter Kit Projects\\app.ino"
#include "./src/06_Servo_Motor/servoMotor.h"

#line 3 "c:\\Users\\atfig\\Documents\\PlatformIO\\Projects\\Starter Kit Projects\\app.ino"
void setup();
#line 8 "c:\\Users\\atfig\\Documents\\PlatformIO\\Projects\\Starter Kit Projects\\app.ino"
void loop();
#line 3 "c:\\Users\\atfig\\Documents\\PlatformIO\\Projects\\Starter Kit Projects\\app.ino"
void setup()
{
	initializeServo();
}

void loop()
{
	performServoLoop();
}

