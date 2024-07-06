//code to control_robo_using_pb_and_monitor_the_turning_angle_using_imu_i
#include "Wire.h"
#include <MPU6050_light.h>
#include <SoftwareSerial.h>
 
MPU6050 mpu(Wire);
SoftwareSerial bluetooth(2, 3); // RX, TX
unsigned long timer = 0;
int count = 0;
float prevAngleX;
float prevAngleY;
float prevAngleZ;
float angleX;
float angleY;
float angleZ;
float AngleX;
float AngleY;
float AngleZ;
float initialAngleX = 0.0;
float initialAngleY = 0.0;
float initialAngleZ = 0.0;
 
const int motorAPin1 = 5;
const int motorAPin2 = 6;
const int motorBPin1 = 10;
const int motorBPin2 = 11;
 
// Define push button pin
#define BUTTON_PIN 7
 
boolean buttonState = false;
 
void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);
  Wire.begin();
 
  byte status = mpu.begin();
  while (status != 0) {} // Stop everything if could not connect to MPU6050
  mpu.calcOffsets(); // Calibrate the IMU
  initialAngleX = mpu.getAngleX(); // Store initial angle values after calibration
  initialAngleY = mpu.getAngleY();
  initialAngleZ = mpu.getAngleZ();
 
  pinMode(motorAPin1, OUTPUT);
  pinMode(motorAPin2, OUTPUT);
  pinMode(motorBPin1, OUTPUT);
  pinMode(motorBPin2, OUTPUT);
 
  // Push button pin as input
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  // Initially stop the motors
  stopMotors();
}
 
void loop() {
    // Check if the button is pressed
  if (digitalRead(BUTTON_PIN) == LOW) {
    // Button is pressed, move the robot forward
    moveForward();
  } else {
    // Button is released, stop the robot
    stopMotors();
  }
  mpu.update();
 
  if ((millis() - timer) > 10) { // Print data every 10ms
    float correctedAngleX = mpu.getAngleX() - initialAngleX;
    float correctedAngleY = mpu.getAngleY() - initialAngleY;
    float correctedAngleZ = mpu.getAngleZ() - initialAngleZ;
 
    angleX = (correctedAngleX);
    angleY = (correctedAngleY);
    angleZ = (correctedAngleZ);
 
    count++;
 
    if (count == 1) {
      float AngleX = abs(correctedAngleX) - abs(correctedAngleX);
      float AngleY = abs(correctedAngleY) - abs(correctedAngleY);
      float AngleZ = abs(correctedAngleZ) - abs(correctedAngleZ);
      angleX = AngleX;
      angleY = AngleY;
      angleZ = AngleZ;
      Serial.print("Cervical rotation : ");
      Serial.println(angleZ);
 
    }
    else {
      if (((angleX - prevAngleX) >= -1.5 && (angleX - prevAngleX) <= 1.5) && ((angleZ - prevAngleZ) >= -2 && (angleZ - prevAngleZ) <= 2)) {
 
        angleZ = prevAngleZ;
        Serial.print("Cervical rotation : ");
        Serial.println(angleZ);
 
      }
      else if (((angleX - prevAngleX) >= -1.5 && (angleX - prevAngleX) <= 1.5) && !((angleZ - prevAngleZ) >= -2 && (angleZ - prevAngleZ) <= 2)) {
 
        Serial.print("Cervical rotation : ");
        Serial.println(angleZ);
 
      }
      else if (!((angleX - prevAngleX) >= -1.5 && (angleX - prevAngleX) <= 1.5) && ((angleZ - prevAngleZ) >= -2 && (angleZ - prevAngleZ) <= 2)) {
        angleZ = prevAngleZ;
 
        Serial.print("Cervical rotation : ");
        Serial.println(angleZ);
 
      }
      else if (!((angleX - prevAngleX) >= -1.5 && (angleX - prevAngleX) <= 1.5) && !((angleZ - prevAngleZ) >= -2 && (angleZ - prevAngleZ) <= 2)) {
 
        Serial.print("Cervical rotation : ");
        Serial.println(angleZ);
      }
      else {
 
        Serial.print("Cervical rotation : ");
        Serial.println(angleZ);
      }
    }
 
    prevAngleX = abs(correctedAngleX);
    prevAngleY = abs(correctedAngleY);
    prevAngleZ = angleZ;
 
    bluetooth.print("AngleZ: "); // Send angleZ value over Bluetooth
    bluetooth.println(angleZ);
 
    timer = millis();
  }
}
// Function to move the robot forward
void moveForward() {
  digitalWrite(motorAPin1, LOW);
  digitalWrite(motorAPin2, HIGH);
  digitalWrite(motorBPin1, HIGH);
  digitalWrite(motorBPin2, LOW);
  //analogWrite(ENA, 200); // Adjust the PWM value for motor speed
  //analogWrite(ENB, 200); // Adjust the PWM value for motor speed
}
 
// Function to stop the robot
void stopMotors() {
  digitalWrite(motorAPin1, LOW);
  digitalWrite(motorAPin2, LOW);
  digitalWrite(motorBPin1, LOW);
  digitalWrite(motorBPin2, LOW);
  //analogWrite(ENA, 0); // Stop motor A
  //analogWrite(ENB, 0); // Stop motor B
}