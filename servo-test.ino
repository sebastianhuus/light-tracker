#include <Servo.h>

Servo myTestservo;  // create servo object to control a servo

int servoTestPin = 3;

void initServo() {
  myTestservo.attach(servoTestPin);  // attaches the servo on pin 9 to the servo object
}

void testServo() {
  for (int pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    myTestservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (int pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees back to 0 degrees
    myTestservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}