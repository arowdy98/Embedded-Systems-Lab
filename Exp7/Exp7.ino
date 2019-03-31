float t=0, freq = 2 * 3.14 * 1;
float bro;
void analogOutput(int x){
  int i;
  for(i=0;i<8;i++){
    digitalWrite(9-i,x%2);
    x = x/2;
  }
}
void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  Serial.begin(9600);
}

void loop() {
  bro = 2 * 3.14 * map(analogRead(A1),0,1023,0,5);
  Serial.println(analogRead(A0));
  analogOutput(128 + 128 * sin(bro * millis() / 1000));
}
