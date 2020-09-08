#include <Nmea_spoofing.h>
#include <SoftwareSerial.h>

char* nmea_test = "$GPGGA,201245.000,5106.9388,N,11410.5665,W,2,10,0.86,1156.3,M,-17.5,M,0000,0000*61";

void setup(){
  Serial.begin(115200);
  delay(1000);
  
  
}


void loop(){
  char* a = "";
//  //a = spoof_nmea("This is a , comma, right");
//  Serial.println("Start iteration");
  a = spoof_nmea(nmea_test);
  delay(10);
  Serial.println("Should print!");
  Serial.println(a);
//  delay(10);
//  Serial.println("Finish iteration");
//  delay(10);
  Serial.println("");
  Serial.println("");
  Serial.println("");
  Serial.println("");
  delay(2000);
}


