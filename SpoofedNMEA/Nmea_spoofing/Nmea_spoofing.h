
#include <string.h>
#include <stdio.h>


// #include <string>
#ifndef NMEA_SPOOFING_H
#define NMEA_SPOOFING_H


// std::string strip_nmea_crc(std::string);

char* spoof_nmea(char* in_char);

int find_location_of_lat(char* in_nmea);

#endif
    