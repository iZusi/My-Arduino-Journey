// project 1 - Blinking LED Wave

// set delay time (unit in millisecond)
int d = 250;


void setup() {
  // initialize digital pins 2-6 as output
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop() {
  // repeat blinking process with for loop
  for (int a=2; a<7; a++) {
    digitalWrite(a, HIGH); // turn LED on
    delay(d);              // wait for 0.25 second
    digitalWrite(a, LOW);  // turn LED off
    delay(d);
  }

  for (int a=5; a>2; a--) {
    digitalWrite(a,HIGH);
    delay(d);
    digitalWrite(a,LOW);
    delay(d);
  }
}
