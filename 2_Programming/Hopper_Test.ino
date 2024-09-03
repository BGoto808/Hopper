#include <Adafruit_SoftServo.h>  // SoftwareServo (works on non PWM pins)
// Source: https://www.instructables.com/Continuous-Rotation-Servo-Arduino-UNO-a-Tutorial/

// Pin allocation
#define SERVO1PIN 8          // Servo control line on digital pin 8
#define IR_SENSORPIN A0      // IR sensor output pin

Adafruit_SoftServo myServo;  // Create servo object
   
void setup() {

  pinMode(IR_SENSORPIN, INPUT_PULLUP);
  //pinMode(SERVO1PIN, OUTPUT);
  myServo.attach(SERVO1PIN);

  myServo.write(90);            // Servo is stationary
  delay(15);                    // Wait 15ms for the servo to reach the position
}

void loop()  {

  if (digitalRead(IR_SENSORPIN) == LOW) {
    servoControl(180);          // Servo is full speed
  }
  else {
    servoControl(90);           // Servo is stationary
  }
  
  delay(15);                              // waits 15ms for the servo to reach the position

}

void servoControl(int speed) {

  myServo.write(speed);
  myServo.refresh()

}