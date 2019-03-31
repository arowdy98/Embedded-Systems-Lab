int i,j;

void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
}

void pwm(int T){
  for(i=0;i<255;i++){
    if(i<T)
      digitalWrite(13,HIGH);
    else
      digitalWrite(13,LOW);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for(j=0;j<255;j++){
   pwm(j);
   delay(10);
  }
  for(j=255;j>0;j--){
   pwm(j);
   delay(10);
  }
}
