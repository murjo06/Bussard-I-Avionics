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
    Serial.begin(9600);
    initAccelerometer();
    //initAltimeter();
    //initTiltSwitch();
    //initThermometer();
    //initStorage();
    initMagnometer();
}

void loop() {
    long time = millis();
    struct accelerometerData accelerometerValues = getAccelerometerData();
    Serial.print(millis() - time);
    String dataForStorage = String(accelerometerValues.gyroX) + " " + String(accelerometerValues.gyroY) + " " + String(accelerometerValues.gyroZ) + "\n";
    //Serial.print(dataForStorage);
    
    struct compassData magnetometerValues = getMagnometerData();
    
    Serial.print("X: ");
    Serial.print(magnetometerValues.x);
    Serial.print(" Y: ");
    Serial.print(magnetometerValues.y);
    Serial.print(" Z: ");
    Serial.println(magnetometerValues.z);
    

    delay(2000 - millis() + time);
}