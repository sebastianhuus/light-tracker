#include <Servo.h>
#include <math.h>

Servo myservo;  // create servo object to control a servo

int servoPin = 3;
int sensorPin = PIN_A0;

int previousLightLevel; // Variable to track the previous read's light levels. used for delta calculations

// define two flags i can use to track velocity
#define INCREASING 1
#define DECREASING -1

int servoPosition = 90;
int servoState = INCREASING;


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

    // Wait for a short period to avoid spamming the serial monitor:
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

void increaseAngle(int increment) {
    int newPosition = servoPosition + increment;
    if (newPosition > 180) {
        newPosition = 180;
    }

    myservo.write(newPosition);
    servoPosition = newPosition;
}

void decreaseAngle(int decrement) {
    int newPosition = servoPosition - decrement;
    if (newPosition < 0) {
        newPosition = 0;
    }

    myservo.write(newPosition);
    servoPosition = newPosition;
}