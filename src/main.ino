#include <Gestures_inferencing.h>
#include "edge-impulse-sdk/dsp/image/image.hpp"

#include "esp_camera.h"
#include "FS.h"
#include "SD.h"
#include "SPI.h"
#include <ArduinoBLE.h>
#include <Arduino.h>
#include <stdint.h>
#include "SCMD.h"
#include "SCMD_config.h" //Contains #defines for common SCMD register names and values
#include "Wire.h"
#include "camera_helpers.h"
#include "motor_helpers.h"
#include "inference_helpers.h"

SCMD myMotorDriver;

// Define BLE and camera settings
BLEService batteryService("180F");
BLEUnsignedCharCharacteristic batteryLevelChar("2A19", BLERead | BLENotify);

// SD card initialization
static bool sd_sign = false;

void setup() {
    Serial.begin(115200);
    if (!sdCardInit()) {
        Serial.println("SD card initialization failed");
    }
    
    if (!cameraInit()) {
        Serial.println("Camera initialization failed");
    }

    if (!BLE.begin()) {
        Serial.println("BLE Initialization failed");
        while (1);
    }

    // BLE setup
    setupBLE();

    Serial.println("Bluetooth device active, waiting for connections...");
}

void loop() {
    BLEDevice central = BLE.central();
    if (central) {
        Serial.print("Connected to central: ");
        Serial.println(central.address());
        digitalWrite(LED_BUILTIN, HIGH);
        
        while (central.connected()) {
            captureAndInfer();
        }
        
        digitalWrite(LED_BUILTIN, LOW);
        Serial.print("Disconnected from central: ");
        Serial.println(central.address());
    }
}
