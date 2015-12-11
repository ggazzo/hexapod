
#include <Wire.h>
#include "Servo.h"

ServoI2C s(0);
void setup () {
    Wire.begin();
    ServoI2C::init();
}

void loop () {
    s.setDregree(100);// 0~180
}
