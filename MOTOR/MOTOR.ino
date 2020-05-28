/* NOTES
  Lib source https://github.com/AndreaLombardo/L298N/
  Speed range go from 0 to 255, default is 100.

  Wiring schema in file "L298NX2 - Schema_without_EN_pin.png"
*/

// Include the libraries
#include <L298NX2.h>
#include <SoftwareSerial.h>

// Pin definition
const unsigned int LEFT_IN1_A = 2;
const unsigned int LEFT_IN2_A = 3;

const unsigned int LEFT_IN1_B = 4;
const unsigned int LEFT_IN2_B = 5;

// const unsigned int EN_A = 3;
const unsigned int RIGHT_IN1_A = 6;
const unsigned int RIGHT_IN2_A = 7;

const unsigned int RIGHT_IN1_B = 8;
const unsigned int RIGHT_IN2_B = 9;
// const unsigned int EN_B = 9;

int stepA = 1;

int inByte;

char forward = 0x10;
char backward = 0x11;
char right = 0x12;
char left = 0x13;

long lastCommandReceivedAt;

// Initialize both motors
L298NX2 rightMotors(RIGHT_IN1_A, RIGHT_IN2_A, RIGHT_IN1_B, RIGHT_IN2_B);
L298NX2 leftMotors(LEFT_IN1_A, LEFT_IN2_A, LEFT_IN1_B, LEFT_IN2_B);

SoftwareSerial bluetoothSerial(2, 3); // RX, TX

void setup()
{
  // Used to display information
  Serial.begin(9600);

  // Wait for Serial Monitor to be opened
  while (!Serial) {
    //do nothing
  }

  //initialize bluetooth serial communication
  bluetoothSerial.begin(9600);
  Serial.println("Inicializando!");

  // Set initial speed for both motors
  rightMotors.setSpeed(100);
  leftMotors.setSpeed(100);
}

void loop()
{

  if (bluetoothSerial.available()) {
    inByte = bluetoothSerial.read();
    lastCommandReceivedAt = millis();
    //print lasto received command
    Serial.println(inByte);
  }

  // If the last command was received in more than...
  if ((millis() - lastCommandReceivedAt) > 2300 )
  {
    stopAllMotors(); //stop all the motors
    lastCommandReceivedAt = millis(); //restart the counter

    //parando o motor depois de um tempo X sem comando evitamos que ele fique parado em um certo comando por conta da perca de conexão do bluetooth, ou travamento do aplicativo, ou no caso da tela do celular apagar.
  }


  switch (stepA)
  {
    case 1:
      // Tell both motors to go forward (may depend by your wiring)
      //      rightMotors.forwardA();
      //      rightMotors.backwardB();
      //      leftMotors.forwardA();
      //      leftMotors.backwardB();

      break;

    case 2:
      // Change individual side speeds
      rightMotors.setSpeed(255);
      leftMotors.setSpeed(90);

      break;

    case 3:
      // Stop
      rightMotors.stop();
      leftMotors.stop();
      break;

    case 4:
      break;

    case 5:
      break;
  }

  if (stepA < 5)
  {
    stepA++;
  }
  else
  {
    stepA = 1;
  }

  printSomeInfo();
  delay(3000);






  //  printSomeInfo();
  //
  //  delay(3000);


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
  Serial.print("Right Motor A is moving = ");
  Serial.print(rightMotors.isMovingA() ? "YES" : "NO");
  Serial.print(" at speed = ");
  Serial.println(rightMotors.getSpeedA());
  Serial.print("Right Motor B is moving = ");
  Serial.print(rightMotors.isMovingB() ? "YES" : "NO");
  Serial.print(" at speed = ");
  Serial.println(rightMotors.getSpeedB());

  Serial.print("Left Motor A is moving = ");
  Serial.print(leftMotors.isMovingA() ? "YES" : "NO");
  Serial.print(" at speed = ");
  Serial.println(leftMotors.getSpeedA());
  Serial.print("Left Motor B is moving = ");
  Serial.print(leftMotors.isMovingB() ? "YES" : "NO");
  Serial.print(" at speed = ");
  Serial.println(leftMotors.getSpeedB());
}


void stopAllMotors(){
  rightMotors.stop();
  leftMotors.stop();
}
