#include <Adafruit_GPS.h>
#include <SoftwareSerial.h>
SoftwareSerial serial1(3,2);
Adafruit_GPS GPS(&serial1);

String NMEA1;
String NMEA2;
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
//  GPS.sendCommand(PMTK_SET_NMEA_OUTPUT_ALLDATA); // Only send RMC and GGA
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
    
    String nmea = GPS.lastNMEA();
    if (nmea.substring(2,7) == "GPGGA"){
      Serial.print(nmea);
    }
  }
}

void readGPS(){
  //clearGPS();
  while(!GPS.newNMEAreceived()){
    c = GPS.read();
  }
  
  GPS.parse(GPS.lastNMEA());

}



