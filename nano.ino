void setup() {
  Serial.begin(9600); // Initialize serial communication at 9600 baud rate
  pinMode(LED_BUILTIN, OUTPUT); // Set the built-in LED pin as an output
}

void loop() {
  if (Serial.available() > 0) { // Check if data is available to read
    String data = Serial.readStringUntil('\n'); // Read the data from the serial port until newline character
    float temperature = data.toFloat(); // Convert the received data to a floating-point number
    Serial.println(temperature, 2); // Print with 2 decimal places
    
    // Check if the temperature exceeds 40.00
    if (temperature > 40.00) {
      digitalWrite(LED_BUILTIN, HIGH); // Turn on the built-in LED
      delay(100);
      digitalWrite(LED_BUILTIN, LOW);
      delay(100);
    } else {
      digitalWrite(LED_BUILTIN, LOW); // Turn off the built-in LED
    }
  }
}
