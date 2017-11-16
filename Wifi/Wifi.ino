/*
  WiFi Web Server
 
 A simple web server that shows the value of the analog input pins.
 using a WiFi shield.
 
 This example is written for a network using WPA encryption. For 
 WEP or WPA, change the Wifi.begin() call accordingly.
 
 Circuit:
 * WiFi shield attached
 * Analog inputs attached to pins A0 through A5 (optional)
 
 created 13 July 2010
 by dlf (Metodo2 srl)
 modified 31 May 2012
 by Tom Igoe

 */

#include <SPI.h>
#include <WiFi.h>
#include <Servo.h>

Servo microservo;
char ssid[] = "Fun Theory-Innovacion";      // your network SSID (name) 
char pass[] = "robertoyoc23";   // your network password               
int status = WL_IDLE_STATUS;
IPAddress ip(192, 168, 0, 52); 
String readString;
int pos=0;
WiFiServer server(80);

void setup() {
  //Initialize serial and wait for port to open:
  Serial.begin(9600); 
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  
  // check for the presence of the shield:
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present"); 
    // don't continue:
    while(true);
  } 
  
  // attempt to connect to Wifi network:
  while ( status != WL_CONNECTED) { 
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:    
    status = WiFi.begin(ssid, pass);


    // wait 10 seconds for connection:
    delay(10000);
    WiFi.config(ip);
  } 
  server.begin();
}


void loop() {
  // listen for incoming clients
  WiFiClient client = server.available();
  if (client) {
    while (client.connected()) {   
      if (client.available()) {
        char c = client.read();
     
        //Lee caracter por caracter HTTP
        if (readString.length() < 100) {
          //Almacena los caracteres a un String
          readString += c;
          
         }

         // si el requerimiento HTTP fue finalizado
         if (c == '\n') {          
           Serial.println(readString); //Imprime en el monitor serial
     
           client.println("HTTP/1.1 200 OK");           //envia una nueva pagina en codigo HTML
           client.println("Content-Type: text/html");
           client.println();     
           client.println("<HTML>");
           client.println("<HEAD>");
           client.println("<TITLE>Ethernet Arduino</TITLE>");
           client.println("</HEAD>");
           client.println("<BODY>");
           client.println("<hr />");
           client.println("<H1>Arduino Ethernet Shield</H1>");
           client.println("<br />");  
           client.println("<H2>Control on/off 2-6  Servo 7</H2>");
           client.println("<br />");  
           
           client.println("<a href=\"/?button2on\"\"> Encender Pin2</a> ");           // construye en la pagina cada uno de los botones
           client.println(" | | | ");
           client.println("<a href=\"/?button2off\"\"> Apagar Pin2</a><br /> ");   
           client.println("<br />");
           
           client.println("<br />"); 
           client.println("<a href=\"/?button3on\"\"> Encender Pin3</a> ");
           client.println(" | | | ");
           client.println("<a href=\"/?button3off\"\"> Apagar Pin3</a><br /> ");   
           client.println("<br />");
           
           client.println("<br />"); 
           client.println("<a href=\"/?button4on\"\"> Encender Pin4</a> ");
           client.println(" | | | ");
           client.println("<a href=\"/?button4off\"\"> Apagar Pin4</a><br /> ");   
           client.println("<br />");
           
           client.println("<br />");  
           client.println("<a href=\"/?button5on\"\"> Encender Pin5</a>");
           client.println(" | | | ");
           client.println("<a href=\"/?button5off\"\"> Apagar Pin5</a><br />");   
           client.println("<br />");
           
           client.println("<br />"); 
           client.println("<a href=\"/?button6on\"\"> Encender Pin6</a> ");
           client.println(" | | | ");
           client.println("<a href=\"/?button6off\"\"> Apagar Pin6</a><br /> ");   
           client.println("<br />");
           
           
           client.println("<br />"); 
           client.println("<a href=\"/?left\"\">Girar  Izq Pin7</a>");
           client.println(" | | | ");
           client.println("<a href=\"/?right\"\">Girar Der Pin7</a><br />"); 
           client.println("<hr />");
           client.println("<p>by: elprofegarcia.com</p>");  
           client.println("<br />"); 
           client.println("</BODY>");
           client.println("</HTML>");
     
           delay(1);
           //detiene el cliente servidor
           client.stop();
           
           //control del arduino si un boton es presionado
                   
           if (readString.indexOf("?button2on") >0){
               digitalWrite(2, HIGH);
           }
           if (readString.indexOf("?button2off") >0){
               digitalWrite(2, LOW);
           }
           
           if (readString.indexOf("?button3on") >0){
               digitalWrite(3, HIGH);
           }
           if (readString.indexOf("?button3off") >0){
               digitalWrite(3, LOW);
           }
           
           
           if (readString.indexOf("?button4on") >0){
               digitalWrite(4, HIGH);
           }
           if (readString.indexOf("?button4off") >0){
               digitalWrite(4, LOW);
           }
           
            if (readString.indexOf("?button5on") >0){
               digitalWrite(5, HIGH);
           }
           if (readString.indexOf("?button5off") >0){
               digitalWrite(5, LOW);
           }
           
           
           if (readString.indexOf("?button6on") >0){
               digitalWrite(6, HIGH);
           }
           if (readString.indexOf("?button6off") >0){
               digitalWrite(6, LOW);
              
           }
           
           
           if (readString.indexOf("?left") >0){
                for(pos = 0; pos < 180; pos += 3)  // Giro de 0 a 180 grados 
                {                                  
                  microservo.write(pos);             
                  delay(15);                       // Espera 15 ms para que el servo llege a la posicion 
                } 
           }
           if (readString.indexOf("?right") >0){
                for(pos = 180; pos>=1; pos-=3)     //Giro de 180 a 0 grados 
                {                                
                  microservo.write(pos);              
                  delay(15);                       // Espera 15 ms para que el servo llege a la posicion 
                } 
           }
            // Limpia el String(Cadena de Caracteres para una nueva lectura
            readString="";  
           
         }
       }
    }
}
}
