#include <Adafruit_SoftServo.h>  // SoftwareServo (works on non PWM pins)
// Source: https://www.instructables.com/Continuous-Rotation-Servo-Arduino-UNO-a-Tutorial/

// Pin allocation
#define SERVOPIN 8           // Servo control line on digital pin 8
#define IR_SENSORPIN 9       // IR sensor output pin
#define LED 10               // LED output if needed

Adafruit_SoftServo myServo;  // Create servo object
   
void setup() {

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
  //fullTest();

  delay(500);                    
}

// Sensor blink test, if sensor detects something the LED will blink
void sensorTest() {

  if (digitalRead(IR_SENSORPIN) == LOW) {
    digitalWrite(LED, HIGH);
    delay(1000);
    digitalWrite(LED, LOW);
  }

}

// Servo speed control
void servoControl(int speed) {

  myServo.write(speed);
  myServo.refresh();

}

// Servo test, sets speed to 5 random values
void servoTest() {

  for (int i = 0; i < 5; i++) {
    servoControl(random(0,180));
    delay(1000);
  }

}

// Full test with IR sensor and servo
void fullTest() {

  if (digitalRead(IR_SENSORPIN) == LOW) {
    servoControl(180);          // Servo is full speed
  }
  else {
    servoControl(90);           // Servo is stationary
  }

}