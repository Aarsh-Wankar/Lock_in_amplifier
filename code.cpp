#include <math.h>
const int analogPin1 = A0; // Analog input pin
const int analogPin2 = A5;
float sensorValue1 = 0;
float sensorValue2 = 0;      // Variable to store the sensor value

void setup() {
    Serial.begin(9600);   // Initialize serial communication
}

void loop() {
    // Read analog input
    int sensorsum1 = 0;
    int sensorsum2 = 0;
    for (int i =0; i<50; i++){
      sensorsum1 += analogRead(analogPin1);
      delay(20);
    }
    sensorValue1 = sensorsum1/50;
    delay(100);
    for (int i =0; i<50; i++){
      sensorsum2 += analogRead(analogPin2);
      delay(20);
    }
    sensorValue2 = sensorsum2/50;
    // Print the analog value to the serial monitor
    // Serial.print("Sensor 1: ");
    // Serial.print(sensorValue1*(5000.0/1023.0)+50.0);
    // Serial.print("    ");
    // Serial.print("Sensor 2: ");
    // Serial.println(sensorValue2*(5000.0/1023.0)+20.0);
    float volt1 = sensorValue1*(5000.0/1023.0)+50.0;
    float volt2 = sensorValue2*(5000.0/1023.0)+20.0;
    double degrees = (atan2(volt1/70, volt2/68))*180/PI;
    Serial.print("Voltage in mvpp: ");
    Serial.print(sqrt(sq(volt1/70)+sq(volt2/68)));
    Serial.print("    Phase: ");
    Serial.println(round(degrees));

    delay(200);  // Wait for 1 second before taking the next reading
}
