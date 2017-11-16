void setup() {
  // put your setup code here, to run once:
  pinMode(13,1);
  pinMode(12,1);
  pinMode(11,1);
  Serial.begin(38400);
}
void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    switch(Serial.read())
    {
      case 'b': digitalWrite(13,0);
      break;
      case 'a': digitalWrite(13,1);
      break;
      case 'c': digitalWrite(12, 0);
      break;
      case 'd': digitalWrite(12, 1);
      break;
      case 'f': digitalWrite(11, 0);
      break;
      case 'g': digitalWrite(11, 1);
      break; 
      default:
        delay(500);
    }
  }
}
