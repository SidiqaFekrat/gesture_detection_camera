
#include "inference_helpers.h"
#include "edge-impulse-sdk/dsp/image/image.hpp"
#include "edge-impulse-sdk/classifier/ei_classifier_types.hpp"
#include "Gestures_inferencing.h"

extern uint8_t *snapshot_buf;

void captureAndInfer() {
    snapshot_buf = (uint8_t*)malloc(EI_CAMERA_RAW_FRAME_BUFFER_COLS * EI_CAMERA_RAW_FRAME_BUFFER_ROWS * EI_CAMERA_FRAME_BYTE_SIZE);
    if (snapshot_buf == nullptr) {
        Serial.println("Failed to allocate snapshot buffer");
        return;
    }

    ei::signal_t signal;
    signal.total_length = EI_CLASSIFIER_INPUT_WIDTH * EI_CLASSIFIER_INPUT_HEIGHT;
    signal.get_data = &ei_camera_get_data;

    if (cameraCapture((size_t)EI_CLASSIFIER_INPUT_WIDTH, (size_t)EI_CLASSIFIER_INPUT_HEIGHT, snapshot_buf) == false) {
        Serial.println("Failed to capture image");
        free(snapshot_buf);
        return;
    }

    ei_impulse_result_t result = {0};
    EI_IMPULSE_ERROR err = run_classifier(&signal, &result, false);

    if (err != EI_IMPULSE_OK) {
        Serial.printf("Error running classifier: %d\n", err);
        return;
    }

    for (size_t ix = 0; ix < EI_CLASSIFIER_LABEL_COUNT; ix++) {
        Serial.printf("Prediction: %s -> %.5f\n", result.classification[ix].label, result.classification[ix].value);
    }

    free(snapshot_buf);
}
