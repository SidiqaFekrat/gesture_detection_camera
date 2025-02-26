This project integrates an ESP32 camera module with a motor control system using Edge Impulse to create a gesture-controlled water shooting mechanism. The system detects hand gestures via the ESP32 camera, triggers a water pump, and sends notifications via BLE.

#Requirements
Hardware:

1. ESP32 with Camera: This hardware is used to detect the hand gestures used
  used for this project. With the help of the camera that is on this board, it allowed to
  capture the images of the gesture that we wanted to detect to recognize the
  gesture and control the water shooting system.

3. Submersible 3V DC Water Pump: This hardware is used to shoot water when a
  gesture is detected by the camera. Also, it is powered by a battery and
  controlled by the ESP32 board.

5. SparkFun Qwiic Motor Driver: The purpose of using this hardware is to control
  the water pump. It is very useful when connecting and managing the Pump’s
  power and operation through the ESP32 board.

7. SD Card: Is used to save the images.
   
8. BLE: Sends notifications to a connected device about detected objects.
    
9. A 3V battery: Is used the battery to power the water pump and other components
in our project.

Software:
1. Arduino IDE
2. Libraries:
   .ArduinoBLE
   .SCDM Motor Driver
   .ESP32 Board
   .Edge Impulse account



#Setup
1. Install the necessary libraries in the Arduino IDE:
  * ArduinoBLE
  * ESP32 with camera 
  * SCMD motor driver library

2. Connect the ESP32 with motor to motor dirver and water pump as specified in the code.
3. Upload the code to the ESP32 and open Serial Monitor.
4. The system will capture gestures, run inference, store images, and activate the water pump based in detected gestures.


#Conclusion:
This project enables gesture-controlled automation using the ESP32, Edge Impulse, and BLE. It is an efficient, interative solution for gesture-based control of water shooting mechanisms.

#Future Enhancements:
1. Add more gestures for different actions.
2. Improve recognition accuracy with additional sensors.

