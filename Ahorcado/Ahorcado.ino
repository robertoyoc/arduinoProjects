void setup() {
  // put your setup code here, to run once:
for (int x=5; x<14;x++){
  pinMode(x,1);

}
Serial.begin(9600);
}
int x=-1;
void Fin(){
  for(int k=0; k<4; k++);
  {
    for (int x=5; x<14;x++){
      digitalWrite(x,1);
    }
    delay(500);
    for (int x=5; x<14;x++){
      digitalWrite(x,0);
    }
    delay(500);
  }
  x=-1;
}

void loop() {
  // put your main code here, to run repeatedly:
  switch(Serial.read()){
    case 'c':
      x--;
      break;
    case 'i':
      x++;
      break;
    case 'f':
      Fin(); 
  }
  if(x<-1)
  {
    x= -1; 
  }
  else if(x>9){
    x=9;
  }
  switch(x)
  {
    case -1:
    digitalWrite(13,0);
    break;
    case 0:
    digitalWrite(13,1);
    digitalWrite(10,0);
    break;
    case 1:
    digitalWrite(10,1);
    digitalWrite(11,0);
    break;
    case 2:
    digitalWrite(11,1);
    digitalWrite(12,0);
    break;
    case 3:
    digitalWrite(12,1);
    digitalWrite(9,0);
    break;
    case 4:
    digitalWrite(9,1);
    digitalWrite(8,0);
    break;
    case 5:
    digitalWrite(8,1);
    digitalWrite(7,0);
    break;
    case 7:
    digitalWrite(7,1);
    digitalWrite(6,0);
    break;
    case 8:
    digitalWrite(6,1);
    digitalWrite(5,0);
    break;
    case 9:
    digitalWrite(5,1);
    break;
  }
  Serial.println(x);
}
