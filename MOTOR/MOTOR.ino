/* NOTES
Lib source https://github.com/AndreaLombardo/L298N/
Speed range go from 0 to 255, default is 100.

Wiring schema in file "L298NX2 - Schema_without_EN_pin.png"
*/

// Include the (new) library
#include <L298NX2.h>

// Pin definition
// const unsigned int EN_A = 3;
const unsigned int IN1_A = 5;
const unsigned int IN2_A = 6;

const unsigned int IN1_B = 7;
const unsigned int IN2_B = 8;
// const unsigned int EN_B = 9;

// Initialize both motors
L298NX2 rightMotors(IN1_A, IN2_A, IN1_B, IN2_B);

void setup()
{
  // Used to display information
  Serial.begin(9600);

  // Wait for Serial Monitor to be opened
  while (!Serial) {
    //do nothing
  }

  // Set initial speed for both motors
  rightMotors.setSpeed(100);
}

void loop()
{
  // Tell both motors to go forward (may depend by your wiring)
  rightMotors.forwardA();
  rightMotors.backwardB();

  // Alternative method:
  // motors.run(L298N::FORWARD);

  //print the motor satus in the serial monitor
  printSomeInfo();

  delay(3000);

  // Stop
  rightMotors.stop();

  // Alternative method:
  // motors.run(L298N::STOP);

   printSomeInfo();

   delay(3000);

  // Change individual speeds
  // motors.setSpeedA(255);
  // motors.setSpeedB(90);

  // Tell motor A to go back (may depend by your wiring)
//  motors.backwardA();

  // Alternative method:
  // motors.runA(L298N::BACKWARD);

  // Tell motor B to go forward (may depend by your wiring)
//  motors.backwardB();

  // Alternative method:
  // motors.runB(L298N::FORWARD);

//  printSomeInfo();

//  delay(3000);

  // Stop
//  motors.stop();

//  printSomeInfo();

  // Change individual speeds
//  motors.setSpeedA(90);
//  motors.setSpeedB(255);

//  delay(3000);
}

/*
Print some informations in Serial Monitor
*/
void printSomeInfo()
{
  Serial.print("Motor A is moving = ");
  Serial.print(rightMotors.isMovingA() ? "YES" : "NO");
  Serial.print(" at speed = ");
  Serial.println(rightMotors.getSpeedA());
  Serial.print("Motor B is moving = ");
  Serial.print(rightMotors.isMovingB() ? "YES" : "NO");
  Serial.print(" at speed = ");
  Serial.println(rightMotors.getSpeedB());
}
