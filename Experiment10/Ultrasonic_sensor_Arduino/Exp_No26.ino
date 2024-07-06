//Clap robo
// Define motor pins
int motor1A = 8;
int motor1B = 9;
int motor2A = 10;
int motor2B = 11;

int soundSensor = 2;

void setup() {
  pinMode(soundSensor, INPUT);
  pinMode(motor1A, OUTPUT);
  pinMode(motor1B, OUTPUT);
  pinMode(motor2A, OUTPUT);
  pinMode(motor2B, OUTPUT);
}
void loop() {
  int SensorData = digitalRead(soundSensor);
  if (SensorData == 1) {

    // Move forward
    digitalWrite(motor1A, HIGH);
    digitalWrite(motor1B, LOW);
    digitalWrite(motor2A, HIGH);
    digitalWrite(motor2B, LOW);
  }
  else {
    // Stop
    digitalWrite(motor1A, LOW);
    digitalWrite(motor1B, LOW);
    digitalWrite(motor2A, LOW);
    digitalWrite(motor2B, LOW);
  }
}
