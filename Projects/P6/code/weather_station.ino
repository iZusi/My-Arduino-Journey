// Project 6 - Weather Station

#include <LiquidCrystal.h>
#include "DHT.h"          // call the DHT library

#define DHTPIN 9          // pin connected to DHT
#define DHTTYPE DHT11     // type of DHT module

DHT dht(DHTPIN, DHTTYPE);
const int rs=3, en=4, d4=5, d5=6, d6=7, d7=8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// custom character for the degree symbol
byte degreeSymbol[8] = {
  B00111,
  B00101,
  B00111,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};


void setup(){
  dht.begin();     // start sensor
  lcd.begin(16, 2);
  lcd.clear();

  // create a custom character for the degree symbol
  lcd.createChar(0, degreeSymbol);
}

void loop(){
  // read temp and humidity values
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // check if DHT sensor is working
  if (isnan(t) || isnan(h)){
    lcd.setCursor(0, 0);
    lcd.print("Failed to read from DHT");
  }
  // otherwise show readings on the screen
  else{
    lcd.setCursor(0, 0);
    lcd.print("Humidity: ");
    lcd.print(h);
    lcd.print("%");
    lcd.setCursor(0, 1);
    lcd.print("Temp: ");
    lcd.print(t);
    lcd.write(byte(0));   // display the degree symbol
    lcd.print("C");
  }
}