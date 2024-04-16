/*
  This file contains code to control a servo motor using an Arduino board.
  The servo motor rotates from 0 degrees to 180 degrees and then back to 0 degrees.
*/

#include <Servo.h>

Servo myTestservo;  // create servo object to control a servo

int servoTestPin = 3;

void initServo() {
  /*
    Initializes the servo by attaching it to the specified pin.
  */
  myTestservo.attach(servoTestPin);  // attaches the servo on pin 9 to the servo object
}

void testServo() {
  /*
    Tests the servo by rotating it from 0 degrees to 180 degrees and then back to 0 degrees.
  */
  for (int pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    myTestservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (int pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees back to 0 degrees
    myTestservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}