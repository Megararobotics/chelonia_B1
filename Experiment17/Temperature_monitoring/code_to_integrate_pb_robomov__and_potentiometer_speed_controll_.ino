// Define motor pins
#define ENA 3 // Enable Motor A (PWM)
#define IN1 5 // Input 1 of Motor A
#define IN2 6 // Input 2 of Motor A
#define ENB 9 // Enable Motor B (PWM)
#define IN3 10 // Input 1 of Motor B
#define IN4 11 // Input 2 of Motor B

// Define potentiometer pin
#define POTENTIOMETER_PIN A0

// Define push button pin
#define BUTTON_PIN 2

boolean buttonState = false;

void setup() {
  // Motor pins as output
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

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
}

// Function to move the robot forward
void moveForward() {
  // Read the value of the potentiometer
  int potValue = analogRead(POTENTIOMETER_PIN);
  
  // Map the potentiometer value to PWM range (0-255)
  int speed = map(potValue, 0, 1023, 0, 255);
  
  // Set motor speed
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);

  // Move the robot forward
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

// Function to stop the robot
void stopMotors() {
  // Stop both motors
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}
