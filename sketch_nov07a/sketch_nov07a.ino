#define Pecho 6
#define Ptrig 7
long duracion, distancia;
int x;

void setup(){
  pinMode(Pecho, INPUT);
  pinMode(Ptrig, OUTPUT);
  pinMode(13,1);
  Serial.begin(9660);
}

void loop(){
  x=500;
  digitalWrite(Ptrig, LOW);
  delayMicroseconds(2);
  digitalWrite(Ptrig,HIGH);
  delayMicroseconds(10);
  digitalWrite(Ptrig, LOW);
  
  duracion= pulseIn(Pecho, HIGH);
  distancia= (duracion/2)/29;
  
  if(distancia >=500 || distancia <= 0){
    Serial.println("---");
  }
  else{
    Serial.print(distancia);
    Serial.println("cm");
    digitalWrite(13,0);
  }
  if(distancia <=10 && distancia >=1){
    digitalWrite(13,1);
    x=5000;
    Serial.println("Alarma....");
  }
  delay(x);
}
