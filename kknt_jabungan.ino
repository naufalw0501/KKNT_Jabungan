#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include "DHT.h"

LiquidCrystal_I2C lcd(0x27,16,4);
// Deklarasi PIN DHT11 //
#define DHTPIN 2
// Tipe sensor yang digunakan (DHT11 atau DHT22) //
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);


void setup() {
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0,0);
  lcd.print("KKN TEMATIK");
  lcd.setCursor(0,1);
  lcd.print("RW 6 JABUNGAN");
  dht.begin();
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("T1=      T2=xx.x");
  lcd.setCursor(0,1);
  lcd.print("S1=   S2=ok h=");
}

void loop() {
  // Membaca kelembaban //
  float h = dht.readHumidity();
  // Membaca suhu dalam satuan Celsius //
  float t1 = dht.readTemperature();

  //kondisiuntukdht
  if (t1 <= 24) {
    lcd.setCursor(3,1);
    lcd.println("--");
    lcd.setCursor(5,1);
    lcd.print(" S");
    lcd.setCursor(3,0);
    lcd.print(t1,1);
    lcd.setCursor(14,1);
    lcd.print(h,0);
  }
  else if (t1 > 24 && t1 <= 27 ) {
    lcd.setCursor(3,1);
    lcd.println("ok");
    lcd.setCursor(5,1);
    lcd.print(" S");
    lcd.setCursor(3,0);
    lcd.print(t1,1);
    lcd.setCursor(14,1);
    lcd.print(h,0);
  }
  else if (t1 > 27) {
    lcd.setCursor(3,1);
    lcd.println("++");
    lcd.setCursor(5,1);
    lcd.print(" S");
    lcd.setCursor(3,0);
    lcd.print(t1,1);
    lcd.setCursor(14,1);
    lcd.print(h,0);
  }
  

  float hic = dht.computeHeatIndex(t1, h, false);

  // Menampilkan data ke LCD //


  // Jeda Waktu, ubah menjadi 2000 untuk DHT22//
  delay(1000);
}
