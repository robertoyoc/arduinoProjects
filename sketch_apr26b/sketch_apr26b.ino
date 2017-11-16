  void setup() {
  // put your setup code here, to run once:
  pinMode(13,1);
  pinMode(12,1);
  pinMode(11,1);
  pinMode(10,1);
  Serial.begin(38400); 
}
void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    switch(Serial.read())
    {
      case 'a': 
      digitalWrite(13,0);
      digitalWrite(10,0);
      digitalWrite(12,1);
      digitalWrite(11,1);
      break;
      case 'b':
      digitalWrite(13,1);
      digitalWrite(10,1);
      digitalWrite(12,0);
      digitalWrite(11,0);
      break;
      case 'd':
      digitalWrite(13,0);
      digitalWrite(10,0);
      digitalWrite(12,1);
      digitalWrite(11,0);
      break;
      case 'c':
      digitalWrite(13,0);
      digitalWrite(10,0);
      digitalWrite(12,0);
      digitalWrite(11,1);
      break;
      case 'f':
      digitalWrite(13,0);
      digitalWrite(10,0);
      digitalWrite(12,0);
      digitalWrite(11,0);
      break;
    }
    delay(500);
  }
} 
