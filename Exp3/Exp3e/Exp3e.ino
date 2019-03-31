float x,y;

void setup() {
  pinMode(A1, INPUT);
  Serial.begin(9600);
  pinMode(2, OUTPUT);
}

void loop() {
  y = analogRead(A1)/1023.0;
  x = (10.00/(y))-10;
  if(x<0.01){
    digitalWrite(2, HIGH);
  }
  else{
    digitalWrite(2, LOW);
  }
  Serial.print("The resistance in kOhm is: ");
  Serial.println(x);

  delay(200);
}
