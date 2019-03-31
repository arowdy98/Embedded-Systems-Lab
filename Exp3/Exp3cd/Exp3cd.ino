#include <LiquidCrystal.h>
float x,y;
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

void setup() {
  pinMode(A1, INPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);              // start the library
  lcd.setCursor(0,0);
}

void loop() {
  y = analogRead(A1)/1023.0;
  x = (10.00/(y))-10;
  
  lcd.setCursor(0,0);
  lcd.print("R in kOhm: ");
  lcd.print(x);

  Serial.print("The resistance in kOhm is: ");
  Serial.println(x);

  delay(200);
}
