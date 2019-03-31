void setup() {
  //Input at 2 and 4
  //PWM output at 3
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

int x;
void loop() {
  if (Serial.available() > 0) {
     x = Serial.parseInt();
     Serial.println(x);

     if(x>0){
      digitalWrite(2,HIGH);
      digitalWrite(4,LOW);      
     } 
     else{
      x=-x;
      digitalWrite(2,HIGH);
      digitalWrite(4,LOW);
     }
     analogWrite(3, x);    
  }
}
