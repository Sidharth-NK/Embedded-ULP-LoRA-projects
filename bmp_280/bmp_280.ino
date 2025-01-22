#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

// Define Chip Select (CS) for SPI communication
#define BMP_CS   12  // Chip Select Pin
#define BMP_MISO 11 // MISO Pin (Master In Slave Out)
#define BMP_MOSI 8 // MOSI Pin (Master Out Slave In)
#define BMP_SCK  13 // SCK Pin (Serial Clock)

// Create an instance of the BMP280 sensor using SPI
Adafruit_BMP280 bmp(BMP_CS, BMP_SCK, BMP_MISO, BMP_MOSI); // Pass the CS, SCK, MISO, MOSI pins

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  while (!Serial);  // Wait for serial monitor to open

  // Initialize BMP280 sensor
  if (!bmp.begin()) {
    Serial.println("BMP280 sensor not detected. Check wiring and SPI connection!");
    while (1);  // Halt if the sensor is not detected
  }

  // Optional: Configure BMP280 settings for better accuracy
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,       // Normal mode
                  Adafruit_BMP280::SAMPLING_X16,      // 16x oversampling for temperature
                  Adafruit_BMP280::SAMPLING_X16,      // 16x oversampling for pressure
                  Adafruit_BMP280::FILTER_X16,        // 16x filter
                  Adafruit_BMP280::STANDBY_MS_500);   // 500ms standby
}

void loop() {
  // Read and display temperature and pressure
  float temperature = bmp.readTemperature();
  float pressure = bmp.readPressure() / 100.0F;  // Convert pressure to hPa

  // Display values on the Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("Pressure: ");
  Serial.print(pressure);
  Serial.println(" hPa");

  Serial.println("--------------------------------");
  delay(1000);  // Wait for 1 second before the next reading
}
