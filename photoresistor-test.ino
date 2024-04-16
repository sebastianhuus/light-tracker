

/**
 * @file photoresistor-test.ino
 * @brief This file contains functions to test a photoresistor and print the light level to the serial monitor.
 */

int sensorTestPin = PIN_A0;

/**
 * @brief Initializes the photoresistor by setting up the serial communication.
 */
void initPhotoresistor() {
    // Initialize serial communication at 9600 bits per second:
    Serial.begin(9600);
}

/**
 * @brief Tests the photoresistor by reading the light level and printing it to the serial monitor.
 */
void testPhotoresistor() {
    // Read the value from the photoresistor:
    int testLightLevel = analogRead(sensorTestPin);

    // Print the light level to the serial monitor:
    Serial.println(testLightLevel);

    // Wait for a short period to avoid spamming the serial monitor:
    delay(250);
}