#include "Arduino.h"
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#define seaLevelPressure 1028

Adafruit_BME280 bme;

struct altimeterData {
    float pressure;
    float altitude;
    float temperature;
    float humidity;
};

void initAltimeter() {
    if(!bme.begin(0x76)) {
        Serial.println("BME280 not found");
        while(1) {
            delay(100);
        }
    }
}

struct altimeterData getAltimeterData() {
    struct altimeterData data;
    data.pressure = bme.readPressure();
    data.altitude = bme.readAltitude(seaLevelPressure);
    data.temperature = bme.readTemperature();
    data.humidity = bme.readHumidity();
    return data;
}