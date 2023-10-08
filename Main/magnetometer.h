#include "HardwareSerial.h"
#include <Wire.h>
#include <QMC5883L.h>

QMC5883L compass;

struct compassData {
    int x;
    int y;
    int z;
};

void initMagnometer() {
    compass.init();
}

struct compassData getMagnometerData() {
    int x, y, z;
    compass.read(&x, &y, &z);
    struct compassData data;
    data.x = x;
    data.y = y;
    data.z = z;
    return data;
}