#include "Servo.h"
#include <Wire.h>
ServoI2C::ServoI2C(int a) {
    this->address = a;
};


void ServoI2C::setDregree(unsigned char d){
    this->degree = d % (180  + 1);

    word v = map(d, 0, 180, 0, 4095);// sends one byte
    Wire.beginTransmission(_i2caddr);
    Wire.write(PCA9685_LED0 + 4*this->address);
    Wire.write(lowByte(0));
    Wire.write(highByte(0));
    Wire.write(lowByte(v));
    Wire.write(highByte(v));
    Wire.endTransmission();
}
