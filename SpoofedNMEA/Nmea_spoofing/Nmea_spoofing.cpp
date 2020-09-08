#include <Nmea_spoofing.h>

// std::string strip_nmea_crc(std::string nmea_in){
//     std::string nmea_out = nmea_in;
//     return nmea_out;


// }


int find_location_of_lat(char* in_nmea){
    char search_char[] = ",";
    int len_char = strlen(in_nmea);
    int num_found = 0;

    for (int i=0;i<len_char;i++){
        if (in_nmea[i] == *search_char){
            num_found++;
        }
    }

    return num_found;
}



char* spoof_nmea(char* in_char){

    int num_comma = find_location_of_lat(in_char); //find_location_of_lat(in_char);
    char* added_char;
    strcpy(added_char, in_char);

    if (num_comma > 1){
        // sprintf(added_char, ": Found %i commas", num_comma);

        strcat(added_char,": TEST");
    }


    //char* adding_str = in_char;
    //sprintf(adding_str, ": FOUND %i COMMAS", num_comma);
    // strcat(adding_str, "ADDED");

    // // Seach for "$"
    // char search_char[] = ",";
    // int len_char = strlen(in_char);

    // for (int i=0;i<len_char;i++){
    //     if (in_char[i] == *search_char){
    //         in_char[i] = '!';
    //         strcat(in_char," found");
    //     }
    // }

    // change to string
    // std::string input_str(in_char);
    // // change something
    // std::size_t found_loc = input_str.find("$");
    // input_str.append(" : FOUND");
    // change back to char
    // const char* return_str = input_str.c_str();

    return added_char;
}