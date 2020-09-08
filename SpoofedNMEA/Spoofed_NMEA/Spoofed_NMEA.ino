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

String lat_spoofed;
String lon_spoofed;
char Hemisphere[] = "X";
char side[] = "Z";

// CRC Stuff

const byte buff_len = 90;
char CRCbuffer[buff_len];

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

//  lat_spoofed = "58";
//  lon_spoofed = "123";
//  Hemisphere = "N";
//  side = "W";
  
  
  readGPS();
  if (GPS.fix == 1){
    
    String nmea = GPS.lastNMEA();
    if (nmea.substring(2,7) == "GPGGA"){
//      nmea.replace(nmea.substring(19,28), "999.9390");
//      nmea.replace(nmea.substring(19,28), "999.9390");
//      nmea.replace(nmea.substring(29,30), side);
        nmea[29] = *Hemisphere;
        add_crc_and_print(nmea.substring(1,nmea.indexOf("*")+1));
        //Serial.println();
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

String add_spoofed_lat(String gga_original, String latitude_new){
    return "Test"
  
}


void add_crc_and_print(String msg) {
  msg.toCharArray(CRCbuffer, sizeof(CRCbuffer)); // put complete string into CRCbuffer
  byte crc = convertToCRC(CRCbuffer); // call function to compute the crc value

  Serial.print(msg);
  if (crc < 16) Serial.print("0"); // add leading 0 if needed
  Serial.println(crc, HEX);
}

byte convertToCRC(char *buff) {
  // NMEA CRC: XOR each byte with previous for all chars between '$' and '*'
  char c;
  byte i;
  byte start_with = 0;    // index of starting char in msg
  byte end_with = 0;      // index of starting char in msg
  byte crc = 0;

  for (i = 0; i < buff_len; i++) {
    c = buff[i];
    if (c == '$') {
      start_with = i;
    }
    if (c == '*') {
      end_with = i;
    }
  }
  if (end_with > start_with) {
    for (i = start_with + 1; i < end_with; i++) { // XOR every character between '$' and '*'
      crc = crc ^ buff[i] ;  // xor the next char
    }
  }
  else { // else if error, print a msg  
    Serial.println("CRC ERROR");
  }
  return crc;
  
  // based on code by Elimeléc López - July-19th-2013
}

