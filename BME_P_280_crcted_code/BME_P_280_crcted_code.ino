

#include <BME280.h>  // Include the BME280 Sensor library

const uint32_t SERIAL_SPEED{115200};  ///< Default   baud rate for Serial I/O

/************************************************************************************
** Software SPI requires 4 digital pins to be defined in order to work:            
** CS   - Chip Select or sometimes called SS for Slave-select. Used to address chip  CSB pin of BME280
** MISO - Wire used to send data from the BME280 to program   SDO pin of BME280
** MOSI - Wire used to send data from the program to BME280   SDA pin of BME280
** SCK  - System Clock. This is used for timing data - CS pin of BME280
************************************************************************************/          

const uint8_t SPI_CS_PIN{10};    ///< Pin for slave-select of BME280
const uint8_t SPI_SCK_PIN{13};   ///< Pin for clock signal
const uint8_t SPI_MOSI_PIN{11};  ///< Master-out, Slave-in Pin
const uint8_t SPI_MISO_PIN{12};  ///< Master-in, Slave-out Pin


BME280_Class BME280;  // Create an instance of the BME280 //

float altitude(const float seaLevel = 1013.25) {
  static float Altitude;
  int32_t      temp, hum, press;
  BME280.getSensorData(temp, hum, press);  // Get the most recent values from the device
  Altitude = 44330.0 * (1.0 - pow(((float)press / 100.0) / seaLevel,0.1903));  // Convert into altitude in meters
  return (Altitude);
}  // of method altitude()

void setup() {
  Serial.begin(SERIAL_SPEED);
#ifdef __AVR_ATmega32U4__  // If this is a 32U4 processor, then wait 3 seconds to initialize USB/
  delay(3000);
#endif
  Serial.println(F("Starting Software SPIDemo example program for BME280"));
  Serial.print(F("- Initializing BME280 sensor\n"));

  while (!BME280.begin(SPI_CS_PIN, SPI_MOSI_PIN, SPI_MISO_PIN, SPI_SCK_PIN))  // Software SPI
  {
    Serial.println(F("-  Unable to find BME280. Waiting 3 seconds."));
    delay(3000);
  }  // of loop until device is located
  BME280.mode(SleepMode);
  Serial.print(F("- Sensor detected in operating mode \""));
  Serial.print(BME280.mode());
  Serial.println(F("\"."));
  if (BME280.mode() == 0) {
    Serial.print(F("- Turning sensor to normal mode, mode is now \""));
    Serial.print(BME280.mode(NormalMode));
    Serial.println("\"");
  }  // of if-then we have sleep mode
  Serial.println(F("- Setting 16x oversampling for all sensors"));
  BME280.setOversampling(TemperatureSensor, Oversample16);
  BME280.setOversampling(HumiditySensor, Oversample16);
  BME280.setOversampling(PressureSensor, Oversample16);
  Serial.println(F("- Setting IIR filter to maximum value of 16 samples"));
  BME280.iirFilter(IIR16);
  Serial.println(F("- Setting time between measurements to 1 second"));
  BME280.inactiveTime(inactive1000ms);
  Serial.print(F("- Each measurement cycle will take "));
  Serial.print(BME280.measurementTime(MaximumMeasure) / 1000);
  Serial.println(F("ms.\n\n"));
}  // of method setup()

void loop() {

  static uint8_t loopCounter = 0;                         // iteration counter
  static int32_t temperature, humidity, pressure;         // Store readings
  BME280.getSensorData(temperature, humidity, pressure);  // Get most recent readings
  Serial.print(F("Temperature: "));
  Serial.print(temperature / 100.0);  // Temperature in deci-degrees
  Serial.print(F("C "));
  if (BME280.getOversampling(HumiditySensor) != 0) {
    Serial.print(F("Humidity: "));
    Serial.print(humidity / 100.0);  // Humidity in deci-percent
    Serial.print(F("% "));
  }  // of if-then humidity sensing turned off
  Serial.print(F("Pressure: "));
  Serial.print(pressure / 100.0);  // Pressure in Pascals
  Serial.print(F("hPa Altitude: "));
  Serial.print(altitude());
  Serial.println(F("m"));
  delay(2000);
  if (++loopCounter % 10 == 0)  // Every 10th reading
  {
    Serial.print(F("\n- Turning "));
    if (BME280.getOversampling(HumiditySensor) == 0) {
      BME280.setOversampling(HumiditySensor, Oversample16);
      Serial.print(F("ON"));
    } else {
      BME280.setOversampling(HumiditySensor, SensorOff);
      Serial.print(F("OFF"));
    }  // of if-then-else humidity sensing turned off
    Serial.println(F(" humidity sensing"));
    Serial.print(F("- Each measurement cycle will now take "));
    Serial.print(BME280.measurementTime(MaximumMeasure) / 1000.0);  // returns microseconds
    Serial.println(F("ms.\n"));
  }  // of if-then first loop iteration
}  // of method loop()