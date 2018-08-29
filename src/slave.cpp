#ifdef SLAVE

#include <Arduino.h>
#include <Wire.h>

void requestEvent();
void receiveEvent(int howMany);

volatile byte cmd;

void setup() {
    Wire.begin(8);
    Wire.onRequest(requestEvent);
    Wire.onReceive(receiveEvent);

    Serial.begin(9600);
    Serial.println("SLAVE!");
}

void loop() {
}

void requestEvent() {
    if (cmd == '0') {
        Wire.write("Nothing");
    } else {
        Wire.write("CMD");
        Wire.write(cmd);
    }
}

void receiveEvent(int howMany) {
    while (Wire.available()) {
        cmd = Wire.read();
    }
}

#endif
