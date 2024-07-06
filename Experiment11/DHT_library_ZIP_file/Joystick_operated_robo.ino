//Code for Dual Axis Joystick
// Motor pins
#define ENA 3 // Enable Motor A (PWM)
#define IN1 5 // Input 1 of Motor A
#define IN2 6 // Input 2 of Motor A
#define ENB 9 // Enable Motor B (PWM)
#define IN3 10 // Input 1 of Motor B
#define IN4 11 // Input 2 of Motor B
 
// Joystick pins
#define Xaxis_pin A0 // Arduino pin connected to the VRx Pin
#define Yaxis_pin A1 // Arduino pin connected to the VRy Pin
#define SW_pin A2    // Arduino pin connected to the SW Pin
 
// Joystick thresholds
#define THRESHOLD 512 // Define the midpoint for joystick reading
 
void setup() {
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH); // Enable pull-up resistor
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  Serial.begin(9600);
}
 
void loop() {
  int xValue = analogRead(Xaxis_pin);
  int yValue = analogRead(Yaxis_pin);
  if (xValue < 400) {
    // Move left
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(ENA, map(xValue, 0, THRESHOLD, 0, 255));
    analogWrite(ENB, map(xValue, 0, THRESHOLD, 0, 255));
  } else if (xValue > 600) {
    // Move right
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENA, map(xValue, THRESHOLD, 1023, 0, 255));
    analogWrite(ENB, map(xValue, THRESHOLD, 1023, 0, 255));
  } else if (yValue < 400) {
    // Move backward
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENA, map(yValue, 0, THRESHOLD, 0, 255));
    analogWrite(ENB, map(yValue, 0, THRESHOLD, 0, 255));
  } else if (yValue > 600) {
    // Move forward
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(ENA, map(yValue, THRESHOLD, 1023, 0, 255));
    analogWrite(ENB, map(yValue, THRESHOLD, 1023, 0, 255));
  } else {
    // Stop motors if joystick is at the center
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    analogWrite(ENA, 0);
    analogWrite(ENB, 0);
  }
 
  Serial.print("X-axis: ");
  Serial.print(xValue);
  Serial.print(" : ");
  Serial.print("Y-axis: ");
  Serial.print(yValue);
  Serial.print(" : ");
  Serial.print("Switch:  ");
  Serial.println(digitalRead(SW_pin));
  delay(200);
}