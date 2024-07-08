#include <DHT.h> // Include the DHT library for humidity and temperature sensor

#define DHTPIN 2     // Define the digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // Define the type of DHT sensor (DHT11 or DHT22)
DHT dht(DHTPIN, DHTTYPE); // Create a DHT object

// Motor control pins
const int motorAPin1 = 8;
const int motorAPin2 = 9;
const int motorBPin1 = 10;
const int motorBPin2 = 11;

// Ultrasonic sensor pins
const int trigPin = 4;
const int echoPin = 5;

void setup() {
  Serial.begin(9600); // Start serial communication for debugging
  dht.begin(); // Start the DHT sensor

  // Set motor control pins as OUTPUT
  pinMode(motorAPin1, OUTPUT);
  pinMode(motorAPin2, OUTPUT);
  pinMode(motorBPin1, OUTPUT);
  pinMode(motorBPin2, OUTPUT);

  // Set ultrasonic sensor pins as INPUT
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Read humidity and temperature from the DHT sensor
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Check if any reads failed
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Print humidity and temperature values to serial monitor
  //Serial.print("Humidity: ");
  //Serial.print(humidity);
  Serial.print("%\t");
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println("°C");


  // Example motor control: Move forward continuously
  moveForward();

  // Check for obstacles using ultrasonic sensor
  if (checkObstacle()) {
    // If obstacle detected, stop and turn left
    stopMotors();
    turnLeft();
    delay(1000); // Adjust as needed for turn duration
  }
}

void moveForward() {
  digitalWrite(motorAPin1, HIGH);
  digitalWrite(motorAPin2, LOW);
  digitalWrite(motorBPin1, HIGH);
  digitalWrite(motorBPin2, LOW);
}

void stopMotors() {
  digitalWrite(motorAPin1, LOW);
  digitalWrite(motorAPin2, LOW);
  digitalWrite(motorBPin1, LOW);
  digitalWrite(motorBPin2, LOW);
}

void turnLeft() {
  digitalWrite(motorAPin1, LOW);
  digitalWrite(motorAPin2, LOW);
  digitalWrite(motorBPin1, HIGH);
  digitalWrite(motorBPin2, LOW);
}

bool checkObstacle() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  float distance = (duration * 0.0343) / 2; // Calculate distance in cm
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print("\t");

  if (distance < 10) { // Adjust distance threshold as needed
    return true; // Obstacle detected
  } else {
    return false; // No obstacle detected
  }
}
