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
  delay(1000);
  //ADAFRUIT GPS:
  //    vin -- 5v
  //    gnd -- gnd
  //    rx --- D2
  //    tx --- D3
  Serial.println("Longitude,  Latitude,   Altitude");

}

void loop() {

  readGPS();
  
  if (GPS.fix == 1){
    
    degWhole=float(int(GPS.longitude/100)); //gives me the whole degree part of Longitude
    degDec = (GPS.longitude - degWhole*100)/60; //give me fractional part of longitude
    deg = degWhole + degDec; //Gives complete correct decimal form of Longitude degrees
    if (GPS.lon=='W') {  //If you are in Western Hemisphere, longitude degrees should be negative
      deg= (-1)*deg;
  }
  Serial.print(deg,4); 
  Serial.print(", "); 
  
  degWhole=float(int(GPS.latitude/100)); //gives me the whole degree part of latitude
  degDec = (GPS.latitude - degWhole*100)/60; //give me fractional part of latitude
  deg = degWhole + degDec; //Gives complete correct decimal form of latitude degrees
  
  if (GPS.lat=='S') {  //If you are in Southern hemisphere latitude should be negative
    deg= (-1)*deg;
  }
  Serial.print(deg,4); 
  Serial.println(","); 
  }
  
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

 

}

void clearGPS() {
  while(!GPS.newNMEAreceived()){
    c = GPS.read();
  }

  //GPS.parse(GPS.lastNMEA());

}



