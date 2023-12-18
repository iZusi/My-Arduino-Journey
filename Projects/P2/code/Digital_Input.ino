// Project 2 - Digital Input with Arduino

#define LED 12
#define BUTTON 7

void setup() {
  pinMode(LED, OUTPUT);       // output for the LED
  pinMode(BUTTON, INPUT);     // input for the button
}

void loop() {
  if (digitalRead(BUTTON) == HIGH) {
    digitalWrite(LED, HIGH);   // turn LED on
  }
  else {
    digitalWrite(LED, LOW);   // turn LED off
  }
}
