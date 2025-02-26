#include "motor_helpers.h"
#include "SCMD.h"

SCMD myMotorDriver;

void motorInit() {
    myMotorDriver.settings.commInterface = I2C_MODE;
    myMotorDriver.settings.I2CAddress = 0x5D;
    myMotorDriver.settings.chipSelectPin = 10;

    while (myMotorDriver.ready() == false);
    Serial.println("Motor initialized");

    myMotorDriver.inversionMode(1, 1);
    myMotorDriver.enable();
}

void controlMotor(uint8_t motor, uint8_t direction, uint8_t speed) {
    myMotorDriver.setDrive(motor, direction, speed);
}

