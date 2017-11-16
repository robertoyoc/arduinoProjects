#define Pecho 6
#define Ptrig 7
long duracion, distancia;
int personas;

void setup(){
  pinMode(Pecho, INPUT);
  pinMode(Ptrig, OUTPUT);
  pinMode(13,1);
  Serial.begin(9660);
}
bool detecta();

void loop(){
  
  if(detecta())
  {
    personas++;
    while(detecta())
    {
      delay(20);
    }
  }
   Serial.print(personas);
   Serial.println(" personas.");
   delay(200);
}
bool detecta()
{
   digitalWrite(Ptrig, LOW);
  delayMicroseconds(2);
  digitalWrite(Ptrig,HIGH);
  delayMicroseconds(10);
  digitalWrite(Ptrig, LOW);
  
  duracion= pulseIn(Pecho, HIGH);
  distancia= (duracion/2)/29;
  if(distancia<145) return true;
  else return false;
}


