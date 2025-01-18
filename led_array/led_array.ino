// Define the pins for the LEDs
int ledPins[] = {5, 6, 7, 8, 9, 10, 11, 12}; 
// Pin 2, 3, 4 are interrupt pins connected directly to the LoRaWAN module,act as interrupt, so using pins 5-12

void setup() {
  // Set up the LED pins as outputs
  for (int i = 0; i < 8; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}
void loop() {
  // Call different functions to display patterns
  blinkAll();
  delay(1000);

  runningLights();
  delay(1000);

  // Uncomment for alternate blinking
  // alternateBlink();
  // delay(1000);

  // Add more patterns as needed
}
// Function to blink all LEDs
void blinkAll() {
  for (int i = 0; i < 8; i++) {
    digitalWrite(ledPins[i], HIGH);
  }
  delay(500);
  for (int i = 0; i < 8; i++) {
    digitalWrite(ledPins[i], LOW);
  }
  delay(500);
}

// Function to alternate blink LEDs (optional, commented out)
// void alternateBlink() {
//   for (int i = 0; i < 8; i += 2) {
//     digitalWrite(ledPins[i], HIGH);
//     delay(250);
//     digitalWrite(ledPins[i], LOW);
//   }
//   delay(500);
//   for (int i = 1; i < 8; i += 2) {
//     digitalWrite(ledPins[i], HIGH);
//     delay(250);
//     digitalWrite(ledPins[i], LOW);
//   }
//   delay(500);
// }
// Function to create a running lights pattern
void runningLights() {
  // Forward direction
  for (int i = 0; i < 8; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(40);
    digitalWrite(ledPins[i], LOW);
    delay(40);
  }

  // Reverse direction
  for (int i = 7; i >= 0; i--) {
    digitalWrite(ledPins[i], HIGH);
    delay(40);
    digitalWrite(ledPins[i], LOW);
    delay(40);
  }
}
