int batteryPin = A0;   // Analog pin connected to the battery
int newBatt = 2;       // Digital pin for the green/blue LED
int okBatt = 4;        // Digital pin for the yellow LED
int oldBatt = 6;       // Digital pin for the red LED

void setup() {
  pinMode(newBatt, OUTPUT);
  pinMode(okBatt, OUTPUT);
  pinMode(oldBatt, OUTPUT);
}

void loop() {
  int batteryValue = analogRead(batteryPin);  // Read battery voltage
  float voltage = (batteryValue / 1023.0) * 5.0;  // Convert to voltage (assuming 5V reference)

  // Determine which LED to light up based on the battery voltage
  if (voltage >= 1.6) {
    digitalWrite(newBatt, HIGH);
    digitalWrite(okBatt, LOW);
    digitalWrite(oldBatt, LOW);
  }
  else if (voltage >= 1.4) {
    digitalWrite(newBatt, LOW);
    digitalWrite(okBatt, HIGH);
    digitalWrite(oldBatt, LOW);
  }
  else if (voltage >= 1.0) {
    digitalWrite(newBatt, LOW);
    digitalWrite(okBatt, LOW);
    digitalWrite(oldBatt, HIGH);
  }
  else {
    // All LEDs off if voltage is below the lowest threshold
    digitalWrite(newBatt, LOW);
    digitalWrite(okBatt, LOW);
    digitalWrite(oldBatt, LOW);
  }
}
