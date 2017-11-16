int rled = 11; // Pin PWN 11 para led rojo
int gled = 10; // Pin PWM 10 para led azul
int bled = 9;  // Pin PWM 9  para led verde
 
/*----Declaracion de variables auxiliares-----*/
int i; // Variable para ciclos repetitivos
int repeat = 5; // Variables para cantidad limite de repeticiones
 
 
void setup() {
/*----- Se inicializan pines PWM como salida*/  
  pinMode(rled, OUTPUT);
  pinMode(bled, OUTPUT);
  pinMode(gled, OUTPUT);
}
 
void loop() {
  rgbon();
  
}
void rgbon(){
  analogWrite(rled,255); // Se enciende color rojo
  delay(500);            // Se esperan 500 ms
  analogWrite(rled,0);   // Se apaga color rojo 
  analogWrite(bled,255); // Se enciende color azul
  delay(500);            // Se esperan 500 ms
  analogWrite(bled,0);   // Se apaga color azul
  analogWrite(gled,255); // Se enciende color verde
  delay(500);            // Se esperan 500 ms
  analogWrite(gled,0);   // Se apaga colo verde
}
void rgb(int red, int green, int blue){
  analogWrite(rled, red);
  analogWrite(gled, green);
  analogWrite(bled, blue);
  
}

