#ifdef MASTER

#include <Arduino.h>
#include <Wire.h>

void setup() {
    Wire.begin();

    Serial.begin(9600);
    Serial.println("MASTER!");
}

void loop() {
    if (Wire.available()) {
        while (Wire.available()) {
            char c = Wire.read();
            Serial.print(c);
        }
        Serial.println("");
    }

    if (Serial.available()) {
        Wire.beginTransmission(8);
        Wire.write(Serial.read());
        Wire.endTransmission(8);

        Wire.requestFrom(8, 20);
    }
}

#endif
