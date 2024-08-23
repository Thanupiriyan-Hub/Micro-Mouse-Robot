// Define the pin connected to the onboard LED
const int ledPin = PC13;

void setup() {
  // Initialize the LED pin as an output
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Turn the LED on
  digitalWrite(ledPin, LOW);  // LOW because the LED is active low
  delay(500);                 // Wait for 500 milliseconds

  // Turn the LED off
  digitalWrite(ledPin, HIGH); // HIGH to turn off the LED
  delay(500);                 // Wait for 500 milliseconds
}
