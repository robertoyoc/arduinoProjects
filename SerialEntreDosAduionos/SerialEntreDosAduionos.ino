void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  Serial.println(" Soy Serial");
  Serial3.println(" Soy Serial1");
}

String Texto, textrec;
void loop() {
  if(Serial.available()){
    Texto=  Serial.readString();
    for(int x=0; x<Texto.length(); x++){
      Serial.print(Texto[x]);
      Serial3.print(Texto[x]);
      delay(500);
    }
  }
  Texto="";
  if(Serial1.available()>0){
    /*textrec=  Serial1.readString();
    Serial.println(textrec);
    Serial1.println(" Recibi el texto: " + textrec);
    Serial1.println(" Envie el texto: " + Texto);
    Serial.println(" Escribe tu texto...");
    textrec = "";
    */
  }
  delay(500);
  
}
