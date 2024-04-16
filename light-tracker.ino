#include <Servo.h>  // simplifies servo logic in the code
#include <math.h>   // used for abs() call

Servo myservo;  // create servo object to control a servo

int servoPin = 3;       // pwm pin for the servo
int sensorPin = PIN_A0; // analog pin for light-dependent resistor

int previousLightLevel; // Variable to track the previous read's light levels. used for delta calculations

// define two flags i can use to track velocity
#define INCREASING 1
#define DECREASING -1

int servoPosition = 90;  // The current position of the servo motor in degrees. Initalized at 90 degrees
int servoState = INCREASING;  // The current state of the servo motor. It can be either INCREASING or DECREASING.


void setup() {
    myservo.attach(servoPin);  // attaches the servo on pin 9 to the servo object
    myservo.write(servoPosition); // init servo to 90 degrees

    // Initialize serial communication at 9600 bits per second:
    Serial.begin(9600);
    previousLightLevel = analogRead(sensorPin);
}

void loop() {
    // Read the value from the photoresistor:
    int currentLightLevel = analogRead(sensorPin);

    // calculate difference in light level since last scan
    int lightLevelDelta = currentLightLevel - previousLightLevel;

    // Delta less than 0 indicates a negative development in light level. 
    // Other cases indicate that development is 0 or positive,
    // and in that case we should just continue rotating in current direction.
    if ( lightLevelDelta < 0 ) {
        // Only reverse if the difference is larger than the threshold
        if ( abs(lightLevelDelta) >= 5 ) { reverseDirection(); }
    }

    if ( servoState == INCREASING ) {
        increaseAngle(5);
    }
    else if ( servoState == DECREASING ) {
        decreaseAngle(5);
    }

    printLightInfo(currentLightLevel, lightLevelDelta);

    // Wait for a short period to avoid spamming the serial monitor and moving the servo too often:
    delay(250);

    // Update the delta tracker
    previousLightLevel = currentLightLevel;
}

void printLightInfo(int currentLightLevel, int lightLevelDelta) {
    // Print the light levels and delta to the serial monitor:
    Serial.print("Light Level: ");
    Serial.print(currentLightLevel);
    Serial.print(" | Previous Light Level: ");
    Serial.print(previousLightLevel);
    Serial.print(" | Light Level Delta: ");
    Serial.println(lightLevelDelta);
}

void reverseDirection() {
    // Reverse the velocity
    if (servoState == INCREASING) { servoState = DECREASING; }
    else if (servoState == DECREASING) { servoState = INCREASING; }
}

/**
 * Increases the angle of the servo motor by the specified increment.
 * 
 * @param increment The amount by which to increase the angle.
 */
void increaseAngle(int increment) {
    int newPosition = servoPosition + increment;
    if (newPosition > 180) {
        newPosition = 180;
    }

    myservo.write(newPosition);
    servoPosition = newPosition;
}

/**
 * Decreases the angle of the servo motor by the specified decrement value.
 * 
 * @param decrement The amount by which to decrement the angle.
 */
void decreaseAngle(int decrement) {
    int newPosition = servoPosition - decrement;
    if (newPosition < 0) {
        newPosition = 0;
    }

    myservo.write(newPosition);
    servoPosition = newPosition;
}