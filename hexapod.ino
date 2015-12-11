
#include <Wire.h>
#include "Servo.h"

Servo s(0);
void setup () {
    Wire.begin();
    Servo::init();
}

void loop () {
    s.setDregree(100);// 0~180
}
