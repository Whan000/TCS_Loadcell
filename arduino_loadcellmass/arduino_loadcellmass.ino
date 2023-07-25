#include"HX711.h"
#include <LiquidCrystal.h>
HX711 scale(A1,A0);
LiquidCrystal lcd(12,11,5,4,3,2);
void setup(){
  Serial.begin(38400);
  lcd.begin(8,2);
  //scale.set_scale(291.f);
  //scale.tare();
  //delay(100);
  scale.set_scale(103500.f);
  // lcd.setCursor(0,0);
  // lcd.print(scale.get_units()-82.66);
  // lcd.setCursor(0,1);
  // lcd.print("Kilos");
  // Serial.println(scale.get_units(1), 1);
  // lcd.setCursor(0, 0);
  // lcd.print("STARTING");
  // lcd.setCursor(0, 1);
  // lcd.print("   UP   ");
  // delay(2000);
  // lcd.clear();

}
void loop(){
  
  Serial.println(scale.get_units());
  if ((scale.get_units()-82.27) >= 11 && scale.get_units()-82.27 <= 15.5){
  lcd.setCursor(0,0);
  lcd.print(scale.get_units()-82.27);
  lcd.setCursor(6,0);
  lcd.print("Kg");
  lcd.setCursor(0,1);
  lcd.print("GOOD    ");
  //delay(100);
  }
  if ((scale.get_units()-82.27) <11 && scale.get_units()-82.27 >= 9) {
  lcd.setCursor(0,0);
  lcd.print(scale.get_units()-82.27);
  lcd.setCursor(6,0);
  lcd.print("Kg");
  lcd.setCursor(0,1);
  lcd.print("PREPARE ");
  //Serial.println(scale.get_units(1), 1);
  //delay(100);


  }
  if ((scale.get_units()-82.27 <9) && scale.get_units()-82.27 >= 0) {
  lcd.setCursor(0,0);
  lcd.print(scale.get_units()-82.27);
  lcd.setCursor(6,0);
  lcd.print("Kg");
  lcd.setCursor(0,1);
  lcd.print("CHANGE  ");
  //delay(1000);

  }
  if(scale.get_units()-82.27 < 0){

  lcd.setCursor(0, 0);
  lcd.print(scale.get_units()-82.27);
  lcd.setCursor(6,0);
  lcd.print("Kg");
  lcd.setCursor(0,1);
  lcd.print("CALIB!  ");
  //delay(100);

  }
  if(scale.get_units()-82.27 >15.5){

  lcd.setCursor(0, 0);
  lcd.print(scale.get_units()-82.27);
  lcd.setCursor(6,0);
  lcd.print("Kg");
  lcd.setCursor(0,1);
  lcd.print("ErrOL   ");
  //delay(100);
  }
}