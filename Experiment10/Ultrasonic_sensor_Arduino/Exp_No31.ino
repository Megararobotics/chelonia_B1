//Air quality monitor robo
#define Sensor A0
#define IN1 8 // Input 1 of Motor A
#define IN2 9 // Input 2 of Motor A
#define IN3 10 // Input 1 of Motor B
#define IN4 11 // Input 2 of Motor B
 
void setup() {
  Serial.begin(9600); // Change the baud rate to 9600
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  //Serial1.begin(9600); // Start Bluetooth communication at 9600 baud
}
 
void loop() {
  int value = analogRead(Sensor);
  Serial.print("Value: ");
  Serial.println(value);
 
  if (value > 181) {
    stopMotors();
    Serial.println("Air quality not good");
  } else {
    Serial.println("Air quality good");
    moveForward();
  }
 
  delay(1000); // Add a delay to reduce the rate of serial prints
}
// Function to move the robot forward
void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  //analogWrite(ENA, 200); // Adjust the PWM value for motor speed
  //analogWrite(ENB, 200); // Adjust the PWM value for motor speed
}
 
// Function to stop the robot
void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  //analogWrite(ENA, 0); // Stop motor A
  //analogWrite(ENB, 0); // Stop motor B
}
