// Project 5 - Controlling Traffic with Two 7-Segment LEDs

// Define pin assignments for data, latch, clock, and traffic light LEDs
#define data 10
#define latch 8
#define clock 6
#define red 4
#define yellow 3
#define green 2

// Define an array with segment configurations for digits 0 to 9 and letters A to F
int digits[] = {252, 96, 218, 242, 102, 182, 190, 224, 254, 246, 238, 62, 156, 122, 158, 142};

// Setup function runs once at the start
void setup() {
  // Set pin modes for data, latch, clock, and traffic light LEDs
  pinMode(data, OUTPUT);
  pinMode(latch, OUTPUT);
  pinMode(clock, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
}

// Function to display a two-digit number on the 7-segment LEDs
void displayNumber(int n) {
  int left, right = 0;

  // Check if the number is greater than or equal to 10
  if (n >= 10) {
    // Extract the digits of the number
    right = n % 10;
    left = n / 10;

    // Activate the latch and shift out segment configurations for both digits
    digitalWrite(latch, LOW);
    shiftOut(data, clock, LSBFIRST, digits[right]);
    shiftOut(data, clock, LSBFIRST, digits[left]);
    digitalWrite(latch, HIGH);
  }

  // If the number is less than 10
  if (n < 10) {
    // Activate the latch and shift out segment configurations for the single digit
    digitalWrite(latch, LOW);
    shiftOut(data, clock, LSBFIRST, digits[n]);
    shiftOut(data, clock, LSBFIRST, digits[0]); // Display a leading zero for better visibility
    digitalWrite(latch, HIGH);
  }
}

// Loop function runs repeatedly
void loop() {
  // Red light phase
  for (int i = 15; i > -1; i--) {
    // Display the countdown number on the 7-segment LEDs and activate the red light
    displayNumber(i);
    digitalWrite(red, HIGH);
    delay(1000);
    digitalWrite(red, LOW);
  }

  // Yellow light phase
  for (int i = 10; i > -1; i--) {
    // Display the countdown number on the 7-segment LEDs and activate the yellow light
    displayNumber(i);
    digitalWrite(yellow, HIGH);
    delay(1000);
    digitalWrite(yellow, LOW);
  }

  // Green light phase
  for (int i = 15; i > -1; i--) {
    // Display the countdown number on the 7-segment LEDs and activate the green light
    displayNumber(i);
    digitalWrite(green, HIGH);
    delay(1000);
    digitalWrite(green, LOW);
  }
}
