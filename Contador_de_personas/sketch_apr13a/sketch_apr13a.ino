void setup() {
  // put your setup code here, to run once:
  Serial.begin(38400);
  pinMode(13,1);
}
char x;

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    x= Serial.read();
    if(x=='a'){
      digitalWrite(13,1);
      delay(1000);
      digitalWrite(13,0);
    }
  }

}
