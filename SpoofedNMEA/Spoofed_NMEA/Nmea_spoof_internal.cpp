#ifndef NMEA_SPOOF_INTERNAL
#define NMEA_SPOOF_INTERNAL

#if (ARDUINO>100)
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

String return_in(String input_str);

int find_location_of_lat(String in_nmea);


#endif
