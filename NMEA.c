#include <stdio.h>
#include <stdlib.h>
#include "parser.h"





int main(void){

char *message="$GNGGA,001043.00,4404.14036,N,12118.85961,W,1,12,0.98,1113.0,M,-21.3,M*47";

printf("helllo world %s \n", message);
NMEA_parser(message);
return 0;
}