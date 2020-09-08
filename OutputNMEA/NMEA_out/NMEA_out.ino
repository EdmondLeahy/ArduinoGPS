#include <Adafruit_GPS.h>
#include <SoftwareSerial.h>
SoftwareSerial serial1(3,2);
Adafruit_GPS GPS(&serial1);

char* NMEA1;
char* NMEA2;
char c; 
float deg; //Will hold positin data in simple degree format
float degWhole; //Variable for the whole part of position
float degDec;  //Variable for the decimal part of degree

void setup() {
  Serial.begin(115200);
  GPS.begin(9600);
  GPS.sendCommand("$PGCMD,33,0*6D"); // Turn off Antenna Uptdate
  GPS.sendCommand(PMTK_SET_NMEA_UPDATE_1HZ); // Set Update rate to 1hz
  GPS.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCGGA); // Only send RMC and GGA
  //GPS.sendCommand(PMTK_SET_NMEA_OUTPUT_ALLDATA); // Only send RMC and GGA
  //GPS.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCONLY); // Only send RMC 
  delay(100);
  //ADAFRUIT GPS:
  //    vin -- 5v
  //    gnd -- gnd
  //    rx --- D2
  //    tx --- D3

}

void loop() {

  readGPS();
  if (GPS.fix == 1){
   Serial.println(NMEA2); 
   //Serial.println("test");
  }
  delay(10);
}

void readGPS(){
  //clearGPS();
  while(!GPS.newNMEAreceived()){
    c = GPS.read();
  }
  NMEA1 = GPS.lastNMEA();
  GPS.parse(NMEA1);
  while(!GPS.newNMEAreceived()){
    c = GPS.read();
  }
  NMEA2 = GPS.lastNMEA();
  GPS.parse(NMEA2);

}



