// defines ultrasonic sensor pins
const int trigPin = 2;
const int echoPin = 3;
 
// Defines variables
long duration, distance;
String status = "";
 
// defines motorpins
const int motor1A = 8;
const int motor1B = 9;
const int motor2A = 10;
const int motor2B = 11;
 
// defines variables
String A, B, C, D;
 
void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
 
  pinMode(motor1A, OUTPUT);
  pinMode(motor1B, OUTPUT);
  pinMode(motor2A, OUTPUT);
  pinMode(motor2B, OUTPUT);
 
  Serial.begin(9600); // Starts the serial communication
 
}
 
void loop()
{
 
  // Clears the trigPin
 
  digitalWrite(trigPin, LOW);
 
  delayMicroseconds(2);
 
  // Sets the trigPin on HIGH state for 10 micro seconds
 
  digitalWrite(trigPin, HIGH);
 
  delayMicroseconds(10);
 
  digitalWrite(trigPin, LOW);
 
  // Reads the echoPin, returns the sound wave travel time in microseconds
 
  duration = pulseIn(echoPin, HIGH);
 
  // Calculating the distance
 
  distance = (duration / 2) / 28.5;
 
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
  Serial.println(" cm");
 
  if (distance >= 50)            //check wheather the distance >= 50
  { //If the above condition is 'true' then the statement below will execute
    //Moves Forward with high speed
    digitalWrite(motor1A, HIGH);
    digitalWrite(motor1B, LOW);
    digitalWrite(motor2A, HIGH);
    digitalWrite(motor2B, LOW);
    Serial.print("NO OBSTACLES NEARBY");
  }
  else
  { //If above the condition is 'true' then the statement below will execute
    //STOPS
    digitalWrite(motor1A, LOW);
    digitalWrite(motor1B, LOW);
    digitalWrite(motor2A, LOW);
    digitalWrite(motor2B, LOW);
    Serial.print("Obstacle detected nearby and Robo Stops");
  }
}
