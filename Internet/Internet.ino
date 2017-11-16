#include <WiFi.h>

char ssid[] = "INFINITUMx8ts";     //  your network SSID (name) 
char key[] = "6115bb4168";    // your network key
int keyIndex = 0;            //your network key Index number
int status = WL_IDLE_STATUS;     // the Wifi radio's status

void setup() {
  // initialize serial:
  Serial.begin(9600);

  // attempt to connect using WEP encryption:
  Serial.println("Attempting to connect to WEP network...");
  status = WiFi.begin(ssid, keyIndex, key);

  // if you're not connected, stop here:
  if ( status != WL_CONNECTED) { 
    Serial.println("Couldn't get a wifi connection");
    while(true);
  } 
  // if you are connected, print out info about the connection:
  else {
    Serial.println("Connected to network");
  }
}

void loop() {
  // do nothing
}
