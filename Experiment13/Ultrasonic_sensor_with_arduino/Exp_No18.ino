//Computer Operated Turtle Bot:
// Define motor control pins
const int motor1Dir1 = 8; // Direction input 1 for Motor 1
const int motor1Dir2 = 9; // Direction input 2 for Motor 1
const int motor2Dir1 = 10; // Direction input 1 for Motor 2
const int motor2Dir2 = 11; // Direction input 2 for Motor 2

void setup() {
  // Set motor control pins as OUTPUT
  pinMode(motor1Dir1, OUTPUT);
  pinMode(motor1Dir2, OUTPUT);

  pinMode(motor2Dir1, OUTPUT);
  pinMode(motor2Dir2, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();
    executeCommand(command);
  }
}

void executeCommand(char command) {
  switch (command) {
    case 'b':
      moveForward();
      break;
    case 'f':
      moveBackward();
      break;
    case 'l':
      moveLeft();
      break;
    case 'r':
      moveRight();
      break;
    case 's':
      stopMotors();
      break;
    default:
      break;
  }
}

void moveForward() {
  digitalWrite(motor1Dir1, HIGH);
  digitalWrite(motor1Dir2, LOW);
  digitalWrite(motor2Dir1, HIGH);
  digitalWrite(motor2Dir2, LOW);
}

void moveBackward() {
  digitalWrite(motor1Dir1, LOW);
  digitalWrite(motor1Dir2, HIGH);
  digitalWrite(motor2Dir1, LOW);
  digitalWrite(motor2Dir2, HIGH);
}

void moveLeft() {
  digitalWrite(motor1Dir1, LOW);
  digitalWrite(motor1Dir2, HIGH);
  digitalWrite(motor2Dir1, HIGH);
  digitalWrite(motor2Dir2, LOW);
}

void moveRight() {
  digitalWrite(motor1Dir1, HIGH);
  digitalWrite(motor1Dir2, LOW);
  digitalWrite(motor2Dir1, LOW);
  digitalWrite(motor2Dir2, HIGH);
}

void stopMotors() {
  digitalWrite(motor1Dir1, LOW);
  digitalWrite(motor1Dir2, LOW);
  digitalWrite(motor2Dir1, LOW);
  digitalWrite(motor2Dir2, LOW);
}
