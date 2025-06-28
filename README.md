# 🌐 Ultra Low Power LoRa (ULP LoRa) Projects

This repository contains a collection of embedded systems projects developed using a custom **ULP LoRa board**, which is a modified **Arduino Pro Mini** paired with the **RFM95W LoRa module** for ultra-low power, long-range wireless communication.

> ⚙️ Focus: Minimal power usage, real-world sensor interfacing, wireless data transmission, and cloud-based visualization via ChirpStack, InfluxDB, and Grafana.

---

## Hardware Overview

### 🔸 ULP LoRa Board

The ULP LoRa board is a minimalistic design built for low-power IoT deployments. It is ideal for remote sensors, data loggers, and anything that benefits from long-range, low-data-rate communication.

**Key Features:**
- Based on **Arduino Pro Mini (ATmega328P)**
- Powered at **3.3V**, clocked at **8 MHz**
- Integrated **RFM95W LoRa Module**
- Supports **UART, I2C, SPI**
- Extremely low power draw in sleep mode

**Image: ULP LoRa Board**  
![image](https://github.com/user-attachments/assets/f41d5448-cdb1-4899-83ce-b6ac10f52841)

---

### 🔸 FTDI1232 Programmer

Used to upload code and perform serial communication with the Arduino Pro Mini. It provides USB-to-UART bridging with support for 3.3V logic.

**Image: FTDI Connected to ULP LoRa Board (Same as Arduino Pro Mini Connection)**  
![image](https://github.com/user-attachments/assets/e48c065f-57fa-4d8a-976d-ff09b52667aa)

---

## Repository Structure

| Folder | Description |
|--------|-------------|
| `BME_P_280_crcted_code` | Corrected code for BME280 sensor |
| `BMP_180_LMIC_chirp_pressure` | LoRaWAN pressure data transmission via BMP180 |
| `BMP_180_LMIC_chirp_temperature` | LoRaWAN temperature data transmission |
| `SHT_45` | I2C interface for SHT45 sensor |
| `UART_Communication` | UART testing and communication |
| `bmp180_sensor` | Raw BMP180 sensor reading |
| `bmp_280` | SPI communication with BMP280 |
| `chirpstack_integer` | ChirpStack integer-based payload project |
| `ldr` | Light sensor (LDR) interface |
| `led_array` | LED array pattern display |
| `logic_gates` | Software-implemented digital logic gates |
| `Blink.ino` | Basic LED blink test sketch |

---

## Experiments Done

### GPIO + Digital Logic
- ✅ LED Blink
- ✅ LED Array Patterns
- ✅ Software-based Logic Gates (AND, OR, NAND, NOR, XOR, XNOR)

### Sensor Integration
- ✅ BMP180 (I2C)
- ✅ BMP280 (SPI)
- ✅ SHT20 / SHT45 (I2C)
- ✅ LDR (analog)
- ✅ Reed Switch
- ✅ Servo Motor
- ✅ DHT11 + Dust Sensor (Air Quality)

---

## LoRa + LoRaWAN Integration

### RFM95W LoRa Module

- Frequency: **433 / 868 / 915 MHz** (India: 865–867 MHz)
- Modulation: **LoRa (CSS)**
- Data Rate: **0.3 kbps – 27 kbps**
- Max TX Power: **20 dBm**
- Sleep Current: **~1.2 µA**

### LoRaWAN Stack

- Based on **MCCI LoRaWAN LMIC** Library
- Projects include both **string-based** and **integer-based** payloads
- Compatible with **ChirpStack** and **TTN**

---

## ChirpStack Integration Workflow

1. **Create Device Profile**
   - Add LoRa class, frequency plan, data rate, etc.
2. **Register Device**
   - Add DevAddr, AppSKey, NwkSKey (ABP mode)
3. **Write Codec**
   - Decode payload using JavaScript
4. **Monitor Device Data**
   - Check live uplink data in Application > Device Data

---

## InfluxDB + Grafana Visualization

- **InfluxDB** stores real-time sensor values pushed via ChirpStack
- **Grafana** visualizes the time-series data with dashboards

### Steps:
1. Generate token in InfluxDB (enable read/write)
2. Integrate InfluxDB in ChirpStack (copy token, bucket)
3. Visualize in Grafana: paste Influx queries → choose panel types

---

## Communication Protocols Used

| Protocol | Devices |
|----------|---------|
| I2C      | SHT20, BME280, BMP180 |
| SPI      | BMP280, RFM95 |
| UART     | FTDI to Arduino serial, UART Communication sketches |

---

## LoRa Code Types

- `LMIC_String.ino`: Sends readable strings (e.g., "Temp: 24.1C")
- `LMIC_Integer.ino`: Sends compact integer data (e.g., temp=241)

---

## References & Code Links
- 🔗 MCCI LMIC Library: [github.com/mcci-catena/arduino-lmic](https://github.com/mcci-catena/arduino-lmic)
- 🔗 ChirpStack Docs: [chirpstack.io](https://www.chirpstack.io/)
- 🔗 InfluxDB: [influxdata.com](https://www.influxdata.com/)
- 🔗 Grafana: [grafana.com](https://grafana.com/)

---

## Author

**Sidharth Krishna:**  
[GitHub](https://github.com/Sidharth-NK) 
[LinkedIn](https://www.linkedin.com/in/sidharth-krishna25/)

---

## License

This repository is open-sourced under the MIT License.  
Use it, modify it, improve it — attribution is appreciated!

---

