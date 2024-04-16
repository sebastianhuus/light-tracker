int sensorTestPin = PIN_A0;

void initPhotoresistor() {
    // Initialize serial communication at 9600 bits per second:
    Serial.begin(9600);
}

void testPhotoresistor() {
    // Read the value from the photoresistor:
    int testLightLevel = analogRead(sensorTestPin);

    // Print the light level to the serial monitor:
    Serial.println(testLightLevel);

    // Wait for a short period to avoid spamming the serial monitor:
    delay(250);
}