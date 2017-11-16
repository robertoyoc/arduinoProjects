/*
 * Programa para el control de un vehículo de dos motores mediante puente h y módulo bluuetooth.
 * Creado por RoboTRICKs.
 * Integrantes: 
 * Roberto Yoc.
 * Kevin Barrera.
 * Jacobo Sánchez.
 * Alejandro Reséndiz.
 * Kenya Millán.
 * Fecha de creación: 14 de Octubre de 2015.
 */

/*
 * Versión 1.4 by RoboTRICKs
 * Se modifica el tiempo de espera para la siguiente intruccion del bluetooth
 * ahora es mas preciso.
 */

/*
 * Versión 1.3 by RoboTRICKs
 * Se incluyen las variables m1a, m2a para las velocidades de los motores al ir hacia adelante.
 * Se incluyen las variables m1t, m2t para las velocidades de los motores al ir hacia atrás.
 * Se cambian las instrucciones dentro de las funciones de DigitalWrite a AnalogWrite para
 * permitir la calibración de las velocidades
 */

/*
 * Versión 1.2 by RoboTRICKs
 * Se permite el cambio de los pines de los motores mediante variables.
 * am1 y bm1 para el motor izquierdo
 * am2 y bm2 para el motor derecho
*/

/*
 * Versión 1.1 by RoboTRICKs
 * Se dividen las instrucciones en funciones.
 * adelante(), atras(), izquierda() y derecha()
 * Elimina la configuración por defecto a 9600 baudios para la conexión del bluetooth.
 */

/*
 * Versión 1.0 by RoboTRICKs
 * Control de la dirección de motores mediante puente H.
 * El circuito acepta como controladoras:
 * Puente H controller.
 * LD293D
 * Puente H convencional
 * Puente H mediante transistores
 * 
 * Conexión de los motores a pines 10 y 9 para el motor izquierdo. 6 y 5 para el motor derecho.
 */
  #include <SoftwareSerial.h>

  SoftwareSerial BT(11,10);
 
  int am1= 9;
  int bm1 = 8;
  int am2 = 6;
  int bm2 =5;

  int m1a= 255; // cambia respecto a la velocidad del motor
  int m2a= 255; //cambia respecto a la velocidad del motor
  int m1t= 255; // cambia respecto a la velocidad del motor
  int m2t= 255; //cambia respecto a la velocidad del motor
  
  
  void setup() {
  // put your setup code here, to run once:

  pinMode(am1,1);
  pinMode(bm1,1);
  pinMode(am2,1);
  pinMode(bm2,1);
  BT.begin(9600);                      
}
void loop() {
  // put your main code here, to run repeatedly:
  if(BT.available()){
    Serial.print(BT.read());
    Serial.print("H");
    switch(BT.read())
    {
      case 'f':
      detener();
      break;
      case 'a': 
      adelante();
      break;
      case 'b':
      atras();
      break;
      case 'd':
      derecha();
      break;
      case 'c':
      izquierda();
      break;
    }
    delay(100);
  }
} 
void adelante(){
  analogWrite(am1, m1a);
  analogWrite(am2, m2a);
}
  void atras(){
  analogWrite(bm1, m1t);
  analogWrite(bm2, m2t);
}
void izquierda(){
  analogWrite(am1, m1a);
  analogWrite(bm2, m2a);
}
void derecha(){
  analogWrite(bm1, m1a);
  analogWrite(am2, m2a);
}
void detener(){
  analogWrite(am1, 0);
  analogWrite(am2, 0);
  analogWrite(bm2, 0);
  analogWrite(bm1, 0);
}


