float x;
void setup() {
  pinMode(A2, INPUT);
  Serial.begin(9600);
}

void loop() {
  x = analogRead(A2);
  x = (x*500)/1023.0;
  Serial.println(x);
  delay(1000);
}
