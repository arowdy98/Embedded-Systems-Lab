float y;

void setup() {
  pinMode(A1, INPUT);
  Serial.begin(9600);
}

void loop() {
  y = analogRead(A1)/1023.0;
  Serial.print("The resistance in kOhm is: ");
  Serial.println((10.00/(y))-10);
}
