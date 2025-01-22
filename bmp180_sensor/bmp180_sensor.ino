#include <Arduino.h>
#include <Wire.h>
#include <BMP180I2C.h>

#define I2C_ADDRESS 0x77  // Address of BMP180 is 0x77
int bled = 6;  // Blue LED pin for pressure
int rled = 7;  // Red LED pin for temperature

// Create a BMP180 object using the I2C interface
BMP180I2C bmpSensor(I2C_ADDRESS);

float tempThreshold = 28.0; // Temperature threshold (in °C) for the red LED
float pressureThreshold = 100630.0; // Pressure threshold (in Pa) for the blue LED

void setup() {
  // Set the LED pins as output
  pinMode(bled, OUTPUT);
  pinMode(rled, OUTPUT);

  Serial.begin(9600);  // Initialize serial communication

  // Wait for serial connection to open (only necessary on some boards)
  while (!Serial);

  Wire.begin();

  // Initialize the sensor
  if (!bmpSensor.begin()) {
    Serial.println("begin() failed. Check your BMP180 Interface and I2C Address.");
    while (1); // Stop execution if sensor initialization fails
  }

  // Reset sensor to default parameters to avoid previous configuration issues
  bmpSensor.resetToDefaults();

  // Enable ultra-high resolution mode for pressure measurements
  bmpSensor.setSamplingMode(BMP180MI::MODE_UHR);
}

void loop() {
  delay(1000);  // Wait for a second between readings

  // Start a temperature measurement
  if (!bmpSensor.measureTemperature()) {
    Serial.println("Could not start temperature measurement, is a measurement already running?");
    return;
  }

  // Wait for the temperature measurement to finish
  do {
    delay(100);
  } while (!bmpSensor.hasValue());

  // Get the temperature reading
  float tempReading = bmpSensor.getTemperature();
  Serial.print("Temperature: ");
  Serial.print(tempReading);
  Serial.println(" °C");

  // Start a pressure measurement (pressure depends on temperature measurement)
  if (!bmpSensor.measurePressure()) {
    Serial.println("Could not start pressure measurement, is a measurement already running?");
    return;
  }

  // Wait for the pressure measurement to finish
  do {
    delay(100);
  } while (!bmpSensor.hasValue());

  // Get the pressure reading
  float pressureReading = bmpSensor.getPressure();  // Use float for pressure
  Serial.print("Pressure: ");
  Serial.print(pressureReading);
  Serial.println(" Pa");

  // Control LEDs based on temperature and pressure readings
  // if (tempReading > tempThreshold) {
  //   digitalWrite(rled, HIGH);  // Turn on red LED if temperature exceeds threshold
  //   delay(500);  // Blink the LED for 500ms
  //   digitalWrite(rled, LOW);   // Turn off red LED
  //   delay(500);  // Wait for 500ms before next blink
  // }

  // if (pressureReading > pressureThreshold) {
  //   digitalWrite(bled, HIGH);  // Turn on blue LED if pressure exceeds threshold
  //   delay(500);  // Blink the LED for 500ms
  //   digitalWrite(bled, LOW);   // Turn off blue LED
  //   delay(500);  // Wait for 500ms before next blink
  // }
}
