#include <SPI.h>
#include <Ethernet.h>

#define Pecho 6
#define Ptrig 5
long duracion, distancia;
int personas;
int inicial_1=0, inicial_2=0, def;
bool inicial= false;

int detecta();
void imprimepag();
void persona();

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };   //Direccion Fisica MAC
byte ip[] = { 192, 168, 0, 50 };                       // IP Local que usted debe configurar 
byte gateway[] = { 192, 168, 0, 1 };                   // Puerta de enlace
byte subnet[] = { 255, 255, 255, 0 };                  //Mascara de Sub Red
EthernetServer server(80);                             //Se usa el puerto 80 del servidor     

void setup() {
  pinMode(Pecho, INPUT);
  pinMode(Ptrig, OUTPUT);
  Serial.begin(9600);  // Inicializa el puerto serial
  do{
    inicial_1= detecta();
    delay(1000);
    inicial_2 = detecta();
    if(inicial_1>inicial_2)
    {
      if((inicial_1-inicial_2) <=1){
        def= inicial_1;
        inicial= true;
      }   
    }
    else{
      if((inicial_2-inicial_1) <=1){
        def= inicial_2;
        inicial=true;
      }
    }
  }while(!inicial);
 
  Ethernet.begin(mac, ip, gateway, subnet); // Inicializa la conexion Ethernet y el servidor
  server.begin();
  Serial.print("El Servidor es: ");
  Serial.println(Ethernet.localIP());
  imprimepag();
  Serial.println(def);
}


void loop() {
  int aux= detecta();
  if(aux<def)
  {
    persona();
    delay(5000);
  }
  else{
    delay(300);
    imprimepag();
  }
}
int detecta()
{
  digitalWrite(Ptrig, LOW);
  delayMicroseconds(2);
  digitalWrite(Ptrig,HIGH);
  delayMicroseconds(10);
  digitalWrite(Ptrig, LOW);
  
  duracion= pulseIn(Pecho, HIGH);
  distancia= (duracion/2)/29;
  return distancia;
}
void imprimepag(){
 EthernetClient client = server.available();
  if (client) {  
      if (client.available()) {        
     
           client.println("HTTP/1.1 200 OK");           //envia una nueva pagina en codigo HTML
           client.println("Content-Type: text/html");
           client.println();     
           client.println("<HTML>");
           client.println("<HEAD>");
           client.println("<meta charset='UTF-8'>");
           client.println("<TITLE>Arduino</TITLE>");
           client.println("<style type='text/css'>");
           client.println ("body{");
            client.println("text-align: center;");
            client.println("vertical-align: center;");
            client.println("width: 100%;");
            client.println("height: 100%;");
            client.println("background-color: #02f292;");
            client.println("display: block;");
            client.println("}");
            client.println("p{");
            client.println("font-size: 60px; ");
            client.println("}");
            client.println("</style");
           client.println("</HEAD>");
           client.println("<BODY>");
           client.println("<p> ¡Esperando personas! Aún estamos a tiempo. </p>");
           client.println("</BODY>");
           client.println("</HTML>");
     
           delay(1);
           //detiene el cliente servidor
           client.stop();
         }
  }
}
void persona(){
  EthernetClient client = server.available();
  if (client) { 
      if (client.available()) {        
     
           client.println("HTTP/1.1 200 OK");           //envia una nueva pagina en codigo HTML
           client.println("Content-Type: text/html");
           client.println();     
           client.println("<HTML>");
           client.println("<HEAD>");
           client.println("<meta http-equiv='Refresh' content='0;url=http://localhost/arduino'>");
           client.println("<TITLE>Arduino</TITLE>");
           client.println("</HEAD>");
           client.println("<BODY>");
           client.println("</BODY>");
           client.println("</HTML>");
     
           delay(1);
           //detiene el cliente servidor
           client.stop();
         }
       }
}

