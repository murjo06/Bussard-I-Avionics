#include "Arduino.h"
#include <SPI.h>
#include <SD.h>

String data = "";
String currentData = "";

File file;

void initStorage() {
    if (!SD.begin(4)) {
        Serial.println("SD Storage initialization failed");
        while(1) {
            delay(100);
        }
    }
    Serial.println("SD Storage initialized");
    file = SD.open("flight.txt", FILE_WRITE);
}

void updateData(String addedData) {
    currentData += addedData;
}

void writeToStorage() {
    if(file) {
        file.print(currentData);
        file.close();
        data += currentData;
        currentData = "";
    }
    file = SD.open("flight.txt", FILE_WRITE);
}