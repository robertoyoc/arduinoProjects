int contador=1;
void setup()
{
  //Led 13 para indicar final de operacion de configuracion AT
  pinMode(13,OUTPUT);
  //Velocidad del modulo bluetooth, 9600 por defecto
  Serial.begin(9600);
  //Apagamos el led 13
  digitalWrite(13,LOW);
}
void loop()
{
  //Es para realizar los cambios una sola vez
  while (contador==1)
  {
   //Indicacion de tiempo de espera iniciado
   digitalWrite(13,HIGH);
   /*Tiempo de espera de 15 segundos (prudencial, se puede cambiar, depende de lo que tardes
   en volver a conectarlos) para reconectar cables RX y TX del modulo bluetooth
   a la placa Arduino ya que para programar esta deben estar desconectados*/
   delay(5000);
   //Indicacion de tiempo de espera finalizado
   digitalWrite(13,LOW);
   //Iniciamos comunicacion con modulo bluetooth mediante comandos AT
   Serial.println("AT");
   //Espera de 1 segundo según datasheet entre envio de comandos AT
   delay(1000);
   //Cambio de nombre donde se envia AT+NAME y seguido el nombre que deseemos
   Serial.println("AT+NAMEMIXER");
   //Espera de 1 segundo según datasheet entre envio de comandos AT
   delay(1000);
   /*Cambio de la velocidad del modulo en baudios
   Se envia AT+BAUD y seguido el numero correspondiente:
   
   1 --> 1200 baudios
   2 --> 2400 baudios
   3 --> 4800 baudios
   4 --> 9600 baudios (por defecto)
   5 --> 19200 baudios
   6 --> 38400 baudios
   7 --> 57600 baudios
   8 --> 115200 baudios
   
   */
   Serial.println("AT+BAUD4");
   //Espera de 1 segundo según datasheet entre envio de comandos AT
   delay(1000);
   //Configuracion Password, se envia AT+PIN y seguido password que queremos
   Serial.println("AT+PIN3750");
   //Espera de 1 segundo según datasheet entre envio de comandos AT
   delay(1000);
   //Mostramos tanto por puerto serial y por led la finalizacion de la
   //configuracion AT del modulo bluetooth
   Serial.println("OK Cambios Realizados correctamente");
   digitalWrite(13,HIGH);
   //Al tener contador=2 ya no se vuelve a repetir el while, a no ser que
   //se produzca un reset, por tanto comenzaria un nuevo cambio de configuracion
   contador=2;
}
}
 
