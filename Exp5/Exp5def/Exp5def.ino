int triggerPin = 2;
int echoPin = 3;
unsigned long time;
float x;


void setup() {
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(A1, INPUT);

  Serial.begin(9600);
}

void loop() {
//      Serial.println(analogRead(A1));

  if(analogRead(A1)>400){
    digitalWrite(triggerPin, LOW);
    delayMicroseconds(3);
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(15); //The trigger is high for atleast 15us
    digitalWrite(triggerPin, LOW);
    while(digitalRead(echoPin) == LOW);
    time = micros();
    while(digitalRead(echoPin) == HIGH);
    time = micros() - time;
    Serial.println((time*340.0)/2000000.0);
  }
  else{
    Serial.println(0);
  }
  delay(100);
}
