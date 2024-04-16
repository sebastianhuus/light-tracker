#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int servoPin = 3;
int sensorPin = PIN_A0;

void setup() {
    myservo.attach(servoPin);  // attaches the servo on pin 9 to the servo object

    // Initialize serial communication at 9600 bits per second:
    Serial.begin(9600);
}

void loop() {
    // Read the value from the photoresistor:
    int lightLevel = analogRead(sensorPin);

    // Print the light level to the serial monitor:
    Serial.println(lightLevel);

    // Wait for a short period to avoid spamming the serial monitor:
    delay(250);
}