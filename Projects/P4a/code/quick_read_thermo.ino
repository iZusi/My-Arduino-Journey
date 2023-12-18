// define the pins that the LEDs are connected to:
#define HOT 6
#define NORMAL 4
#define COLD 2
#define sensorPin A0

// initialize variables
float hotTemp = 26.0;
float coldTemp = 20.0;

void setup(){
  pinMode(HOT, OUTPUT);
  pinMode(NORMAL, OUTPUT);
  pinMode(COLD, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  int reading = analogRead(sensorPin);    // get the LM35 sensor reading
  float voltage = reading * (5.0 / 1024);   // convert sensor reading to voltage
  float tempC = voltage * 100;    // convert the voltage into temperature in celcius

  // act on temperature range
  if (tempC < coldTemp){
    digitalWrite(COLD, HIGH);
    delay(1000);
    digitalWrite(COLD, LOW);
  }
  else if (tempC > coldTemp && tempC <= hotTemp){
    digitalWrite(NORMAL, HIGH);
    delay(1000);
    digitalWrite(NORMAL, LOW);
  }
  else {
  // tempC is > hotTemp
    digitalWrite(HOT, HIGH);
    delay(1000);
    digitalWrite(HOT, LOW);
  }

  // print the temperature reading
  Serial.print("Temperature: ");
  Serial.print(tempC);
  Serial.print("\xC2\xB0"); // shows the degree symbol
  Serial.print("C");
  Serial.println();
}
