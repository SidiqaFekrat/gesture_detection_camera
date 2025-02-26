#include "camera_helpers.cpp"
#include "motor_helpers.cpp"
#include "inference_helpers.cpp"

// Camera and motor initialization
void setup() {
    Serial.begin(115200);

    // Initialize camera
    if (!initCamera()) {
        Serial.println("Failed to initialize camera.");
        return;
    }

    // Initialize SD card
    if (!initSDCard()) {
        Serial.println("SD card initialization failed!");
        return;
    }

    // Initialize BLE
    initBLE();

    // Initialize Motor
    initMotor();
}

void loop() {
    // Capture and process image
    uint8_t* image = captureImage();
    if (image != nullptr) {
        // Run inference
        runInference(image);
        // Control motor based on inference result
        controlMotorBasedOnInference();
    }
    delay(100);
}

