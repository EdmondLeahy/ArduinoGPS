#include <Adafruit_GPS.h>
#include <SoftwareSerial.h>
SoftwareSerial serial1(3,2);
Adafruit_GPS GPS(&serial1);

String NMEA1;
String NMEA2;
char c; 

void setup() {
  Serial.begin(115200);
  GPS.begin(9600);
  GPS.sendCommand("$PGCMD,33,0*6D"); // Turn off Antenna Uptdate
  GPS.sendCommand(PMTK_SET_NMEA_UPDATE_1HZ); // Set Update rate to 1hz
  GPS.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCGGA); // Only send RMC and GGA
  delay(1000);
  //ADAFRUIT GPS:
  //    vin -- 5v
  //    gnd -- gnd
  //    rx --- D2
  //    tx --- D3

}

void loop() {
  readGPS();
  
  
}

void readGPS(){
  clearGPS();
  while(!GPS.newNMEAreceived()){
    c = GPS.read();
  }

  GPS.parse(GPS.lastNMEA());
  NMEA1 = GPS.lastNMEA();

  while(!GPS.newNMEAreceived()){
    c = GPS.read();
  }

  GPS.parse(GPS.lastNMEA());
  NMEA2 = GPS.lastNMEA();

  Serial.println(NMEA1);
  Serial.println(NMEA2);
  Serial.println(" ");
  

}

void clearGPS() {
  while(!GPS.newNMEAreceived()){
    c = GPS.read();
  }

  //GPS.parse(GPS.lastNMEA());

}



