void setup() {
  //Input at 2 and 4
  //PWM output at 3
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(A0, INPUT);
  Serial.begin(9600);

}

float x, y;
void loop() {
  y = analogRead(A0);
  y = (y*500)/1023.0;
  Serial.print(y);
  Serial.print("   ");
  if(y>30){
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    x = map(y,30,40,0,255);
    analogWrite(3, x);
    Serial.println(x);
  }
  else{
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    analogWrite(3, 0);
  }
  delay(200);
}
