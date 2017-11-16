
String textoR;


void setup()  
{
 Serial3.begin(9600);
 
 Serial.begin(9600);
 Serial.println("Hola, estoy esperando datos."); 
}

void loop(){
   if(Serial3.available()>0)
   {
     textoR= Serial3.readString();
     Serial.println(textoR);
   }
}

