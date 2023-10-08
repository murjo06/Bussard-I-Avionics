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
    initAltimeter();
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
    
    struct altimeterData altimeterValues = getAltimeterData();
    struct accelerometerData accelerometerValues = getAccelerometerData();
    struct compassData magnetometerValues = getMagnometerData();

    Serial.println("Altimeter:");
    Serial.print("Pressure: ");
    Serial.print(altimeterValues.pressure);
    Serial.print(" Altitude: ");
    Serial.print(altimeterValues.altitude);
    Serial.print(" Humidity: ");
    Serial.print(altimeterValues.humidity);
    Serial.print(" Temperature: ");
    Serial.println(altimeterValues.temperature);
    Serial.println();
    
    Serial.println("Accelerometer:");
    Serial.print("X: ");
    Serial.print(accelerometerValues.accelerationX);
    Serial.print(" Y: ");
    Serial.print(accelerometerValues.accelerationY);
    Serial.print(" Z: ");
    Serial.print(accelerometerValues.accelerationZ);
    Serial.print(" Pitch: ");
    Serial.print(accelerometerValues.pitch);
    Serial.print(" Yaw: ");
    Serial.print(accelerometerValues.yaw);
    Serial.print(" Roll: ");
    Serial.println(accelerometerValues.roll);
    Serial.println();

    Serial.println("Magnetometer:");
    Serial.print("X: ");
    Serial.print(magnetometerValues.x);
    Serial.print(" Y: ");
    Serial.print(magnetometerValues.y);
    Serial.print(" Z: ");
    Serial.println(magnetometerValues.z);
    Serial.println()
    

    delay(5000 - millis() + time);
}