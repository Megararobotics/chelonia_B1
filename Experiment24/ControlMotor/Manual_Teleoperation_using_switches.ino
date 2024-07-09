// Define motor pins 
#define motor1A 5 
#define motor1B 6
#define motor2A 10
#define motor2B 11
 
// Define push buttons 
#define FWDBTN 2 
#define BCKBTN 3
#define LFTTURN 4 
#define RGHTTURN 7
 
void setup() {
 
  // Set motor pins as output
  pinMode(motor1A, OUTPUT);
  pinMode(motor1B, OUTPUT);  
  pinMode(motor2A, OUTPUT);
  pinMode(motor2B, OUTPUT);
 
  // Set push buttons as input  
  pinMode(FWDBTN, INPUT_PULLUP); 
  pinMode(BCKBTN, INPUT_PULLUP);
  pinMode(LFTTURN, INPUT_PULLUP);
  pinMode(RGHTTURN, INPUT_PULLUP);
  // Stop motors initially
  stopMotors();
}
 
void loop() {
 
  // Forward button logic  
  if(digitalRead(FWDBTN) == LOW) {
    moveForward(); 
  } else if(digitalRead(BCKBTN) == LOW) {
    moveBackward();
  } else if(digitalRead(LFTTURN) == LOW) {
    turnLeft();
  } else if(digitalRead(RGHTTURN) == LOW) {
    turnRight();
  } else {
    stopMotors();  
  }
}
 
// Define motion functions
 
void moveForward() {
// Logic to move forward
   // Move forward
  digitalWrite(motor1A, HIGH);
  digitalWrite(motor1B, LOW);
  digitalWrite(motor2A, HIGH);
  digitalWrite(motor2B, LOW);
}
 
void moveBackward() {
 
  // Logic to move backward
  // Move Backward
  digitalWrite(motor1A, LOW);
  digitalWrite(motor1B, HIGH);
  digitalWrite(motor2A, LOW);
  digitalWrite(motor2B, HIGH);
}
 
void turnLeft() {
 
  // Logic to turn left
  // Turn left
  digitalWrite(motor1A, LOW);
  digitalWrite(motor1B, HIGH);
  digitalWrite(motor2A, HIGH);
  digitalWrite(motor2B, LOW);
}
 
void turnRight() {
 
  // Logic to turn right
  // Turn right
  digitalWrite(motor1A, HIGH);
  digitalWrite(motor1B, LOW);
  digitalWrite(motor2A, LOW);
  digitalWrite(motor2B, HIGH); 
}
 
void stopMotors() {
 
  // Logic to stop motors
  // Stop
  digitalWrite(motor1A, LOW);
  digitalWrite(motor1B, LOW);
  digitalWrite(motor2A, LOW);
  digitalWrite(motor2B, LOW);
}
