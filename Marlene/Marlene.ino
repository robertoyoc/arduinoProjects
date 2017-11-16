int turbo=0;

void adelante();
void atras();
void izquierda();
void derecha();

void setup() {
  // put your setup code here, to run once:
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(13,OUTPUT);
  Serial.begin(9600);
}
char l;
void loop() {
  if(Serial.available()){
    l= Serial.read();
    switch(l){
      case 'f': detener();
      break;
      case 'a': adelante();
      break;
      case 'b': atras();
      break;
      case 'd': derecha();
      break;
      case 'c': izquierda();
      break;
      case 'h': turbo=100;
      digitalWrite(13,1);
      break;
      case 'g': turbo=0;
      digitalWrite(13,0);
      break;
    }
  }
  delay(100);
}
 
void adelante(){
  analogWrite(10, 155+turbo);
  analogWrite(6, 155+turbo);
}
void atras(){
  analogWrite(9, 115+turbo);
  analogWrite(5, 155+turbo);
}
void izquierda(){
  analogWrite(10, 155+turbo);
}
void derecha(){
  analogWrite(6, 155+turbo);
}

void detener(){
  analogWrite(10,0);
  analogWrite(6, 0);
  analogWrite(5, 0);
  analogWrite(9, 0);
}

