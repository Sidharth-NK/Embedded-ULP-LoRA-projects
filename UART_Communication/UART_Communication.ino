void setup() {
  // Initialize UART communication at 9600 baud rate
  Serial.begin(9600);
  Serial.println("UART Communication Initialized");
}

void loop() {
  // Check if data is available on the serial port
  if (Serial.available() > 0) {
    // Read the incoming byte
    char incomingData = Serial.read();
    
    // Echo the received data back
    Serial.print("Received: ");
    Serial.println(incomingData);
  }
}
