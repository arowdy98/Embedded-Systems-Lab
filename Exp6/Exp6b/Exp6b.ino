float x,y,z;
void setup() {
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  Serial.begin(9600);
}

void loop() {
  x = (analogRead(A1) - 337.92) / 61.44 * 9.81;
  y = (analogRead(A2) - 337.92) / 61.44 * 9.81;
  z = (analogRead(A3) - 330.92) / 62.5 * 9.81;

  Serial.print(" x = ");
  Serial.print(x);
  Serial.print(" y = ");
  Serial.print(y);
  Serial.print(" z = ");
  Serial.println(z);
  delay(500);
}
