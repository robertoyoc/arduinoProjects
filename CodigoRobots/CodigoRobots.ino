  int am1= 11;
  int bm1 = 12;
  int am2 = 10;
  int bm2 =9;

  int m1a= 240; // cambia respecto a la velocidad del motor
  int m2a= 255; //cambia respecto a la velocidad del motor
  int m1t= 245; // cambia respecto a la velocidad del motor
  int m2t= 255; //cambia respecto a la velocidad del motor
  
  
  void setup() {
  // put your setup code here, to run once:

  pinMode(am1,1);
  pinMode(bm1,1);
  pinMode(am2,1);
  pinMode(bm2,1);
  Serial.begin(9600); 
}
String texto;
void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    texto= Serial.readString();
    for(int i=0; i<texto.length(); i++)
    {
      switch(texto[i])
      {
        case 'a': 
        ade();
        break;
        case 'b':
        atr();
        break;
        case 'd':
        der();
        break;
        case 'c':
        izq();
        break;
      }
      delay(500);
    }
  }
} 
void ade(){
  analogWrite(am1, m1a);
  analogWrite(am2, m2a);
  delay(640);
  analogWrite(am1, 0);
  analogWrite(am2, 0);
}
  void atr(){
  analogWrite(bm1, m1t);
  analogWrite(bm2, m2t);
  delay(640);
  analogWrite(bm1, 0);
  analogWrite(bm2, 0);
}
void izq(){
  analogWrite(am1, m1a);
  analogWrite(bm2, 60);
  delay(870);
  analogWrite(am1, 0);
  analogWrite(bm2, 0);
  analogWrite(am1, m1a);
  analogWrite(am2, m2a);
  delay(200);
  analogWrite(am1, 0);
  analogWrite(am2, 0);
  
}
void der(){
  analogWrite(am2, m2a);
  analogWrite(bm1, 60);
  delay(880);
  analogWrite(am2, 0);
  analogWrite(bm1, 0);
   analogWrite(am1, m1a);
  analogWrite(am2, m2a);
  delay(200);
  analogWrite(am1, 0);
  analogWrite(am2, 0);
}

