#include <Adafruit_SoftServo.h>  // SoftwareServo (works on non PWM pins)
// Source: https://www.instructables.com/Continuous-Rotation-Servo-Arduino-UNO-a-Tutorial/

/*

PCB NOTES:
- 40mm length
- (3) AAA batteries
- On/off switch (push button)
- LED to tell if it's on

*/

// Pin allocation
#define SERVOPIN 8           // Servo control line on digital pin 8, 5V
#define IR_SENSORPIN 9       // IR sensor output pin, 3.3V, ADD 220 RESISTOR <-- Tested, can also be 5V
#define LED 10               // LED output if needed, ADD 220 RESISTOR

Adafruit_SoftServo myServo;  // Create servo object

void setup() {
  
  // Initiating Serial communication
  Serial.begin(9600);

  // Initiating pins
  pinMode(IR_SENSORPIN, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  myServo.attach(SERVOPIN);

  // Setting values on pins
  digitalWrite(LED, LOW);

  // Delay for 15ms  
  delay(15);  
}

void loop()  {

  //sensorTest();
  //servoTest();
  fullTest();

  delay(20);                    
}

// Sensor blink test, if sensor detects something the LED will blink
void sensorTest() {
  if (digitalRead(IR_SENSORPIN) == LOW)
    digitalWrite(LED, HIGH);
  else
    digitalWrite(LED, LOW);
}

// Servo speed control with default function
void servoControl(int speed) {
  myServo.write(speed);
  myServo.refresh();
}

// Servo test, full speed forward
void servoTest() {
  servoControl(180);
}

// Full test with IR sensor and servo
void fullTest() {
  if (digitalRead(IR_SENSORPIN) == LOW)
    servoControl(90);             // Servo is stationary
  else
    servoControl(180);            // Servo moves full speed forward
}