
String Ord;
int x=20;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(3,1);
  pinMode(12,1);
  pinMode(11,1);
  pinMode(10,1);
  pinMode(9,1);
  pinMode(8,1);
  pinMode(7,1);
  pinMode(6,1);
  pinMode(5,1);
  pinMode(4,1);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available())
  {
     Ord= Serial.readString();
     if(Ord=="M2D")
      {
          digitalWrite(3, 1);
          Ord=Serial.readString();
          while(Ord!="S")
          {
            delay(x);
            Ord=Serial.readString();
          }
          digitalWrite(3, 0);
      }
      if(Ord=="M2U")
      {
          digitalWrite(12, 1);
          Ord=Serial.readString();
          while(Ord!="S")
          {
            delay(x);
            Ord=Serial.readString();
          }
          digitalWrite(12, 0);
      }
      if(Ord=="M1A")
      {
          digitalWrite(5, 1);
Ord=Serial.readString();
          while(Ord!="S")
          {
            delay(x);
            Ord=Serial.readString();
          }
          digitalWrite(5, 0);
      }
      if(Ord=="M1C")
      {
          digitalWrite(4, 1);
          Ord=Serial.readString();
          while(Ord!="S")
          {
            delay(x);
            Ord=Serial.readString();
          }
          digitalWrite(4, 0);
      }
      if(Ord=="M3D")
      {
          digitalWrite(9, 1);
          Ord=Serial.readString();
          while(Ord!="S")
          {
            delay(x);
            Ord=Serial.readString();
          }
          digitalWrite(9, 0);
      }if(Ord=="M3U")
      {
          digitalWrite(8, 1);
          Ord=Serial.readString();
          while(Ord!="S")
          {
            delay(x);
            Ord=Serial.readString();
          }
          digitalWrite(8, 0);
      }
      if(Ord=="M4D")
      {
          digitalWrite(7, 1);
          Ord=Serial.readString();
          while(Ord!="S")
          {
            delay(x);
            Ord=Serial.readString();
          }
          digitalWrite(7, 0);
      }if(Ord=="M4U")
      {
          digitalWrite(6, 1);
          Ord=Serial.readString();
          while(Ord!="S")
          {
            delay(x);
            Ord=Serial.readString();
          }
          digitalWrite(6, 0);
      }
      if(Ord=="M5I")
      {
          digitalWrite(10, 1);
          Ord=Serial.readString();
          while(Ord!="S")
          {
            delay(x);
            Ord=Serial.readString();
          }
          digitalWrite(10,0);
      }if(Ord=="M5D")
      {
          digitalWrite(11, 1);
          Ord=Serial.readString();
          while(Ord!="S")
          {
            delay(x);
            Ord=Serial.readString();
          }
          digitalWrite(11, 0);
      }
  }
}
