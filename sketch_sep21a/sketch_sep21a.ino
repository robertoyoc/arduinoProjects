void setup() {
  // put your setup code here, to run once:
  pinMode(13,1);
  pinMode(12,1);
  pinMode(11,1);
  pinMode(10,1);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(13,1);
  digitalWrite(10,1);
  delay(1000);
  digitalWrite(13,0);
  digitalWrite(10,0);
  delay(1000);
  digitalWrite(12,1);
  digitalWrite(11,1);
  delay(1000);
  digitalWrite(12,0);
  digitalWrite(11,0);

}
