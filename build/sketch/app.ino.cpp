#include <Arduino.h>
#line 1 "c:\\Coding\\Arduino\\Starter Kit Projects\\app.ino"
#include "./src/07_Light_Theremin/lightTheremin.h"

#line 3 "c:\\Coding\\Arduino\\Starter Kit Projects\\app.ino"
void setup();
#line 8 "c:\\Coding\\Arduino\\Starter Kit Projects\\app.ino"
void loop();
#line 3 "c:\\Coding\\Arduino\\Starter Kit Projects\\app.ino"
void setup()
{
	initializeTheremin();
}

void loop()
{
	performThereminLoop();
}

