void setup() {
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println(analogRead(A0));
  analogWrite(13, map(analogRead(A0), 1, 1024, 1, 255));
}
