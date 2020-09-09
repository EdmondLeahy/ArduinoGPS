#include "Nmea_spoof_internal.h"
#include <SoftwareSerial.h>
String nmea_test = "$GPGGA,201245.000,5106.9388,N,11410.5665,W,2,10,0.86,1156.3,M,-17.5,M,0000,0000*61";

void setup(){
  Serial.begin(115200);
//  delay(1000);
  
  
}


void loop(){
  String a = "This is a , comma, right";
  Serial.println(find_location_of_lat(nmea_test));
  
//  Serial.println("spoofing");
//  const char* spoofed = spoof_nmea(a);
//  Serial.println("spoofed");
//  Serial.println("Start iteration");
//  a = spoof_nmea(nmea_test);
  delay(1000);
//  Serial.println(spoofed);
//  Serial.println(a);
//  delay(10);
//  Serial.println("Finish iteration");
//  delay(10);
//  Serial.println("");
//  Serial.println("");
//  Serial.println("");
//  Serial.println("");
//  delay(2000);
}


