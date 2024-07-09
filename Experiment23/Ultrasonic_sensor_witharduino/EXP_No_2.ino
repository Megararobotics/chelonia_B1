// Define motor control pins(EXP 2)
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
    case 'B':
      moveForward();
      break;
    case 'F':
      moveBackward();
      break;
    case 'L':
      moveLeft();
      delay(1800);
      stopMotors();
      delay(200);
      moveForward();
      break;
    case 'R':
      moveRight();
      delay(1800);
      stopMotors();
      delay(200);
      moveForward();
      break;
    case 'STOP':
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