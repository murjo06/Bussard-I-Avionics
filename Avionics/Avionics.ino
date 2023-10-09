#include <Wire.h>
#include "magnetometer.h"
#include "accelerometer.h"
#include "altimeter.h"
#include "tilt.h"
#include "thermometer.h"
#include "storage.h"

// I2C Addresses: Accelerometer: 0x68, Altimeter: 0x76, Magnetometer: 0x0D

void setup() {
    Wire.begin();
    Serial.begin(115200);
    initAccelerometer();
    initAltimeter();
    //initTiltSwitch();
    //initThermometer();
    initStorage();
    initMagnometer();
}

void loop() {
    long time = millis();
    struct altimeterData altimeterValues = getAltimeterData();
    struct accelerometerData accelerometerValues = getAccelerometerData();
    struct compassData magnetometerValues = getMagnometerData();

    updateData(String(altimeterValues.altitude) + " " + String(altimeterValues.pressure) + " " + String(altimeterValues.humidity) + " " + String(altimeterValues.temperature) + " " + String(accelerometerValues.accelerationX) + " " + String(accelerometerValues.accelerationY) + " " + String(accelerometerValues.accelerationZ) + " " + String(accelerometerValues.pitch) + " " + String(accelerometerValues.yaw) + " " + String(accelerometerValues.roll) + " " + String(accelerometerValues.temperature) + " " + String(magnetometerValues.x) + " " + String(magnetometerValues.y) + " " + String(magnetometerValues.z) + "\n");
    writeToStorage();

    delay(5000 - millis() + time);
}