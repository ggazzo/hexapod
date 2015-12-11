#ifndef __SERVO_H__
#define __SERVO_H__


#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#ifndef _i2caddr
#define _i2caddr 0x40
#endif

#include <Wire.h>
#define PCA9685_MODE1 0x00 // location for Mode1 register address
#define PCA9685_MODE2 0x01 // location for Mode2 reigster address
#define PCA9685_LED0 0x06 // location for start of LED0 registers
class Servo {
public:
    Servo(int a);
    void setDregree(unsigned char d);

    static bool init() {
        Wire.begin();
    	delay(1);
    	Servo::writeRegister(PCA9685_MODE1, (byte)0x01);	// reset the device

    	delay(1);
    	bool isOnline;
    	if (Servo::readRegister(PCA9685_MODE1)==0x01)	{
    		isOnline = true;
    	} else {
    		isOnline = false;
    	}
    	Servo::writeRegister(PCA9685_MODE1, (byte)B10100000);	// set up for auto increment
    	Servo::writeRegister(PCA9685_MODE2, (byte)0x10);	// set to output

    	return isOnline;
    }

    static word readRegister(int regAddress) {
    	word returnword = 0x00;
    	Wire.beginTransmission(_i2caddr);
    	Wire.write(regAddress);
    	Wire.endTransmission();
    	Wire.requestFrom((int)_i2caddr, 1);

    //    int c=0;
    	//Wait for our 2 bytes to become available
    	while (Wire.available()) {
            //high byte
    //        if (c==0)   { returnword = Wire.read() << 8; }
            //low byte
      //      if (c==1)   {
    		returnword |= Wire.read();
    		//}
            //c++;
        }

    	return returnword;
    }
    static void writeRegister(int regAddress, byte data) {
    	Wire.beginTransmission(_i2caddr);
    	Wire.write(regAddress);
    	Wire.write(data);
    	Wire.endTransmission();
    }


private:
    int degree;
    int address;
    int getDregree(void){
        return this->degree;
    }
};
#endif
