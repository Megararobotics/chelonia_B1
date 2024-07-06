//defines ultrasonic sensor pins
const int trigPin = 4;
const int echoPin = 5;

//Left Motor connected to 8,9 digitalPins
int LMP = 8;
int LMN = 9;
//Right Motor connected to 10,11 digitalPins
int RMP = 10;
int RMN = 11;

//Left sensors on digitalpin 2,6
int LSP = 2;
int RSP = 6;

// Initial Values of Sensors
int sensor[2] = {0, 0};

// defines variables
long duration , distance;
String A,B,C,D;

void setup() 
{
 //Motor pins are OUTPUT
 pinMode(LMP,OUTPUT);//Leftside Motor
 pinMode(LMN,OUTPUT);//Leftside Motor
 pinMode(RMP,OUTPUT);//Rightside Motor
 pinMode(RMN,OUTPUT);//Rightside Motor
 
 //IR Sensor pins are INPUT
 pinMode(LSP,INPUT);//Left IR Sensor
 pinMode(RSP,INPUT);//Right IR Sensor

 //ultrasonic sensor
 pinMode(trigPin, OUTPUT); 
 pinMode(echoPin, INPUT);

 Serial.begin(9600);   //setting serial monitor at a default baund rate of 9600
}

void loop() 
{ 
 digitalWrite(trigPin, LOW);
 delayMicroseconds(2);
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 distance= duration*0.034/2;
 Serial.print("Distance: ");
 Serial.println(distance);
  
 //Read sensor data and store it
 int LSD = digitalRead(LSP);
 Serial.print("LSD");  
 Serial.println(LSD);
 delay(250);
 int RSD = digitalRead(RSP);
 Serial.print("RSD");  
 Serial.println(RSD);
 delay(250);

 if(distance > 15)//If distance > 15 , then the following conditions will be executed
 {
  if(LSD == 0 && RSD == 0)//If left & right sensors are not in black line(0's) , then robot will move forward
  {
   //Moves Forward
   analogWrite(LMP,HIGH);
   analogWrite(LMN,LOW);
   analogWrite(RMP,HIGH);
   analogWrite(RMN,LOW);
   Serial.print("Forward");//Print Forward  
   Serial.println();
  } 
  else if(LSD == 1 && RSD == 0)//If Left sensor is in black line(1) and right sensor not in black line(0) , then robot will turn left direction and moves forward
  { 
   //Turns Left
   analogWrite(LMP,LOW);
   analogWrite(LMN,HIGH);
   analogWrite(RMP,HIGH);
   analogWrite(RMN,LOW);
   Serial.print("Left");//Print Left  
   Serial.println();
  }
  else if(LSD == 0 && RSD == 1)//If Right sensor is in black line(1) and left sensor is not in black line(0) , then robot will turn right direction and moves forward
  {
   //Turns Right
   analogWrite(LMP,HIGH);
   analogWrite(LMN,LOW);
   analogWrite(RMP,LOW);
   analogWrite(RMN,HIGH);
   Serial.print("Right");//Print Right  
   Serial.println();
  }
 }  
 else if(distance < 15)//If the distance < 15 from the obstacle , then the following conditions will be executed , i.e., the robot will stops running
 {
  //Stop 
  analogWrite(LMP,LOW);
  analogWrite(LMN,LOW);
  analogWrite(RMP,LOW);
  analogWrite(RMN,LOW);
  Serial.print("Stop");//Print Stop 
  Serial.println();
 }
}
