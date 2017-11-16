#include <SoftwareSerial.h>

SoftwareSerial BT00(10, 11);

String text_0, text_1, text_2, text_3="2";



void setup()  
{
 BT00.begin(9600);
 
 Serial.begin(9600);

 Serial.println("Soy Serial");
 BT00.println("Soy Serial 3");
 Serial.println(text_3);
 
 
}

void loop(){
  BT00.listen();
  if(BT00.available()>0)
  {
    text_3= BT00.readString();
    Serial.print("ok");
  }
  delay(100);
  if(Serial.available()>0)
  {
    text_2= Serial.readString();
    BT00.println(text_2);
  }
}

