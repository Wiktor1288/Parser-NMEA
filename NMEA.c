#include <stdio.h>
#include <stdlib.h>
#include "parser.h"





int main(void){
NMEA_GGA struct_1;
char *message="$GNGGA,001043.00,4404.14036,N,12118.85961,W,1,12,0.98,1113.0,M,-21.3,M*47";
char *message2="$GPGGA,123519,4807.038,N,01131.000,E,1,08,0.9,545.4,M,46.9,M,,*47";


printf("helllo world %s \n", message2);
printf("helllo world %s \n", message);
if(NMEA_parser(message2,&struct_1))
    ShowDataGGA(struct_1);


if(NMEA_parser(message,&struct_1))
    ShowDataGGA(struct_1);

return 0;

}