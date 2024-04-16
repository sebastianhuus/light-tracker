#include <Servo.h>
#include <math.h>

Servo myservo;  // create servo object to control a servo

int servoPin = 3;
int sensorPin = PIN_A0;

int previousLightLevel; // Variable to track the previous read's light levels. used for delta calculations

void setup() {
    myservo.attach(servoPin);  // attaches the servo on pin 9 to the servo object

    // Initialize serial communication at 9600 bits per second:
    Serial.begin(9600);
    previousLightLevel = analogRead(sensorPin);
}

void loop() {
    // Read the value from the photoresistor:
    int lightLevel = analogRead(sensorPin);

    // calculate difference in light level since last scan
    int deltaLight = lightLevel - previousLightLevel;

    // if the absolute difference is large enough, then we should move. otherwise, stand still
    if ( abs(deltaLight) > 10) {
        // rotate servo
    }

    // Print the light level to the serial monitor:
    Serial.println(lightLevel);

    // Wait for a short period to avoid spamming the serial monitor:
    delay(250);
}