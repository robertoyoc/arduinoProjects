

void setup() {
  // put your setup code here, to run once:
  pinMode(13,1);
  pinMode(12,1);
  pinMode(11,1);
  pinMode(10,1);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available())
  {
      if(Serial.read()=='a'){
      digitalWrite(10,1);
      delay(2000);
      digitalWrite(10,0);
      }
      if(Serial.read()=='w'){
      digitalWrite(13,1);
      digitalWrite(10,1);
      delay(4000);
      digitalWrite(13,0);
      digitalWrite(10,0);
      }
      if(Serial.read()=='d'){
      digitalWrite(13,1);
      delay(2000);
      digitalWrite(13,0);
      }
      if(Serial.read()=='s'){
      digitalWrite(12,1);
      digitalWrite(11,1);
      delay(4000);
      digitalWrite(12,0);
      digitalWrite(11,0);
      }
  }
  

}
