//defines ultrasonic sensor pins
const int trigPin = 4;//Trig pin of ultrasonic sensor connected to Arduino(D12)
const int echoPin = 5;//Echo pin of ultrasonic sensor connected to Arduino(D13)

#define MIN_DISTANCE 10
#define MAX_DISTANCE 30

//Left Motor connected to 4,5 digitalPins
int LMP = 8;
int LMN = 9;
//Right Motor connected to 10,9 digitalPins
int RMP = 10;
int RMN = 11;

//Left sensor on digitalpin 2
int LSP = 2;
//Right sensor on digitalpin 3
int RSP = 6;

//Declaring the variable duration & distance
long duration;
int distance;//Variable to store ultrasonic distance

void setup()
{
  //Motor pins are OUTPUT
  pinMode(LMP, OUTPUT); //Leftside Motor
  pinMode(LMN, OUTPUT); //Leftside Motor
  pinMode(RMP, OUTPUT); //Rightside Motor
  pinMode(RMN, OUTPUT); //Rightside Motor

  //IR Sensor pins are INPUT
  pinMode(LSP, INPUT); //Left IR Sensor(analog i/p)
  pinMode(RSP, INPUT); //Right IR Sensor(analog i/p)

  //Ultrasonic Sensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.begin(9600);
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

  int RSD = digitalRead(RSP);
  Serial.print("RSD");
  Serial.println(RSD);
  delay(250);
  int LSD = digitalRead(LSP);
  Serial.print("LSD");
  Serial.println(LSD);
  delay(250);

  if (distance < 10) //If the distance of object is less than 10 , then the robot will stop moving
  {
    //Stops moving the robot
    analogWrite(LMP, LOW);
    analogWrite(LMN, LOW);
    analogWrite(RMP, LOW);
    analogWrite(RMN, LOW);
    Serial.print("Stop");//Print Stop
    Serial.println();
  }
  //If IR sensor detects the hand then its value will be LOW else the value will be HIGH
  else if (RSD == 0 && LSD == 1) //If right sensor detects object(0) , then turn right. We increase left motor speed and decrease the right motor speed to turn towards right
  {
    //Turn Right
    analogWrite(LMP, HIGH);
    analogWrite(LMN, LOW);
    analogWrite(RMP, LOW);
    analogWrite(RMN, HIGH);
    Serial.print("Right");//Print Right
    Serial.println();
  }
  else if (RSD == 1 && LSD == 0) //If left sensor detects object(0) , then turn left. We increase right motor speed and decrease the left motor speed to turn towards left
  {
    //Turn Left
    analogWrite(LMP, LOW);
    analogWrite(LMN, HIGH);
    analogWrite(RMP, HIGH);
    analogWrite(RMN, LOW);
    Serial.print("Left");//Print Left
    Serial.println();
  }
  else if (RSD == 0 && LSD == 0) //If left & right sensors detects object(both values 0's) , then turn left. We increase right motor speed and decrease the left motor speed to turn towards left
  {
    //Moves Forward
    analogWrite(LMP, HIGH);
    analogWrite(LMN, LOW);
    analogWrite(RMP, HIGH);
    analogWrite(RMN, LOW);
    Serial.print("Forward");//Print Forward
    Serial.println();
  }
  else if (distance >= MIN_DISTANCE && distance <= MAX_DISTANCE) //If distance is between min(10) and max(30) then go to straight line
  {
    //Moves Forward
    analogWrite(LMP, HIGH);
    analogWrite(LMN, LOW);
    analogWrite(RMP, HIGH);
    analogWrite(RMN, LOW);
    Serial.print("Forward");//Print Forward
    Serial.println();
  }
  else//stop the motors
  {
    //Stops moving the robot
    analogWrite(LMP, LOW);
    analogWrite(LMN, LOW);
    analogWrite(RMP, LOW);
    analogWrite(RMN, LOW);
    Serial.print("Stop");//Print stop
    Serial.println();
  }
}
