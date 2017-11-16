void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 pinMode(13,1);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    if(Serial.read()=='a'){
      digitalWrite(13,1);
      delay(1000);
      digitalWrite(13,0);
    }
  }
}
