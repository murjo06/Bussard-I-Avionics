#include "HardwareSerial.h"
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_MPU6050 mpu;

struct accelerometerData {
    float accelerationX;
    float accelerationY;
    float accelerationZ;
    float yaw;
    float pitch;
    float roll;
    float temperature;
};

void initAccelerometer() {
	if (!mpu.begin()) {
		Serial.println("MPU6050 not found");
		while(1) {
            delay(100);
        }
	}
	mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
	mpu.setGyroRange(MPU6050_RANGE_500_DEG);
	mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
	delay(100);
}

struct accelerometerData getAccelerometerData() {
    struct accelerometerData data;
	sensors_event_t a, g, temp;
	mpu.getEvent(&a, &g, &temp);
    data.accelerationX = a.acceleration.x - 10.22;
    data.accelerationY = a.acceleration.y + 0.21;
    data.accelerationZ = a.acceleration.z - 3.2;
    data.yaw = g.gyro.x + 0.02;
    data.pitch = g.gyro.y;
    data.roll = g.gyro.z + 0.07;
    data.temperature = temp.temperature;
	return data;
}