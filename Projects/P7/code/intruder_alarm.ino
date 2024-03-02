// Project 7 - Intruder Alarm

// initialize variables
#define echoPin 6
#define trigPin 7
#define MAX_DIST 500
#define buzzerPin 9
int redLED = 4, greenLED = 8;   // red LED to pin 4 and green LED to pin 8

// include libraries
#include <NewPing.h>
NewPing sonar(trigPin, echoPin, MAX_DIST);


// define function to generate frequency on the buzzer pin
void buzz(int frequency, long duration){
  long period = 1000000L / frequency;             // calculate the period in microseconds
  long cycles = frequency * duration / 1000;      // calculate the number of cycles
  for(int i = 0; i < cycles; i++){
    digitalWrite(buzzerPin, HIGH);      // turn on the buzzer pin
    delayMicroseconds(period / 2);      // wait for half of the period
    digitalWrite(buzzerPin, LOW);       // turn off the buzzer pin
    delayMicroseconds(period / 2);      // wait for the other half of the period
  }
}

// define setup function
void setup(){
  Serial.begin(115200);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

// define loop function
void loop(){
  int duration, dist, pos = 0, i;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);    // trig pin sends a ping
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);  // echo pin receives the ping
  dist = (duration / 2) / 29.1;
  Serial.print(dist);
  Serial.println(" cm");

  // if sensor detects object within 100 cm
  if(dist <= 100){
    buzz(1500, 250);     // turn on buzzer for 250 milliseconds

    digitalWrite(greenLED, LOW);    // turn off green LED
    digitalWrite(redLED, HIGH);     // turn on red LED
    delay(450);

    digitalWrite(redLED, LOW);
    delay(450);

    digitalWrite(redLED, HIGH);
    delay(450);

    digitalWrite(redLED, LOW);
  }

  // otherwise
  else{
    digitalWrite(buzzerPin, LOW);   // turn off buzzer
    digitalWrite(redLED, LOW);      // turn off red LED
    digitalWrite(greenLED, HIGH);   // turn on green LED
  }

  delay(450);
}