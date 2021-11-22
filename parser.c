#include "parser.h"

int checksum(const char *sentence) {
    int c = 0;
    if (*sentence == '$')
        sentence++;

    while (*sentence && *sentence != '*')
        c ^= *sentence++;

    return c;
}

int HextoDec(char *Hex){
    int base=1, length, i=0;
    int decimal;

    length = strlen(Hex);
    
    for(i = length--; i >= 0; i--)
    {
        if(Hex[i] >= '0' && Hex[i] <= '9')
        {
            decimal += (Hex[i] - 48) * base;
            base *= 16;
        }
        else if(Hex[i] >= 'A' && Hex[i] <= 'F')
        {
            decimal += (Hex[i] - 55) * base;
            base *= 16;
        }
        else if(Hex[i] >= 'a' && Hex[i] <= 'f')
        {
            decimal += (Hex[i] - 87) * base;
            base *= 16;
        }
    }
    return decimal;
}

bool NMEA_parser(const char *NMEA_message, &){
    int itr=0, i;
    const char *help_char =NMEA_message;
    char buffor[5];
    memset(&buffor, 0, 5);

    while(*help_char){
        if(*help_char == '*'){
            strcpy(buffor, ++help_char);
            break;
        }
        help_char=help_char+sizeof(char);
    }

    
    if(HextoDec(buffor)!=checksum(NMEA_message))
        return false;



  return true;
}

