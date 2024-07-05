#define in1 8
#define in2 9
 
#define in3 10
#define in4 11

 
int xAxis = 140, yAxis = 140;
 
int motorSpeedA = 0;
int motorSpeedB = 0;
 
void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  Serial.begin(9600);
  //delay(500);
}
 
void loop() {
  // Default value - no movement when the Joystick stays in the center
  xAxis = 140;
  yAxis = 140;
 
  // Read the incoming data from the Smartphone Android App
  while (Serial.available() >= 2) {
    xAxis = Serial.read();
    delay(10);
    yAxis = Serial.read();
    Serial.print(xAxis);
    Serial.print(",");
    Serial.println(yAxis);
  }
  delay(10);
  // Makes sure we receive correct values
 
  if (xAxis > 130 && xAxis < 150 && yAxis > 130 && yAxis < 150) {
    Stop();
  }
 
  if (yAxis > 130 && yAxis < 150) {
 
    if (xAxis < 130) {
      turnRight();
      motorSpeedA = map(xAxis, 130, 60, 0, 255);
      motorSpeedB = map(xAxis, 130, 60, 0, 255);    
    }
 
    if (xAxis > 150) {
      turnLeft();
      motorSpeedA = map(xAxis, 150, 220, 0, 255);
      motorSpeedB = map(xAxis, 150, 220, 0, 255); 
    }
 
  } else {
 
    if (xAxis > 130 && xAxis < 150) {
 
      if (yAxis < 130) {
        forward();
      }
      if (yAxis > 150) {
        backward();
      }
 
      if (yAxis < 130) {
        motorSpeedA = map(yAxis, 130, 60, 0, 255);
        motorSpeedB = map(yAxis, 130, 60, 0, 255); 
      }
 
      if (yAxis > 150) {
        motorSpeedA = map(yAxis, 150, 220, 0, 255);
        motorSpeedB = map(yAxis, 150, 220, 0, 255);
      }
    } else {
 
      if (yAxis < 130) {
        forward();
      }
      if (yAxis > 150) {
        backward();
      }
 
      if (xAxis < 130) {
        motorSpeedA = map(xAxis, 130, 60, 255, 50);
        motorSpeedB = 255; 
      }
      if (xAxis > 150) {
        motorSpeedA = 255;
        motorSpeedB = map(xAxis, 150, 220, 255, 50); 
      }
    } 
  }
 
  analogWrite(enA, motorSpeedA); // Send PWM signal to motor A
  analogWrite(enB, motorSpeedB); // Send PWM signal to motor B
}
 
 
void forward() {
  Serial.println("forward");
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW); 
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
 
void backward() {
  Serial.println("backward");
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH); 
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}
 
void turnRight() {
  Serial.println("turnRight");
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW); 
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}
 
void turnLeft() {
  Serial.println("turnLeft");
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH); 
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
 
void Stop() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW); 
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  Serial.println("stop");
}
