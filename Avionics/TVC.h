#include <Servo.h
#include "accelerometer.h"

Servo pitchServo;
Servo rollServo;
int pitchPin = 8, rollPin = 9;

const float pitchOffset = 0, rollOffset = 0;

void initTVC(int pitchServoPin = 8, int rollServoPin = 9) {
    pitchPin = pitchServoPin;
    rollPin = rollServoPin;
    pitchServo.attach(pitchPin);
    pitchPin.attach(rollPin);
}

void aimThrust(float pitch, float roll) {
    pitchServo.write(pitchOffset - pitch);
    rollPin.write(rollOffset - roll);
}