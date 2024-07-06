//Shape forming robo
// Define motor pins
#define motor1Pin1 8
#define motor1Pin2 9
#define motor2Pin1 10
#define motor2Pin2 11



void setup() {
  // Initialize motor pins as outputs
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  // Initialize serial communication for debugging
  Serial.begin(9600);


}

void loop() {
  if (Serial.available()) {
    char command = Serial.read();

    switch (command) {
      case 'l':
        moveLShape();
        break;
      case 'c':
        moveCircular();
        break;
      default:
        stop();
        break;
    }
  }
}

// Function to move the robot in L-shape
void moveLShape() {
  // Move forward for some distance
  moveForward();
  delay(1000);
  stop();

  //stop
  stop();
  delay(1000);

  // Turn right
  turnRight();
  delay(500);
  stop();

  //stop
  stop();
  delay(1000);

  //Move forward again
  moveForward();
  delay(1000);
  stop();
}

// Function to move the robot in a circular motion
void moveCircular() {
  // Rotate the robot clockwise
  rotateClockwise();
}

// Function to move the robot forward
void moveForward() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
}

// Function to stop the robot
void stop() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
}

// Function to turn the robot right
void turnRight() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
}

// Function to rotate the robot clockwise
void rotateClockwise() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
  // Adjust the delay time to control the speed of rotation
  delay(100);
}
