#include "HX711.h"
// #include <LiquidCrystal.h>



HX711 scale(A1, A0);
// LiquidCrystal lcd(12,11,5,4,3,2);
void setup() {
  // lcd.begin(8,2);
  // lcd.setCursor(0,1);
  Serial.begin(38400);
  // Serial.println(scale.read());
  //scale.set_scale(728.f);
  scale.set_scale();
  scale.tare();
}

void loop() {
  //Serial.println(scale.read());
  // Serial.print("ScaleRead      =");
  // Serial.println(scale.read());
  // Serial.print("ScalegetUnit    =");
  // Serial.println(scale.get_units());
  // delay(1000);
  Serial.println(scale.get_units(10));
}
