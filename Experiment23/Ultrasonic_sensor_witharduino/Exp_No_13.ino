//Adjustng speed w.r.t us sensor and display the current status in app
//#include <SoftwareSerial.h>
 
// defines ultrasonic sensor pins
const int trigPin = 4;
const int echoPin = 5;
 
// Defines variables
long duration, distance;
String status = "";
 
// defines motorpins 
const int motor1A = 8;
const int motor1B = 9;
const int motor2A = 10;
const int motor2B = 11;
 
// Bluetooth module pins
//SoftwareSerial BTSerial(2, 3); // RX | TX (Change these pins as per your module's connection)
 
// defines variables
String A,B,C,D;
 
void setup()
{
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT);
 
pinMode(motor1A, OUTPUT); 
pinMode(motor1B, OUTPUT);
pinMode(motor2A, OUTPUT);
pinMode(motor2B, OUTPUT);
Serial.begin(9600); // Starts the serial communication
 
// Start Bluetooth communication
//BTSerial.begin(9600);
 
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
 
distance= (duration/2)/28.5;
 
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
Serial.println(" cm");
 
  // Send ultrasonic sensor data to mobile app via Bluetooth
  /*BTSerial.print("Distance: ");
  BTSerial.print(distance);
  BTSerial.println(" cm");*/
 
  // Simulate monitor status
  //status = "Normal"; // Change status as per your monitoring conditions
  // Send monitor status to mobile app via Bluetooth
  /*BTSerial.print("Status: ");
  BTSerial.println(status);*/
 
  delay(1000); // Adjust delay based on your requirements
 
 
if(distance >= 80)             //check wheather the distance >= 80
{                              //If the above condition is 'true' then the statement below will execute 
   //Moves Forward with high speed
   digitalWrite(motor1A, LOW);
   analogWrite(motor1B, 255);
   analogWrite(motor2A, 255);
   analogWrite(motor2B, 0);
   Serial.print("Moving Forward with full speed");           //Print A 
   //Serial.println();
   //BTSerial.print("Moving Forward with full speed");
}
else if(distance >= 50 )       //check wheather the distance >= 50
{                              //If above the condition is 'true' then the statement below will execute
   //Move Forward with less speed than above
   digitalWrite(motor1A, LOW);
   analogWrite(motor1B, 175);
   analogWrite(motor2A, 175);
   analogWrite(motor2B, 0);
   Serial.print("Moving Forward with speed:175");           //Print B
   //Serial.println();
   //BTSerial.print("Moving Forward with speed:175");
} 
else if(distance >= 10)        //check wheather the distance >= 10
{                              //If above the condition is 'true' then the statement below will execute
   //Move Forward with less speed than above
   digitalWrite(motor1A, LOW);
   analogWrite(motor1B, 100);
   analogWrite(motor2A, 100);
   analogWrite(motor2B, 0);
   Serial.print("Moving Forward with speed:100");            
   //Serial.println();
   //BTSerial.print("Moving Forward with speed:100");
}
else                           //If obstacle detects with distance <10, then the robot turns right direction and moves forward
{
  digitalWrite(motor1A, LOW);
  analogWrite(motor1B, 0);
  analogWrite(motor2A, 0);
  analogWrite(motor2B, 0);
  Serial.print("Stopped");           //Print D    
  //Serial.println();
  //BTSerial.print("Stopped");
  //delay(900);
}
}
