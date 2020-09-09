

String return_in(String input_str){
  return input_str;
}


int find_location_of_lat(String in_nmea){
    char search_char[] = ",";
    int len_char = in_nmea.length();
    int num_found = 0;

    for (int i=0;i<len_char;i++){
        if (in_nmea[i] == *search_char){
            num_found++;
        }
    }

    return num_found;
}
