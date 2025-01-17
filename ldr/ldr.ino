const int ldrPin = A0;  // Pin connected to the LDR module
int ldrValue = 0;    
int led = 9;    // Variable to store the LDR value

void setup() {
  Serial.begin(9600); 
  pinMode(led,OUTPUT);// Start serial communication;
}

void loop() {
  ldrValue = analogRead(ldrPin);  // Read the LDR value (light intensity)
  // Serial.print("LDR Value: ");
  // Serial.println(ldrValue);  // Print the value to the Serial Monitor
  int Nw=map(ldrValue,0,700,0,255);
  Serial.print("Analog Value:");
  Serial.println(Nw);
  analogWrite(led,Nw);
  delay(1000);
 // Wait for 500ms before reading again
}