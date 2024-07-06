//Speed control using a Joystick. 
// Motor pins
#define ENA 9 // Enable Motor A (PWM)
#define IN1 8 // Input 1 of Motor A
#define IN2 7 // Input 2 of Motor A
#define ENB 3 // Enable Motor B (PWM)
#define IN3 5 // Input 1 of Motor B
#define IN4 4 // Input 2 of Motor B
 
// Joystick pins
#define Xaxis_pin A0 // Arduino pin connected to the VRx Pin
#define Yaxis_pin A1 // Arduino pin connected to the VRy Pin
 
void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  Serial.begin(9600);
}
 
void loop() {
  int xValue = analogRead(Xaxis_pin); // Read X-axis value from joystick
  int yValue = analogRead(Yaxis_pin); // Read Y-axis value from joystick
  int speedA = map(yValue, 0, 1023, -255, 255); // Map Y-axis value to speed range for motor A
  int speedB = map(xValue, 0, 1023, -255, 255); // Map X-axis value to speed range for motor B
  // Adjust direction and speed for motor A
  if (speedA >= 0) {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
  } else {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    speedA = -speedA; // Make speed positive for backward direction
  }
  // Adjust direction and speed for motor B
  if (speedB >= 0) {
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  } else {
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    speedB = -speedB; // Make speed positive for backward direction
  }
  // Set speed for motor A and B
  analogWrite(ENA, speedA);
  analogWrite(ENB, speedB);
 
  // Print joystick values for debugging
  Serial.print("Motor A Speed: ");
  Serial.print(speedA);
  Serial.print(" | Motor B Speed: ");
  Serial.println(speedB);
  delay(100); // Adjust delay as needed
}
