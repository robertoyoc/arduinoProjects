#include <Servo.h>
Servo S1;
void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  S1.attach(13);
  S1.write(0); 
  Serial.begin(9600);
}
char k;
void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available()){
    k = Serial.read();
    switch(k){
      case'F': sto();
      break;
      case 'A': ade();
      break; 
      case 'B': atr();
      break;
      case'C': izq();
      break;
      case'D': der();
      break;
      case'E': ser();
      break;
    }
  }
  delay(100);
}
void ade(){
  analogWrite(10, 255); 
  analogWrite(11, 230); 
}
void atr(){
  analogWrite(9, 255);
  analogWrite(3, 230); 
}
void izq(){
  analogWrite(11, 230);
  analogWrite(9, 255);
}
void der(){
  analogWrite(10,255);
  analogWrite(3,230);
}
void sto(){
  analogWrite(9, 0);
  analogWrite(10, 0);
  analogWrite(3, 0); 
  analogWrite(11,0); 
  
}
void ser(){
  S1.write(110);
  delay(250); 
  S1.write(0);
}
