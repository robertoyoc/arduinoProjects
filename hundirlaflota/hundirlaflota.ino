#define r1 2
#define r2 5
#define g1 3
#define g2 6
#define b1 4
#define b2 7
#define c1 9
#define c2 8
void setup() {
  // put your setup code here, to run once:
pinMode(2,0);
pinMode(3,0);
pinMode(4,0);
pinMode(5,0);
pinMode(6,0);
pinMode(7,0);
pinMode(8,0);
pinMode(9,0);
}


void loop() {
  // put your main code here, to run repeatedly:
  pintar("BRBG");
 
  
}
void pintar(String Texto){
  int Posiciones[4];
  int value;
  for(int x=0; x<4; x++){
    value=0;
    switch(Texto[x]){
      case 'R': value +=2;
      break;
      case 'G': value +=3;
      break;
      case 'B': value +=4;
      break;
    }
    if(x%2==1)
      value+=3;
    Posiciones[x] = value;
  }
for(int x=0; x<4000; x+=20){
    //c1f1
    digitalWrite(c1,1);
    digitalWrite(Posiciones[0],1);
    delay(2);
    //c1f2
    digitalWrite(c1,1);
    digitalWrite(Posiciones[0],0);
    digitalWrite(Posiciones[1],1);
    delay(2);
    //c2f1
    digitalWrite(Posiciones[1],0);
    digitalWrite(c1,0);
    digitalWrite(c2,1);
    digitalWrite(Posiciones[2],1);
    delay(2);
    //c2f2
    digitalWrite(c2,1);
    digitalWrite(Posiciones[2],0);
    digitalWrite(Posiciones[3],1);
    delay(2);
    digitalWrite(Posiciones[3],0);
    digitalWrite(c2,0);
    
    
  }
}

