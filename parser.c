#include "parser.h"

int checksum(const char *sentence) {
    int c = 0;
    if (*sentence == '$')
        sentence++;

    while (*sentence && *sentence != '*')
        c ^= *sentence++;

    return c;
}

int HexToDec(char *Hex){
    int base=1, length=0, i=0;
    int decimal=0;

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

bool NMEA_parser(const char *NMEA_message, NMEA_GGA *structure_with_data ){
    int itr=0, i=0;
    const char *help_char =NMEA_message;
    char buffor[20];
    
    memset(buffor, 0, 20);
    while(*help_char){
        if(*help_char == '*'){
            strcpy(buffor, ++help_char);
            break;
        }
        help_char++;
    }

    printf("\n %s to %d i to %d  \n",buffor,HexToDec(buffor),checksum(NMEA_message));
    
    if(HexToDec(buffor)!=checksum(NMEA_message))
        return false;

    memset(buffor, 0, 20);
    while(*NMEA_message){
        itr=0;
        if( *NMEA_message == ','){
            i++;
            if(i==2) {
                strncpy(buffor, ++NMEA_message,2);
                structure_with_data->Latitude.degrees=atoi(buffor);
                memset(buffor, 0, 20);
                NMEA_message+=2;
                while(*NMEA_message!=','){
                    NMEA_message++;
                    itr++;
                }
                strncpy(buffor, NMEA_message-itr,itr);
                structure_with_data->Latitude.minutes=atof(buffor);
                memset(buffor, 0, 20);
                NMEA_message--; 
            }
            if(i ==3 ){
                NMEA_message++;
                switch(*NMEA_message){
                    case 'N':
                        structure_with_data->Latitude.direction=0;
                    break;

                    case 'S':
                        structure_with_data->Latitude.direction=1;
                    break;

                    default:
                        return false;
                    break;
                }
            }

            if(i==4) {
                strncpy(buffor, ++NMEA_message,2);
                structure_with_data->Longitude.degrees=atoi(buffor);
                memset(buffor, 0, 20);
                NMEA_message+=2;
                while(*NMEA_message!=','){
                    NMEA_message++;
                    itr++;
                }
                strncpy(buffor, NMEA_message-itr,itr);
                structure_with_data->Longitude.minutes=atof(buffor);
                memset(buffor, 0, 20);
                NMEA_message--; 
            }

            if(i ==5 ){
                NMEA_message++;
                switch(*NMEA_message){
                    case 'W':
                        structure_with_data->Longitude.direction=2;
                    break;

                    case 'E':
                        structure_with_data->Longitude.direction=3;
                    break;

                    default:
                        return false;
                    break;
                }
            }
          
        }
        if(i ==7 ){
            strncpy(buffor, ++NMEA_message,2);
            structure_with_data->Number_of_satellites=atoi(buffor);
            memset(buffor, 0, 20);
            NMEA_message++;

        }

        if(i ==9 ){
            NMEA_message++;
            while(*NMEA_message!=','){
                NMEA_message++;
                itr++;
            }
            strncpy(buffor, NMEA_message-itr,itr);
            structure_with_data->Altitude_m=atof(buffor);
            memset(buffor, 0, 20);
            NMEA_message--; 
        }
          NMEA_message++;

    }


  return true;
}

void ShowDataGGA(NMEA_GGA structure_1){
    printf("\n Coord:\n  Latitude: %d degrees %f min  %d direction",structure_1.Latitude.degrees, structure_1.Latitude.minutes, structure_1.Latitude.direction);
    printf("\n  Longitude: %d degrees %f min  %d direction",structure_1.Longitude.degrees, structure_1.Longitude.minutes, structure_1.Longitude.direction);
    printf("\n  Number of satellites %d", structure_1.Number_of_satellites);
    printf("\n  Altitude %f \n", structure_1.Altitude_m);
}




