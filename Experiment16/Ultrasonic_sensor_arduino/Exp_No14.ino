// Define IR sensor pin
const int irSensorPin = A0;

// Define motor control pins
const int motorAPin1 = 8;
const int motorAPin2 = 9;
const int motorBPin1 = 10;
const int motorBPin2 = 11;

void setup() {
  Serial.begin(9600); // Start serial communication
  pinMode(irSensorPin, INPUT); // Set IR sensor pin as INPUT

  // Set motor control pins as OUTPUT
  pinMode(motorAPin1, OUTPUT);
  pinMode(motorAPin2, OUTPUT);
  pinMode(motorBPin1, OUTPUT);
  pinMode(motorBPin2, OUTPUT);
}

void loop() {
  // Read IR sensor value
  int irSensorValue = analogRead(irSensorPin);

  // Check if obstacle is detected
  if (irSensorValue < 30) { // Adjust IR_THRESHOLD according to sensor calibration
    // Obstacle detected, stop the motors
    stopMotors();
    Serial.println("Obstacle detected! Stopping motors.");
  } else {
    // No obstacle detected, move forward
    moveForward();
    Serial.println("No obstacle detected. Moving forward.");
  }
}

// Function to stop the motors
void stopMotors() {
  digitalWrite(motorAPin1, LOW);
  digitalWrite(motorAPin2, LOW);
  digitalWrite(motorBPin1, LOW);
  digitalWrite(motorBPin2, LOW);
}

// Function to move forward
void moveForward() {
  digitalWrite(motorAPin1, HIGH);
  digitalWrite(motorAPin2, LOW);
  digitalWrite(motorBPin1, HIGH);
  digitalWrite(motorBPin2, LOW);
}
