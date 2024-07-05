#include <NewPing.h>
 
#define LEFT_TRIG_PIN 2
#define LEFT_ECHO_PIN 3
#define FRONT_TRIG_PIN 4
#define FRONT_ECHO_PIN 5
#define RIGHT_TRIG_PIN 6
#define RIGHT_ECHO_PIN 7
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
 
NewPing leftSensor(LEFT_TRIG_PIN, LEFT_ECHO_PIN, MAX_DISTANCE);
NewPing frontSensor(FRONT_TRIG_PIN, FRONT_ECHO_PIN, MAX_DISTANCE);
NewPing rightSensor(RIGHT_TRIG_PIN, RIGHT_ECHO_PIN, MAX_DISTANCE);
 
const int LEFT_MOTOR_IN1 = 8; // Define the pins for controlling left motor direction
const int LEFT_MOTOR_IN2 = 9;
const int RIGHT_MOTOR_IN1 = 10; // Define the pins for controlling right motor direction
const int RIGHT_MOTOR_IN2 = 11;
 
void setup() {
  Serial.begin(9600);
  pinMode(LEFT_MOTOR_IN1, OUTPUT); // Set motor driver pins as outputs
  pinMode(LEFT_MOTOR_IN2, OUTPUT);
  pinMode(RIGHT_MOTOR_IN1, OUTPUT);
  pinMode(RIGHT_MOTOR_IN2, OUTPUT);
}
 
void loop() {
  int leftDistance = leftSensor.ping_cm();
  int frontDistance = frontSensor.ping_cm();
  int rightDistance = rightSensor.ping_cm();
 
  if (leftDistance > 0 && rightDistance > 0 && frontDistance > 0) {
    if (frontDistance < 20) { // If obstacle in front
      if (leftDistance > rightDistance) {
        // Turn left
        turnLeft();
      } else {
        // Turn right
        turnRight();
      }
    } else {
      // Move forward
      moveForward();
    }
  }
}
 
void moveForward() {
  // Control the motors to move the robot forward
  digitalWrite(LEFT_MOTOR_IN1, HIGH);
  digitalWrite(LEFT_MOTOR_IN2, LOW);
  digitalWrite(RIGHT_MOTOR_IN1, HIGH);
  digitalWrite(RIGHT_MOTOR_IN2, LOW);
}
 
void turnLeft() {
  // Control the motors to turn left
  digitalWrite(LEFT_MOTOR_IN1, LOW);
  digitalWrite(LEFT_MOTOR_IN2, HIGH);
  digitalWrite(RIGHT_MOTOR_IN1, HIGH);
  digitalWrite(RIGHT_MOTOR_IN2, LOW);
}
 
void turnRight() {
  // Control the motors to turn right
  digitalWrite(LEFT_MOTOR_IN1, HIGH);
  digitalWrite(LEFT_MOTOR_IN2, LOW);
  digitalWrite(RIGHT_MOTOR_IN1, LOW);
  digitalWrite(RIGHT_MOTOR_IN2, HIGH);
}
