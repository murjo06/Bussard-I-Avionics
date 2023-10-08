int thermometerPin = A0;

void initThermometer(int pin = A0) {
    thermometerPin = pin;
    pinMode(thermometerPin, INPUT);
    analogReference(DEFAULT);
}

float getThermometerData() {
    float voltageOutAverage = 0;
    for(int i = 0; i < 1024; i++) {
        voltageOutAverage = voltageOutAverage + analogRead(thermometerPin);
    }
    return (voltageOutAverage * 0.000243) - 20.48;
}