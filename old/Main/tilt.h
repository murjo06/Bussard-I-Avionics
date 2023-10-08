#include <Arduino.h>

int tiltSwitchPin = 7;

void initTiltSwitch(int pin = 7) {
    tiltSwitchPin = pin;
    pinMode(tiltSwitchPin, INPUT);
}

int getTiltSwitchData() {
    return digitalRead(tiltSwitchPin);
}