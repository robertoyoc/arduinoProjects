void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  Serial.begin(9600);
}
char k;
void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available()){
    k = Serial.read();
    switch(k){
      case'f': sto();
      break;
      case 'a': ade();
      break; 
      case 'b': der();
      break;
      case'c': izq();
      break;
      case'd': atr();
      break;
    }
  }
  delay(100);
}
void ade(){
  analogWrite(3, 255);
  analogWrite(10, 255); 
}
void der(){
  analogWrite(9, 255);
  analogWrite(11, 255); 
}
void izq(){ 
  analogWrite(10,255);
  analogWrite(11,255);
}
void atr(){
  analogWrite(3, 255);
  analogWrite(9, 255);
}
void sto(){
  analogWrite(9, 0);
  analogWrite(10, 0);
  analogWrite(3, 0); 
  analogWrite(11,0); 
  
}
