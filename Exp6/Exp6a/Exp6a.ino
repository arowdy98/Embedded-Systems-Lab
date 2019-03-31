int dataarray[41];
int i;
float RH;
int temperature;
int j = 0;
int t = 0;


void setup() {
  Serial.begin(9600);
  pinMode(A1, OUTPUT);
  digitalWrite(A1, HIGH);
  delay(1000);
  digitalWrite(A1, LOW);
  delay(20);
  digitalWrite(A1, HIGH);
  delayMicroseconds(20);
  pinMode(A1, INPUT);
  delayMicroseconds(160);
}

void loop() {
  for(i=0;i<40;i++){
    while(digitalRead(A1)==LOW);
    t = micros();
    while(digitalRead(A1)==HIGH);
    t = micros() - t;
    if(t>50){
      dataarray[i] = 1;
    }
    else{
      dataarray[i] = 0;    
    }
  }
  RH = 0;
  j=0;
  for(i=7;i>-8;i--){
      RH += dataarray[j] * pow(2,i);
      j++;
  }
  Serial.println(RH);
}
