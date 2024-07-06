#include <SPI.h>
#include <MFRC522.h>
//#include <SoftwareSerial.h>  // Include the SoftwareSerial library for Bluetooth communication

#define SS_PIN 10
#define RST_PIN 5

//#define RX_PIN 2   // Define the RX pin for Bluetooth communication
//#define TX_PIN 3   // Define the TX pin for Bluetooth communication

// Define motor pins
#define IN1 9 // Input 1 of Motor A
#define IN2 8 // Input 2 of Motor A
#define IN3 7 // Input 1 of Motor B
#define IN4 3 // Input 2 of Motor B

// Define push button pin
#define BUTTON_PIN 2

boolean buttonState = false;

MFRC522 rfid(SS_PIN, RST_PIN);

//SoftwareSerial bluetoothSerial(RX_PIN, TX_PIN);  // Create a SoftwareSerial object

void setup() {
  Serial.begin(9600);
  //bluetoothSerial.begin(9600);  // Initialize Bluetooth communication

  SPI.begin(); // init SPI bus
  rfid.PCD_Init(); // init MFRC522

  Serial.println("Tap RFID/NFC Tag on reader");
  // Motor pins as output
  //pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  //pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Push button pin as input
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  // Initially stop the motors
  stopMotors();
}

void loop() {
  if (rfid.PICC_IsNewCardPresent()) { // new tag is available
    if (rfid.PICC_ReadCardSerial()) { // NUID has been read
      MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
      Serial.print("UID:");
      for (int i = 0; i < rfid.uid.size; i++) {
        Serial.print(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");
        Serial.print(rfid.uid.uidByte[i], HEX);
      }
      Serial.println();

      // Send message to Bluetooth app
      Serial.println("Robo passes");

      rfid.PICC_HaltA(); // halt PICC
      rfid.PCD_StopCrypto1(); // stop encryption on PCD
    }
  }
  // Check if the button is pressed
  if (digitalRead(BUTTON_PIN) == LOW) {
    // Button is pressed, move the robot forward
    moveForward();
  } else {
    // Button is released, stop the robot
    stopMotors();
  }
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
