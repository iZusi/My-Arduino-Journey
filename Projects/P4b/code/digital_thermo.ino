// Define pin numbers for 7-segment display and temperature sensor
#define data 6
#define latch 8
#define clock 10
#define sensorPin A0

int temp = 0;  // Variable to store temperature value

// Define segments for digits 0 to 9, A to F
int digits[] = {252, 96, 218, 242, 102, 182, 190, 224, 254, 246, 238, 62, 156, 122, 158, 142};

void setup() {
  // Set pin modes for 7-segment display
  pinMode(data, OUTPUT);
  pinMode(latch, OUTPUT);
  pinMode(clock, OUTPUT);
  
  Serial.begin(9600);  // Initialize serial communication for debugging
}

// Function to display a two-digit number on the 7-segment display
void displayNumber(int n) {
  int left, right = 0;

  if (n < 10) {
    // If the number is less than 10, display it on the right segment
    digitalWrite(latch, LOW);
    shiftOut(data, clock, LSBFIRST, digits[n]);
    shiftOut(data, clock, LSBFIRST, digits[0]);
    digitalWrite(latch, HIGH);
  }

  if (n >= 10) {
    // If the number is 10 or greater, display the two digits
    right = n % 10;    // Extract the rightmost digit
    left = n / 10;     // Extract the leftmost digit
    digitalWrite(latch, LOW);
    shiftOut(data, clock, LSBFIRST, digits[right]);
    shiftOut(data, clock, LSBFIRST, digits[left]);
    digitalWrite(latch, HIGH);
  }
}

void loop() {
  // Read temperature from the sensor
  int reading = analogRead(sensorPin);
  float voltage = reading * (5.0 / 1024);  // Convert sensor reading to voltage
  float tempC = voltage * 100;             // Convert voltage to temperature in Celsius
  temp = int(tempC);                       // Convert temperature to an integer
  
  // Display the temperature on the 7-segment display
  displayNumber(temp);
  delay(1000);  // Delay for 1 second

  // Print the temperature reading to the serial monitor
  Serial.print("Temperature: ");
  Serial.print(tempC);
  Serial.print("\xC2\xB0");  // Display the degree symbol
  Serial.print("C");
  Serial.println();
}